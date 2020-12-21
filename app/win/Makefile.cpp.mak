GSRC = ..\code\readyapp\src
GBIN = bin
GBUILD = build
GTARGET = $(GBIN)\rdcpp.exe

GINCS = \
    -I$(GSRC)\include \
    -IC:\Users\Admin\Downloads\Programs\ReadyLib\dev\sqlite\3.29.0\mingw\include \
    -IC:\Users\Admin\Downloads\Programs\ReadyLib\dev\opencv\2.4.13\mingw\include \
    -IC:\Users\Admin\Downloads\Programs\ReadyLib\dev\gsl\2.2.1\mingw\include \
    
GLIBS = \
    -LC:\Users\Admin\Downloads\Programs\ReadyLib\dev\sqlite\3.29.0\mingw\lib \
    -LC:\Users\Admin\Downloads\Programs\ReadyLib\dev\opencv\2.4.13\mingw\lib \
    -LC:\Users\Admin\Downloads\Programs\ReadyLib\dev\gsl\2.2.1\mingw\lib \
    -lsqlite3 -lopencv_core2413 -lopencv_imgproc2413 -lopencv_highgui2413 \
    -lgsl \

GOBJS = \
    $(patsubst $(GSRC)/%.cpp, $(GBUILD)/%.o, $(wildcard $(GSRC)/*.cpp)) \
    $(patsubst $(GSRC)/manager/%.cpp, $(GBUILD)/%.o, $(wildcard $(GSRC)/manager/*.cpp)) \

GCFLAGS = \
    -std=gnu++11 \
    
all: clean_exe compile run

compile: $(GOBJS)
	@if not exist $(GBIN) ( mkdir $(GBIN) )
	g++ $(GCFLAGS) -o $(GTARGET) $(GOBJS) $(GLIBS) 
	@echo.
$(GBUILD)/%.o: $(GSRC)/%.cpp
	@if not exist $(GBUILD) ( mkdir $(GBUILD) )
	g++ $(GCFLAGS) -c $< -o $@ $(GINCS)
$(GBUILD)/%.o: $(GSRC)/manager/%.cpp
	@if not exist $(GBUILD) ( mkdir $(GBUILD) )
	g++ $(GCFLAGS) -c $< -o $@ $(GINCS)
run:
	@$(GTARGET)
clean_exe: 
	@if not exist $(GBIN) ( mkdir $(GBIN) )
	del /s /q $(GBIN)\*.exe
clean: 
	@if not exist $(GBIN) ( mkdir $(GBIN) )
	@if not exist $(GBUILD) ( mkdir $(GBUILD) )
	del /s /q $(GBUILD)\*.o $(GBIN)\*.exe
