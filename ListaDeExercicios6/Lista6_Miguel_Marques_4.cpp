#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

class Eq2grau
{
    // float a,b,c;
    float a,b,c,delta=0,r1,r2,m1=0,m2=0;

    public:
        Eq2grau(float A, float B, float C){
            a = A; b = B; c = C;
        }

        void gera_raizes_r_e_c(){

            cout << "\nFuncao: f(x) = " << a << "x^2" << ((b < 0)? " ": " + ") << b << "x" << ((c < 0)? " ": " + ") << c << endl;

            delta = ((b*b)-(4*a*c));
            cout << "\nDelta " << b << "^2" << "-4*" << a << "*" << c << ": " << delta << endl;

            if (delta >= 0){
                if (delta == 0){
                    r1 = (-b-sqrt(delta))/(2*a);
                    r2 = r1;
                    m1,m2 = 0,0;
                }else{
                    r1 = (-b+sqrt(delta))/(2*a);
                    r2 = (-b-sqrt(delta))/(2*a);
                    m1,m2 = 0,0;
                }
            }else{
                r1 = -b/(float(2*a));
                m1 = sqrt(abs(delta))/(2*a);
                r2 = -b/(float(2*a));
                m2 = abs(sqrt(abs(delta))/(2*a));
            }
        }

        void mostra_zeros_da_eq(){
            if (delta >= 0){
                cout << setprecision(4) << "\nR1: " << r1 << " + " << m1 << "j" << endl;
                cout << setprecision(4) << "R2: " << r2 << " + " << m2 << "j" << endl;
            }
            else{
                cout << setprecision(4) << "\nR1: " << r1 << ((a < 0)? " ": " +") << m1 << "j" << endl;
                cout << setprecision(4) << "R2: " << r2 << ((a > 0)? " - ": " +") << m2 << "j" << endl;
            }
        }
};

int main()
{
    float a,b,c;
    
    cout << "\nDigite os coeficientes:" << endl;
    cout << "\nDigite o valor de a: ";
    cin >> a;
    cout << "Digite o valor de b: ";
    cin >> b;
    cout << "Digite o valor de c: ";
    cin >> c;

    Eq2grau calcEq(a,b,c);

    calcEq.gera_raizes_r_e_c();
    calcEq.mostra_zeros_da_eq();

    return 0;
}