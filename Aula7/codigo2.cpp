#include <iostream>

using namespace std;

int main(){

    int x = 1;

    typedef int decimal;
    decimal i = 1;

    cout << "Tamanho da variavel int: " << sizeof(x) << endl;
    cout << "Tamanho da variavel int definida como decimal: " << sizeof(i) << endl;

    int y = x<<2;
    cout << "Valor de y: " << y << endl;
    cout << "Valor da variavel x deslocada duas casas para esquerda: " << y << endl;
    
    y = y>>2;
    cout << "Valor da variavel x deslocada duas casas para direita: " << y << endl;

    return 0;
}