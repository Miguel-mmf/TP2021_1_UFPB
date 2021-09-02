#include <iostream>

using namespace std;

int main(){

    int x;
    char caractere;
    float y;
    double z;
    long double w;

    cout << "Tamanho de um char: " << sizeof(caractere) << " bytes" << endl;
    cout << "Tamanho de um int: " << sizeof(x) << " bytes" << endl;
    cout << "Tamanho de um float: " << sizeof(y) << " bytes" << endl;
    cout << "Tamanho de um double: " << sizeof(z) << " bytes" << endl;
    cout << "Tamanho de um long double: " << sizeof(w) << " bytes" << endl;

    return 0;
}