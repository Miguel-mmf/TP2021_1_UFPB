#include <iostream>

using namespace std;

int main()
{
    // formas de declarar um array bidimensional
    int tabela[2][3] = {0,1,2,3,4,5};
    int tabela2[2][3] = {
        {0,1,2},
        {3,4,5}
    };

    for(int i=0; i < 2; i++){
        for(int j=0; j < 3; j++){
            cout << "Tabela[" << i << "][" << j << "]: " << tabela[i][j];
            cout << " --- Tabela2[" << i << "][" << j << "]: " << tabela[i][j] << endl;
        }
    }

    cout << "Tamanho do array bidimensional tabela[2][3]: " << sizeof(tabela) << endl;
    cout << "Tamanho do array bidimensional tabela2[2][3]: " << sizeof(tabela2) << endl;

    return 0;
}