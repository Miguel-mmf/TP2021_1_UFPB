#include <iostream>
#include <string.h>

using namespace std;
void convert_d_to_b(int,int);

int main(){

    char caractere;
    int num = 0;

    cout << "Digite uma letra: ";
    cin >> caractere;
    cout << "Digite um numero de 1 a 8: ";
    cin >> num;

    convert_d_to_b((int)caractere,num);

    return 0;
}


void convert_d_to_b(int caractere_int, int num){

    char num_b[9]; //= "00000000";

    int posicao = 7;
    num_b[8] = '\0';
    do{
        if (caractere_int % 2 == 0){
            num_b[posicao] = '0';
        }
        else{
            num_b[posicao] = '1';
        }
        caractere_int /= 2;
        posicao--;
    }while(caractere_int != 0);

    if (posicao >= 0){
        do{
            num_b[posicao] = '0';
            posicao--;
        }while(posicao >= 0);
    }

    cout << "Caractere em binario: " << num_b << endl;
    cout << "Quantidade de bits: " << strlen(num_b) << endl;
    cout << num << " bit: " << num_b[num-1] << endl;
}