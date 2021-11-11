#include <iostream>

using namespace std;

template <class tipo> void calc_perimento(tipo base, tipo alt){

    // por segurança, vou considerar que o usuário envie um valor negativo para base e altura.
    if (base > 0){
            
        float aux = int(base), aux2 = int(alt);

        if ((base != aux) && (alt != aux2)){ // altura será do mesmo type que a variavel base devido o "tipo alt".
            cout << "\nValor do perimetro " << "(2xbase + 2xaltura): " << (2*base + 2*alt) << endl;
            cout << "Os valores enviados sao reais" << endl;
        }
        else if ((base == aux) && (alt == aux2)){
            cout << "\nValor do perimetro " << "(2xbase + 2xaltura): " << (2*base + 2*alt) << endl;
            cout << "Os valores enviados sao inteiros" << endl;
        }
        else{
            cout << "\nUm dos valores enviados e inteiro e o outro e real!" << endl;
        }
    }
    else{
        cout << "\nValor do perimetro " << "(2xbase + 2xaltura): " << (2*base + 2*alt) << endl;
        cout << "Os valores enviados sao reais" << endl;
    }
}