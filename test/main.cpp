#include "Filmes.h"
#include "Diretores.h"
#include <iostream>

using namespace std;

int main() {

    Diretor* diretorzao = new Diretor("LANTEJOLA");
    Filme* filmao = new Filme("FILMAO", 2008);

    filmao->adicionarDiretor(diretorzao);
    cout << "Nome do filme = " << filmao->getNome() << endl;
    cout << "Ano do filme = " << filmao->getAno() << endl;
    cout << "Diretor do filme = " << (filmao->getDiretor())->getNome() << endl;

    (filmao->getDiretor())->setNome("NEGAOZINHO ARTHUR");

    cout << "Diretor do filme = " << (filmao->getDiretor())->getNome() << endl;

    return 0;
}