GSRC = $(GPROJECT_SRC)
GBIN = bin
GBUILD = build
GTARGET = $(GPROJECT_TARGET)    
#================================================
# cpp
all: clean_exe qmake compile run

qmake:
	@qmake
compile: $(GOBJS)
	@make 
run:
	@$(GTARGET) $(argv)
clean_exe: 
	@if ! [ -d $(GBIN) ] ; then mkdir -p $(GBIN) ; fi
	@rm -f $(GBIN)/*
clean: 
	@if ! [ -d $(GBIN) ] ; then mkdir -p $(GBIN) ; fi
	@if ! [ -d $(GBUILD) ] ; then mkdir -p $(GBUILD) ; fi
	@rm -f $(GBUILD)/*.o $(GBIN)/*
#================================================    
# qt
qt_install:
	@pacman -S --needed -y \
	mingw-w64-i686-qt5 \
	mingw-w64-i686-qt-creator \
	mingw-w64-i686-gdb \
	mingw-w64-i686-cmake \
	mingw-w64-i686-clang \
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
git_push_o:
	@cd $(GPROJECT_PATH) && git add --all && git commit -m "Initial Commit" && git push -u origin master
git_clone:
	@cd $(GPROJECT_ROOT) && git clone $(GGIT_URL) $(GGIT_NAME) 
#================================================
