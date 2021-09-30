#include "my_class.h"
#include <iostream>

using namespace std;

int main(){

    my_class mc;
    
    while(true){

        cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>> MENU DE OPCOES <<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;

        int opcao_menu;
        cout << "Selecione uma das opcoes abaixo:\n0 - Encerrar programa;\n1 - Sequencia de Letras do Alfabeto;\n2 - Somatorio y a partir de (x + 3);\n3 - Raiz quadrada dos numeros no intervalo;\n4 - Padrao numerico/asterisco;\n5 - Valores de f(x) no intervalo [Xmin,..., X+Passo,Xmax];\n6 - Zeros reais e imaginarios de f(x);\n\nOpcao: ";
        cin >> opcao_menu;

        switch(opcao_menu){

            case 0:
                cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>> PROGRAMA ENCERRADO <<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
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
                cout << "\n\n A opcao inserida e invalida!" << endl;
        }
    }

    return 0;
}