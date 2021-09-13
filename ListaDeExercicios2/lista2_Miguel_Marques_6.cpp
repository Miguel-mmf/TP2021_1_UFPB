#include <iostream>
#include <cmath>
#define pi 3.1415

using namespace std;

float converte_rad_grau(float);

int main(){

    float cateto_adj = 0;
    float cateto_ops = 0;

    cout << "Digite o valor do cateto adjacente: ";
    cin >> cateto_adj;
    cout << "Digite o valor do cateto oposto: ";
    cin >> cateto_ops;

    float hipotenusa = hypot(cateto_adj,cateto_ops);
    float angulo1 = acos(cateto_adj/hipotenusa);
    float angulo2 = acos(cateto_ops/hipotenusa);

    cout << "\nAngulo 1: " << converte_rad_grau(angulo1) << endl;
    cout << "Seno do angulo " << converte_rad_grau(angulo1) << ": " << sin(angulo1) << endl;
    cout << "Cosseno do angulo " << converte_rad_grau(angulo1) << ": " << cos(angulo1) << endl;
    cout << "Tangente do angulo " << converte_rad_grau(angulo1) << ": " << tan(angulo1) << endl;

    cout << "\nAngulo 2: " << converte_rad_grau(angulo2) << endl;
    cout << "Seno do angulo " << converte_rad_grau(angulo2) << ": " << sin(angulo2) << endl;
    cout << "Cosseno do angulo " << converte_rad_grau(angulo2) << ": " << cos(angulo2) << endl;
    cout << "Tangente do angulo " << converte_rad_grau(angulo2) << ": " << tan(angulo2) << endl;

    cout << "\nSoma dos angulos em grau: " << converte_rad_grau(angulo1) + converte_rad_grau(angulo2) << endl;
    cout << "Soma dos angulos em radianos: " << angulo1 + angulo2 << endl;

    return 0;
}


float converte_rad_grau(float angulo_rad){
    return (angulo_rad*180)/pi;
}