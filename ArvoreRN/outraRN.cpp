#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

//PROTOTIPOS

//METODOS AUXILIARES
int is_red (struct jsw_node *root);
struct jsw_node *jsw_single (struct jsw_node *root, int dir);
struct jsw_node *jsw_double (struct jsw_node *root, int dir);
int jsw_rb_assert (struct jsw_node *root);
struct jsw_node *make_node (int data);

//INSERCAO
int jsw_insert (struct jsw_tree *tree, int data);//**principal**
struct jsw_node *jsw_insert_r (struct jsw_node *root, int data);

//REMOCAO
int jsw_remove (struct jsw_tree *tree, int data);//**principal**
struct jsw_node *jsw_remove_r (struct jsw_node *root, int data, int *done);
struct jsw_node *jsw_remove_balance (struct jsw_node *root, int dir, int *done);

//IMPRESSAO
void listaNoEFilhos(struct jsw_node *root);//**principal**

//BUSCA
struct jsw_node *jsw_search(int data, struct jsw_node *root);//principal

//ESTRUTURA NO
struct jsw_node {
  int red;
  int data;
struct jsw_node *link[2];
};

//ESTRUTURA ARVORE
struct jsw_tree {
  struct jsw_node *root;
};

//principal
main(){




}

//DESCRICAO DOS METODOS!

//AUXILIAR - verifica se um no e vermelho
//retorna 1 se for vermelho
int is_red(struct jsw_node *root)
{
  return ((root != NULL) && (root->red == 1));
}

//AUXILIAR - rotacao simples (direita e esquerda)
struct jsw_node *jsw_single(struct jsw_node *root, int dir)
{
  struct jsw_node *save = root->link[!dir];
  root->link[!dir] = save->link[dir];
  save->link[dir] = root;
  root->red = 1;
  save->red = 0;
  return save;
}

//AUXILIAR - rotacao dupla (direita e esquerda) -> utiliza a rotacao simples ja q dupla = 2x simples
struct jsw_node *jsw_double(struct jsw_node *root, int dir)
{
  root->link[!dir] = jsw_single(root->link[!dir], !dir);
  return jsw_single(root, dir);
}

//AUXILIAR - verifica se atende as propriedades de arvore RN
//0 = violacao
//1 = arvore vazia
//se for RN, retorna a qtd de nos negros em um caminho
int jsw_rb_assert(struct jsw_node *root)
{
   int lh, rh;

   if (root == NULL)
   	return 1;
   else {
     struct jsw_node *ln = root->link[0];
     struct jsw_node *rn = root->link[1];
     /* violacao: pai e filho sao vermelhos  */
     if (is_red(root)) {
       if (is_red(ln) || is_red(rn)) {
         cout<<"Red violation"<<endl;
         return 0;
       }
     }
     lh = jsw_rb_assert ( ln );
     rh = jsw_rb_assert ( rn );
     /* violacao: nao e mais arvore binaria de busca */
     if ((ln != NULL && ln->data >= root->data) || (rn != NULL && rn->data <= root->data))
     {
       cout<<"Binary tree violation"<<endl;
       return 0;
     }
     /* altura de caminho de nos negros imcompativel */
     if (lh != 0 && rh != 0 && lh != rh) {
       cout<<"Black violation"<<endl;
       return 0;
     }
     /* conta nos negros */
     if (lh != 0 && rh != 0)
       return is_red (root) ? lh : lh + 1;
     else
       return 0;
   }
}

//AUXILIAR - cria um no para insercao (no a ser inserido e sempre vermelho -> menos violacoes)
struct jsw_node *make_node(int data)
{
   struct jsw_node *rn = (jsw_node *)malloc(sizeof *rn);
   if (rn != NULL) {
     rn->data = data;
     rn->red = 1; /* 1 is red, 0 is black */
     rn->link[0] = NULL;
     rn->link[1] = NULL;
   }
   return rn;
}

