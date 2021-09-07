#include <iostream>
#include <cmath>
#include <iomanip>
#define pi 3.141592653589

using namespace std;
float converte_grau_rad(float);

int main(){
    int angulo = 0;

    do{
        cout << setprecision(10) << "Angulo: " << angulo << " --- Seno: " << sin(converte_grau_rad(angulo)) << " --- Cosseno: " << cos(converte_grau_rad(angulo)) << endl;
        
        angulo++;
    }while(angulo <= 90);

    return 0;
}


float converte_grau_rad(float angulo){
    return (angulo*pi)/180;
}