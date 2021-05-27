all: full

full: main.o deque.o
	gcc main.o deque.o -o full

main.o: main.c
	gcc -c main.c


deque.o: deque.c
	gcc -c deque.c

run: full
	./full

clean:
	rm -rf *.o full
