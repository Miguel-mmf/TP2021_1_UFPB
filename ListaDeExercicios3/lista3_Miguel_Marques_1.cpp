#include <iostream>

using namespace std;

int main(){

    int num1, num2;

    cout << "Digite um valor: ";
    cin >> num1;
    cout << "Digite um segundo valor: ";
    cin >> num2;

    if (num1 != num2)
        if (num1 > num2)
            cout << "\n" << num1 << " eh maior que " << num2 << endl;
        else
            cout << "\n" << num2 << " eh maior que " << num1 << endl;
    else
        cout << "\n" << num1 << " eh igual a " << num2 << endl;


    return 0;
}