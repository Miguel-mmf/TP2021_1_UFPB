//Os valores entre 1 e 100 separados por vírgula.

#include <iostream>

int main(){

    int count = 0;

    std::cout << "Miguel Marques Ferreira\n";

    do{
        std::cout << count; //<< ", "; utilizando isso, após o número 100 será acrescentado uma ,
        if (count != 100){
            std::cout << ", ";
        }
        count+=1;
    }while(count<=100);

    return 0;
}