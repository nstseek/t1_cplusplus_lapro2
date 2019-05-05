# *
# * Arquivo: makefile
# * Autor: Rafael Lopes Schneider e Arthur Costa Ribeiro
# * Data: 5 maio 2019
# *
# *
CXX = g++

CXXFLAGS = -Wall -O -g

main: Ator.o Filme.o Diretor.o main.cpp
	$(CXX) $(CXXFLAGS) Ator.o Filme.o Diretor.o main.cpp -o main

Filme.o: Filme.cpp Filme.h Diretor.o Ator.o
	$(CXX) $(CXXFLAGS) -c Filme.cpp

Ator.o: Ator.cpp Ator.h
	$(CXX) $(CXXFLAGS) -c Ator.cpp

Diretor.o: Diretor.cpp Diretor.h
	$(CXX) $(CXXFLAGS) -c Diretor.cpp

clean:
	rm -rf *.o main