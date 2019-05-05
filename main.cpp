/*
 * Arquivo: main.cpp
 * Autor: Rafael Lopes Schneider e Arthur Costa Ribeiro
 * Data: 5 maio 2019
 *
 */
#include "Ator.h"
#include "Filme.h"
#include "Diretor.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <sstream>
#define BDATORES "BD_Atores.txt"
#define BDDIRETORES "BD_Diretores.txt"
#define LINESIZE 1000

using namespace std;

Filme* pesquisarFilme(string nome, int indexFilmes, Filme** filmes, bool details) {
    bool found = false;
    for(int i = 0; i < indexFilmes; i++) {
        if(filmes[i][0].getNome() == nome) {
            found = true;
            if(details == false) return filmes[i];
            if(details == true) {
                cout << filmes[i][0].toString() << endl;
                break;
            }
        }
    }
    if(found == false && details == true) cout << "\nFilme nao encontrado\n" << endl;
    return nullptr;
}

void consultaAtor(string nome, int indexFilmes, Filme** filmes) {
    for(int i = 0; i < indexFilmes; i++) {
        if(filmes[i][0].consultarAtor(nome)) {
            cout << filmes[i][0].toString() << endl;
        }
    }
}

void consultaDiretor(string nome, int indexFilmes, Filme** filmes) {
    for(int i = 0; i < indexFilmes; i++) {
        if(filmes[i][0].getDiretor()[0].getNome() == nome) {
            cout << filmes[i][0].toString() << endl;
        }
    }
}

Ator* criarAtor(string nome, int* indexAtores, Ator*** atores) {
    for(int i = 0; i < *indexAtores; i++) {
        if(atores[0][i][0].getNome() == nome) {
            cout << "Ator ja existente - utilizando ator ja criado" << endl;
            return *atores[i];
        }
    }
    Ator* newAtorCriado = new Ator(nome);
    Ator** atoresBuf = (Ator**) realloc(*atores, sizeof(Ator*)*(*indexAtores+1));
    *atores = atoresBuf;
    /*
    -- ESSA MERDA NAO TA FUNCIONANDO, DEPOIS DE RODAR 2 VEZES, ELE SIMPLESMENTE FAZ ESSA ATRIBUICAO
    -- MAS QUANDO EU SAIO DA FUNCAO, O ATORES QUE TA LA FORA EH DIFERENTE DO ATORES QUE TA AQUI DENTRO
    -- BASICAMENTE ELE TAVA CRIANDO A VAR ATOR** ATORES EM ESCOPO LOCAL, NUM SEI OQ ROLOU, VAMO TENTA ATOR*** ATORES
    */
    /*
    -- ATUALIZACAO DESSA MERDA INFINITA, APARENTEMENTE, EU NAO SABIA QUE EU TINHA QUE PASSAR O POINTER DO POINTER DO POINTER
    -- PRA QUE A MINHA VAR DO TIPO POINTER FOSSE ALTERADA LA FORA, PENSANDO AGORA LOGICAMENTE ISSO FAZ TODO SENTIDO
    -- E EU SOU MEIO BURRO POR NAO TER PENSADO NISSO, MAS OK, VIDA QUE SEGUE, PERDI TEMPO MAS APRENDI, PRECISO PASSAR POINTER
    -- DO POINTER DO POINTER E USAR O * OU O [0] PRA PODER ALTERAR UM POINTER EXTERIORMENTE NO PROGRAMA, EH ISTO
    */
    atores[0][*indexAtores] = newAtorCriado;
    *indexAtores += 1;
    return newAtorCriado;
    // colocar no array de atores
}

Diretor* criarDiretor(string nome, int* indexDiretores, Diretor*** diretores) {
    for(int i = 0; i < *indexDiretores; i++) {
        if(diretores[0][i][0].getNome() == nome) {
            cout << "Diretor ja existente - utilizando diretor ja criado" << endl;
            return diretores[0][i];
        }
    }
    Diretor* newDiretorCriado = new Diretor(nome);
    Diretor** diretoresBuf = (Diretor**) realloc(*diretores, sizeof(Diretor*)*(*indexDiretores+1));;
    *diretores = diretoresBuf;
    diretores[0][*indexDiretores] = newDiretorCriado;
    *indexDiretores += 1;
    return newDiretorCriado;
    // colocar no array de diretores
}

