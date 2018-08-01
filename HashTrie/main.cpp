#include<iostream>
#include<string>
#include<stdlib.h>
#include<fstream>


using namespace std;
//Numero de letras no alfabeto
#define NUM_CHILDREN 26

typedef struct No *Apontador;
typedef struct No {
	bool terminal;
	Apontador pont[26];
	} NoTrie;

Apontador raiz; // raiz da árvore
char alfabeto[NUM_CHILDREN] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
int l,pos;
char str[100];
void insere(char chave[]);// public
void insereReg(char chave[], Apontador p);
NoTrie* buscaReg(char chave[], Apontador p, int *a);
int buscaBinRec(char vetor[],int ini,int fim,char pesq);
int length(char input[]);
void remove(char chave[]);
bool removeReg(char chave[], Apontador p);
void busca(char chave[]);// public


#include "Hash.hpp"
void printAllFromPrefix(NoTrie * pt, string prefix);

void readFile(  );
Hash tabela;

main(){
	char chave[100];
/*	strcpy(chave,"algorithm");
	insere(chave);
	strcpy(chave,"application");
	insere(chave);
	strcpy(chave,"test");
	insere(chave);
	strcpy(chave,"testing");
	insere(chave);
	pos=0;
	cout << "ÁRVORE EM PRÉ-ORDEM" << endl;
	printAllFromPrefix(raiz, "");

	strcpy(chave,"testing");
	busca(chave);
	remove(chave);
	pos=0;
	cout << "ÁRVORE EM PRÉ-ORDEM" << endl;
	printAllFromPrefix(raiz, "");

	strcpy(chave,"test");
	remove(chave);
	pos=0;
	cout << "ÁRVORE EM PRÉ-ORDEM" << endl;
	printAllFromPrefix(raiz, "");


	strcpy(chave,"algorithm");
	remove(chave);
	pos=0;
	cout << "ÁRVORE EM PRÉ-ORDEM" << endl;
	printAllFromPrefix(raiz, "");


	strcpy(chave,"application");
	remove(chave);
	pos=0;
	cout << "ÁRVORE EM PRÉ-ORDEM" << endl;
	printAllFromPrefix(raiz, "");*/

    //Hash tabela;
    readFile();


    cout << "O q deseja fazer? \n";

    int op1 = 0;
    char palavra[100];
    while(op1 != 10)
    {
        op1 = 0;
        cout << "1 - Saber qual linha a palavra desejada está\n";
        cout << "2 - Saber as linhas de todas as palavras\n 10 - Sair\n";
        cin >> op1;

        switch(op1)
        {
        case 1:
            cout << "Qual a palavra?\n";
            cin >> palavra;
            tabela.busca(palavra);
            break;
        case 2:
            printAllFromPrefix(raiz, "");
            break;
        case 10:
            cout << "Tchau\n";
            op1 = 10;
            break;
        default:
            cout << "Tente novamente\n";
            break;
        }
    }
cout << "Hashing sozinho funciona, quando leio do texto deve haver alguma alteração da palavra q faz com q busque por algo diferente do inserido\n";
    cout << "Qual a palavra?\n";
            cin >> palavra;
            tabela.insere(palavra, 200);
            tabela.busca(palavra);
            tabela.busca("oi");




}


void readFile()
{
    string linha; // linha a ser copiada
    string palavra;// palavra copiada;
    string dots = ".,", space = " ";
    int nLinha = 0, temp;


    ifstream arquivo;
    arquivo.open("teste.txt", ios::in);//ios in pois soh preciso ler input operations
    if(arquivo.is_open())
    {
        while(arquivo.good())// good indica se a linha eh legivel
        {
            nLinha++;
            getline(arquivo, linha);
            // vou pular linhas de espaçamento - espaçamento conta como um char na linha?
            while(linha.length() > 1)
            {
                temp = -1;
                for(int ite = 0; ite < linha.length(); ite++) // retorna o numero do char antes do espaço
                {
                    if(linha[ite] == space[0])
                    {
                        temp = ite;
                        break;
                    }
                }
                if(temp != -1)// -1 igual a npos?
                {
                    palavra = linha.substr(0, temp-1);
                    // remoção de pontos
                    if( (palavra[palavra.length()] == dots[0] ) || (palavra[palavra.length()] == dots[1] ) )
                        palavra = palavra.substr(0, (palavra.length()-1) );
                    linha = linha.substr(temp+1);// do char seguinte ao espaço ateh o final
                }
                else
                {
                    palavra = linha;
                    if( (palavra[palavra.length()] == dots[0] ) || (palavra[palavra.length()] == dots[1] ) )
                        palavra = palavra.substr(0, (palavra.length()-1) );
                    linha = linha.substr(linha.length());// copio ateh ultimo elemento
                }

                char word[palavra.length()];
                cout << "A palavra copiada foi: " << palavra << endl;// vou adicionar as coisas aqui
                for(int it = 0; it < palavra.length(); it++)
                {
                    palavra[it] = tolower(palavra[it]);
                    word[it] = palavra[it];
                }

                cout << "A palavra minuscula eh: " << palavra << endl;// vou adicionar as coisas aqui

                insere(word);
                tabela.insere(word, nLinha);
            }
        }
        arquivo.close();
    } else cout << "Naum deu para abrir o arquivo" << endl;
}










