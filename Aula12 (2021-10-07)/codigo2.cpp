#include <iostream>

using namespace std;

int main(){

    int x = 1;
    int &y = x;

    cout << "x: " << x << endl;
    cout << "y: " << y << endl;

    y++;
    cout << "x: " << x << endl;
    cout << "y: " << y << endl;

    x = x + 10;
    cout << "x: " << x << endl;
    cout << "y: " << y << endl;
    
    return 0;
}