#include <iostream>

using namespace std;

int teste(int);
int teste(int,int);
float teste(float,float);

int main()
{

    int x = 10, y = 20;
    float z = 10;

    cout << teste(x) << endl;
    cout << teste(x,y) << endl;
    cout << teste(z,z) << endl;

    return 0;
}

int teste(int num)
{
    return num*num;
}

int teste(int num1,int num2)
{
    return num1*num2;
}

float teste(float num1,float num2)
{
    return (num1*num2)/2;
}