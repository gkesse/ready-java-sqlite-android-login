GSRC = ../src
GBIN = bin
GBUILD = build
GTARGET = $(GBIN)/GProject.exe

GINCS =\
    /I$(GSRC)/manager
    
GOBJS =\
    $(GBUILD)/main.obj \
    $(GBUILD)/GParent.obj \
    $(GBUILD)/GChild.obj
    
all: $(GOBJS)
	link /OUT:$(GTARGET) $(GOBJS)
$(GBUILD)/main.obj: $(GSRC)/main.cpp
	cl /c /EHsc $(GSRC)/main.cpp /Fo$(GBUILD)/main.obj $(GINCS)
$(GBUILD)/GParent.obj: $(GSRC)/manager/GParent.cpp
	cl /c /EHsc $(GSRC)/manager/GParent.cpp /Fo$(GBUILD)/GParent.obj
$(GBUILD)/GChild.obj: $(GSRC)/manager/GChild.cpp
	cl /c /EHsc $(GSRC)/manager/GChild.cpp /Fo$(GBUILD)/GChild.obj
clean:
	del /Q $(GBUILD)\* $(GBIN)\*
