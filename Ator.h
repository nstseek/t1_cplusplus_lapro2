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