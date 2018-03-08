GSRC = ../src
GBIN = bin
GBUILD = build
GTARGET = $(GBIN)/GProject.exe

GINCS =\
    /I$(GSRC)/manager
    
GOBJS =\
    $(GBUILD)/main.obj \
    $(GBUILD)/GShape.obj \
    $(GBUILD)/GShapeLine.obj \
    $(GBUILD)/GShapeRectangle.obj \
    $(GBUILD)/GShapeEllipse.obj
    
all: $(GOBJS)
	link /OUT:$(GTARGET) $(GOBJS)
$(GBUILD)/main.obj: $(GSRC)/main.cpp
	cl /c /EHsc $(GSRC)/main.cpp /Fo$(GBUILD)/main.obj $(GINCS)
$(GBUILD)/GShape.obj: $(GSRC)/manager/GShape.cpp
	cl /c /EHsc $(GSRC)/manager/GShape.cpp /Fo$(GBUILD)/GShape.obj
$(GBUILD)/GShapeLine.obj: $(GSRC)/manager/GShapeLine.cpp
	cl /c /EHsc $(GSRC)/manager/GShapeLine.cpp /Fo$(GBUILD)/GShapeLine.obj
$(GBUILD)/GShapeRectangle.obj: $(GSRC)/manager/GShapeRectangle.cpp
	cl /c /EHsc $(GSRC)/manager/GShapeRectangle.cpp /Fo$(GBUILD)/GShapeRectangle.obj
$(GBUILD)/GShapeEllipse.obj: $(GSRC)/manager/GShapeEllipse.cpp
	cl /c /EHsc $(GSRC)/manager/GShapeEllipse.cpp /Fo$(GBUILD)/GShapeEllipse.obj
clean:
	del /Q $(GBUILD)\* $(GBIN)\*
