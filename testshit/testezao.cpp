#include <iostream>
#include <sstream>
#include <ctime>
#include <fstream>
#include <cstdlib>

using namespace std;

class seila {
    private:
        int numero;
    public:
        seila() {
            numero = 50;
        }
        int getNum() {
            return numero;
        }

};

seila* createSeila() {
    return new seila();
}

int main() {
    seila* objeto = new seila();
    seila castedObject = seila(*objeto); // cast pointer obj to obj

    cout << objeto->getNum() << endl;
    cout << objeto[0].getNum() << endl;
    cout << castedObject.getNum() << endl;

    string* vetorString = (string*) malloc(sizeof(string)*2);
    vetorString[0] = "iae mano";
    vetorString[1] = "belezinha?";
    cout << vetorString[0] << endl;
    cout << vetorString[1] << endl;

    string teste = "iae veio";
    string teste2 = teste.substr(0, string::npos);

    // cout << teste << endl;
    // cout << teste2 << endl;

    string** teste3 = (string**) malloc(sizeof(string*));
    teste3[0] = new string(teste.data());

    cout << teste3[0][0] << endl;

    string** teste4 = (string**) realloc(teste3, sizeof(string*)*2);
    teste3 = teste4;
    teste3[1] = new string(vetorString[1].data());
    
    cout << teste3[0][0] << endl;
    cout << teste3[1][0] << endl;

    // string** teste4 = (string**) realloc(teste3, sizeof(string*)*2);
    // teste3 = teste4;
    // cout << teste3[0][0] << endl;
    // teste3[1] = new string(vetorString[0].data());

    // cout << teste3[1][0] << endl;
    // cout << teste3[0] << endl;
    // cout << teste3[1] << endl;

    time_t rawtime;
    time(&rawtime);
    const char* localTime = ctime(&rawtime);

    string* date = new string(localTime);
    string year = date[0].substr((date[0].length()-5), string::npos);
    year.resize(4);
    cout << year << endl;
    cout << date[0] << endl;

    seila* uolo = createSeila();

    cout << uolo->getNum() << endl;

    ofstream file;
    file.open("iae.txt", ios_base::out);
    if(file.good()) {
        file << year << endl;
    }
    else {
        cout << "error opening file" << endl;
    }

    file.close();
    remove("iae.txt");

    file.open("iou.txt", ios_base::out);
    if(file.good()) {
        file << year << endl;
    }
    else {
        cout << "error opening file" << endl;
    }


    return 0;
}