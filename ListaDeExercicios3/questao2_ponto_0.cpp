#include <iostream>

using namespace std;

int main(){

    char caractere;
    int num = 0, caractere_int, count = 1,condicao;

    cout << "Digite uma letra: ";
    cin >> caractere;
    cout << "Digite um numero de 1 a 8: ";
    cin >> num;

    caractere_int = (int)caractere;
    condicao = num;

    do{
        if (count < (9-condicao)){
            caractere_int /= 2;
            count++;
        }
        else{
            if (caractere_int % 2 == 0){
                cout << num << " bit: 0" << endl;
                break;
            }
            else{
                cout << num << " bit: 1" << endl;
                break;
            }
        }
    }while(caractere_int >= 0);

    return 0;
}