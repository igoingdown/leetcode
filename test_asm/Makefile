all:hello_world

hello_world: hello_world.o
	ld -static -o hello_world hello_world.o


hello_world.o: hello_world.s
	as -o hello_world.o hello_world.s
