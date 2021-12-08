#include <iostream>

using namespace std;
void imprime_array(int [][10]);

int matriz[10][10]; // matriz inicializada com zeros

int main()
{
	int (*p)[10];
	p = matriz;
	
    cout << "Matriz de zeros original" << endl;
	imprime_array(matriz);

	int value = 1;
	
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++, value++){
			p[i][j] = value;
		}
	}

    cout << "\nMatriz de preenchida" << endl;
    imprime_array(p);
}

void imprime_array(int array[10][10]){

    cout << "[";

    for(int i=0; i < 10; i++){
        cout << "[";
        for(int j=0; j < 10; j++){
            cout << array[i][j];
            if (j!=9){cout << ", ";}
        }
        cout << "]";
        if (i!=9){cout << "\n";}
    }
    cout << "]";
}