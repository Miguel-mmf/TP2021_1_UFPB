#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    // abrindo o arquivo para escrita (de saida)
    ofstream saida("text_codigo1.txt");

    // teste para saber se o arquivo foi aberto corretamente
    if (!saida){
        cout << "O arquivo nao pode ser aberto!";
        return 1;
    }

    // salvando dados no arquivo
    saida << "Miguel" << endl;
    saida << 2021 << endl;
    saida << "Numero em linha com " << 2021 << " sem o endl no fim" << endl;

    saida.close();
    
    return 0;
}