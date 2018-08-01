#ifndef HEAPSORT_HPP_
#define HEAPSORT_HPP_

template < typename T >
void heapSort( T *vet, unsigned int tam );

template< typename T >
void heapify( T *vetor, T *pai, unsigned int n );

template< typename T >
T *troca( T *el1, T *el2 );

template< typename T >
void heaper( T *v, unsigned int tam );



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
     T *fE, *fD, *maior = pai, *aux;
     fE = ( (pai-vetor) << 1 ) + 1 + vetor;
     fD = fE + 1;

     if( ((*fE >= *fD) || (fD >= vetor + n)) && (fE <= vetor + n-1) ) maior = fE;

     if( ((*fD >= *fE) || (fE >= vetor + n)) && (fD <= vetor + n-1) ) maior = fD;

     if ( maior == pai ) return;

     if ( pai == troca( pai, maior ) ) return;

     heapify( vetor, maior , n );
}

// compara e troca os elementos e retorna o ponteiro do maior
template< typename T >
T *troca( T *el1, T *el2 )
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
    T *cont = i + v;

    for( i; i>=0; i-- )
    {
        heapify(v, cont, tam);

        cont--;
    }
}



#endif // HEAPSORT_HPP_
