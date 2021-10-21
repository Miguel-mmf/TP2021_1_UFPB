#include <iostream>

using namespace std;

template <class tipo> float produto(tipo x, tipo y){return x*y;}

int main()
{
    int i=3,j=4;
    float a=6.25, b=2.5;

    cout << "Chamada com tipos genericos: " << produto(i,j) << endl;
    cout << "Chamada com tipos genericos: " << produto(a,b) << endl;
    //cout << "Chamada com tipos genericos: " << produto(i,a) << endl;
        // não é possível uma vez que os parametros precisam ser do mesmo tipo

    return 0;
}