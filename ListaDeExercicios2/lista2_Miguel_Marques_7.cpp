#include <iostream>
#include <cmath>
#include <iomanip>
#define pi 3.1415

using namespace std;

float calc_perimetro(float);
float calc_area(float);

int main(){

    float raio = 0;

    cout << "Digite o valor do raio: ";
    cin >> raio;

    cout << setprecision(10) << "\nPerimetro do circulo de raio " << raio << ": " << calc_perimetro(raio) << endl;
    cout << setprecision(10) <<"Area do circulo de raio " << raio << ": " << calc_area(raio) << endl;

    return 0;
}

float calc_perimetro(float raio){
    return 2*pi*raio;
}

float calc_area(float raio){
    return 2*pi*(pow(raio,2));
}