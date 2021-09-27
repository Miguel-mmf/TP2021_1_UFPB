#include <iostream>
#include <cmath>
#define asterisco '*'

using namespace std;

class my_class
    {
        public:
            void gera_seq_alfabeto();
            void gera_somatorio_y();
            void gera_raizes_do_intervalo();
            void gera_pardao_num_asterisco();
            void gera_valores_fx();
            void gera_raizes_r_e_c();
    };


void my_class::gera_seq_alfabeto()
{

    char letra1,letra2;
    cout << "\nDigite a primeira letra da sequencia: ";
    cin >> letra1;
    cout << "Digite a ultima letra da sequencia: ";
    cin >> letra2;

    if (letra1 != letra2){
        
        cout << "\nSequencia: ";
        if (letra2 > letra1){
            int j = (int)letra2+1;

            for(int i=(int)letra1; i < j; i++){
                cout << char(i) << ((i == j-1)? "." : ", ");
            }
        }else{
            int j = (int)letra1+1;

            for(int i=(int)letra2; i < j; i++){
                cout << char(i) << ((i == j-1)? "." : ", ");
            }
        }
    }else{
        cout << "\n As letras sao iguais e, portanto, nao tem sequencia para ser mostrada!" << endl;
    }

    cout << "\n\n";
}

void my_class::gera_somatorio_y(){
    
    int a,b;
    cout << "\nDigite o primeiro valor do somatorio: ";
    cin >> a;
    cout << "Digite a limite superior do somatorio: ";
    cin >> b;

    if(a != b){
        int somatorio = 0;
        for(a,b;a<=b;a++){
            somatorio+=(a+3);
        }
        cout << "\nSomatorio: " << somatorio << endl;
    }else{
        cout << "\nSomatorio: " << a+3 << endl;
    }
}

void my_class::gera_raizes_do_intervalo(){

    int a,b;
    cout << "\nDigite o primeiro valor do intervalo: ";
    cin >> a;
    cout << "Digite a ultimo valor do intervalo: ";
    cin >> b;

    if(a != b){

        cout << "\n";
        for(a,b;a<=b;a++){
            cout << "Raiz quadrada de " << a << ": " << sqrt(a) << endl;
        }
    }else{
        cout << "Raiz quadrada de " << a << ": " << sqrt(a) << endl;
    }
}

void my_class::gera_pardao_num_asterisco(){

    int n;
    cout << "\nDigite o valor do n: ";
    cin >> n;

    if (n != 0){
        for(int count = n; count > 0;count--){
            for(int count2 = 1; count2<=n;count2++){
                if (count2 <= count){
                    cout << count2;
                }else{
                    cout << asterisco;
                }
                // cout << ((count2 <= count)? count2 : (char)asterisco);
            }
            cout << "\n";
        }
    }else{
        cout << "Numero menor igual a zero! Invalido!" << endl;
    }
}

void my_class::gera_valores_fx(){

    int a,b,c,Xmin,Xmax,passo;
    cout << "\nDigite os coeficientes:" << endl;
    cout << "\nDigite o valor de a: ";
    cin >> a;
    cout << "Digite o valor de b: ";
    cin >> b;
    cout << "Digite o valor de c: ";
    cin >> c;

    cout << "\nFuncao: f(x) = " << a << "x^2 + " << b << "x + " << c << endl;

    cout << "\nDigite o valor de Xmin: ";
    cin >> Xmin;
    cout << "Digite o valor de Xmax: ";
    cin >> Xmax;
    cout << "Digite o valor do passo: ";
    cin >> passo;
    cout << "\n";

    if (Xmin != Xmax && Xmin < Xmax){
        for(int i = Xmin; Xmin <= Xmax; Xmin+=passo){
            cout << "f(x=" << Xmin << ") = " << a << "x^2 + " << b << "x + " << c << ": " << a*pow(Xmin,2)+b*Xmin+c << endl;
        }
    }else{
        cout << "f(x=" << Xmin << ") = " << a << "x^2 + " << b << "x + " << c << ": " << a*pow(Xmin,2)+b*Xmin+c << endl;
        cout << "Numeros iguais! Invalido!" << endl;
    }
}

void my_class::gera_raizes_r_e_c(){

    int a,b,c,delta=0;
    cout << "\nDigite os coeficientes:" << endl;
    cout << "\nDigite o valor de a: ";
    cin >> a;
    cout << "Digite o valor de b: ";
    cin >> b;
    cout << "Digite o valor de c: ";
    cin >> c;

    cout << "\nFuncao: f(x) = " << a << "x^2" << ((b < 0)? " ": " + ") << b << "x" << ((c < 0)? " ": " + ") << c << endl;

    delta = ((b*b)-(4*a*c));
    cout << "\nDelta " << b << "^2" << "-4*" << a << "*" << c << ": " << delta << endl;

    if (delta >= 0){
        if (delta == 0){
            cout << (-b-sqrt(delta))/(2*a) << endl;
            cout << (-b+sqrt(delta))/(2*a) << endl;
        }else{
            cout << "\nRaiz x1: " << (-b+sqrt(delta))/(2*a) << endl;
            cout << "\nRaiz x2: " << (-b-sqrt(delta))/(2*a) << endl;
        }
    }else{
        cout << "\nRaiz x1: " << -b/(float(2*a)) << ((a < 0)? " ": " +") << sqrt(abs(delta))/(2*a) << "i" << endl;
        cout << "\nRaiz x2: " << -b/(float(2*a)) << ((a > 0)? " - ": " +") << abs(sqrt(abs(delta))/(2*a)) << "i" << endl;
    }
}