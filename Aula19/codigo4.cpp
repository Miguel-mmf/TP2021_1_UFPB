#include <iostream>

using namespace std;

int main()
{
    char c;
    char *pc;

    pc = &c;
    
    for(c = 'A'; c <= 'Z'; c++){
        cout << *pc << endl;
    }

    return 0;
}