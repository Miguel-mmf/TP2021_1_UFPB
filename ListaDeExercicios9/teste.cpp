#include <iostream>
#include <cstring>

int main()
{
    char a[100] = "Miguel Marques Ferreira";
    char b[100] ="Ferreira";
    char c[100];
    
    c = strcmp(a, b);
    std::cout << strcmp(a, b) << std::endl;
    std::cout << a-b << std::endl;

    return 0;
}