#include "my_class.h"
#include <iostream>

using namespace std;

int main(){

    my_class mc;
    
    while(true){

        int opcao_menu;
        cout << "Selecione uma das opcoes abaixo:\n0 - Encerrar programa;\n1 - Letras do alfabeto entre x1 e x2;\n2 - Somatorio y a partir de um valor A e B;\n3 - Raiz quadrada;\n4 - Padrao numerico/asterisco;5 - Valores de f(x) = ax^2 + bx + c entre [Xmin,...,Xmax] com passos P;\n6 - Zeros reais de f(x) = ax^2 + bx + c;\n\nOpcao: ";
        cin >> opcao_menu;

        switch(opcao_menu){

            case 0:
                cout << "Programa encerrado!" << endl;
                return 0;
            case 1:
                mc.gera_seq_alfabeto();
                break;
            case 2:
                mc.gera_somatorio_y();
                break;
            case 3:
                mc.gera_raizes_do_intervalo();
                break;
            case 4:
                mc.gera_pardao_num_asterisco();
                break;
            case 5:
                mc.gera_valores_fx();
                break;
            case 6:
                mc.gera_raizes_r_e_c();
                break;

            default:
                cout << "\n\n A opção inserida e invalida!" << endl;
        }
    }

    return 0;
}