//INSERCAO -> insere um no e trata todos os 3 casos de violacao de propriedades de arvore RN
//retorna 1 se inserido corretamente
int jsw_insert ( struct jsw_tree *tree, int data )
{
   tree->root = jsw_insert_r ( tree->root, data );
   tree->root->red = 0;
   return 1;
}
//metodo auxiliar para INSERCAO
struct jsw_node *jsw_insert_r ( struct jsw_node *root, int data )
{
   if ( root == NULL )
   root = make_node ( data );
   else if ( data != root->data ) {
     int dir = root->data < data;
     root->link[dir] = jsw_insert_r (root->link[dir], data);
   if ( is_red ( root->link[dir] ) ) {
      if ( is_red ( root->link[!dir] ) ) {
         /* caso 1 */
         root->red = 1;
         root->link[0]->red = 0;
         root->link[1]->red = 0;
       }
       else {
         /* casos 2 e 3 */
        if ( is_red ( root->link[dir]->link[dir] ) )
           root = jsw_single ( root, !dir );
         else if ( is_red ( root->link[dir]->link[!dir] ) )
           root = jsw_double ( root, !dir );
       }
     }
   }
   return root;
 }


//REMOCAO -> remove um no da arvore RN
//retorna 1 se removido corretamente
int jsw_remove ( struct jsw_tree *tree, int data )
{
   int done = 0;
   tree->root = jsw_remove_r ( tree->root, data, &done );
   if ( tree->root != NULL )
     tree->root->red = 0;
   return 1;
}
//prrimeiro metodo auxiliar para REMOCAO
struct jsw_node *jsw_remove_r ( struct jsw_node *root, int data, int *done )
{
   if ( root == NULL )
     *done = 1;
   else {
     int dir;
     if ( root->data == data ) {
       if ( root->link[0] == NULL || root->link[1] == NULL ) {
         struct jsw_node *save = root->link[root->link[0] == NULL];
         /* caso 0 */
         if ( is_red ( root ) )
           *done = 1;
         else if ( is_red ( save ) ) {
           save->red = 0;
           *done = 1;
         }
         free ( root );
         return save;
       }
       else {
         struct jsw_node *heir = root->link[0];
        while ( heir->link[1] != NULL )
           heir = heir->link[1];
         root->data = heir->data;
         data = heir->data;
       }
     }
     dir = root->data < data;
     root->link[dir] = jsw_remove_r ( root->link[dir], data, done );
     if ( !*done )
      root = jsw_remove_balance ( root, dir, done );
   }
   return root;
}
//segundo metodo auxiliar para REMOCAO -> trata todas as violacoes possiveis causadas pelo metodo de remocao anterior
struct jsw_node *jsw_remove_balance ( struct jsw_node *root, int dir, int *done )
{
struct jsw_node *p = root;
   struct jsw_node *s = root->link[!dir];
   /* reducao ao caso de remocao de filho vermelho */
   if ( is_red ( s ) ) {
     root = jsw_single ( root, dir );
     s = p->link[!dir];
   }
   if ( s != NULL ) {
     if ( !is_red ( s->link[0] ) && !is_red ( s->link[1] ) ) {
      if ( is_red ( p ) )
       *done = 1;
       p->red = 0;
       s->red = 1;
     }
     else {
       int save = p->red;
       int new_root = ( root == p );
      if ( is_red ( s->link[!dir] ) )
       p = jsw_single ( p, dir );
       else
       p = jsw_double ( p, dir );
       p->red = save;
       p->link[0]->red = 0;
       p->link[1]->red = 0;
       if ( new_root )
       root = p;
       else
       root->link[dir] = p;
       *done = 1;
     }
   }
   return root;
}

//IMPRESSAO - imprime a árvore RN inteira detalhadamente
void listaNoEFilhos(struct jsw_node *root) {
	if (root != NULL) {
		int esq =0, dir =0;
		if (root->link[0] != NULL) esq = root->link[0]->data;
		if (root->link[1] != NULL) dir = root->link[1]->data;
		cout << "No: " << root->data << ", esq: " << esq << ", dir: " << dir << ", cor: (1=rubro & 0=negro) " << root->red << endl;
		listaNoEFilhos(root->link[0]);
		listaNoEFilhos(root->link[1]);
	}
}

//BUSCA - busca uma chave (ou data) na arvore rn e retorna o no correspondente
struct jsw_node *jsw_search(int data, struct jsw_node *root) {
	if (root == NULL) {
		return NULL;
	} else if (data < root->data) {
		return jsw_search(data, root->link[0]);
	} else if (data > root->data) {
		return jsw_search(data, root->link[1]);
	} else
		return root;
}
