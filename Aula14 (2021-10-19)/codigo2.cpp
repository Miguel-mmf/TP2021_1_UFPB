#include <iostream>

using namespace std;

template <class tipo> tipo func(tipo x){return (x < 0)? -x : x;}

int main()
{
    int i = -3;
    float a = -6.1;
    
    cout << " Chamada com tipo generico int: " << func(i) << endl;
    cout << " Chamada com tipo generico float: " << func(a) << endl;

    return 0;
}