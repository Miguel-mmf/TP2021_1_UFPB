#include <iostream>

using namespace std;

template <class tipo, class tipo2> float produto(tipo x, tipo2 y){return x*y;}

int main()
{
    int i=3,j=4;
    float a=6.25, b=2.5;

    cout << "Chamada com tipos genericos: " << produto(i,j) << endl;
    cout << "Chamada com tipos genericos: " << produto(a,b) << endl;
    cout << "Chamada com tipos genericos: " << produto(i,a) << endl;

    return 0;
}