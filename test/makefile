CC = g++
CFLAGS = -c

all: test

test: main.o Filmes.o Diretores.o
	$(CC) main.o Filmes.o Diretores.o -o test

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

Filmes.o: Filmes.cpp Diretores.cpp
	$(CC) $(CFLAGS) Filmes.cpp

Diretores.o: Diretores.cpp
	$(CC) $(CFLAGS) Diretores.cpp

clean: 
	rm -rf *.o test