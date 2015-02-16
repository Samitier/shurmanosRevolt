SOURCES := $(wildcard src/*.cpp)
OBJECTS := $(patsubst src/%.cpp,obj/%.o,$(SOURCES))

CXX=clang++
CXX_FLAGS=-O0 -g -DGLIBCXX_DEBUG -Wall -std=c++11

all: bin obj bin/main.x Makefile

bin:
	mkdir bin

obj:
	mkdir obj

bin/main.x: $(OBJECTS)
	@echo Compiling main executable
	$(CXX) $(CXX_FLAGS) -o bin/main.x $(OBJECTS) -lBox2D -ljsoncpp -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio  

src/%.cpp: src/%.h

obj/%.o: src/%.cpp
	@echo Compiling $< into $@
	$(CXX) $(CXX_FLAGS) -I/usr/include -I/usr/include/jsoncpp -c $< -o $@
	
clean: 
	rm obj/*.o bin/main.x
