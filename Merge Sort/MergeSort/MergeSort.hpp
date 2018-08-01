#ifndef _MERGESORT_HPP_
#define _MERGESORT_HPP_


template <typename T>
void mergeSort( T *vet, unsigned int tamanho );

template <typename T>
void mergeS( T *vet, T *vetaux, unsigned int esq, unsigned int meio, unsigned int dir );

template <typename T>
void merger( T *vet, T *vetaux, unsigned int esq, unsigned int meio, unsigned int dir );

template <typename T>
void mergeMSort( T *vet, unsigned int tamanho );

template <typename T>
void mergeMS( T *vet, T *vetaux, unsigned int esq, unsigned int meio, unsigned int dir );


template <typename T>
void mergeSort( T *vet, unsigned int tamanho )
{
     T *vaux = new T[tamanho];

     mergeS(vet, vaux, 0, (tamanho-1)/2, tamanho-1);
}

// separa em duas partes, organiza as partes, junta as partes de forma organizada
template <typename T>
void mergeS( T *vet, T *vetaux, unsigned int esq, unsigned int meio, unsigned int dir )
{
     if(dir <= esq) return;

     mergeS( vet, vetaux, esq, (dir+esq)/2, meio );
     mergeS( vet, vetaux, (meio+1), (meio+1+dir)/2, dir );

     merger( vet, vetaux, esq, meio, dir );
}

// junta as partes de forma organizada
template <typename T>
void merger( T *vet, T *vetaux, unsigned int esq, unsigned int meio, unsigned int dir )
{
     int i = esq;
     int j = meio+1;
     int k = i;

     while( (i <= meio) && (j <= dir) )
     {
            if( *(vet+i) < *(vet+j) )
            {
                *(vetaux+k) = *(vet+i);

                i++;
                k++;
            }
            else
            {
                *(vetaux+k) = *(vet+j);

                j++;
                k++;
            }
     }

     if(meio < i)
     {
          while( j <= dir )
          {
                 *(vetaux+k) = *(vet+j);

                 j++;
                 k++;
          }
     }
     if(dir < j)
     {
         while( i <= meio )
          {
                *(vetaux+k) = *(vet+i);

                i++;
                k++;
          }
     }

     for( i = esq; i<=dir; i++ )
     {
         *(vet+i) = *(vetaux+i);
     }
}


// Merge Melhorado --------------------------------------------------------------------
template <typename T>
void mergeMSort( T *vet, unsigned int tamanho )
{
     T *vaux = new T[tamanho];

     mergeMS(vet, vaux, 0, (tamanho-1)/2, tamanho-1);
}


// separa em duas partes, organiza as partes e
// junta as partes de forma organizada se necessário
template <typename T>
void mergeMS( T *vet, T *vetaux, unsigned int esq, unsigned int meio, unsigned int dir )
{
     if(dir <= esq) return;

     mergeMS( vet, vetaux, esq, (dir+esq)/2, meio );
     mergeMS( vet, vetaux, (meio+1), (meio+1+dir)/2, dir );

     if( *(vet+meio) > *(vet+meio+1) ) merger( vet, vetaux, esq, meio, dir );
}



#endif // _MERGESORT_HPP_
