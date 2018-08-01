#ifndef BUBBLESORT_H_
#define BUBBLESORT_H_

template< typename T >
void bubbleSort( T vet[], unsigned int tamanho );



template< typename T >
void bubbleSort( T vet[], unsigned int tamanho )
{
    if( tamanho <= 1 ) return;

    T aux;
    bool para = true;

    for( int i=0; i<(tamanho-1); i++ )
    {
        if( vet[i] > vet[i+1] )
        {
            aux = vet[i];
            vet[i] = vet[i+1];
            vet[i+1] = aux;
            para = false;
        }
    }
    if( para == true ) return;

    bubbleSort( vet, tamanho-1 );
}






#endif // BUBBLESORT_H_
