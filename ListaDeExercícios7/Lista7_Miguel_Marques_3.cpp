#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int main()
{
    char nome1[100], nome2[100], nome3[100];
    char aux_n1, aux_n2, aux_n3;

    cout << "Digite o nome de uma pessoa: ";
    cin.getline(nome1,256);
    cout << "Digite o nome de uma pessoa: ";
    cin.getline(nome2,256);
    cout << "Digite o nome de uma pessoa: ";
    cin.getline(nome3,256);

    cout << "\nNomes ordenados em ordem alfabetica" << endl;

    aux_n1 = tolower(nome1[0]);
    aux_n2 = tolower(nome2[0]);
    aux_n3 = tolower(nome3[0]);

    if (int(aux_n1) < int(aux_n2) && int(aux_n1) < int(aux_n3)){
        cout << nome1 << endl;
        if (int(aux_n2) < int(aux_n3)){
            cout << nome2 << endl;
            cout << nome3 << endl;
        }
        else{
            cout << nome3 << endl;
            cout << nome2 << endl;
        }
    }
    else if (int(aux_n2) < int(aux_n1) && int(aux_n2) < int(aux_n3)){
        cout << nome2 << endl;
        if (int(aux_n1) < int(aux_n3)){
            cout << nome1 << endl;
            cout << nome3 << endl;
        }
        else{
            cout << nome3 << endl;
            cout << nome1 << endl;
        }
    }
    else{
        cout << nome3 << endl;
        if (int(aux_n1) < int(aux_n2)){
            cout << nome1 << endl;
            cout << nome2 << endl;
        }
        else{
            cout << nome2 << endl;
            cout << nome1 << endl;
        }
    }

    return 0;
}