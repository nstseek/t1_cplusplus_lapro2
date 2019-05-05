#include "Filme.h"
#include <iostream>
#include <sstream>

using namespace std;

// tem q fazer o filme receber ao menos 1 ator e 1 diretor, como o trabalho pede
Filme::Filme(string nome_, string ano_) {
    nome = nome_;
    ano = ano_;
    num_atores = 0;
    diretor = nullptr;
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
        for(unsigned int i = 0; i < num_atores; i++) {
            if(atores[i] == ator) {
                cout << "Ator ja esta no filme" << endl;
                return;
            }
        }
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
    for(unsigned int i = 0; i < num_atores; i++) {
        if(atores[i][0].getNome() == nome) {
            return true;
        }
    }
    return false;
}

void Filme::getAtores() {
    for(unsigned int i = 0; i < num_atores; i++) 
        cout << "Ator " << i+1 << ": " << atores[i][0].getNome() << endl;
}

string Filme::toString() {
    stringstream ss;
    if(getDiretor() == nullptr) cout << "FATAL ERROR - NULL DIRETOR" << endl;
    if(getNumAtores() == 0) cout << "FATAL ERROR - ZERO ATORES" << endl;
    ss << "Filme:\t\t" << getNome() << " (" << getAno() << ")" << endl;
    ss << "Diretor:\t" << getDiretor()[0].getNome() << endl;
    ss << "Atores:\t\t" << atores[0][0].getNome() << endl;
    for(unsigned int i = 1; i < num_atores; i++) 
        ss << "\t\t" << atores[i][0].getNome() << endl;
    return ss.str();
}

string Filme::toString(bool file) {
    stringstream ss;
    ss << "--" << getNome() << " (" << getAno() << ")" << endl;
    return ss.str();
}