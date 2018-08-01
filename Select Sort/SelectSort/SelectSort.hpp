#ifndef SELECTSORT_HPP_
#define SELECTSORT_HPP_



template <typename T>
void selectSort( T *vet, unsigned int tam );

template <typename T>
T *seleMaior( T *v, unsigned int n );



template <typename T>
void selectSort( T *vet, unsigned int tam )
{
    T *aux, auxi;

    for( int i=0; i<tam; i++ )
    {
        aux = seleMaior(vet, tam-i);

        auxi = *aux;
        *aux = *( vet+tam-1-i );
        *( vet+tam-1-i ) = auxi;
    }
}

// seleciona o ponteiro do maior valor e o retorna
template <typename T>
T *seleMaior( T *v, unsigned int n )
{
    T *maior = v;

    for( int i=0; i<n; i++ )
    {
        if( *maior < *(v+i) ) maior = ( v+i );

    }

    return maior;
}

#endif // SELECTSORT_HPP_
