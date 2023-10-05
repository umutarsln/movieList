CC=g++
# CFLAGS will be the options passed to the compiler.
CFLAGS= -c -Wall

all: prog

prog: main.o movieListSrc.o
	$(CC) main.o MovieListSrc.o -o prog
main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp
movieListSrc.o: movieListSrc.cpp
	$(CC) $(CFLAGS) movieListSrc.cpp
clean:
	rm -rf *.o
