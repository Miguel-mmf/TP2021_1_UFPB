#include <iostream>

extern const int col;

template <class size_x, class size_y>
void gera_array(int (&array)[][col], int rows, int cols){

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
        cout << "]" << endl;;
    }
    cout << "]";
}