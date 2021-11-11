#include <iostream>

using namespace std;

long fatorial(long);

int main()
{
    long x;
    cout << "Digite um numero inteiro: ";
    cin >> x;
    cout << "Fatorial = " << fatorial(x) << endl;

    return 0;
}


long fatorial(long i)
{
    if(i > 1)
        return i * fatorial(i-1);
    return 1;
}