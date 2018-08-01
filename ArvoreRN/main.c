#include <stdio.h>
#include <stdlib.h>
#include "ArvoreRN.h"


int main()
{
    struct ArvoreRN arvore;

if(arvore.raiz != NULL) printf("naum null\n");

    arvore.raiz = NULL; // inicializar variavel do construtor

    if(arvore.raiz == NULL) printf("null\n");

    int i = 0;
    for(i; i<100; i++)
    {
        insereArvore(&arvore, i);
        printf("Altura da arvore %d\n", verificador(arvore.raiz));
    }

/*
    insereArvore(&arvore, 10);

    printf( "Tem o elemento? %d\n", busca(&arvore, 10) );

    printf( "Tem o elemento? %d\n", busca(&arvore, 0) );

    remover(&arvore, 11);

    remover(&arvore, 10);

    printf( "Tem o elemento? %d\n", busca(&arvore, 10) );

    printf("%d\n", verificador(arvore.raiz));*/

    printf("Hello world!\n");
    return 0;
}


int busca( struct ArvoreRN *arvore, int x )
{
    return tem(arvore->raiz, x);
}

int tem( struct Celula *celula, int x )
{
    if(celula == NULL) return 0;
    int cont = 0;

    if(celula->chave == x) cont = 1;

    cont = cont + tem(celula->filhos[0], x) + tem(celula->filhos[1], x);

    return cont;
}


int isRed( struct Celula *celula )// verifica se a celula eh vermelha
{
    return ( (celula!=NULL) && (celula->vermelha == 1) );
}

// rotação simples
struct celula *rotSimples( struct Celula *celula, int dir )
{
    struct Celula *aux = celula->filhos[!dir];

    celula->filhos[!dir] = aux->filhos[dir];
    aux->filhos[dir] = celula;

    celula->vermelha = 1;
    aux->vermelha = 0;

    return aux;
}

//rotação duplo
struct Celula *rotDupla( struct Celula *celula, int dir)
{
    celula->filhos[!dir] = rotSimples(celula->filhos[!dir], !dir);

    return rotSimples(celula, dir);
}

//verificação de propriedades da arvore, retorna 0 quando a arvore naum cumpre as propriedades ou a altura de nos pretos
int verificador ( struct Celula *root )
 {
   int lh, rh;

   if ( root == NULL )
     return 1;
   else {
     struct Celula *ln = root->filhos[0];
    struct Celula *rn = root->filhos[1];

     /* Consecutive red links */
     if ( isRed( root ) ) {
       if ( isRed( ln ) || isRed( rn ) ) {
         puts ( "Red violation" );
         return 0;
       }
     }

     lh = verificador( ln );
     rh = verificador( rn );

     /* Invalid binary search tree */
    if ( ( ln != NULL && ln->chave >= root->chave )
       || ( rn != NULL && rn->chave <= root->chave ) )
    {
      puts ( "Binary tree violation" );
      return 0;
    }

     /* Black height mismatch */
     if ( lh != 0 && rh != 0 && lh != rh ) {
       puts ( "Black violation" );
       return 0;
     }

     /* Only count black links */
     if ( lh != 0 && rh != 0 )
       return isRed( root ) ? lh : lh + 1;
     else
       return 0;
   }
 }

struct Celula *criaCelula( int chave )
{
    struct Celula *nova = malloc ( sizeof *nova );

    if(nova != NULL )
    {
        nova->chave = chave;
        nova->vermelha = 1;
        nova->filhos[0] = NULL;
        nova->filhos[1] = NULL;
    }

    return nova;
}

//inserção recursivo
struct Celula *insercao( struct Celula *celula, int chave )
{
    if(celula == NULL)
    {
        celula = criaCelula(chave);// retorna por referencia o ponteiro da celula criada
    }
    else
        {
        if(celula->chave != chave )
            {
                int dir = celula->chave < chave;

                celula->filhos[dir] = insercao(celula->filhos[dir], chave);


            if(isRed(celula->filhos[dir]))// verifica filho q inseriu
            {
                if(isRed(celula->filhos[!dir]))// verifica irmao do filho inserido
                {
                    //caso 1 - se os dois filhos sao vermelhos, troca a cor
                    celula->vermelha = 1;
                    celula->filhos[0]->vermelha = 0;
                    celula->filhos[1]->vermelha = 0;
                }
                else // caso seja preto
                {
                    //casos 2 e 3
                    if(isRed(celula->filhos[dir]->filhos[dir]))// tio preto e esta celula esta do lado mais para fora da arvore
                        celula = rotSimples(celula, !dir);// rot simples
                    else if(isRed(celula->filhos[dir]->filhos[!dir]))// rot dupla caso o filho vermelho esteja do lado mais inerior
                    celula = rotDupla(celula, !dir);
                }
            }
        }
    }
    return celula;
}


