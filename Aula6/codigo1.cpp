#include <iostream>

using namespace std;

int main(){

    for (int i=0; i < 10; i++){
        cout << dec << i << " --- ";
        cout << hex << i << " --- ";
        cout << oct << i << endl;
    }

    cout << "\a" << endl;

    return 0;
}