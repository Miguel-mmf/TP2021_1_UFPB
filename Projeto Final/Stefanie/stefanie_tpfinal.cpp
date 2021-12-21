#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int vetor1[5] = {2, 8 ,5 , 6, 9};
int vetor2[5] = {1, 2 ,3 , 4, 5};

size_t size = sizeof(vetor1)/sizeof(vetor1[0]);

float AVG(int vetor[]);
float VAR(int vetor[]);
float COV(int vetor1[], int vetor2[]);


void main(){

float rho;
rho = COV(vetor1,vetor2)/(sqrt(VAR(vetor1)*(VAR(vetor2))));
printf("%f \n", rho);

}




float AVG(int vetor[])
{
    float sum = 0;
    for (int i = 0 ; i < size; i++)
    {
        sum = sum + vetor[i];
    }
    return sum/size;
}

float VAR(int vetor[])
{
    float sum = 0;
    for (int i = 0 ; i < size ; i++)
    {
        sum = sum + ((vetor[i] - AVG(vetor))*(vetor[i] - AVG(vetor)));
    }
    return sum;
}

float COV(int vetor1[], int vetor2[])
{
   float sum = 0;
    for (int i = 0 ; i < size; i++)
    {
        sum = sum + ((vetor1[i]-AVG(vetor1))*(vetor2[i] - AVG(vetor2)));
    } 
    return sum;
}