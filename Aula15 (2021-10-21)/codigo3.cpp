#include <iostream>
#include "minmax.h"

using namespace std;

int main()
{
    int i=3,j=4;
    float a=6.25, b=2.5;
    char c='a',d='x';

    cout << "Maximo (i,j): " << Max(i,j) << endl;
    cout << "Minimo (i,j): " << Min(i,j) << endl;

    cout << "Maximo (a,b): " << Max(a,b) << endl;
    cout << "Minimo (a,b): " << Min(a,b) << endl;

    cout << "Maximo (c,d): " << Max(c,d) << endl;
    cout << "Minimo (d,d): " << Min(c,d) << endl;

    return 0;
}