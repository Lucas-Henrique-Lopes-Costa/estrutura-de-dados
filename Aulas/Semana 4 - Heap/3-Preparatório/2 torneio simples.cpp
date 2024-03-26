/*
Questão 2: Torneio Simples
Um torneio é uma árvore estritamente binária na qual cada nó não folha contém uma cópia do maior elemento entre seus dois filhos. O conteúdo das folhas de um torneio determina o conteúdo de todos os seus nós. Um torneio com n folhas representa um conjunto de n elementos.
Implemente um torneio utilizando uma estratégia semelhante a um Heap. Note que normalmente um torneio é uma árvore estritamente binária, cheia. Como, neste problema, temos que o tamanho da entrada pode não ser uma potência de 2, será necessário fazer ajustes para trabalhar com o que costumamos chamar de torneio incompleto. Uma das abordagens possíveis é apresentada nos slides e vídeo do assunto, verifique.
O
código fornecido
é uma base que você pode utilizar. O aluno tem total liberdade em não utiliza-lo ou modifica-lo.
Faça um programa que funcione como um torneio.
A entrada deve conter o número de participantes (número inteiro) seguido dos participantes (números inteiros). A saída apresenta o valor base do participante campeão do torneio.
Entradas:
Quantidade de participantes
Identificação dos participantes
Saídas:
Valor base do campeão do torneio
Exemplo de Entrada:
8
2 7 4 1 3 9 6 8
Exemplo de Saída:
9
Exemplo de Entrada:
13
11 5 3 4 2 15 7 9 10 8 12 6 13
Exemplo de Saída:
15
*/

/*
 *  Torneio
 *
 *  Realiza torneio simples de numeros inteiros
 *
 *  Made by Renato Ramos da Silva in 18/09/23
 *
 */
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int INVALIDO = -1;

class torneio
{
private:
    int *heap;
    int tamanho;
    int capacidade;
    int inicioDados;
    inline int pai(int filho);
    inline int esquerda(int getPai);
    inline int direita(int getPai);
    void arruma();
    void compete(int i);
    void verBaseMaior();

public:
    torneio(int vet[], int tam);
    ~torneio();
};

// Construtor da classe
torneio::torneio(int vet[], int tam)
{
}

// Destrutor da classe
torneio::~torneio()
{
}

// Retorno a posição do nó pai de um determinado elemento
int torneio::pai(int filho)
{
}

// Retorna o filho à esquerda de um determinado nó
int torneio::esquerda(int pai)
{
}

// Retorna o filho à direita do nó pai
int torneio::direita(int pai)
{
}

// Faz a competição por cada posição vencedora no vetor e imprime o vencedor
void torneio::arruma()
{
}

// Faz a competição entre os elementos
void torneio::compete(int i)
{
}

int main()
{
    int tam;
    cin >> tam;

    int vet[tam];
    for (int i = 0; i < tam; i++)
    {
        cin >> vet[i];
    }

    torneio participantes(vet, tam);

    return 0;
}