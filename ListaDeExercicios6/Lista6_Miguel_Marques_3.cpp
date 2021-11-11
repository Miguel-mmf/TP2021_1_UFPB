#include <iostream>

using namespace std;

class Resistor
{
    float resistencia;
    public:
        Resistor(float r){resistencia=r;}
        float calc_tensao(float corrente)
        {
            return resistencia*corrente;
        };
        float calc_corrente(float tensao)
        {
            return tensao/resistencia;
        };
};

int main()
{
    bool sair = false;
    float resistencia, tensao, corrente;

    while(!sair){

        cout << "Digite o valor da resistencia: ";
        cin >> resistencia;

        if (resistencia > 0){
            Resistor R(resistencia);

            cout << "Digite um valor de corrente: ";
            cin >> corrente;

            cout << "Digite um valor de tensao: ";
            cin >> tensao;

            cout << "Tensao na resistencia de " << resistencia << "Ohms a partir de uma corrente de " << corrente << "A: " << R.calc_tensao(corrente) << endl;
            cout << "Corrente na resistencia de " << resistencia << "Ohms a partir de uma tensao de " << tensao << "V: " << R.calc_corrente(tensao) << endl;
        }

        cout << "\nDeseja inserir novos valores (1- sim, 2- nao): ";
        cin >> sair;
        if(sair == true){sair = false;} else{break;};

    }

    return 0;
}