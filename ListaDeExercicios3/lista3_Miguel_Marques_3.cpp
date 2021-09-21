#include <iostream>

using namespace std;
int calc_Req_paralelo(float, float);

int main(){

    float R1, R2, Req;

    cout << "Digite o valor da primeira resistencia: ";
    cin >> R1;
    cout << "Digite o valor da segunda resistencia: ";
    cin >> R2;
    
    Req = calc_Req_paralelo(R1,R2);
    cout << "Para as resistencias " << R1 << " e " << R2 << endl;
    cout << "Resistencia equivalente em paralelo: " << Req << endl;
    cout << "\nQuando uma tensao de 5V e aplicada na resistencia equivalente, a corrente que passa em Req e de " << 5/Req << " A." << endl;

    return 0;
}

int calc_Req_paralelo(float r1, float r2){
    return ((r1*r2)/(r1+r2));
}