#include <cstdlib>
#include <iostream>
#include <time.h>
#include "InsertSort.hpp"

template< typename T >
void imprimeVet( T v[], unsigned int n );

using namespace std;

int main()
{
    srand( time(NULL) );
    unsigned int tamanho = 500;
    int vet[tamanho];

    for(int i=0; i<tamanho; i++)
    {
            vet[i] = rand()%10;
         //   vet[i] = i;
    }

   // imprimeVet(vet, tamanho);

    insertSort(vet, tamanho);

   // imprimeVet(vet, tamanho);

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




