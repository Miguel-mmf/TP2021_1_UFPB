#include <iostream>

using namespace std;

class Retangulo
{
    int x, y;
    public:
    void set () {
        cout << "Digite valor de x:" << endl;
        cin >> x;
        cout << "Digite valor de y:" << endl;
        cin >> y;
    }
    Retangulo () {x = 0; y = 0;}
    int area () {return x*y;}
};

int main()
{
    float areas[10];

    Retangulo Ret[10]; // cria uma array com 4 objetos

    for (int i = 0; i < 10; i++){
        Ret[i].set();
        areas[i] = Ret[i].area();
        cout << "Area = " << areas[i] << "\n" << endl;
    }

    cout << "Array Areas = [";
    for (int i=0; i < 10; i++){
        cout << areas[i];
        if (i!=9){cout << ", ";}
    }

    cout << "]" << endl;

    return 0;
}