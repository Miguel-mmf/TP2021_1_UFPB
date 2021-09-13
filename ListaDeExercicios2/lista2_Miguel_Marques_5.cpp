#include <iostream>
#include <cmath>

using namespace std;

int main(){

    float cateto_adj = 0;
    float cateto_ops = 0;

    cout << "Digite o valor do cateto adjacente: ";
    cin >> cateto_adj;
    cout << "Digite o valor do cateto oposto: ";
    cin >> cateto_ops;

    cout << "\nValor da hipotenusa do triangulo: " << hypot(cateto_adj,cateto_ops) << endl;

    return 0;
}