GSRC = $(GPROJECT_SRC)
GBIN = bin
GBUILD = build
GTARGET = $(GPROJECT_EXE)

GINCS = \
    -I$(GSRC)\include \
    
GLIBS = \

GOBJS = \
    $(patsubst $(GSRC)/%.cpp, $(GBUILD)/%.o, $(wildcard $(GSRC)/*.cpp)) \

GCFLAGS = \
    -std=gnu++11 \
    
#================================================
# cpp
all: clean_exe compile run

compile: $(GOBJS)
	@if ! [ -d $(GBIN) ] ; then mkdir -p $(GBIN) ; fi
	@g++ $(GCFLAGS) -o $(GTARGET) $(GOBJS) $(GLIBS) 
$(GBUILD)/%.o: $(GSRC)/%.cpp
	@if ! [ -d $(GBUILD) ] ; then mkdir -p $(GBUILD) ; fi
	@g++ $(GCFLAGS) -c $< -o $@ $(GINCS)
run:
	$(GTARGET) $(argv)
clean_exe: 
	@if ! [ -d $(GBIN) ] ; then mkdir -p $(GBIN) ; fi
	@rm -f $(GTARGET)
clean: 
	@if ! [ -d $(GBIN) ] ; then mkdir -p $(GBIN) ; fi
	@if ! [ -d $(GBUILD) ] ; then mkdir -p $(GBUILD) ; fi
	@rm -f $(GBUILD)/*.o $(GTARGET)
#================================================    
# git
git_install:
	@pacman -S --needed git
	@pacman -S --needed vim
git_config:
	@git config --global user.name "Gerard KESSE"
	@git config --global user.email "tiakagerard@hotmail.com"
	@git config --global core.editor "vim"
	@git config --list
git_store:
	@git config credential.helper store
git_push:
	@cd $(GPROJECT_PATH) && git pull && git add --all && git commit -m "Initial Commit" && git push -u origin master
git_clone:
	@cd $(GPROJECT_ROOT) && git clone $(GGIT_URL) $(GGIT_NAME) 
#================================================
