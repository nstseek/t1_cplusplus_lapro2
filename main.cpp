#include "Ator.h"
#include "Filme.h"
#include "Diretor.h"
#include <iostream>
#include <fstream>
#define BDATORES "BD_Atores2.txt"
#define BDDIRETORES "BD_Diretores.txt"
#define LINESIZE 1000

using namespace std;

Filme* pesquisarFilme(string nome, int indexFilmes, Filme** filmes) {
    for(int i = 0; i < indexFilmes; i++) {
        if(filmes[i][0].getNome() == nome) {
            return filmes[i];
        }
    }
    return nullptr;
}

int main() {
    // -- rotina de teste das classes criadas --
    // Ator* oAtorzaoPesado = new Ator("KEVI O CHRIS");
    // Ator* atorDoB = new Ator("BROTA NA PENHA MEU AMOR E SOBE NO MEU PAU");
    // Diretor* diretorzao = new Diretor("RTSHEIK EH GOXTOSO");
    // Filme* rebolaPoPay = new Filme("REBOLA PO PAY", 2019, diretorzao, oAtorzaoPesado);

    // cout << oAtorzaoPesado->getNome() << endl;
    // cout << diretorzao->getNome() << endl;
    // cout << rebolaPoPay->getNome() << endl;
    // cout << rebolaPoPay->getAno() << endl;
    // cout << rebolaPoPay->getNome() << endl;
    // cout << rebolaPoPay->getDiretor()->getNome() << endl;
    // rebolaPoPay->getAtores();
    // cout << rebolaPoPay->toString() << endl;
    // rebolaPoPay->adicionarAtor(atorDoB);
    // cout << rebolaPoPay->toString() << endl;

    // -- Abrindo arquivos e vendo se estao ok para leitura
    ifstream BDAtores;
    ifstream BDDiretores;

    BDAtores.open(BDATORES, ifstream::in);
    if(!(BDAtores.is_open() && BDAtores.good())) {
        cout << "Fatal - error opening file " << BDATORES << endl;
        return 1;
    }
    
    BDDiretores.open(BDDIRETORES, ifstream::in);
    if(!(BDDiretores.is_open() && BDDiretores.good())) {
        cout << "Fatal - error opening file " << BDDIRETORES << endl;
        return 1;
    }

    // -- contador de atores e diretores pra criacao de array
    // int totalAtores = -1;
    // char buf[GETLINESIZE];
    // while(BDAtores.good()) {
    //     totalAtores++;
    //     BDAtores.getline(buf, GETLINESIZE, '#');
    // }

    // cout << totalAtores << endl;
    // BDAtores.seekg(0, ios_base::beg);

    // int totalDiretores = -1;
    // while(BDDiretores.good()) {
    //     totalDiretores++;
    //     BDDiretores.getline(buf, GETLINESIZE, '#');
    // }

    // cout << totalDiretores << endl;
    // BDDiretores.seekg(0, ios_base::beg);

    Ator** atores = (Ator**) malloc(sizeof(Ator*));
    int indexAtores = 0;
    Ator** atoresBuf;
    Diretor** diretores = (Diretor**) malloc(sizeof(Diretor*));
    int indexDiretores = 0;
    Diretor** diretoresBuf;
    Filme** filmes = (Filme**) malloc(sizeof(Filme*));
    int indexFilmes = 0;
    Filme** filmesBuf;

    char buf[2] = {0, 0};
    string nome;
    string** filmesDoAtor = (string**) malloc(sizeof(string*));
    string** filmesAtorBuf;
    string** anoDoFilme = (string**) malloc(sizeof(string*));
    string** anoBuf;
    string buffer;
    int indexFilmesAtor = 0;
    int stop = 0;
    Filme* filmePtr;
    while(BDAtores.good()) {
        BDAtores.get(buf[0]);
        if(buf[0] == '#') {
            BDAtores.get(buf[0]);
            getline(BDAtores, nome);
            while(stop == 0) {
                BDAtores.get(buf[0]);
                if(buf[0] != '#' && BDAtores.good()) {
                    BDAtores.get(buf[1]);
                    if(buf[0] == '-' && buf[1] == '-') {
                        getline(BDAtores, buffer, '(');
                        buffer.resize((buffer.size()-1));
                        if(indexFilmesAtor > 0) {
                            filmesAtorBuf = (string**) realloc(filmesDoAtor, sizeof(string)*(indexFilmesAtor+1));
                            filmesDoAtor = filmesAtorBuf;
                            anoBuf = (string**) realloc(anoDoFilme, sizeof(string)*(indexFilmesAtor+1));
                            anoDoFilme = anoBuf;
                        }
                        filmesDoAtor[indexFilmesAtor] = new string(buffer.data());
                        getline(BDAtores, buffer, ')');
                        anoDoFilme[indexFilmesAtor] = new string(buffer.data());
                        indexFilmesAtor++;
                        BDAtores.get(buf[0]);
                    }
                }
                else {
                    if(indexAtores > 0) {
                        atoresBuf = (Ator**) realloc(atores, sizeof(Ator*)*(indexAtores+1));
                        atores = atoresBuf;
                    }
                    atores[indexAtores] = new Ator(nome);
                    indexAtores++;
                    for(int i = 0; i < indexFilmesAtor; i++) {
                        if(indexFilmes == 0) {
                            filmes[indexFilmes] = new Filme(filmesDoAtor[i][0], anoDoFilme[i][0]);
                            filmes[indexFilmes][0].adicionarAtor(atores[indexAtores]);
                            indexFilmes++;
                        }
                        else {
                            filmesBuf = (Filme**) realloc(filmes, sizeof(Filme*)*(indexFilmes+1));
                            filmes = filmesBuf;
                            filmePtr = pesquisarFilme(filmesDoAtor[i][0], indexFilmes, filmes);
                            if(filmePtr == nullptr) {
                                filmes[indexFilmes] = new Filme(filmesDoAtor[i][0], anoDoFilme[i][0]);
                                filmes[indexFilmes][0].adicionarAtor(atores[indexAtores]);
                                indexFilmes++;
                            }
                            else {
                                filmePtr[0].adicionarAtor(atores[indexAtores]);
                            }
                        }
                    }
                    stop = 1;
                    BDAtores.seekg(-1, ios_base::cur);
                }
            }
            stop = 0;

        }
    }

    // for(int i = 0; i < indexFilmesAtor; i++)
    //     cout << "Filme e ano: " << filmesDoAtor[i][0] << " " << anoDoFilme[i][0] << endl;

    for(int i = 0; i < indexFilmes; i++) {
        cout << filmes[i][0].toString() << endl;
    }

    return 0;
}