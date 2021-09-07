all: main

main: log.o main.o static.o
	g++ -v -o main main.o static.o log.o

main.o:main.cpp
	g++ -v -c main.cpp -o main.o

log.o:log.cpp
	g++ -v -c log.cpp -o log.o

static.o:static.cpp
	g++ -v -c static.cpp -o static.o

