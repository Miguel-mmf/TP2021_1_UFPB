#include <iostream>

using namespace std;

int main(){

    string texto;
    
    do{
        cout << "Digite um texto: ";
        getline(cin,texto);
        cout << "\nVoce digitou " << texto << endl;
    }while(texto != "bye");

    return 0;
}