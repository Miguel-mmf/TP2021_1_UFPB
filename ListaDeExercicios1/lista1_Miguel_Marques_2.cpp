// Seu nome completo e os números entre 0 e sua idade na mesma linha.

#include <iostream>

int main(){

    int count = 0;

    std::cout << "Miguel Marques Ferreira ";

    do{
        std::cout << count << " ";
        count+=1;
    }while(count<=20);

    return 0;
}