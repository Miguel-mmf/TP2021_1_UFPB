#include <iostream>
#include <cstring>
//#include <ctype.h>

using namespace std;

int main()
{
    char senha[8];
    bool valid_caractere = false;

    cout << "Digite uma senha de 8 caracteres minusculos: ";
    cin >> senha;

    if ((strlen(senha) < 8) || strlen(senha) > 8){
        cout << "A senha nao contem 8 caracteres." << endl;
    }
    else{
        for (int i = 0; i < 8; i++){
            if (isupper(senha[i])){
                valid_caractere = true;
                cout << "A senha " << senha << " contem o caractere " << senha[i] << " na posicao " << (i+1) << endl;
            }
        }
        if(valid_caractere)
            cout << "A senha tem caracteres maiusculos"<< endl;
    }

    return 0;
}