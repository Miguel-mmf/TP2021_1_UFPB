#include <iostream>
#include <cmath>

using namespace std;

class Circulo
{
    float raio;
    float const pi = M_PI;

    public:
        Circulo(int r){raio = r;}
        Circulo(){raio = 2.5;}
        float calc_area(float raio){return (pi*pow(raio,2));}
        float calc_area(){return (pi*pow(raio,2));}
        float calc_perimetro(float raio){return 2*raio*pi;}
        float calc_perimetro(){return 2*raio*pi;}
};


int main()
{
    bool sair = false;
    float raio;

    while(!sair){

        cout << "Digite o valor do raio para o calculo da area e do perimetro: ";
        cin >> raio;

        Circulo Circ(raio);
        cout << "\nArea do circulo: " << Circ.calc_area() << endl;
        cout << "\nPerimetro do circulo: " << Circ.calc_perimetro() << endl;

        cout << "\nDeseja inserir um novo raio (1- sim, 2- nao): ";
        cin >> sair;
        if(sair == true){sair = false;} else{break;};
    }

    // Circulo Circ;
        //dessa forma, eu precisaria enviar o raio nas funções calc_perimetro e calc_area
    // while(!sair){

    //     cout << "Digite o valor do raio para o calculo da area e do perimetro: ";
    //     cin >> raio;

    //     cout << "\nArea do circulo: " << Circ.calc_area(raio) << endl;
    //     cout << "\nPerimetro do circulo: " << Circ.calc_perimetro(raio) << endl;

    //     cout << "\nDeseja inserir um novo raio (1- sim, 2- nao): ";
    //     cin >> sair;
    //     if(sair == true){sair = false;} else{break;};
    // }

    return 0;
}