#include <iostream>
#include <cmath>
#include <cstdlib>
#include <conio.h> //https://code-reference.com/c/conio.h

#include "opcao1.h"
#include "opcao3.h"
#include "opcao5.h"
#include "opcao12.h"

using namespace std;

void gera_menu();
float calc_quadrado(int);
void gera_opcao2(int);
inline float gera_potencia(float a, float n)
{
    if(n >= 1)
        return a*gera_potencia(a,n-1);
    return 1;
}

inline void gera_num_alea(int num){
    if (num >= 0){
        cout << "\nValor do dado: " << rand()%100 << endl;
        return gera_num_alea((num-1));
    }
}

int Max = 0,Min = 1000000;


int main()
{

    while(true){

        cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>> MENU DE OPCOES <<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;

        int opcao_menu;
        
        gera_menu();
        cin >> opcao_menu;

        switch(opcao_menu){

            case 0:
                cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>> PROGRAMA ENCERRADO <<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
                return 0;
            case 1:
            {
                float temp;
                int sair = 0;

                cout << "\nDigite a temperatura em graus Celsius: ";
                cin >> temp;
                while(not sair){
                    cout << "\n\nTemperatura em Fahrenheit: " << convert_celsius_to_fahrenheit(temp) << endl;
                    cout << "Temperatura em Kelvin: " << convert_celsius_to_kelvin(temp) << endl;
                    cout << "\n Deseja inserir uma nova temperatura (1- sim, 2- nao): ";
                    cin >> sair;
                    if(sair == 1){sair = 0;} else{break;};

                    cout << "\nDigite uma nova temperatura em graus Celsius: ";
                    cin >> temp;
                };
                break;
            }
            case 2:
            {
                int num[4], index=0,sair = 0;

                while(not sair){

                    cout << "\n\n";
                    while(index <=4){
                        cout << "Digite um valor inteiro: ";
                        cin >> num[index];
                        index++;
                    };
                    
                    cout << "\n\n";
                    for(index = 0; index <= 4; index++){
                        calc_maxmin(num[index]);
                    }

                    cout << "\nValor maximo da sequencia de numeros: " << Max << endl;
                    cout << "Valor minimo da sequencia de numeros: " << Min << endl;

                    cout << "\n Deseja inserir um novo valor (1- sim, 2- nao): ";
                    cin >> sair;
                    if(sair == 1){sair = 0;index=0;} else{break;};
                };
                break;
            }
            case 3:
            {
                int num[4], index=0,sair = 0;

                while(not sair){

                    cout << "\n\n";
                    while(index <=4){
                        cout << "Digite um valor inteiro: ";
                        cin >> num[index];
                        index++;
                    };
                    
                    cout << "\n\n";
                    for(index = 0; index <= 4; index++){
                        gera_opcao2(num[index]);
                    }

                    cout << "\n Deseja inserir um novo valor (1- sim, 2- nao): ";
                    cin >> sair;
                    if(sair == 1){sair = 0;index=0;} else{break;};
                };
                break;
            }
            case 4:
            {
                int num,sair = 0;
                static int count=0;

                cout << "\nDigite um valor inteiro (0 para sair): ";
                cin >> num;

                while(num != 0){

                    cout << "Quadrado do numero " << num << ": " << calc_quadrado(num) << endl;
                    count++;

                    cout << "\nDigite um novo valor inteiro(0 para sair): ";
                    cin >> num;
                };

                cout << "\nNumero de valores inseridos: " << count << endl;
                break;
            }
            case 5:
            {
                float a, b, c;
                int sair = 0;

                while(not sair){

                    cout << "\nDigite os coeficientes:" << endl;
                    cout << "\nDigite o valor de a: ";
                    cin >> a;
                    cout << "Digite o valor de b: ";
                    cin >> b;
                    cout << "Digite o valor de c: ";
                    cin >> c;

                    cout << "\nFuncao: f(x) = " << a << "x^2" << ((b < 0)? " ": " + ") << b << "x" << ((c < 0)? " ": " + ") << c << endl;

                    gera_raizes_r_e_c(a,b,c);

                    cout << "\n Deseja inserir uma nova equacao (1- sim, 2- nao): ";
                    cin >> sair;
                    if(sair == 1){sair = 0;}
                };
                break;
            }
            case 6:
            {
                float a, b;
                int sair = 0;

                while(not sair){

                    cout << "\nDigite os coeficientes:" << endl;
                    cout << "\nDigite o valor de a: ";
                    cin >> a;
                    cout << "Digite o valor de b: ";
                    cin >> b;

                    cout << "\nFuncao: f(x) = " << a << "x" << ((b < 0)? " ": " + ") << b << endl;

                    gera_raizes_r_e_c(0,a,b);

                    cout << "\n Deseja inserir uma nova equacao (1- sim, 2- nao): ";
                    cin >> sair;
                    if(sair == 1){sair = 0;}
                };
                break;
            }
            case 7:
            {
                float a, n;
                int sair = 0;

                while(not sair){

                    cout << "\nDigite os coeficientes:" << endl;
                    cout << "\nDigite o valor de a: ";
                    cin >> a;
                    cout << "Digite o valor de n: ";
                    cin >> n;

                    cout << "\nPotencia de " << a << " elevado a " << n << " : " << gera_potencia(a, n) << endl;

                    cout << "\n Deseja inserir novoas valores de a e n (1- sim, 2- nao): ";
                    cin >> sair;
                    if(sair == 1){sair = 0;}
                };
                break;
            }
            case 8:
                break;
            case 9:
                break;
            case 10:
            {
                cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>> GERADOR DE DADOS ALEATORIOS <<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
                cout << "\nDigite q para sair e SPACE para um novo valor do dado." << endl;

                int sair = 1;
                char tecla;
                
                while(sair){
                    tecla = getch();
                    
                    if (int(tecla) == 32){
                        gera_num_alea(100);
                    }
                    if (int(tecla) == 81 || int(tecla) == 113){
                        cout << "\n\nPrograma Encerrado!" << endl;
                        sair = 0;
                    }
                }
                break;
            }
            case 11:
            {
                cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>> EMULADOR DE DADO <<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
                cout << "\nDigite q para sair e SPACE para um novo valor do dado." << endl;
                int sair = 1;
                char tecla;
                
                while(sair){
                    tecla = getch();
                    
                    if (int(tecla) == 32){
                        cout << "\nValor do dado: " << abs(rand()%10 - 3) << endl;
                    }
                    if (int(tecla) == 81 || int(tecla) == 113){
                        cout << "\n\nPrograma Encerrado!" << endl;
                        sair = 0;
                    }
                }
                break;
            }
            case 12:
            {
                float angulo;
                int sair = 0;

                while(not sair){

                    cout << "\nDigite o valor de um angulo em graus: ";
                    cin >> angulo;

                    calc_sin_cos(angulo);

                    cout << "\n Deseja inserir novoas valores de a e n (1- sim, 2- nao): ";
                    cin >> sair;
                    if(sair == 1){sair = 0;}
                };
                break;
            }

            default:
                cout << "\n\n A opcao inserida e invalida!" << endl;
        }
    }

    return 0;
}


void gera_menu()
{
    cout << "Selecione uma das opcoes abaixo:\n0 - Encerrar programa;\n1 - Opcao 1;\n2 - Opcao 2;\n3 - Opcao 3;\n4 - Opcao 4;\n5 - Opcao5;\n6 - Opcao 6;\n7 - Opcao 7;\n8 - Opcao 8;\n9 - Opcao 9;\n10 - Opcao 10;\n11 - Opcao 11;\n12 - Opcao 12;\n\nOpcao: ";
}