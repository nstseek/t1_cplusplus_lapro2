#ifndef ATORES_H
#define ATORES_H
#include <string>

using namespace std;

class Atores {
    private:
        string Nome;
    public:
        Atores(string N);
        string getNome();
};

#endif