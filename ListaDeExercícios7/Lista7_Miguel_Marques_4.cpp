#include <iostream>

using namespace std;

float calc_potencia_media(int, float [], float []);

int main()
{
    int n;

    cout << "Quantos valores de tensao e corrente?" << endl;
    cin >> n;

    while(n > 50){
        cout << "O numero de valores de tensao de corrente deve ser menor que 50! Digite um novo valor: ";
        cin >> n;
    }

    float V[n], I[n];
    
    for(int i=0; i < n; i++){
        cout << "Ponto " << (i+1) << ":" << endl;
        cout << "Tensao: ";
        cin >> V[i];
        cout << "Corrente: ";
        cin >> I[i];
    }

    cout << "Potencia eletrica media dos pares de pontos (tensao,corrente) " << calc_potencia_media(n,V,I) << endl;

    return 0;
}


float calc_potencia_media(int n,float array1[], float array2[]){

    float sum_potencias = 0;
    for(int i=0; i < n; i++) sum_potencias += array1[i] * array2[i];

    return (sum_potencias/n);
}