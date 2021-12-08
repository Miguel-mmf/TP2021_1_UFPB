#include <iostream> 

using namespace std;

int main()
{
	int vetor_inteiros[1000];

	int *p = vetor_inteiros;

    cout << "Tamanho do array: " << sizeof(vetor_inteiros)/sizeof(vetor_inteiros[0]) << endl;

	for(int i =0; i < sizeof(vetor_inteiros)/sizeof(vetor_inteiros[0]);i++){
		*(p+i) = i+1;
		cout << *(p+i);
        if (i < 999)
            cout  << ", ";
	}
}