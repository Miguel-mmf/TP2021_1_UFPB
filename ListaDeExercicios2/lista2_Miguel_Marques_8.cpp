#include <iostream>

using namespace std;

namespace maria {
    int idade = 18;
    float cre = 8.3;
    void incrementar_idade() { idade++; }
}

namespace jose {
    int idade = 21;
    float cre = 4.3;
}

namespace miguel {
    int idade = 20;
    int  ano_nascimento = 2001;
    string  mes_nascimento = "Marco";
    int  dia_nascimento = 8;
    char primeira_letra_nome('M');

    void _0_ate_idade(int max){

        string  teste = "";    
        int count = 1;

        do{
            cout << teste << count << endl;
            count++;
            teste+="-";
        }while(count <= max);
    }
}

int main(){

    cout << maria::idade << endl;
    maria:: incrementar_idade();
    cout << maria::idade << endl;
    cout << "------------------------------------------------" << endl;
    cout << miguel::idade << endl;
    cout << miguel::ano_nascimento << endl;
    cout << miguel::mes_nascimento << endl;
    cout << miguel::dia_nascimento << endl;
    cout << miguel::primeira_letra_nome << endl;

    miguel::_0_ate_idade(miguel::idade);

    return 0;
}