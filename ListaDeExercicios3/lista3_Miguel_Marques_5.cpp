#include <iostream>

using namespace std;
void detecta_int_ou_char(char);

int main(){

    char c1, c2, c3, c4, c5;
    char caracteres[6];

    cout << "Digite um caractere: ";
    cin >> c1;
    cout << "\nDigite um caractere: ";
    cin >> c2;
    cout << "\nDigite um caractere: ";
    cin >> c3;
    cout << "\nDigite um caractere: ";
    cin >> c4;
    cout << "\nDigite um caractere: ";
    cin >> c5;

    detecta_int_ou_char(c1);
    detecta_int_ou_char(c2);
    detecta_int_ou_char(c3);
    detecta_int_ou_char(c4);
    detecta_int_ou_char(c5);

    return 0;
}


void detecta_int_ou_char(char caractere){
    // utilizando a tabela ASCII

    if (int(caractere) >= 48 && int(caractere) <= 57)
        cout << "O caractere " << caractere << " e um inteiro." << endl;
    else if(int(caractere) >= 97 && int(caractere) <= 122)
        cout << "O caractere " << caractere << " e uma letra minuscula." << endl;
    else if (int(caractere) >= 65 && int(caractere) <= 90)
        cout << "O caractere " << caractere << " e uma letra maiuscula." << endl;
    else
        cout << caractere << " e um caractere nao inteiro e que nao esta no alfabeto." << endl;
}