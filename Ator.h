/*
 * Arquivo: Ator.h
 * Autor: Rafael Lopes Schneider e Arthur Costa Ribeiro
 * Data: 5 maio 2019
 *
 */

#ifndef ATOR_H
#define ATOR_H
#include <string>

using namespace std;

class Ator {
    private:
        string nome;
    public:
        Ator(string N);
        string getNome();
};

#endif