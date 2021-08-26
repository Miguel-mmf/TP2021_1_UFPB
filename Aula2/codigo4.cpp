#include <iostream>

int main(){

    int count=0;
    int  valMax;
    std::cout <<  "Digite a quantidade de repetições: \n";
    std::cin >> valMax;

    do{
        count +=1;
        std::cout << count << "         Vai parar em " << valMax << "\n";
    }while(count < valMax);

    return 0;
}