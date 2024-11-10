

all: objects
	gcc -o main *.o

objects: main.c pressure.c
	gcc -c main.c pressure.c

clean:
	rm -f main *.o
