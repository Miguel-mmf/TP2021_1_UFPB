#include <iostream>
#include <cmath>

using namespace std;

class Equacao
{
        float a, b, c;
    public:

        Equacao(){
            a=1;
            b=1;
            c=1;
        }

        Equacao(float A, float B, float C){
            a=A;
            b=B;
            c=C;
        }

        void setvalores(float A, float B, float C){
            a=A;
            b=B;
            c=C;
        }

        void mostraFx(float Xmin, float Xmax, float passo);
        void zerosFx();
};


void Equacao::mostraFx(float Xmin, float Xmax, float passo)
{
    float valor;

    while(Xmin <= Xmax){
        valor = (a*pow(Xmin,2) + b*Xmin + c);
        cout << "F(" << Xmin << ") = " << valor << endl;
        Xmin+=passo;
    }
}

void Equacao::zerosFx(){
    float delta;

    delta = pow(b,2) - 4*a*c;
    if (a == 0){
        cout << "Raiz: " << ((-c)/b) << endl;
    }
    else{
        if (delta == 0)
            cout << "Ambas as raizes possuem valor igual a " << -b/(2*a) << " para o delta igual a 0." << endl;
        else if (delta > 0){
            float x1 = (-b + sqrt(delta))/(2*a);
            float x2 = (-b - sqrt(delta))/(2*a);

            cout << "Raiz 1: " << x1 << endl;
            cout << "Raiz 2: " << x2 << endl;
        }
        else if (delta < 0){
            float x = (-b)/(2*a);

            cout << "Raiz 1: " << x << " - " << sqrt(delta*(-1))/(2*a) << "i" << endl;
            cout << "Raiz 2: " << x << " + " << (-1)*sqrt(delta*(-1))/(2*a) << "i" << endl;
        }
    }
}


int main()
{
    int opcoes, sair = 0;

    while (sair != 1){
        cout << "Escolha uma das opcoes: 1- Opcao 1; 2- Opcao 2; 3- Opcao 1; 4- Opcao 1; 5- Retornar a tela inicial;" << endl;
        cin >> opcoes;

        switch(opcoes){

            case 1:
            {
                int count=0, sum=0, max=0, min=100000, num;
                while(true){

                    cout << "Digite um valor: ";
                    cin >> num;
                    
                    if (num > max) max = num;
                    if (num < min) min = num;
                    
                    sum+=num;
                    count++;

                    if (num == 0){
                        cout << "Media: " << float(sum/count) << endl;
                        cout << "Maior valor: " << max << endl;
                        cout << "Menor valor: " << min << endl;
                        break;
                    }
                }
                break;
            };
            
            case 2:
            {
                float a, b, c, Xmin, Xmax, passo;
                cout << "Digite os coeficientes a, b e c: ";
                cin >> a >> b >> c;

                Equacao Eq(a,b,c);
                cout << "Digite o valor Xmin, Xmax e o passo: ";
                cin >> Xmin >> Xmax >> passo;

                Eq.mostraFx(Xmin, Xmax, passo);

                cout << "Raizes" << endl;

                Eq.zerosFx();

                break;
            }
            
            case 3:
            {
                int n;
                cout << "Quanto elementos no array: ";
                cin >> n;

                Equacao Eqs[n];

                float a, b, c;

                for(int i = 0; i < n; i++){
                    cout << "Digite os coeficientes a, b e c: ";
                    cin >> a >> b >> c;

                    Eqs[i].setvalores(a,b,c);
                }

                for(int i = 0; i < n; i++){

                    cout << endl;

                    Eqs[i].zerosFx();
                }

                break;
            }

            case 4:
            {

                break;
            }

            case 5:
            {
                cout << "De volta a tela inicial!" << endl;
                break;
            }

            default:
                return 0;
        }
    }

    return 0;
}