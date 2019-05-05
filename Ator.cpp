/*
 * Arquivo: Ator.cpp
 * Autor: Rafael Lopes Schneider e Arthur Costa Ribeiro
 * Data: 5 maio 2019
 *
 */
#include "Ator.h"

using namespace std;

Ator::Ator(string N) {
    nome = N;
}

string Ator::getNome() {
    return nome;
}