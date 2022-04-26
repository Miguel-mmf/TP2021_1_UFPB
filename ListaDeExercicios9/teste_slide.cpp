#include <iostream>
#include <fstream>
#include <iomanip> // Para manipuladores de stream: setw, left, etc.
#include <string>
using namespace std;
int main(){
    int n=1;
    string Nome;
    ofstream Saida;
    Saida.open("saida2.txt");
    if (!Saida) {cout << "Erro!" << endl; return 1;}
    while(1){
        cout << "Entre com o primeiro nome do aluno (digite 0 para sair): " << endl;
        getline(cin, Nome);
        if (Nome == "0") break;
        
        Nome.resize(30, ' ');
        Saida << left << setw(10) << n++ << setw(30) << Nome << endl;
    }
    return 0;
}