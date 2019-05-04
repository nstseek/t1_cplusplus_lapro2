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
    int lul = 59;
    int *lulzao = &lul;
    seila* objeto = new seila();
    seila castedObject = seila(*objeto); // cast pointer obj to obj

    cout << objeto->getNum() << endl;
    cout << objeto[0].getNum() << endl;
    cout << castedObject.getNum() << endl;

    cout << lulzao << endl;
    cout << *lulzao << endl;

    stringstream ss;
    ss << "iae negao do mato";

    string buf = ss.str();

    cout << buf << endl;
    
    return 0;
}