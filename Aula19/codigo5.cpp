#include <iostream>

using namespace std;

class Retangulo
{
        int x, y;
    public:
        void setar_valores (int a, int b){ 
            x = a; y = b;
        }
        int getX () {return x;}
        int getY () {return y;}
        int area () {return (x*y);}
};

int main()
{
    Retangulo Ret;
    Retangulo *Ret2;

    Ret2 = &Ret;
    Ret2->setar_valores(3, 4);

    cout << "Area = " << Ret2->area();

    return 0;
}
