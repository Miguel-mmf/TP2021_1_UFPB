// Imprimir o padrão
    // 1
    // 12
    // 123
    // 1234
    // 12345
    // 123456

#include <iostream>

int main(){

    int count = 1;
    int condicao = 1;

    std::cout << "Miguel Marques Ferreira\n";

    do{
        
        do{
            std::cout << count;
            count +=1;
        }while(count<=condicao);

        std::cout << "\n";
        condicao += 1;
        count = 1;
    }while(condicao<=6);

    return 0;
}