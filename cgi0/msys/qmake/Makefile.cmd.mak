GBIN = bin
GBUILD = build
GTARGET_EXE = $(GBIN)/rdcpp.exe
GTARGET_WEB = $(GPROJECT_BIN)
#================================================
all: clean_exe qmake compile copy run 
#================================================
# cpp
qmake:
	qmake
compile:
	make
copy:
	@if [ -f $(GTARGET_EXE) ] ; then cp -f $(GTARGET_EXE) $(GPROJECT_BIN) ; fi
run:
	$(GTARGET_EXE) $(argv)
clean_exe: 
	@if ! [ -d $(GBIN) ] ; then mkdir -p $(GBIN) ; fi
	rm -f $(GBIN)/*
clean: 
	@if ! [ -d $(GBIN) ] ; then mkdir -p $(GBIN) ; fi
	@if ! [ -d $(GBUILD) ] ; then mkdir -p $(GBUILD) ; fi
	rm -f $(GBUILD)/* $(GBIN)/*
#================================================    
# git
git_push:
	@cd $(GPROJECT_PATH) && git pull && git add --all && git commit -m "Initial Commit" && git push -u origin master
git_status:
	@cd $(GPROJECT_PATH) && git status
git_clone:
	@cd $(GPROJECT_ROOT) && git clone $(GGIT_URL) $(GGIT_NAME) 
#================================================    
# pacman
pacman_version:
	pacman --version
pacman_search:
	pacman -Ss $(GPACMAN_PACKAGE_SEARCH) | grep -ie "i686"
pacman_install:
	pacman -S $(GPACMAN_PACKAGE_INSTALL)
#================================================    
# pkgconfig
pkgconfig_version:
	pkg-config --version
pkgconfig_list:
	pkg-config --list-all
pkgconfig_search:
	pkg-config --list-all | grep -ie $(GPKGCONFIG_PACKAGE_SEARCH)
pkgconfig_libs:
	pkg-config --libs $(GPKGCONFIG_PACKAGE_LIBS)
pkgconfig_flags:
	pkg-config --cflags $(GPKGCONFIG_PACKAGE_CFLAGS)
#================================================    
# tmp
tmp_download:
	cd $(GTMP_PATH) && git clone $(GTMP_URL) $(GTMP_NAME)
tmp_compile:
	cd $(GTMP_PATH)/$(GTMP_NAME)$(GTMP_ROOT) && qmake && make
tmp_run:
	cd $(GTMP_PATH)/$(GTMP_NAME)$(GTMP_ROOT) && release/$(GTMP_EXE)
#================================================    
# qt_examples
qte_all: qte_compile qte_run

qte_compile:
	cd $(GQTE_PATH) && qmake && make
qte_run:
	cd $(GQTE_PATH) && release/$(GQTE_EXE)
#================================================    
# lib_git
lib_git_download:
	if ! [ -d $(GLIB_SRC) ] ; then mkdir -p $(GLIB_SRC) ; fi
	cd $(GLIB_SRC) && git clone $(GLIB_GIT_URL) $(GLIB_NAME)
lib_git_configure_help:
	cd $(GLIB_GIT_PATH) && ./configure --help
lib_git_configure_build:
	cd $(GLIB_GIT_PATH) && ./configure --prefix=$(GLIB_BUILD)
lib_git_configure_make:
	if ! [ -d $(GLIB_BUILD) ] ; then mkdir -p $(GLIB_BUILD) ; fi
	cd $(GLIB_GIT_PATH) && make && make install
#================================================    
# lib_dwl
lib_dwl_configure_help:
	cd $(GLIB_DWL_PATH) && ./configure --help
lib_dwl_configure_build:
	cd $(GLIB_DWL_PATH) && ./configure --prefix=$(GLIB_BUILD)
lib_dwl_configure_make:
	if ! [ -d $(GLIB_BUILD) ] ; then mkdir -p $(GLIB_BUILD) ; fi
	cd $(GLIB_DWL_PATH) && make && make install
#================================================    
# lib_aur
lib_aur_download:
	if ! [ -d $(GLIB_SRC) ] ; then mkdir -p $(GLIB_SRC) ; fi
	cd $(GLIB_SRC) && git clone $(GLIB_GIT_URL) $(GLIB_NAME)
lib_aur_make:
	cd $(GLIB_GIT_PATH) && makepkg -si
#================================================    
# lib_mak
lib_mak_make:
	cd $(GLIB_MAK_PATH) && make
#================================================    
