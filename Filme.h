#ifndef FILME_H
#define FILME_H
#define ATORES_MAX 10
#include <string>
#include "Diretor.h"
#include "Ator.h"

using namespace std;

class Filme {
    private:
        string nome;
        unsigned int ano;
        Diretor* diretor;
        Ator* atores[ATORES_MAX];
        unsigned int num_atores;
    public:
        Filme(string nome_, unsigned int ano_);
        void adicionarDiretor(Diretor* dir);
        void removerDiretor();
        void adicionarAtor(Ator* ator);
        void removerAtor(unsigned int pos);
        string getNome();
        unsigned int getAno();
        Diretor* getDiretor();
        Ator* getAtor();
        // retornar pointer pra array? ok
        // namespace filme? n é namespace, é nome de classe, parece igual porem diferente
};

#endif