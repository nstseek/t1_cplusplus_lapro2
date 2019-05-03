#ifndef DIRETORES_H
#define DIRETORES_H
#include <string>

using namespace std;

class Diretores {
    private:
        string Nome;
    public:
        Diretores(string N);
        string getName();
};

#endif