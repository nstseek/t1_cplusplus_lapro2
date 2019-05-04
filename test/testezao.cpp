#include <iostream>
#include <sstream>

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

    return 0;
}