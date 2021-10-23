#include <iostream>
#include <cmath>

using namespace std;

void gera_raizes_r_e_c(float a, float b, float c){

    float delta=0;

    delta = ((b*b)-(4*a*c));
    cout << "\nDelta " << b << "^2" << "-4*" << a << "*" << c << ": " << delta << endl;

    if (delta >= 0){
        if (delta == 0){
            cout << (-b-sqrt(delta))/(2*a) << endl;
            cout << (-b+sqrt(delta))/(2*a) << endl;
        }else{
            cout << "\nRaiz x1: " << (-b+sqrt(delta))/(2*a) << endl;
            cout << "\nRaiz x2: " << (-b-sqrt(delta))/(2*a) << endl;
        }
    }else{
        cout << "\nRaiz x1: " << -b/(2*a) << ((a < 0)? " ": " +") << sqrt(abs(delta))/(2*a) << "i" << endl;
        cout << "\nRaiz x2: " << -b/(2*a) << ((a > 0)? " - ": " +") << abs(sqrt(abs(delta))/(2*a)) << "i" << endl;
    }
}

void gera_raizes_r_e_c(int a=0, float b=0, float c=0){

    cout << "\nRaiz: " <<  ((-1*c)/b) << endl;
}