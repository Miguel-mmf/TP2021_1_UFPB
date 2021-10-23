#include <iostream>

using namespace std;

float calc_quadrado(int num){return num*num;}

float calc_cubo(int num){return num*num*num;}

float calc_fatorial(int num)
{
    if (num>1)
        return num*calc_fatorial(num-1);
    return 1;
}

void gera_opcao2(int num)
{
    cout << "\nNumero: " << num << endl;
    cout << "Quadrado do numero " << num << ": " << calc_quadrado(num) << endl;
    cout << "Cubo do numero " << num << ": " << calc_cubo(num) << endl;
    cout << "Fatorial do numero " << num << ": " << calc_fatorial(num) << endl;
}