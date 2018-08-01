#include <cstdlib>
#include <iostream>
#include <time.h>
#include "MergeSort.hpp"
#include "VerificadorDeOrdem.hpp"

template< typename T >
void imprimeVet( T v[], unsigned int n );

using namespace std;

int main()
{
    srand( time(NULL) );
    unsigned int tamanho = 500000;
    int *vet = new int[tamanho];

    for(int i=0; i<tamanho; i++)
    {
            vet[i] = rand()%10;
         //   vet[i] = i;
    }

   // imprimeVet(vet, tamanho);

    mergeMSort(vet, tamanho);

   // imprimeVet(vet, tamanho);

    cout << "Se igual a 1 a ordem esta correta: " << verificaOrdem(vet, tamanho) << endl;

    return 0;
}


// imprime vetor
template< typename T >
void imprimeVet( T v[], unsigned int n )
{
     cout << "O vetor eh:" << endl;

     for(int i=0; i<n; i++)
    {
            cout << v[i] << " ";
    }
     cout << endl;
}




