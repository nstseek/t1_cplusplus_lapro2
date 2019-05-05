#include "Ator.h"
#include "Filme.h"
#include "Diretor.h"
#include <iostream>
#include <fstream>
#define BDATORES "BD_Atores.txt"
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
    string** filmesArq = (string**) malloc(sizeof(string*));
    string** filmesArqBuf;
    string** anoDoFilme = (string**) malloc(sizeof(string*));
    string** anoBuf;
    string buffer;
    int indexFilmesArq = 0;
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
                        if(indexFilmesArq > 0) {
                            filmesArqBuf = (string**) realloc(filmesArq, sizeof(string)*(indexFilmesArq+1));
                            filmesArq = filmesArqBuf;
                            anoBuf = (string**) realloc(anoDoFilme, sizeof(string)*(indexFilmesArq+1));
                            anoDoFilme = anoBuf;
                        }
                        filmesArq[indexFilmesArq] = new string(buffer.data());
                        getline(BDAtores, buffer, ')');
                        anoDoFilme[indexFilmesArq] = new string(buffer.data());
                        indexFilmesArq++;
                        BDAtores.get(buf[0]);
                    }
                }
                else {
                    if(indexAtores > 0) {
                        atoresBuf = (Ator**) realloc(atores, sizeof(Ator*)*(indexAtores+1));
                        atores = atoresBuf;
                    }
                    atores[indexAtores] = new Ator(nome);
                    for(int i = 0; i < indexFilmesArq; i++) {
                        if(indexFilmes == 0) {
                            filmes[indexFilmes] = new Filme(filmesArq[i][0], anoDoFilme[i][0]);
                            filmes[indexFilmes][0].adicionarAtor(atores[indexAtores]);
                            indexFilmes++;
                        }
                        else {
                            filmesBuf = (Filme**) realloc(filmes, sizeof(Filme*)*(indexFilmes+1));
                            filmes = filmesBuf;
                            filmePtr = pesquisarFilme(filmesArq[i][0], indexFilmes, filmes);
                            if(filmePtr == nullptr) {
                                filmes[indexFilmes] = new Filme(filmesArq[i][0], anoDoFilme[i][0]);
                                filmes[indexFilmes][0].adicionarAtor(atores[indexAtores]);
                                indexFilmes++;
                            }
                            else {
                                // -- ver se o ator ja nao esta no filme
                                if(!filmePtr[0].consultarAtor(nome)) filmePtr[0].adicionarAtor(atores[indexAtores]);
                            }
                        }
                    }
                    indexAtores++;
                    indexFilmesArq = 0;
                    stop = 1;
                    BDAtores.seekg(-1, ios_base::cur);
                }
            }
            stop = 0;

        }
    }

    filmesArq = (string**) malloc(sizeof(string*));
    filmesArqBuf = nullptr;
    anoDoFilme = (string**) malloc(sizeof(string*));
    anoBuf = nullptr;

    indexFilmesArq = 0;
    stop = 0;
    while(BDDiretores.good()) {
        BDDiretores.get(buf[0]);
        if(buf[0] == '#') {
            BDDiretores.get(buf[0]);
            getline(BDDiretores, nome);
            while(stop == 0) {
                BDDiretores.get(buf[0]);
                if(buf[0] != '#' && BDDiretores.good()) {
                    BDDiretores.get(buf[1]);
                    if(buf[0] == '-' && buf[1] == '-') {
                        getline(BDDiretores, buffer, '(');
                        buffer.resize((buffer.size()-1));
                        if(indexFilmesArq > 0) {
                            filmesArqBuf = (string**) realloc(filmesArq, sizeof(string)*(indexFilmesArq+1));
                            filmesArq = filmesArqBuf;
                            anoBuf = (string**) realloc(anoDoFilme, sizeof(string)*(indexFilmesArq+1));
                            anoDoFilme = anoBuf;
                        }
                        filmesArq[indexFilmesArq] = new string(buffer.data());
                        getline(BDDiretores, buffer, ')');
                        anoDoFilme[indexFilmesArq] = new string(buffer.data());
                        indexFilmesArq++;
                        BDDiretores.get(buf[0]);
                    }
                }
                else {
                    if(indexDiretores > 0) {
                        diretoresBuf = (Diretor**) realloc(diretores, sizeof(Diretor*)*(indexDiretores+1));
                        diretores = diretoresBuf;
                    }
                    diretores[indexDiretores] = new Diretor(nome);
                    for(int i = 0; i < indexFilmesArq; i++) {
                        if(indexFilmes == 0) {
                            filmes[indexFilmes] = new Filme(filmesArq[i][0], anoDoFilme[i][0]);
                            filmes[indexFilmes][0].adicionarDiretor(diretores[indexDiretores]);
                            cout << "Criei um filme com o ptr diretor = " << diretores[indexDiretores] << endl;
                            indexFilmes++;
                        }
                        else {
                            filmesBuf = (Filme**) realloc(filmes, sizeof(Filme*)*(indexFilmes+1));
                            filmes = filmesBuf;
                            filmePtr = pesquisarFilme(filmesArq[i][0], indexFilmes, filmes);
                            if(filmePtr == nullptr) {
                                filmes[indexFilmes] = new Filme(filmesArq[i][0], anoDoFilme[i][0]);
                                filmes[indexFilmes][0].adicionarDiretor(diretores[indexDiretores]);
                                cout << "Criei um filme com o ptr diretor = " << diretores[indexDiretores] << endl;
                                indexFilmes++;
                            }
                            else {
                                // -- ver se o ator ja nao esta no filme
                                if(filmePtr[0].getDiretor() == nullptr) {
                                    filmePtr[0].adicionarDiretor(diretores[indexDiretores]);
                                    // cout << "Adicionei o ptr diretor = " << diretores[indexDiretores] << " a um filme" <<endl;
                                    // cout << "Agora o ptr diretor desse filme vale " << filmePtr[0].getDiretor() << endl;
                                }
                                else cout << "FATAL ERROR - FILME JA POSSUI UM DIRETOR" << endl;
                            }
                        }
                    }
                    indexDiretores++;
                    indexFilmesArq = 0;
                    stop = 1;
                    BDDiretores.seekg(-1, ios_base::cur);
                }
            }
            stop = 0;

        }
    }

    // for(int i = 0; i < indexFilmesArq; i++)
    //     cout << "Filme e ano: " << filmesArq[i][0] << " " << anoDoFilme[i][0] << endl;

    // for(int i = 0; i < indexDiretores; i++) {
    //     cout << diretores[i][0].getNome() << endl;
    // }
    
    for(int i = 0; i < indexFilmes; i++) {
        cout << "Estou no filme " << i << endl;
        cout << filmes[i][0].toString() << endl;
        if(i == 15) break;
    }
    cout << "Total de atores: " << indexAtores << endl;
    cout << "Total de filmes: " << indexFilmes << endl;
    cout << "Total de diretores: " << indexDiretores << endl;

    return 0;
}