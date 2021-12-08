#include <iostream>
#include <cmath>

using namespace std;

inline float perimetro(float raio)
{
    return 2*M_PI*raio;
}

int main()
{
	float raio, (*p)(float);

	cout << "Digite o raio para o perimetro ser calculado" << endl;
	cin >> raio;

	p = &perimetro;

	cout << "O valor do perimetro eh " << p(raio) <<endl;

    return 0;
}