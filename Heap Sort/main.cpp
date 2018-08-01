#include <cstdlib>
#include <iostream>
#include <time.h>
#include "HeapSort.hpp"
#include "VerificadorDeOrdem.hpp"

template< typename T >
void imprimeVet( T v[], unsigned int n );

using namespace std;

int main()
{
    srand( time(NULL) );
    unsigned int tamanho = 38000;
   // int vet[tamanho];
    unsigned long int *vet = new unsigned long int[tamanho];

    for(int i=0; i<tamanho; i++)
    {
            vet[i] = rand()%1000;
    }

    //imprimeVet(vet,tamanho);

    heapSort(vet, tamanho);
    //heapItSort<unsigned long int>(vet, tamanho);

    cout << verificaOrdem(vet, tamanho) << endl;

   // imprimeVet(vet,tamanho);

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










