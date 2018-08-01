#ifndef _SHELLSORT_HPP
#define _SHELLSORT_HPP


template <typename T>
void insertSort( T *vetor, unsigned int incremento, unsigned int tamanho );

template <typename T>
void shellSort( T *vetor, unsigned int tamanho )
{
    int i = tamanho;
    while( i!= 1 )
    {
        i = (i>>1);

        insertSort(vetor, i, tamanho);
    }

}

// insert sort de incremento variavel
template <typename T>
void insertSort( T *vetor, unsigned int incremento, unsigned int tamanho )
{
    T aux;

    for(int i = incremento; i<tamanho; i++)
    {
        aux = *(vetor+i);

        for( int j = (i-incremento); j>=0; (j -= incremento) )
        {
            if( *(vetor+j) > aux )
            {
                *(vetor+j+incremento) = *(vetor+j);
                if( (vetor+j-incremento) < vetor ) *(vetor+j) = aux;
            }
            else
            {
                *(vetor+j+incremento) = aux;
                break;
            }
        }
    }
}














#endif // _SHELLSORT_HPP
