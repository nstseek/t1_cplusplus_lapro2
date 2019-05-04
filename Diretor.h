#ifndef DIRETOR_H
#define DIRETOR_H
#include <string>

using namespace std;

class Diretor {
    private:
        string nome;
    public:
        Diretor(string N);
        string getNome();
};

#endif