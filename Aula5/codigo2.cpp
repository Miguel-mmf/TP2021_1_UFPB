#include <iostream>
#include <iomanip>

using namespace std;

int main(){

    int x = 9;
    float int1 = 4.2;
    double INT = 6.123456789;
    
    if (x < 10)
        cout << "O valor de x eh: " << x << "\n";
    if (int1 > 4)
        cout << "O valor de int eh: " << int1 << "\n";
    if (INT <= 10)
        cout << std::setprecision(10) <<"O valor de INT eh: " << INT << "\n";
    
    return 0;
}