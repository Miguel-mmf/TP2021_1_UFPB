#include <iostream>
#include <cstdlib>
#include <cmath>

// criar um sorteador
    // 6 numeros de 0 a 60
    // não pode ter repetição e aleatório
    // armazenar na posição de um array
    // depois do primeiro sorteio, fazer um segundo sorteio
        // não pode repetir com os valores do primeiro sorteio
    // 3 sorteios, sem repetir o número dos sorteios anteriores

using namespace std;

// inline int gera_num_alea(int num){
//     return rand()%60;
// }

class Sorteador
{
        int sorteados[6] = {0,0,0,0,0,0};
    public:

        int gera_num_alea(){
            return abs(rand()%10 - 40);
        }

        int sorteio(int i, int array[6]){
            int num=0, aux=0;
            if (i >= 0){
                while(i >= 0){
                    num = gera_num_alea();
                    for (int j=0; j < 6; j++){
                        if (num == array[j]){
                            break;
                        }
                        else{
                            aux++;
                        }
                        if (aux==5){
                            sorteados[i] = num;
                            i--;
                        }
                    }
                }
            }
            return sorteados[6];
        }

        void imprime_array_sorteado(){
            cout << "[";

            for(int i=0; i < 6; i++){
                cout << sorteados[i];
                if (i!=5){cout << ",";}
            }
            cout << "]";
        };

};

int sorteio1[6], sorteio2[6], sorteio3[6];

int main()
{
    Sorteador Sort;

    Sort.sorteio(5,sorteio1);
    Sort.imprime_array_sorteado();
    
    return 0;
}