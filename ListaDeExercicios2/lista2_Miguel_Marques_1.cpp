#include <iostream>

using namespace std;

void nome_aluno();
void contador(int);

int main(){

    nome_aluno();
    contador(20);

    return 0;
}

void nome_aluno(){
    cout << "Miguel Marques Ferreira" << endl;
}

void contador(int max){
    
    int count = 1;

    do{
        cout << count << endl;
        count++;
    }while(count < max);
}