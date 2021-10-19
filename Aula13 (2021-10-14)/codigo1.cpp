#include <iostream>
#include <ctime>

using namespace std;

inline void delay(clock_t sec){
    clock_t start_time = clock();
    clock_t end_time = sec*1000 + start_time;

    while(clock() <= end_time);
}

int main(){

    cout << "Inicio" << endl;
    delay(5);
    cout << "\nFim!" << endl;

    return 0;
}