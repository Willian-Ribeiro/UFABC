#include <iostream>
#include <cstdlib>
#include <time.h>
#include "BubbleSort.h"

using namespace std;

template< typename T >
void imprime( T v[], unsigned int tamanho );

int main()
{
    srand( time( NULL));
    unsigned int tam = 50;
    int vet[tam];
    for( int i=0; i<tam; i++ )
    {
        vet[i] = rand()%15;
    }

  //  imprime(vet,tam);

    bubbleSort(vet,tam);

   // imprime(vet, tam);

    return 0;
}

// imprime vetor
template< typename T >
void imprime( T v[], unsigned int tamanho )
{
    cout << "O vetor eh:" << endl;
    for( int i=0; i<tamanho; i++ )
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
