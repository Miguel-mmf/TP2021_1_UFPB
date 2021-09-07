#include <iostream>
#define txt "*"

using namespace std;

void gera_piramide(int);

int main(){

    int camadas = 0;

    cout << "Digite o valor de camadas da piramide: ";
    cin >> camadas;

    gera_piramide(camadas);

    return 0;
}

void gera_piramide(int camadas){

    int count = 1;
    int condicao = 1;

    do{
        
        do{
            cout << txt;
            count +=1;
        }while(count<=condicao);

        cout << "\n";
        condicao += 1;
        count = 1;
    }while(condicao<=camadas);
}