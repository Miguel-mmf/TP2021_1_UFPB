#include <iostream>

using namespace std;

class Resistencia
{
    float r, v;
    public:
        void set_valores(float resis, float tensao)
        {
            r = resis;
            v = tensao;
        }
        float calc_corrente(){return v / r;}
};

int main()
{
    Resistencia Res1, Res2, Res3;
    Resistencia Resistencias[3] = {Res1, Res2, Res3};
    Resistencia *Res;

    float resistencia, tensao;

    for (int i = 0; i < 3; i++){
        cout << "Digite um valor de resistencia: ";
        cin >> resistencia;

        cout << "Digite um valor de tensao: ";
        cin >> tensao;

        Res = &Resistencias[i];

        Res->set_valores(resistencia,tensao);

        cout << "Corrente = " << Res->calc_corrente() << " A" << endl;
    }

    return 0;
}