/*
Questão 15: Arquivos - Caracteres não brancos
Faça um programa que abra um arquivo texto chamado "Meu_Arquivo.txt" e conte o número de caracteres não brancos nele. Escreva o resultado da contagem na saída padrão.
Entrada:
O arquivo de texto "Meu_Arquivo.txt".
Saída:
Número de caracteres não brancos dentro do arquivo.
Exemplo de arquivo:
Vou aproveitar os exercicios do dredd para estudar muito e tirar 100 em IALG!!
Exemplo de saída:
65
*/

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream arquivo("Meu_Arquivo.txt");

    if (!arquivo)
    {
        return 1;
    }
    else
    {
        char c;
        int cont = 0;
        while (arquivo.get(c))
        {
            if (c != ' ' && c != '\n' && c != '\t')
            {
                cont++;
            }
        }
        cout << cont;
    }

    return 0;
}
