#include <iostream>

using namespace std;

// O compilador inicia a variável global com zeros em cada posição
int numeros3[10];

int main()
{
    int numeros[] = {0,1,2,3,4,5,6,7,8,9};

    for(int i=0; i <10; i++){
        cout << "Numeros[" << i << "]: " << numeros[i];
        cout << " --- Numeros3[" << i << "]: " << numeros3[i] << endl;
    }

    cout << "Tamanho do array Numeros: " << sizeof(numeros) << endl;
    cout << "Tamanho do array Numeros3: " << sizeof(numeros3) << endl;

    return 0;
}