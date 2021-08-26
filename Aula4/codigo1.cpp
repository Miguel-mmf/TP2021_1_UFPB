#include <iostream>

int Soma(int, int); //protótipo da função soma
int Subtracao(int, int); //protótipo da função subtração

int main(){

    int num1 = 10, num2 = 10;
    int soma = Soma(num1, num2);
    int subtracao = Subtracao(num1,num2);

    std::cout << "Soma: " << soma << std::endl;
    std::cout << "Subtracao: " << subtracao << std::endl;

    return 0;
}

int Soma(int a, int b){
    return a + b;
}

int Subtracao(int a, int b){
    return a - b;
}