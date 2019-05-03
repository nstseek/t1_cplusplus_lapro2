#include "Filmes.h"

using namespace std;

Filme::Filme(string nome_, unsigned int ano_) {
    nome = nome_;
    ano = ano_;
}

void Filme::adicionarDiretor(Diretor* dir) {
    diretor = dir;
}
        
void Filme::removerDiretor() {
    diretor = nullptr;
}

string Filme::getNome() {
    return nome;
}

unsigned int Filme::getAno() {
    return ano;
}

Diretor* Filme::getDiretor() {
    return diretor;
}