void atualizarArquivo() {

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
                            filmePtr = pesquisarFilme(filmesArq[i][0], indexFilmes, filmes, false);
                            if(filmePtr == nullptr) {
                                filmesBuf = (Filme**) realloc(filmes, sizeof(Filme*)*(indexFilmes+1));
                                filmes = filmesBuf;
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
    BDAtores.close();

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
                            indexFilmes++;
                        }
                        else {
                            filmePtr = pesquisarFilme(filmesArq[i][0], indexFilmes, filmes, false);
                            if(filmePtr == nullptr) {
                                filmesBuf = (Filme**) realloc(filmes, sizeof(Filme*)*(indexFilmes+1));
                                filmes = filmesBuf;
                                filmes[indexFilmes] = new Filme(filmesArq[i][0], anoDoFilme[i][0]);
                                filmes[indexFilmes][0].adicionarDiretor(diretores[indexDiretores]);
                                indexFilmes++;
                            }
                            else {
                                if(filmePtr[0].getDiretor() == nullptr) {
                                    filmePtr[0].adicionarDiretor(diretores[indexDiretores]);
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

    BDDiretores.close();

    // for(int i = 0; i < indexFilmesArq; i++)
    //     cout << "Filme e ano: " << filmesArq[i][0] << " " << anoDoFilme[i][0] << endl;

    // for(int i = 0; i < indexDiretores; i++) {
    //     cout << diretores[i][0].getNome() << endl;
    // }
    
    // for(int i = 0; i < indexFilmes; i++) {
    //     cout << filmes[i][0].toString() << endl;
    // }
    // cout << "Total de atores: " << indexAtores << endl;
    // cout << "Total de filmes: " << indexFilmes << endl;
    // cout << "Total de diretores: " << indexDiretores << endl;

    Diretor* newDiretor;
    string diretorNomeBuf;
    Filme* newFilme;
    // Ator** newAtores;
    // Ator** newAtoresBuf;
    int newNumAtores;
    // int newIndexAtores;
    ofstream BDAtoresO;
    ofstream BDDiretoresO;
    stringstream faoutput;
    stringstream fdoutput;

    time_t rawtime;
    time(&rawtime);
    const char* localTime = ctime(&rawtime);

    string* data = new string(localTime);
    string ano = data[0].substr((data[0].length()-5), string::npos);
    ano.resize(4);

    int opt;
    while(1) {
        cout << "Total de filmes: " << indexFilmes << endl;
        cout << "Total de atores: " << indexAtores << endl;
        cout << "Total de diretores: " << indexDiretores << endl;
        cout << "Selecione uma opcao:" << endl;
        cout << "\t1 - Consulta de atores" << endl;
        cout << "\t2 - Consulta de diretores" << endl;
        cout << "\t3 - Consulta de filmes" << endl;
        cout << "\t4 - Cadastrar novo filme" << endl;
        cout << "\t5 - Atualizar " << BDATORES << " e " << BDDIRETORES << endl;
        cout << "\t6 - Sair" << endl;
        cin >> opt;
        switch (opt) {
        case 1:
            cout << "Digite o nome do ator a ser pesquisado: " << endl;
            getchar();
            getline(cin, nome);
            cout << "Voce digitou: " << nome << endl;
            consultaAtor(nome, indexFilmes, filmes);
            break;
        case 2:
            cout << "Digite o nome do diretor a ser pesquisado: " << endl;
            getchar();
            getline(cin, nome);
            consultaDiretor(nome, indexFilmes, filmes);
            break;
        case 3:
            cout << "Digite o nome do filme a ser pesquisado: " << endl;
            getchar();
            getline(cin, nome);
            pesquisarFilme(nome, indexFilmes, filmes, true);
            break;
        case 4:
            cout << "Digite o titulo do filme" << endl;
            getchar();
            getline(cin, nome);
            cout << "Digite o nome do diretor" << endl;
            getline(cin, diretorNomeBuf);
            newDiretor = criarDiretor(diretorNomeBuf, &indexDiretores, &diretores);
            cout << "Digite quantos atores o filme possui" << endl;
            cin >> newNumAtores;

            if(indexFilmes == 0) {
                filmes[indexFilmes] = new Filme(nome, ano);
                newFilme = filmes[indexFilmes];
                indexFilmes++;
            }
            else {
                filmePtr = pesquisarFilme(nome, indexFilmes, filmes, false);
                if(filmePtr == nullptr) {
                    filmesBuf = (Filme**) realloc(filmes, sizeof(Filme*)*(indexFilmes+1));
                    filmes = filmesBuf;
                    filmes[indexFilmes] = new Filme(nome, ano);
                    newFilme = filmes[indexFilmes];
                    indexFilmes++;
                }
                else {
                    cout << "O filme ja existe - utilizando filme ja criado" << endl;
                    newFilme = filmePtr;
                }
            }
            newFilme[0].adicionarDiretor(newDiretor);
            getchar();

            for(int i = 0; i < newNumAtores; i++) {
                cout << "Digite o nome do ator numero " << i+1 << ":" << endl;
                getline(cin, nome);
                newFilme[0].adicionarAtor(criarAtor(nome, &indexAtores, &atores));
            }

            for(int i = 0; i < indexAtores; i++) {
                cout << "to no ator n " << i << " q vale " << atores[i] << endl;
                cout << atores[i][0].getNome() << endl;
            }

            cout << newFilme[0].toString() << endl;

            break;

        case 5:
            if(remove(BDATORES) != 0) {
                cout << "FATAL ERROR - CAN'T DELETE FILE" << endl;
                return 1;
            }
            BDAtoresO.open(BDATORES, ios_base::out);
            if(!(BDAtoresO.good())) {
                cout << "FATAL ERROR - CAN'T OPEN FILE" << endl;
            }

            for(int i = 0; i < indexAtores; i++) {
                faoutput << '#' << endl;
                faoutput << atores[i][0].getNome() << endl;
                for(int j = 0; j < indexFilmes; j++) {
                    if(filmes[j][0].consultarAtor(atores[i][0].getNome())) {
                        faoutput << filmes[j][0].toString(true);
                    }
                }
            }

            BDAtoresO << faoutput.str();

            BDAtoresO.close();

            if(remove(BDDIRETORES) != 0) {
                cout << "FATAL ERROR - CAN'T DELETE FILE" << endl;
                return 1;
            }
            BDDiretoresO.open(BDDIRETORES, ios_base::out);
            if(!(BDDiretoresO.good())) {
                cout << "FATAL ERROR - CAN'T OPEN FILE" << endl;
            }

            for(int i = 0; i < indexDiretores; i++) {
                fdoutput << '#' << endl;
                fdoutput << diretores[i][0].getNome() << endl;
                for(int j = 0; j < indexFilmes; j++) {
                    if(filmes[j][0].getDiretor()[0].getNome() == diretores[i][0].getNome()) {
                        fdoutput << filmes[j][0].toString(true);
                    }
                }
            }

            BDDiretoresO << fdoutput.str();

            BDDiretoresO.close();

            cout << "Arquivos atualizados." << endl;

            break;
        case 6:
            cout << "Saindo..." << endl;
            return 0;
            break;
        // case 7:
        //     for(int i = 0; i < indexAtores; i++) {
        //         cout << atores[i][0].getNome() << endl;
        //     }
        //     for(int i = 0; i < indexDiretores; i++) {
        //         cout << diretores[i][0].getNome() << endl;
        //     }
        //     for(int i = 0; i < indexFilmes; i++) {
        //         cout << filmes[i][0].getNome() << endl;
        //     }
        //     break;
        default:
            cout << "\nERROR - Valor nao reconhecido\n" << endl;
            break;
        }
    }

    return 0;
}