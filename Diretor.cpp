#include "Diretor.h"

using namespace std;

Diretor::Diretor(string N, int filmesSize) {
    nome = N;
    filmes = (string*) malloc(sizeof(string)*filmesSize);
}

string Diretor::getNome() {
    return nome;
}