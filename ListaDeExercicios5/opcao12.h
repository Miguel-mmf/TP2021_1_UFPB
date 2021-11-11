#include <iostream>
#include <cmath>

using namespace std;

template <class tipo2> tipo2 converte_grau_para_rad(tipo2 angulo_grau)
{
    return (angulo_grau*M_PI)/180;
}


template <class tipo> void calc_sin_cos(tipo ang)
{
    cout << "\nAngulo 1: " << ang << endl;
    cout << "Seno do angulo " << ang << ": " << sin(converte_grau_para_rad(ang)) << endl;
    cout << "Cosseno do angulo " << ang << ": " << cos(converte_grau_para_rad(ang)) << endl;
    cout << "Tangente do angulo " << ang << ": " << tan(converte_grau_para_rad(ang)) << endl;
}