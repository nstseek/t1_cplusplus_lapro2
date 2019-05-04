#ifndef DIRETOR_H
#define DIRETOR_H
#include <string>

using namespace std;

class Diretor {
    private:
        string nome;
        string* filmes;
    public:
        Diretor(string N, int filmesSize);
        string getNome();
};

#endif