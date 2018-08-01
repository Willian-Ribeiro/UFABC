#include <cstdlib>
#include <iostream>
#include <time.h>
#include "SelectSort.hpp"

using namespace std;

template< typename T >
void imprimeVet( T v[], unsigned int n );

template <typename T>
void geraVet( T *v, unsigned int n );

int main()
{
    srand( time(NULL) );
    unsigned int tamanho = 50000;
    int vet[tamanho];

    geraVet(vet, tamanho);

  //  imprimeVet(vet,tamanho);

    selectSort(vet, tamanho);

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

// gera vetor de tamanho n de valores aleatórios entre 0 e 9
template <typename T>
void geraVet( T *v, unsigned int n )
{
    for(int i=0; i<n; i++)
    {
            v[i] = rand()%10;
    }
}






