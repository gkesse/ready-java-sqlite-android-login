GSRC = ..\src
GBIN = bin
GBUILD = build
GTARGET = $(GBIN)\GProject.exe

GOBJS = \
	$(GBUILD)\main.o \
	$(GBUILD)\GFile.o
	
all: $(GOBJS)
	g++ -o $(GTARGET) $(GOBJS)
$(GBUILD)\main.o: $(GSRC)\main.cpp
	g++ -c $(GSRC)\main.cpp -o $(GBUILD)\main.o
$(GBUILD)\GFile.o: $(GSRC)\GFile.cpp
	g++ -c $(GSRC)\GFile.cpp -o $(GBUILD)\GFile.o
clean:
	del /q $(GOBJS) $(GTARGET)
