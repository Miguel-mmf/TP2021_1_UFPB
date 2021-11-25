#include <iostream>

using namespace std;

void func_aux_troca(int, int);
void gera_array(int [][3]);
void imprime_array(int [][3]);
void calc_determinante(int [][3]);
void gera_transposta(int [][3]);
void multiplica_matriz_por_x(int [][3],int);

int tabela[3][3];

int main()
{
    float constante;

    gera_array(tabela);
    imprime_array(tabela);

    calc_determinante(tabela);
    gera_transposta(tabela);

    cout << "\nDigite um valor constante para multiplicar elemento por elemento da matriz 3x3:";
    cin >> constante;

    multiplica_matriz_por_x(tabela,constante);

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

void func_aux_troca(int a, int b){
    int temp = a;
    a = b;
    b = temp;
}

void calc_determinante(int array[3][3]){

    int aux[3][5], sum_diogonal_principal[]={1,1,1}, sum_diogonal_secundaria[]={1,1,1};

    for(int i=0; i < 3; i++){
        for(int j=0; j < 3; j++){
            aux[i][j] = array[i][j];
        }
    }
    
    for(int i=0; i < 3; i++){
        for(int j=0; j < 2; j++){
            aux[i][j+3] = array[i][j];
        }
    }

    // cout << "\n[";

    // for(int i=0; i < 3; i++){
    //     cout << "[";
    //     for(int j=0; j < 5; j++){
    //         cout << aux[i][j];
    //         if (j!=4){cout << ", ";}
    //     }
    //     cout << "]";
    //     if (i!=2){cout << "\n";}
    // }
    // cout << "]";

    int sum_s=4, w=0;
    for(int x=0; x < 3; x++){
        for(int i=0; i < 3; i++){
            for(int j=0; j < 5; j++){
                if (j == w){
                    sum_diogonal_principal[x] = sum_diogonal_principal[x]*aux[i][j];
                }
                if (j == sum_s){
                    sum_diogonal_secundaria[x] = sum_diogonal_secundaria[x]*aux[i][j];
                }
            }
            //cout << sum_s << " - " << sum_diogonal_secundaria[x] << endl;
            w+=1;
            sum_s-=1;
        }
        w-=2;
        sum_s+=2;
        if (x>0){
            sum_diogonal_principal[0] += sum_diogonal_principal[x];
            sum_diogonal_secundaria[0] += sum_diogonal_secundaria[x];
        }
    }

    cout << "\nDeterminante: " << (sum_diogonal_principal[0] - sum_diogonal_secundaria[0]) << endl;
    
}

void gera_transposta(int array[3][3]){

    int aux[3][3];

    for(int i=0; i < 3; i++){
        for(int j=0; j < 3; j++){
            aux[i][j] = array[j][i];
        }
    }

    cout << "\nTransposta da matriz 3x3:\n";
    for(int i=0; i < 3; i++){
        cout << "[";
        for(int j=0; j < 3; j++){
            cout << aux[i][j];
            if (j!=2){cout << ", ";}
        }
        cout << "]";
        if (i!=2){cout << "\n";}
    }
    cout << "]";
}

void multiplica_matriz_por_x(int array[][3],int constante){
    
    int aux[3][3];

    for(int i=0; i < 3; i++){
        for(int j=0; j < 3; j++){
            aux[i][j] = array[j][i]*constante;
        }
    }

    cout << "\nMatriz 3x3 multiplicada pela constante " << constante << ":\n";
    for(int i=0; i < 3; i++){
        cout << "[";
        for(int j=0; j < 3; j++){
            cout << aux[i][j];
            if (j!=2){cout << ", ";}
        }
        cout << "]";
        if (i!=2){cout << "\n";}
    }
    cout << "]";
}