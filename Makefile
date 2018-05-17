CXX = g++
CPPFLAGS = -c -std=c++14 -static-libstdc++
LIB_DIR = usr/lib/
OBJ_LIST = game.o main.o texture.o shader.o sprite.o rectangle.o particle.o TextureManager.o StateMachine.o FirstState.o GameObjectManager.o Player.o Enemy.o
LIB_LIST = -lSDL2 -lgl3w -lSDL2_image 

debug:CPPFLAGS = -c -g3

all: release

debug:$(OBJ_LIST)
	$(CXX) -o main $(OBJ_LIST) -L $(LIB_DIR) $(LIB_LIST)

release: $(OBJ_LIST)
	$(CXX) -o main $(OBJ_LIST) -L $(LIB_DIR) $(LIB_LIST)
 
game.o:
	$(CXX) $(CPPFLAGS) src/game.cpp

main.o:
	$(CXX) $(CPPFLAGS) src/main.cpp

shader.o:
	$(CXX) $(CPPFLAGS) src/graphic/shader.cpp

sprite.o:
	$(CXX) $(CPPFLAGS) src/graphic/sprite.cpp

texture.o:
	$(CXX) $(CPPFLAGS) src/graphic/texture.cpp

particle.o:
	$(CXX) $(CPPFLAGS) src/graphic/particle.cpp

rectangle.o:
	$(CXX) $(CPPFLAGS) src/graphic/rectangle.cpp

TextureManager.o:
	$(CXX) $(CPPFLAGS) src/manager/TextureManager.cpp

StateMachine.o:
	$(CXX) $(CPPFLAGS) src/manager/StateMachine.cpp

FirstState.o:
	$(CXX) $(CPPFLAGS) src/state/FirstState.cpp

GameObjectManager.o:
	$(CXX) $(CPPFLAGS) src/manager/GameObjectManager.cpp 

Player.o:
	$(CXX) $(CPPFLAGS) src/object/Player.cpp

Enemy.o:
	$(CXX) $(CPPFLAGS) src/object/Enemy.cpp

clean:
	del *.o