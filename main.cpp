#include "Ator.h"
#include "Filme.h"
#include "Diretor.h"
#include <iostream>

using namespace std;

int main() {
    Ator* oAtorzaoPesado = new Ator("KEVI O CHRIS");
    Ator* atorDoB = new Ator("BROTA NA PENHA MEU AMOR E SOBE NO MEU PAU");
    Diretor* diretorzao = new Diretor("RTSHEIK EH GOXTOSO");
    Filme* rebolaPoPay = new Filme("REBOLA PO PAY", 2019, diretorzao, oAtorzaoPesado);

    cout << oAtorzaoPesado->getNome() << endl;
    cout << diretorzao->getNome() << endl;
    cout << rebolaPoPay->getNome() << endl;
    cout << rebolaPoPay->getAno() << endl;
    cout << rebolaPoPay->getNome() << endl;
    cout << rebolaPoPay->getDiretor()->getNome() << endl;
    rebolaPoPay->getAtores();
    cout << rebolaPoPay->toString() << endl;
    rebolaPoPay->adicionarAtor(atorDoB);
    cout << rebolaPoPay->toString() << endl;

    return 0;
}