GSRC = ../src
GBIN = bin
GBUILD = build
GTARGET = $(GBIN)/GProject.exe

GINCS =\
    /I$(GSRC)/manager
    
GOBJS =\
    $(GBUILD)/main.obj \
    $(GBUILD)/GPerson.obj
    
all: $(GOBJS)
	link /OUT:$(GTARGET) $(GOBJS)
$(GBUILD)/main.obj: $(GSRC)/main.cpp
	cl /c /EHsc $(GSRC)/main.cpp /Fo$(GBUILD)/main.obj $(GINCS)
$(GBUILD)/GPerson.obj: $(GSRC)/manager/GPerson.cpp
	cl /c /EHsc $(GSRC)/manager/GPerson.cpp /Fo$(GBUILD)/GPerson.obj
clean:
	del /Q $(GBUILD)\* $(GBIN)\*
