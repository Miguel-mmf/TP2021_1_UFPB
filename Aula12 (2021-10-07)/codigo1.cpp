// depurando código pelo vscode
#include <iostream>

using namespace std;
void func(int);

int main(){

    int i = 10;
    
    func(i);
    cout << i << endl;
    func(i);

    return 0;
}

void func(int i){
    cout << i << endl;
    i++;
}