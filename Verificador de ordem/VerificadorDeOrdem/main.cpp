#include <cstdlib>
#include <iostream>
#include <time.h>
#include "VerificadorDeOrdem.hpp"

using namespace std;

template< typename T >
void imprimeVet( T v[], unsigned int n );

template <typename T>
void geraVet( T *v, unsigned int n );

string interpreta( bool a );


int main()
{
    srand( time(NULL) );
    unsigned int tamanho = 810;
  //  int vet[tamanho];
    int *vetor = new int[tamanho];

    geraVet(vetor, tamanho);

    imprimeVet(vetor,tamanho);

    cout << "O vetor esta ordenado? " << interpreta( verificaOrdem(vet, tamanho) ) << endl;

    imprimeVet(vet, tamanho);

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

// interpreta bool para string
string interpreta( bool a )
{
    if( a == true ) return "sim";

    return "nao";
}


