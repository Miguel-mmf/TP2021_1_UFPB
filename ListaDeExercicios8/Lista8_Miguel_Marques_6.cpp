#include <iostream>

using namespace std;

class Resistencia
{
        float r;
    public:
        float v;

        Resistencia(){r=1;}
        
        void set_valores(float resis=1,float tensao=1)
        {
            r = resis;
            v = tensao;
        }
        float calc_corrente(){return v / r;}
        float get_resistencia(){return r;}
};


int main()
{
    Resistencia Resistencias[10];
    Resistencia *res;
    int sair, posicao, novo_valor;
    float correntes[10];

    cout << "Circuito com tensao de 1V" << endl;
    for (int i = 0; i < 10; i++){
        Resistencia Res;
        Res.set_valores(); // todas as tensões são 1V
        correntes[i] = Res.calc_corrente();
        cout << "\nCorrente para a resistencia de " << Res.get_resistencia() << ": " << correntes[i] << " ";
        Resistencias[i] = Res;
    }

    while (true){
        
        cout << "\nCircuito com tensao de 1V" << endl;
        cout << "Deseja alterar alguma resistencia? - sim (1) nao (0)" << endl;
        cin >> sair;

        if (sair == 1)
        {
            cout << "Deseja mudar a resistencia de qual posicaoicao? " << endl;
            cin >> posicao;
            cout << "Qual o novo novo_valor? " << endl;
            cin >> novo_valor;

            res = &Resistencias[posicao];
            res->set_valores(novo_valor);
            correntes[posicao] = res->calc_corrente();

            for (int i = 0; i < 10; i++){
                cout << "\nCorrente para a resistencia de " << Resistencias[i].get_resistencia() << ": " <<correntes[i] << " ";
            }
        }
        
        else
            break;
    }

    return 0;
}