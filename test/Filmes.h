#ifndef FILMES_H
#define FILMES_H
#define ATORES_MAX 10
#include <string>
#include "Diretores.h"

using namespace std;

class Filme {
    private:
        string nome;
        unsigned int ano;
        Diretor* diretor;
    public:
        Filme(string nome_, unsigned int ano_);
        void adicionarDiretor(Diretor* dir);
        void removerDiretor();
        string getNome();
        unsigned int getAno();
        Diretor* getDiretor();
};

#endif