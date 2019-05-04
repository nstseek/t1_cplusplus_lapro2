#include "Diretor.h"

using namespace std;

Diretor::Diretor(string N) {
    nome = N;
}

string Diretor::getNome() {
    return nome;
}