#include <iostream>

using namespace std;
void troca1(int x, int y);
void troca2(int& x, int& y);

int main(){

    int x=4, y=7;

    cout << x << " " << y << endl;
    troca1(x,y);
    cout << x << " " << y << endl;
    troca2(x,y);
    cout << x << " " << y << endl;

    return 0;
}


void troca1(int x, int y){
    int temp;
    temp = x;
    x = y;
    y = temp;
}

void troca2(int& x, int& y){
    int temp;
    temp = x;
    x = y;
    y = temp;
}