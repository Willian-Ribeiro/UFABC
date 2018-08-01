#ifndef VERIFICADORDEORDEM_HPP_
#define VERIFICADORDEORDEM_HPP_


template <typename T>
bool verificaOrdem( T *vetor, unsigned int tamanho );


template <typename T>
bool verificaOrdem( T *vetor, unsigned int tamanho )
{
    for( int i=1; i<tamanho; i++ )
    {
        if( *( vetor+i-1 ) > *( vetor+i ) ) return false;
    }

    return true;
}

#endif // VERIFICADORDEORDEM_HPP_
