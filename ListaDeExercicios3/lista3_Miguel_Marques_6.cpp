#include <iostream>

using namespace std;

int main(){

    int idade;

    cout << "Digite a sua idade: ";
    cin >> idade;

    if (idade > 0){
        if(idade <= 10)
            cout << "\nCrianca." << endl;
        else if (idade > 10 && idade <= 15)
            cout << "\nAdolescente." << endl;
        else if (idade > 15 && idade <=25)
            cout << "\nJovem." << endl;
        else
            cout << "\nAdulto." << endl;
    }else
        cout << "Nao existe idade negativa!" << endl;

    return 0;
}