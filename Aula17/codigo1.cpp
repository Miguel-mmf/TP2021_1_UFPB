#include <iostream>

using namespace std;

int main()
{
    int idade[10], media=0;

    for(int i=0; i<10; i++){
        cout << "Digite a idade do aluno: ";
        cin >> idade[i];
        idade[i] = 10 + i;
        cout << idade[i] << endl;
        media = idade[i] + media;
    }

    media = media/10;

    for(int i=0; i < 10; i++){
        cout << "Idade do aluno: idade[" << i << "] = " << idade[i] << endl;
    }

    cout << "Medias das idades: " << media << endl;

    return 0;
}