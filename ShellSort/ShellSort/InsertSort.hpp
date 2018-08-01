#ifndef INSERTSORT_HPP_
#define INSERTSORT_HPP_


template <typename T>
void insertSort( T *vetor, unsigned int tamanho );


template <typename T>
void insertSort( T *vetor, unsigned int tamanho )
{
    T aux;
    unsigned int incremento = 1;

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

#endif // INSERTSORT_HPP_
