#include <iostream>

float media(float, float);

int main(){

    float x, y, z;

    int sair = 0;

    do{
        std::cout << "Digite o primeiro valor: " << std::endl;
        std::cin >> x;

        std::cout << "Digite o segundo valor: " << std::endl;
        std::cin >> y;

        std::cout << "\nValor da Media: " << media(x,y) << std::endl;

        std::cout << "Deseja sair do programa? 0-nao    1-sim" << std::endl;
        std::cin >> sair;
        
    }while(sair != 1);

}

float media(float a, float b){
    return ((a + b)/2);
}