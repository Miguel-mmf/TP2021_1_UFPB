#include <iostream>

using namespace std;

class Retangulo {
    int x,y;
    public:
        int teste = 10;
        void setar_valores(int,int);
        int area(){return x*y;}
};

// Na classe, somente o protótipo da função foi definida.
void Retangulo::setar_valores(int a,int b)
{
    x=a;
    y=b;
}

int main()
{
    Retangulo Ret;
    Ret.setar_valores(3,4);

    cout << "Area do retangulo: " << Ret.area() << endl;
    cout << "Varivavel public da classe Retangulo: " << Ret.teste << endl;

    return 0;
}