SOURCES := $(wildcard src/*.cpp)
OBJECTS := $(patsubst src/%.cpp,obj/%.o,$(SOURCES))

CXX=clang++
CXX_FLAGS=-O0 -g -DGLIBCXX_DEBUG -Wall -std=c++11

all: bin obj bin/main.x

bin:
	mkdir bin

obj:
	mkdir obj

bin/main.x: $(OBJECTS)
	@echo Compiling main executable
	$(CXX) $(CXX_FLAGS) -o bin/main.x $(OBJECTS) -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lBox2D

obj/%.o: src/%.cpp
	@echo Compiling $< into $@
	$(CXX) $(CXX_FLAGS) -Iinclude/SFML -Iinclude/Box2D -c $< -o $@
	
clean: 
	rm obj/*.o bin/main.x
