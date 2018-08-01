#ifndef INSERTSORT_HPP_
#define INSERTSORT_HPP_


template <typename T>
void insertSort( T *vetor, unsigned int tamanho );


template <typename T>
void insertSort( T *vetor, unsigned int tamanho )
{
    T aux;

    for(int i=1; i<tamanho; i++)
    {
        aux = *(vetor + i);

        for(int j=(i-1); j>=0; j--)
        {
            if( *(vetor+j) > aux )
            {
                *(vetor+j+1) = *(vetor+j);
                if((vetor+j) == vetor) *vetor = aux;
            }
            else
            {
                *(vetor+j+1) = aux;
                break;
            }
        }
    }
}


#endif // INSERTSORT_HPP_
