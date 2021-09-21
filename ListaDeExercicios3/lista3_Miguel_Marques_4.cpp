#include <iostream>

using namespace std;

int main(){

    float x,y;

    cout << "Digite um valor para o calculo de f(x): ";
    cin >> x;
    
    cout << "\nPara f(x) = x^2 + x + 2.2" << endl;
    cout << "Quando x=" << x << " --> f(x)=" << (x*x+x+2.2) << endl;

    return 0;
}