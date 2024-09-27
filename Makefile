
LIB_DIR = `cd libs/build/ && ls | xargs readlink -f | while read line; do echo "-L$${line}"; done`
INCLUDES = `cd libs/build/ && ls | xargs readlink -f | while read line; do echo "-I$${line}/include"; done`
LIBS = -lraylib

all:main

clean:
	rm -rf build
	mkdir build

build/main.o : main.cpp
	g++ -c -o ./build/main.o ${INCLUDES} main.cpp

main : build/main.o
	g++ -o ./build/main ./build/main.o ${LIB_DIR} ${LIBS}

run_debug:
	make
	./build/main

.SILENT : run
run:
	make
	./build/main
