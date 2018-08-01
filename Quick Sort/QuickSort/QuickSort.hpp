#ifndef QUICKSORT_CPP_
#define QUICKSORT_CPP_
#include <time.h>


template <typename T>
void quickSort( T *vet, unsigned int nelem );

template <typename T>
unsigned int place( T *v, unsigned int n );

template <typename T>
unsigned int trocaMaior( T *vet, unsigned int n );

template <typename T>
unsigned int trocaMenor( T *vet, unsigned int n );

template <typename T>
void troca(T *vet, unsigned int pos1, unsigned int pos2);


// organiza um vetor de forma r�pida e recursiva
template <typename T>
void quickSort( T *vet, unsigned int nelem )
{
    if(nelem <= 1) return;

    srand( time(NULL) );
    troca( vet, 0, (rand()%nelem) );

    int npos = place(vet, nelem);

    quickSort(vet, npos);
    quickSort( (vet+npos+1), (nelem-npos-1) );
}

// posiciona o elemento � direita dos que s�o menores que ele e � esquerda dos maiores.
template <typename T>
unsigned int place( T *v, unsigned int n )
{
    int posMa = n-1;
    int posMe = 0;

    while(posMa != posMe)
    {
        posMa = posMe + trocaMaior( (v+posMe), posMa-posMe );
        posMe = posMe + trocaMenor( (v+posMe), posMa-posMe );
    }

    return posMa;
}

// verifica se os �ltimos elementos s�o maiores que o 1�, se n�o for os troca
// e retorna a posi��o
template <typename T>
unsigned int trocaMaior( T *vet, unsigned int n )
{
    for(int i=0; i<n; i++)
    {
        if(*(vet+n-i) < *vet)
        {
            troca(vet, (n-i), 0);
            return (n-i);
        }
    }

    return 0;
}

// verifica se os primeiros elementos s�o menores que o �ltimo, se n�o for, os troca
// e retorna a posi��o
template <typename T>
unsigned int trocaMenor( T *vet, unsigned int n )
{
    for(int i=0; i<n; i++)
    {
        if( *(vet+i) > *(vet+n) )
        {
            troca( vet, i, n );
            return i;
        }
    }

    return n;
}

// troca os elementos de um vetor
template <typename T>
void troca(T *vet, unsigned int pos1, unsigned int pos2)
{
    T aux = *(vet+pos1);
    *(vet+pos1) = *(vet+pos2);
    *(vet+pos2) = aux;
}


#endif // QUICKSORT_CPP_






