#include "Diretores.h"

using namespace std;

Diretor::Diretor(string nome_) {
    nome = nome_;
}

void Diretor::setNome(string nome_) {
    nome = nome_;
}

string Diretor::getNome() {
    return nome;
}