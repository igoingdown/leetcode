all: data_buffer

data_buffer: main.o data_buffer.o intervals.o ring.o
	g++ -v -o data_buffer main.o data_buffer.o intervals.o ring.o

main.o:main.cpp
	g++ -v -c main.cpp -o main.o

data_buffer.o:data_buffer.cpp
	g++ -v -c data_buffer.cpp -o data_buffer.o


intervals.o:intervals.cpp
	g++ -v -c intervals.cpp -o intervals.o

ring.o:ring.cpp
	g++ -v -c ring.cpp -o ring.o

