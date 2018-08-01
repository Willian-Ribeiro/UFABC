#ifndef HEAPSORT_HPP_
#define HEAPSORT_HPP_

using namespace std;
template < typename T >
void heapSort( T *vet, unsigned int tam );

template < typename T >
void heapItSort( T *vet, unsigned int tam );

template< typename T >
void heapify( T *vetor, T *pai, unsigned int n );

template< typename T >
void heapifyIt( T *vetor, T *pai, unsigned int n );

template< typename T >
T* troca( T *el1, T *el2 );

template< typename T >
void heaper( T *v, unsigned int tam );

template< typename T >
void heaperIt( T *v, unsigned int tam );



template < typename T >
void heapSort( T *vet, unsigned int tam )
{
    heaper(vet, tam);
    T aux;

    for( tam; tam>1; tam-- )
    {
        aux = *vet;
        *vet = *( vet+tam-1 );
        *( vet+tam-1 ) = aux;

        heapify(vet, vet, tam-1);
    }
}

// realiza trocas de modo a voltar para a estrutura Heap
template< typename T >
void heapify( T *vetor, T *pai, unsigned int n )
{
     T *fE, *fD, *maior = pai;

     fE = (((pai-vetor) << 1 ) + 1 + vetor );

        if( fE > (vetor + n-1) ) return;

        fD = fE + 1;

        if( fD <= (vetor + n-1) )
        {
            if( *fE >= *fD ) maior = fE;
            else maior = fD;
        }
        else maior = fE;

        if ( pai == (troca( pai, maior )) ) return;

     heapify( vetor, maior , n );
}

// compara e troca os elementos e retorna o ponteiro do maior
template< typename T >
T* troca( T *el1, T *el2 )
{

     if( *el1 < *el2 )
     {
         T aux = *el1;
         *el1 = *el2;
         *el2 = aux;
         return el2;
     }

     return el1;
}

// deixa o vetor no formato Heap
template< typename T >
void heaper( T *v, unsigned int tam )
{
    int i = (tam>>1) - 1;
    T *cont;

    for( i; i>=0; i-- )
    {
        cont = i + v;

        heapify(v, cont, tam);
    }
}



// heap sort iterativo ---------------------------------------------------------------
template < typename T >
void heapItSort( T *vet, unsigned int tam )
{
    heaper(vet, tam);
    T aux;

    for( tam; tam>1; tam-- )
    {
        aux = *vet;
        *vet = *( vet+tam-1 );
        *( vet+tam-1 ) = aux;

        heapifyIt(vet, vet, tam-1);
    }
}

// heapify iterativo
template <typename T>
void heapifyIt( T *vetor, T *pai, unsigned int n )
{
     T *fE, *fD, *maior, *aux;

     while(true)
     {
        maior = pai;

        fE = (((pai-vetor) << 1 ) + 1 + vetor );

        if( fE > (vetor + n-1) ) return;

        fD = fE + 1;

        if( fD <= (vetor + n-1) )
        {
            if( *fE >= *fD ) maior = fE;
            else maior = fD;
        }
        else maior = fE;

        if ( pai == (troca( pai, maior )) ) return;

        pai = maior;
     }
}

// deixa o vetor no formato Heap
template< typename T >
void heaperIt( T *v, unsigned int tam )
{
    int i = (tam>>1) - 1;
    T *cont;

    for( i; i>=0; i-- )
    {
        cont = i + v;

        heapifyIt(v, cont, tam);
    }
}



#endif // HEAPSORT_HPP_
