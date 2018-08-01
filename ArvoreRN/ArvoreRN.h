struct Celula
{
    int chave;
    struct Celula *filhos[2];
    int vermelha; //vermelha: 1

};

struct ArvoreRN
{
    struct Celula *raiz;
};


int isRed( struct Celula * );
struct Celula *insercao( struct Celula *, int  );
struct celula *rotSimples( struct Celula *, int  );
struct Celula *rotDupla( struct Celula *, int );
int verificador ( struct Celula * );
struct Celula *criaCelula( int  );
struct Celula *insercao( struct Celula *, int );
int insereArvore( struct ArvoreRN *, int  );// public
struct Celula *remocao ( struct Celula *, int , int * );
int remover( struct ArvoreRN *, int  );// public
struct Celula *remocaoBalanceamento ( struct Celula *, int , int * );
int busca( struct ArvoreRN *, int );// public
int tem( struct Celula *, int );
