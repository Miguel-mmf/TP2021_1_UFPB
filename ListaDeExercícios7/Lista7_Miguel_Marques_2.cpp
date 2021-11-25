#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int main()
{
    char palavra[100], caractere, aux;

    cout << "Digite uma string: ";
    cin.getline(palavra,256);
    cout << "Digite um caractere: ";
    cin >> caractere;

    for(int i=0; i < strlen(palavra); i++){
        aux = tolower(palavra[i]);
        if (aux == caractere){
            if (aux == palavra[i]) cout << "O caractere '" << caractere << "' se encontra na posicao " << (i+1) << endl;
            else cout << "O caractere '" << caractere << "' se encontra na posicao " << (i+1) << " em maiusculo" << endl;
        }
    }

    return 0;
}