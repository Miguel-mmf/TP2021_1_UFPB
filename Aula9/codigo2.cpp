#include <iostream>

using namespace std;

int main(){

    int y,x=3;

    y = ++x*x--; // 4(incremento prefixado)*3(decremento pós-fixado)
    cout << x << endl;
    cout << y << endl;

    x = 3;
    y = x++; // x será 4, y será 3
    cout << y << endl;

    y = ++x; // x será 4, y será 5
    cout << y << endl;

    return 0;
}