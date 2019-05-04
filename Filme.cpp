#include "Filme.h"
#include <iostream>
#include <sstream>

using namespace std;

// tem q fazer o filme receber ao menos 1 ator e 1 diretor, como o trabalho pede
Filme::Filme(string nome_, string ano_) {
    nome = nome_;
    ano = ano_;
    num_atores = 0;
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

string Filme::getAno() {
    return ano;
}

Diretor* Filme::getDiretor() {
    return diretor;
}

void Filme::adicionarAtor(Ator* ator) {
    if(num_atores < ATORES_MAX){
        atores[num_atores] = ator;
        num_atores++;
    } 
    else cout << "Numero maximo de atores atingido (10 atores)" << endl;

}
        
void Filme::removerAtor() {
    if(num_atores > 0) num_atores--;
    else cout << "Nao temos nenhum ator" << endl;
}

unsigned int Filme::getNumAtores() {
    return num_atores;
}

bool Filme::consultarAtor(string nome) {
    bool found = 0;
    for(unsigned int i = 0; i < num_atores; i++) {
        if(atores[i][0].getNome() == nome) found = 1;
    }
    return found;
}

void Filme::getAtores() {
    for(unsigned int i = 0; i < num_atores; i++) 
        cout << "Ator " << i+1 << ": " << atores[i][0].getNome() << endl;
}

string Filme::toString() {
    stringstream ss;
    ss << "===================" << endl;
    ss << "Titulo: " << getNome() << endl;
    ss << "Ano: " << getAno() << endl;
    ss << "Diretor: " << getDiretor()[0].getNome() << endl;
    ss << "Numero de atores: " << getNumAtores() << endl;
    for(unsigned int i = 0; i < num_atores; i++) 
        ss << "    Ator " << i+1 << ": " << atores[i][0].getNome() << endl;
    ss << "===================" << endl;

    return ss.str();
}