GSRC = ../src
GBIN = bin
GBUILD = build
GTARGET = $(GBIN)/GProject.exe

GINCS =\
    /I$(GSRC)/manager
    
GOBJS =\
    $(GBUILD)/main.obj \
    $(GBUILD)/GTime.obj
    
all: $(GOBJS)
	link /OUT:$(GTARGET) $(GOBJS)
$(GBUILD)/main.obj: $(GSRC)/main.cpp
	cl /c /EHsc $(GSRC)/main.cpp /Fo$(GBUILD)/main.obj $(GINCS)
$(GBUILD)/GTime.obj: $(GSRC)/manager/GTime.cpp
	cl /c /EHsc $(GSRC)/manager/GTime.cpp /Fo$(GBUILD)/GTime.obj
clean:
	del /Q $(GBUILD)\* $(GBIN)\*
