#include <iostream>

using namespace std;

int main()
{
    int n = 5;
    int *p;
    cout << "Lixo de memoria no ponteiro p: " << p << endl;

    p = &n;

    cout << "Valor de n: " << n << " &n " << &n << endl;
    cout << "Valor de p: " << p << " &p " << &p << endl; 

    return 0;
}