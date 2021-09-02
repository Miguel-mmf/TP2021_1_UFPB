#include <iostream>

using namespace std;

void convert_d_to_b(int);

int main(){

    char caractere{'m'};

    cout << "Digite um caractere: ";
    cin >> caractere;

    int num = (int)caractere;
    cout << num << endl;

    convert_d_to_b(num);

    return 0;
}

void convert_d_to_b(int num){

    string num_b;

    do{
        if (num % 2 == 0){
            num_b += '0';
        }
        else{
            num_b += '1';
        }
        num = num/2;
    }while(num != 0);

    int posicao = 0;
    while(num_b[posicao] != '\0'){
        posicao++; // total de caracteres
    }

    string num_b_final; //string com o valor de num em 8bits

    if (posicao < 8){
        int diferenca_tam = 8-posicao;

        cout << "Separado" << endl;

        while(diferenca_tam){
            num_b_final += '0';
            cout << '0' << endl;
            diferenca_tam--;
        }
        
        while(posicao >= 0){
            num_b_final += num_b[posicao];
            cout << num_b[posicao] << endl;
            posicao--;
        }
    }
    else{
        cout << "Separado" << endl;
        while(posicao >= 0){
            num_b_final += num_b[posicao];
            cout << num_b[posicao] << endl;
            posicao--;
        }
    }
    cout << "Binario: " << num_b_final << endl;
}