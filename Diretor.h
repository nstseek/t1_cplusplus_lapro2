/*
 * Arquivo: Diretor.h
 * Autor: Rafael Lopes Schneider e Arthur Costa Ribeiro
 * Data: 5 maio 2019
 *
 */
#ifndef DIRETOR_H
#define DIRETOR_H
#include <string>

using namespace std;

class Diretor {
    private:
        string nome;
        string* filmes;
    public:
        Diretor(string N);
        string getNome();
};

#endif