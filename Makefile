CC := clang++
INCLUDE := -I ./include
SRCFILES := $(wildcard ./src/*.cpp)
LIBS := -lSDL2main -lSDL2
# -lSDL2_image -lSDL2_ttf -lSDL2_mixer
CFLAGS = -std=c++17 -Wall -O3 -c ${INCLUDE}
LDFLAGS = -s ${LIBS}

binCompile: objCompile
	${CC} $(wildcard ./build/*.o) -o ./build/main ${LDFLAGS}
	./build/main

objCompile:
	mkdir -p ./build
	${CC} Main.cpp ${SRCFILES} ${CFLAGS}
	mv *.o ./build