// insere comecando na raiz
int insereArvore( struct ArvoreRN *arvore, int chave )
{
    arvore->raiz = insercao( arvore->raiz, chave );
    arvore->raiz->vermelha = 0;
    return 1;
}


// remoção de nós
struct Celula *remocao ( struct Celula *root, int data, int *done )
{
 if ( root == NULL )// celula nula retorna
    *done = 1;
  else {
    int dir;

    if ( root->chave == data ) {
    if ( root->filhos[0] == NULL || root->filhos[1] == NULL ) {// caso simples de 0 ou 1 filho
        struct Celula *save =
          root->filhos[root->filhos[0] == NULL];// copia o filho naum nulo

        /* Caso 0 */
        if ( isRed( root ) )
          *done = 1;
        else if ( isRed( save ) ) {
          save->vermelha = 0;
          *done = 1;
        }

        free ( root );

        return save; // retorno a celula filho apos deletar a pai, se pai preto, faço filho preto e depois deleto pai
      }
      else {// caso de 2 filhos
        struct Celula *heir = root->filhos[0];// copia o filho da esquerda

        while ( heir->filhos[1] != NULL )// ando até o herdeiro da direita sem filho a direita
          heir = heir->filhos[1];

        root->chave = heir->chave;//copia a chave do herdeiro mais a direita na celula que deveria ser eliminada
        data = heir->chave;//copia a chave do herdeiro mais a direita
      }
    }// no caso de remocao de 2 filhos o balanceamento naum fica necessariamente correto
    // portanto naum houve *done = 1

    dir = root->chave < data;
    root->filhos[dir] = remocao( root->filhos[dir], data, done );// elimina o elemento copiado na remocao de dois filhos

    if ( !*done )
      root = remocaoBalanceamento ( root, dir, done );
  }

  return root;
}

int remover( struct ArvoreRN *tree, int data )
{
  int done = 0;

  tree->raiz = remocao( tree->raiz, data, &done );
  if ( tree->raiz != NULL )
    tree->raiz->vermelha = 0;

  return 1;
}


//remocaoBalanceamento para tratar dos casos de remocao de celulas pretas
struct Celula *remocaoBalanceamento ( struct Celula *root, int dir, int *done )
{
  struct Celula *p = root; // p - parent
  struct Celula *s = root->filhos[!dir];// irmao da celula eliminada s - sibling

  if ( s != NULL && !isRed( s ) ) {
    /* casos de irmao preto */
    if ( !isRed( s->filhos[0] ) && !isRed( s->filhos[1] ) ) {// dois filhos de sibling pretos
    if ( isRed( p ) )
        *done = 1; // caso do avo vermelho
      p->vermelha = 0;
      s->vermelha = 1;
    }
    else {
      int save = root->vermelha;// salva a cor da celula avo

      if ( isRed( s->filhos[!dir] ) )
        p = rotSimples( p, dir ); // caso de filho esquerdo de sibling ser vermelho, naum irmporta a cor do filho a direita
      else
        p = rotDupla( p, dir );// caso de filho esquerdo de sibling preto e filho direito vermelho

      p->vermelha = save;// o novo avo deve ter a mesma cor q o antigo
      p->filhos[0]->vermelha = 0;
      p->filhos[1]->vermelha = 0;
      *done = 1;
    }
  }
  else if ( s->filhos[dir] != NULL ) {// s vermelho ou NULL
    /* casos de irmao vermelho */
    struct Celula *r = s->filhos[dir];

    if ( !isRed( r->filhos[0] ) && !isRed( r->filhos[1] ) ) {// por algum motivo seu filho naum pode ser NULL
      p = rotSimples( p, dir );
      p->filhos[dir]->filhos[!dir]->vermelha = 1;
    }// resolvido caso de dois filhos de s pretos
    else {
      if ( isRed( r->filhos[dir] ) )
        s->filhos[dir] = rotSimples( r, !dir );
      p = rotDupla( p, dir );
      s->filhos[dir]->vermelha = 0;
      p->filhos[!dir]->vermelha = 1;
    }

    p->vermelha = 0;
    p->filhos[dir]->vermelha = 0;
    *done = 1;
  }

  return p;
}


