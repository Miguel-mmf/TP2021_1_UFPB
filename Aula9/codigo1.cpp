#include <iostream>

using namespace std;

int main(){

    char c;
    
    cout << "Digite uma letra: " << endl;
    cin >> c;

    if (c >= 'a' && c <='z' || c >= 'A' && c <= 'Z')
        cout << "Eh letra!" << endl;
    else
        cout << "Nao é letra" << endl;

    return 0;
}