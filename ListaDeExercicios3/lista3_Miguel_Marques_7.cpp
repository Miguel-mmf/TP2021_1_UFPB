#include <iostream>
#include <string.h>
#define txt '*'

using namespace std;
void gera_piramide_completa(string,int);
string completa_string(string,int,char);

int main(){

    int altura;
    string linha,linha_top,linha_bottom;

    cout << "Digite a altura da piramide (1 a 10): ";
    cin >> altura;
    
    linha = completa_string(linha, ((altura*4)),' ');
    linha_top = completa_string(linha_top, ((altura*4)),'-');
    linha_bottom = completa_string(linha_bottom, ((altura*4)),'-');

    cout << linha_top << endl;
    gera_piramide_completa(linha,altura);
    cout << linha_bottom << endl;

    return 0;
}


void gera_piramide_completa(string linha,int altura){

    int count = 0;
    int tamanho_medio = (linha.length()-1)/2; // por causa de '\0'
    int m1 = tamanho_medio, m2 = tamanho_medio+1;

    do{
        linha[((m1)-count)] = txt;
        linha[((m2)+count)] = txt;
        cout << linha << endl;
        count++;
    }while(count < altura);
}

string completa_string(string linha, int tamanho, char caractere){

    int posicao = 0;

    while(posicao <= tamanho){
        linha+= caractere;
        posicao++;
    }

    linha[0] = '|';
    linha[tamanho] = '|';

    return linha;
}