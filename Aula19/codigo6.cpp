#include <iostream>

using namespace std;

int main()
{
    // um array já é em si um ponteiro
    int lista[] = {0,1,2,3,4,5};

    cout << lista[1] << endl;
    cout << *lista << endl; // posição 0
    cout << *(lista + 1) << endl; // posição 1
    cout << *(lista + 5) << endl; // posposiçúltima posição

    cout << "Acessando elementos de arrau por ponteiro: " << endl; //
    for (int i=0; i<6; i++){
        cout << *(lista + i) << endl;
    }

    return 0;
}