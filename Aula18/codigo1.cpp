#include <iostream>

using namespace std;

// O compilador inicia a variável global com zeros em cada posição
int numeros3[10];

int main()
{
    int numeros[] = {0,1,2,3,4,5,6,7,8,9};
    int numeros2[10];

    for(int i=0; i <10; i++){
        cout << "Numeros[" << i << "]: " << numeros[i];
        cout << " --- Numeros2[" << i << "]: " << numeros2[i] << endl;
    }

    for(int i=0; i <10; i++){
        cout << "Numeros[" << i << "]: ";
        cin >> (numeros[i],numeros2[i]);
        // cout << "Numeros2[" << i << "]: ";
        // cin >> numeros2[i];
    }

    for(int i=0; i <10; i++){
        cout << "Numeros[" << i << "]: " << numeros[i];
        cout << " --- Numeros2[" << i << "]: " << numeros2[i];
        cout << " --- Numeros3[" << i << "]: " << numeros3[i] << endl;
    }

    return 0;
}