#================================================
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
	@pacman -S --needed --noconfirm mingw-w64-i686-qt5
	@pacman -S --needed --noconfirm mingw-w64-i686-qt-creator
	@pacman -S --needed --noconfirm mingw-w64-i686-gdb
	@pacman -S --needed --noconfirm mingw-w64-i686-cmake
	@pacman -S --needed --noconfirm mingw-w64-i686-clang
#================================================    
# qt_example
qte_all:
	@cd $(GQT_EXAMPLE_ROOT) && qmake && make
qte_run:
	@$(GQT_EXAMPLE_BIN)
#================================================    
# gsl
gsl_install:
	@pacman -S --needed --noconfirm mingw-w64-i686-gsl
gsl_remove:
	@pacman -R mingw-w64-i686-gsl
#================================================    
# git
git_install:
	@pacman -S --needed --noconfirm git
	@pacman -S --needed --noconfirm vim
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
