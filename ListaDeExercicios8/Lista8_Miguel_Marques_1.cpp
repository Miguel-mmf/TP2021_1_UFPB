#include <iostream>
#include <string>
#include <cctype>

using namespace std;

char vogais[10] = {'a','e','i','o','u','A','E','I','O','U'};

void encontra_conta_vogais(char *caracteres);

int main()
{
    char nome1[100], nome2[100], nome3[100];

    cout << "Digite o nome de uma pessoa: ";
    cin.getline(nome1,100);
    cout << "Digite o nome de uma pessoa: ";
    cin.getline(nome2,100);
    cout << "Digite o nome de uma pessoa: ";
    cin.getline(nome3,100);

    encontra_conta_vogais(nome1);
    encontra_conta_vogais(nome2);
    encontra_conta_vogais(nome3);

    return 0;
}

void encontra_conta_vogais(char *caracteres)
{
    int count = 0;
    string nome = caracteres;

    for(*caracteres; *caracteres != '\0';*caracteres++){
        for(int i=0; i < sizeof(vogais)/sizeof(vogais[0]); i++){
            if (*caracteres == vogais[i])
                count++;
        }
    }

    cout << "O nome " << nome << " possui " << count << " vogais." << endl;
}