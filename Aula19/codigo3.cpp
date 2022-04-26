#include <iostream>

using namespace std;

int main()
{
    int idade = 22, cra = 9, periodo = 8;
    int *p;
    
    cout << "idade: " << idade << endl;
    p = &idade;
    cout << "p: " << *p << endl;

    cout << "cra: " << cra << endl;
    p = &cra;
    cout << "p: " << *p << endl;

    cout << "periodo: " << periodo << endl;
    p = &periodo;
    cout << "p: " << *p << endl;

    return 0;
}