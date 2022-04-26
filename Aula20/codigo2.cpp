#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    // abrindo o arquivo para escrita (de saida)
    ofstream saida("text_codigo2.txt");

    // teste para saber se o arquivo foi aberto corretamente
    if (!saida){
        cout << "O arquivo nao pode ser aberto!";
        return 1;
    }

    // salvando dados no arquivo
    saida << "Miguel" << endl;
    saida << 2021 << endl;
    saida << 20 << endl;

    saida.close();

    int idade, ano;
    char nome[100];

    // abrindo o arquivo para escrita (de saida)
    ifstream entrada("text_codigo2.txt");

    // teste para saber se o arquivo foi aberto corretamente
    if (!entrada){
        cout << "O arquivo nao pode ser aberto!";
        return 1;
    }

    entrada >> nome;
    entrada >> ano;
    entrada >> idade;

    entrada.close();

    cout << nome << " " << idade << " " << ano << endl;

    return 0;
}