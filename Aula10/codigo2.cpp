#include <iostream>

using namespace std;

int main(){

    float nota;

    cout << "Digite a nota do aluno: ";
    cin >> nota;
    
    while (nota != 0){

        switch ((int)nota) {
            case 0:
                cout << "Se chegou aqui, tem algo paranormal no código" << endl;
                break;
            case 1: case 2: case 3: case 4:
                cout << "\nReprovado!" << endl;
                break;
            case 5: case 6:
                cout << "\nPode fazer prova final!" << endl;
                break;
            case 7: case 8: case 9: case 10:
                cout << "\nAprovado!" << endl;
                break;
            default:
                cout << "Se chegou aqui, tem algo paranormal no código" << endl;
                break;
        }

        cout << "Digite a nota do aluno: ";
        cin >> nota;
    }

    return 0;
}