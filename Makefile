EM = emcc
SRCS = src/*.cpp
EM_FLAGS = -std=c++1y -s WASM=1
OBJS := $(find ./src -name '*.cpp' ! -name 'main.cpp')

build:
	$(EM) $(SRCS) $(EM_FLAGS)


test:
	g++ test/test.cpp src/Image.cpp src/Object.cpp src/Rect.cpp src/Scene.cpp src/Vector2.cpp -I./src -std=c++1y -o test.out
	./test.out
	rm test.out

.PHONY: build test