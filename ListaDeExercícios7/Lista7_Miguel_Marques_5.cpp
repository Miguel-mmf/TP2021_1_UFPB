#include <iostream>

using namespace std;

void gera_array(int [][3]);
void linha_maior_menor(int [][3]);
void imprime_array(int [][3]);
int tabela[3][3];

int main()
{
    gera_array(tabela);
    imprime_array(tabela);
    linha_maior_menor(tabela);

    return 0;
}


void gera_array(int array[3][3]){

    for(int i=0; i < 3; i++){
        for(int j=0; j < 3; j++){
            cout << "Valor na posicao [" << (i+1) << "][" << (j+1) << "]: ";
            cin >> array[i][j];
        }
    }
}

void linha_maior_menor(int array[3][3]){

    int max=0, linha_max=0, col_max=0, min=10000000, linha_min=0, col_min=0;

    for(int i=0; i < 3; i++){
        for(int j=0; j < 3; j++){
            if (array[i][j] > max){
                max = array[i][j];
                linha_max = (i+1);
                col_max = (j+1);
            }
            if (array[i][j] < min){
                min = array[i][j];
                linha_min = (i+1);
                col_min = (j+1);
            }
        }
    }
    
    cout << "\nA linha " << linha_max << " contem o valor " << max << " na coluna " << col_max << ", o maior valor do array" << endl;
    cout << "A linha " << linha_min << " contem o valor " << min << " na coluna " << col_min << ", o menor valor do array" << endl;
}

void imprime_array(int array[3][3]){

    cout << "[";

    for(int i=0; i < 3; i++){
        cout << "[";
        for(int j=0; j < 3; j++){
            cout << array[i][j];
            if (j!=2){cout << ", ";}
        }
        cout << "]";
        if (i!=2){cout << "\n";}
    }
    cout << "]";
}