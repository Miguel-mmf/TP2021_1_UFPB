#include <iostream>

using namespace std;

void gera_array(int [],int,int);
void func_aux_troca(int, int);
void ordena_array(int [], int, int);
void imprime_array(int [], int, int);

int main()
{
    int dimensao = 0, linhas = 0, colunas = 0;

    cout << "Quantas dimensoes tem o array? (maximo de 2 dimensoes e 100 linhas e colunas)";
    cin >> dimensao;
    
    if(dimensao = 1){
        cout << "Digite o numero de colunas: ";
        cin >> colunas;

        //const int col = colunas;
        int array[0][colunas];

        gera_array(array,linhas,colunas);
        ordena_array(array,linhas,colunas);
        imprime_array(array,linhas,colunas);
    }
    else if(dimensao = 2){
        cout << "Digite o numero de linhas: ";
        cin >> linhas;
        cout << "Digite o numero de colunas: ";
        cin >> colunas;

        int array[linhas][colunas];

        gera_array(array,linhas,colunas);
        ordena_array(array,linhas,colunas);
        imprime_array(array,linhas,colunas);
    }
    else{
        cout << "Programa finalizado!" << endl;
    }

    return 0;
}

void gera_array(int array[][100], int rows, int cols){

    if (rows == 0) rows = 1;

    for(int i=0; i < rows; i++){
        for(int j=0; j < cols; j++){
            cout << "Valor na posição [" << i << "][" << j << "]: ";
            cin >> array[i][j];
        }
    }
}

void func_aux_troca(int a, int b){
    int temp = a;
    a = b;
    b = temp;
}

void ordena_array(int array[][100], int rows, int cols){

    if (rows == 0) rows = 1;

    for(int i=0; i < (rows-1); i++){
        for(int j=0; j < (cols-1); j++){
            if (array[i][j] > array[i][j+1]){
                func_aux_troca(array[i][j],array[i][j+1]);
            }
        }
    }
}

void imprime_array(int array[][100],int rows, int cols){

    if (rows == 0) rows = 1;
    cout << "[";

    for(int i=0; i < rows; i++){
        cout << "[";
        for(int j=0; j < cols; j++){
            cout << array[i][j];
            if (j!=(cols-1)){cout << ", ";}
        }
        cout << "]";
        if (i!=2){cout << "\n";}
    }
    cout << "]";
}