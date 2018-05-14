CXX = g++
CPPFLAGS = -c -std=c++17 -static-libstdc++
LIB_DIR = /usr/lib/
OBJ_LIST = main.o game.o GameObject.o FirstState.o texture.o shader.o sprite.o
LIB_LIST = -lSDL2 -lgl3w -lSDL2_image 

debug:CPPFLAGS = -c -g3 -std=c++17

all: release

debug:$(OBJ_LIST)
	$(CXX) -o main $(OBJ_LIST) -L $(LIB_DIR) $(LIB_LIST)

release: $(OBJ_LIST)
	$(CXX) -o main $(OBJ_LIST) -L $(LIB_DIR) $(LIB_LIST)
 
game.o:
	$(CXX) $(CPPFLAGS) src/game.cpp

main.o:
	$(CXX) $(CPPFLAGS) src/main.cpp

GameObject.o:
	$(CXX) $(CPPFLAGS) src/object/GameObject.cpp

FirstState.o:
	$(CXX) $(CPPFLAGS) src/state/FirstState.cpp

sprite.o:
	$(CXX) $(CPPFLAGS) src/graphics/sprite.cpp

texture.o:
	$(CXX) $(CPPFLAGS) src/graphics/texture.cpp

shader.o:
	$(CXX) $(CPPFLAGS) src/graphics/shader.cpp


clean:
	rm *.o