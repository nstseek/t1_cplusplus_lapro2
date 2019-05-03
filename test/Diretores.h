#ifndef DIRETORES_H
#define DIRETORES_H
#include <string>

using namespace std;

class Diretor {
    private:
        string nome;
    public:
        Diretor(string nome_);
        void setNome(string nome_);
        string getNome();
};

#endif