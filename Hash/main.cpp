#include <iostream>
#include "Hash.hpp"

using namespace std;

int main()
{
    Hash teste;
    char palavra[70];
    cout << "Qual a palavra?\n";
    cin >> palavra;
    teste.insere(palavra,4);
cout << palavra << endl << endl;
for(int i = 0; i < 8; i++)
{
    cout << palavra[i] << endl;
}


    teste.insere("ronaldo", 1);

    cout << "a palavra palavra foi achada?\n" << teste.busca("palavra") << endl;
    cout << "a palavra pa foi achada?\n" << teste.busca("pa") << endl;
    cout << "a palavra ronaldo foi achada?\n" << teste.busca("ronaldo") << endl;

teste.busca(palavra);
    teste.remover("palavra");


    cout << "a palavra palavra foi achada?\n" << teste.busca("palavra") << endl;


    cout << "Hello world!" << endl;
    return 0;
}
