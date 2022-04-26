#include <iostream>
#include <ctime>

using namespace std;

int main(){
    time_t now;
    cout << now << endl;
    // cout << now/1000 << endl;
    // cout << now/60 << endl;
    time(&now)
    int data_hora_atual = localtime(&now);

    cout <<localtime(&now) << endl;
    cout << data_hora_atual->tm_hour << endl;

    return 0;
}