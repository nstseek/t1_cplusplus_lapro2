/*
 * Arquivo: Diretor.cpp
 * Autor: Rafael Lopes Schneider e Arthur Costa Ribeiro
 * Data: 5 maio 2019
 *
 */
#include "Diretor.h"

using namespace std;

Diretor::Diretor(string N) {
    nome = N;
}

string Diretor::getNome() {
    return nome;
}