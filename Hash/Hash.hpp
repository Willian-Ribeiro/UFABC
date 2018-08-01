#ifndef _HASH_HPP_
#define _HASH_HPP_

#include <stdlib.h>
#include <string.h>

class Hash
{
public:
    Hash();
    ~Hash();

    bool busca(char palavra[]);
    void insere (char palavra[], unsigned int linha);
    bool remover(char palavra[]);


private:

    static const unsigned int m = 8191; // m - nº de palavras: Sedgewick - número primo logo abaixo a uma potência de 2
    unsigned int pesos[20];// tamanho maximo de uma palavra
    static const unsigned int linhasTotal = 60; // total de linhas no texto

    typedef struct struct_Celula
    {
        char *chave;
        unsigned short int linhas[linhasTotal];
        struct struct_Celula* prox = NULL;
    } Celula;

    Celula *slots[m];
    void geraPesos();
    unsigned int hashFunction(char palavra[]);
    void deletaRecursivo( Celula *&celula );
};

Hash::Hash()
{
    geraPesos();

    for(int i = 0; i<m; i++)
    {
        slots[i] = NULL;
    }
}

Hash::~Hash()
{
    for(int i = 0; i < m; i++)
    {
        deletaRecursivo(slots[i]);
    }
}

// metodo auxiliar para o destrutor, deleta todas as celulas em sequencia de modo recursivo
void Hash::deletaRecursivo( Celula *&celula )
{
    if(!celula) return;

    deletaRecursivo(celula->prox);// após delete a celula->prox aponta para NULL????
    Celula *aux = celula;
    celula = NULL;
    delete aux;
}

void Hash::geraPesos()
{
    for(int i = 0; i<20; i++)
    {
        pesos[i] = rand();
    }
}

// retorna a saida da função Hash que esta entre 0 e m
unsigned int Hash::hashFunction(char palavra[])
{
    unsigned int soma = 0;
    int i = 0;

    while(palavra[i] != '\0')
    {
        soma += pesos[i] * (unsigned int)palavra[i];
        i++;
    }

    return soma % m;
}

// se houver a palavra, imprime as linhas onde ocorre
bool Hash::busca(char palavra[])
{
    int a = hashFunction(palavra);

    Celula* procurada = slots[ a ];

    while(procurada)
    {
        if(strcmp(procurada->chave, palavra) == 0)
        {
            for(int i = 0; i < linhasTotal; i++)
            {
                if(procurada->linhas[i] != 0)
                {
                    std::cout << procurada->linhas[i] << "; ";
                }
            }
            return true;
        }

        procurada = procurada->prox;
    }

    return false;
}

void Hash::insere (char palavra[], unsigned int linha)
{

    Celula** pos = &slots[ hashFunction(palavra) ];

    while((*pos))
    {
        if( strcmp(((*pos)->chave), palavra) == 0 )// se existir a celula adiciono a linha em que ocorre
        {
            for(int j = 0; j<linhasTotal; j++)
            {
                if((*pos)->linhas[j] == 0)
                {
                    (*pos)->linhas[j] = linha;
                    return;
                }
            }
        }
        else
        {
            pos = &((*pos)->prox);
        }
    }

// caso da celula ainda naum existir
    *pos = new Celula();
    (*pos)->chave = palavra;
    for(int i = 0; i<linhasTotal; i++)// inicializo todas as celulas com todas as linhas = 0
    {
        (*pos)->linhas[i] = 0;
    }
    (*pos)->linhas[0] = linha;
}

// remove a celula dada a chave
bool Hash::remover(char palavra[])
{
    Celula** procurada = &slots[ hashFunction(palavra) ];

    while((*procurada))
    {
        if((*procurada)->chave == palavra)
        {
            Celula **aux = procurada;
            (*procurada) = (*procurada)->prox;
            delete *aux;
            return true;
        }

        procurada = &((*procurada)->prox);
    }

    return false;
}




#endif // _HASH_HPP_
