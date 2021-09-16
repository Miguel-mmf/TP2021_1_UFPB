#include <iostream>

using namespace std;

int main(){

    int y;

    cout << "Digite a media do aluno entre 0 e 10" << endl;
    cin >> y;

    if (y < 7){
        cout << "Reprovado!";
        cout << " Tente novamente, voce consegue." << endl;
    }else{
        if (y >= 9)
            cout << "Aprovado e Parabens!" << endl;
        else
            cout << "Aprovado!" << endl;
    }

    return 0;
}