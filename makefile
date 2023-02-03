all: main

main: main.o vector.o sphere.o renderer.o
	gcc -o main main.o vector.o sphere.o renderer.o -lm

main.o: main.c vector.h sphere.h renderer.h
	gcc -c main.c

vector.o: vector.c vector.h
	gcc -c vector.c

sphere.o: sphere.c sphere.h vector.h renderer.h
	gcc -c sphere.c

renderer.o: renderer.c renderer.h vector.h
	gcc -c renderer.c

run: main
	./main

clean:
	rm -rf main.o vector.o sphere.o renderer.o main
