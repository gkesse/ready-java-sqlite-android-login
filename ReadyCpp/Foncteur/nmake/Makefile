GSRC = ../src
GBIN = bin
GBUILD = build
GTARGET = $(GBIN)/GProject.exe

GINCS =\
    /I$(GSRC)/manager
    
GOBJS =\
    $(GBUILD)/main.obj \
    $(GBUILD)/GFunctor.obj
    
all: $(GOBJS)
	link /OUT:$(GTARGET) $(GOBJS)
$(GBUILD)/main.obj: $(GSRC)/main.cpp
	cl /c /EHsc $(GSRC)/main.cpp /Fo$(GBUILD)/main.obj $(GINCS)
$(GBUILD)/GFunctor.obj: $(GSRC)/manager/GFunctor.cpp
	cl /c /EHsc $(GSRC)/manager/GFunctor.cpp /Fo$(GBUILD)/GFunctor.obj
clean:
	del /Q $(GBUILD)\* $(GBIN)\*