// verifica se chave já existe, caso contrário chama insereReg para inserir
void insere(char chave[]) {
	int a=0;
	l = -1;
	if (raiz == NULL) {
		raiz = (Apontador) malloc(sizeof(NoTrie));
		for(int i=0; i<NUM_CHILDREN; i++) raiz->pont[i]=NULL;
	}
	Apontador pt = buscaReg(chave,raiz,&a);
	if (a == 0) { // não achou chave na Árvore, pode inserir
		insereReg(chave, pt);
	} else {
		cout << "Inclusão inválida!" << endl;
	}
}

// insere chave na árvore
void insereReg(char chave[], Apontador p) {
	for (int h = l + 1; h < length(chave); h++) {
		int j = buscaBinRec(alfabeto,0,NUM_CHILDREN-1,chave[h]);
		Apontador ptz = (Apontador) malloc(sizeof(NoTrie));
		for(int i=0; i<26; i++) ptz->pont[i]=NULL;
		ptz->terminal = false;
		p->pont[j] = ptz;
		p = ptz;
	}
	p->terminal = true;
}

// procura uma chave na lista
NoTrie* buscaReg(char chave[], Apontador p, int *a) {
	if (l < length(chave) - 1) {
		int j = buscaBinRec(alfabeto,0,NUM_CHILDREN-1,chave[l+1]);
		if (p->pont[j] != NULL) {
			p = p->pont[j];
			l++;
			p = buscaReg(chave, p, a);
		}
	} else { // achou e é palavra terminal
		if (p->terminal == true) *a = 1;
	}
	return p;
}

void busca(char chave[]) {
	int a = 0;
	if (raiz != NULL) {
		l = -1;
		Apontador p = buscaReg(chave, raiz, &a);
	}
	if (a==0){
		cout << "Chave não está na árvore!" << endl;
	} else {
		cout << "Chave está na árvore!" << endl;
	}
}

// faz busca binária recursiva
int buscaBinRec(char vetor[],int ini,int fim,char pesq) {
	while(ini<=fim) {
		int meio;
		meio=(ini+fim)/2;
		if(vetor[meio]==pesq){
			return meio;
		} else if (vetor[meio]<pesq) {
			return buscaBinRec(vetor,meio+1,fim,pesq);
		} else {
			return buscaBinRec(vetor,ini,meio-1,pesq);
		}
	}
	return -1;
}

// determina comprimento de uma string (somente caracteres válidos)
int length(char input[]){
    int length = 0;
    while(input[length]!='\0'){
        length++;
    }
	return length;
}

/* lista todas chaves em modo pré-ordem. str e pos são variáveis globais. pos é inicializada com 0 antes da chamada do método*/
void preordem(Apontador p) {
	if (p != NULL) {
		for (int i = 0; i < NUM_CHILDREN; i++) {
			if (p->pont[i] != NULL) {
				str[pos] = alfabeto[i]; pos++;
				preordem(p->pont[i]);
			}
		}
		if (p->terminal) {
			cout << str << endl;
			pos--; str[pos] = '\0';
		} else {
			pos--; str[pos] = '\0';
		}
	}
}

// remove um nó
void remove(char chave[]) {
	int a = 0;
	cout << endl << "REMOVENDO: " << chave << endl << endl;
	if (raiz != NULL) {
		l = -1;
		Apontador pt = buscaReg(chave,raiz,&a);
		if (a == 0) { // não achou chave na Árvore, pode inserir
			cout << "Remoção inválida!" << endl;
		} else {
			l=-1;
			bool ok = removeReg(chave,raiz);
		}
	}
}

// remove um no
bool removeReg(char chave[], Apontador p) {
	bool ok = false;
	int cont = 0;
	if (l < length(chave) - 1) {
		int j = buscaBinRec(alfabeto,0,NUM_CHILDREN-1,chave[l+1]);
		if (p->pont[j] != NULL) {
			l++;
			ok = removeReg(chave, p->pont[j]);
			if (ok) { // checar se há outros ponteiros filhos de p, caso contrário remover p também (recursivamente)
				if (p->terminal) {
					ok=false;
				} else {
					free(p->pont[j]);
					p->pont[j] = NULL;
					for (int i = 0; i < NUM_CHILDREN; i++) {
						if (p->pont[i] != NULL) {
							cont++;
						}
					}
					if (cont > 0) {
						ok = false;
					}
				}
			}
		}
	} else { // achou e e' palavra terminal
		if (p->terminal) {
			p->terminal=false;
			for (int i = 0; i < NUM_CHILDREN; i++) { // checa se tem filhos
				if (p->pont[i] != NULL) {
					cont++;
				}
			}
			if (cont > 0) {
				ok = false;
			} else ok = true;
		}
	}
	return ok; // retorna true se continua removendo
}


/* lista todas chaves em modo pré-ordem
Autor: Edgar Villani Peres */
void printAllFromPrefix(NoTrie * pt, string prefix){
     if(pt->terminal == true){
         cout << prefix << endl;
         char palavra[100];
         for(int ite = 0; ite < prefix.length(); ite++)
         {
             palavra[ite] = prefix[ite];
         }
         tabela.busca(palavra);
     }
     for(char i = 0; i < NUM_CHILDREN; i++){
         if(pt->pont[i] != NULL){
             char appendChar[] = {alfabeto[i], 0};
             string cloneString = prefix;
             cloneString += appendChar;
             printAllFromPrefix(pt->pont[i], cloneString);
         }
     }
 }
