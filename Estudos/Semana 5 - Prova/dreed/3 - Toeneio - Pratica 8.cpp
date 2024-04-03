/*
Um torneio é uma árvore estritamente binária na qual cada nó não folha contém uma cópia do maior elemento entre seus dois filhos. O conteúdo das folhas de um torneio determina o conteúdo de todos os seus nós. Um torneio com n folhas representa um conjunto de n elementos.

Implemente um torneio utilizando uma estratégia semelhante a um Heap. Entretanto, a cada etapa, a condição de vitória (maior elemento ou menor elemento) é alternada. A primeira etapa sempre começa com a condição de vitória sendo o maior elemento, a segunda é o menor valor, a terceira volta a ser o maior, e continua sucessivamente.

Note que normalmente um torneio é uma árvore estritamente binária, cheia. Como, neste problema, temos que o tamanho da entrada pode não ser uma potência de 2, será necessário fazer ajustes para trabalhar com o que costumamos chamar de torneio incompleto. Uma das abordagens possíveis é apresentada nos slides e vídeo do assunto, verifique.

Faça um programa que funcione como um torneio alternado, onde a cada etapa, alterna a condição de vitória (maior ou menor). A primeira etapa sempre começa com a condição de vitória sendo o maior valor, a segunda é o menor valor, a terceira volta a ser o maior, e continua nessa ordem.

A entrada deve conter o número de participantes seguido dos participantes. A saída apresenta o participante vice-campeão do torneio.
Entradas:

Quantidade de participantes
Identificação dos participantes
Saídas:

Vice-campeão do torneio
Exemplo de Entrada:

8
2 7 4 1 3 9 6 8
Exemplo de Saída:

4
Exemplo de Entrada:

13
11 5 3 4 2 15 7 9 10 8 12 6 16
Exemplo de Saída:

16
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int INVALIDO = -1;

class torneio
{
private:
    int *heap;                               // Array para armazenar os participantes do torneio
    int capacidade;                          // Capacidade total da heap
    int inicioDados;                         // Índice onde começam os dados reais na heap
    bool competirMaior;                      // Variável para alternar entre competir pelo maior ou menor valor
    inline int pai(int filho);                // Função auxiliar para encontrar o pai de um nó na heap
    inline int esquerda(int getPai);         // Função auxiliar para encontrar o filho esquerdo de um nó na heap
    inline int direita(int getPai);          // Função auxiliar para encontrar o filho direito de um nó na heap
    void arruma();                           // Método para organizar a heap
    void compete(int i, bool competirMaior); // Método para realizar a competição entre os elementos

public:
    torneio(int vet[], int tam); // Construtor da classe
    ~torneio();                  // Destrutor da classe
    int viceCampeao();           // Método para encontrar o vice-campeão do torneio
};

// Construtor da classe
torneio::torneio(int vet[], int tam)
{
    // Inicialização das variáveis
    int numPais = 1;
    while (numPais < tam)
    {
        numPais *= 2;
    }
    capacidade = numPais - 1 + tam;
    inicioDados = capacidade - tam;
    heap = new int[capacidade];
    memcpy(&heap[inicioDados], vet, sizeof(int) * tam);
    competirMaior = true;
    arruma(); // Organiza a heap após a inicialização
}

// Destrutor da classe
torneio::~torneio()
{
    delete[] heap;
}

// Retorna a posição do pai de um determinado elemento na heap
int torneio::pai(int i)
{
    return (i - 1) / 2;
}

// Retorna a posição do filho esquerdo de um determinado nó na heap
int torneio::esquerda(int i)
{
    return 2 * i + 1;
}

// Retorna a posição do filho direito de um determinado nó na heap
int torneio::direita(int i)
{
    return 2 * i + 2;
}

// Organiza a heap
void torneio::arruma()
{
    // Variáveis para controlar a competição
    int tamanhoChave = (inicioDados + 1) / 2;
    int aux = tamanhoChave;

    // Percorre a heap para realizar as competições
    for (int i = inicioDados - 1; i >= 0; i--)
    {
        // Realiza a competição para o nó atual
        compete(i, competirMaior);

        // Atualiza as variáveis para alternar entre competir pelo maior ou menor valor
        aux--;
        if (aux == 0)
        {
            competirMaior = !competirMaior;
            tamanhoChave /= 2;
            aux = tamanhoChave;
        }
    }
}

// Realiza a competição entre os elementos na heap
void torneio::compete(int i, bool competirMaior)
{
    int esq = esquerda(i);
    int dir = direita(i);

    // Verifica se a competição é para encontrar o maior valor
    if (competirMaior)
    {
        // Se o filho esquerdo existe
        if (esq <= capacidade - 1)
        {
            int maior;

            // Verifica se o filho direito também existe e qual deles é maior
            if (dir <= capacidade - 1 && heap[dir] > heap[esq])
                maior = dir;
            else
                maior = esq;

            // Atualiza o valor do nó atual com o valor do filho maior
            heap[i] = heap[maior];
        }
        else
            heap[i] = INVALIDO;
    }
    else
    { // Competição para encontrar o menor valor
        // Se o filho esquerdo existe
        if (esq <= capacidade - 1)
        {
            int menor;

            // Verifica se o filho direito também existe e qual deles é menor
            if (dir <= capacidade - 1 && heap[dir] < heap[esq])
                menor = dir;
            else
                menor = esq;

            // Atualiza o valor do nó atual com o valor do filho menor
            heap[i] = heap[menor];
        }
        else
            heap[i] = INVALIDO;
    }
}

// Método para encontrar o vice-campeão do torneio
int torneio::viceCampeao()
{
    if (heap[1] == heap[0])
    {
        return heap[2];
    }
    else
    {
        return heap[1];
    }
}

// Função principal
int main()
{
    int tam;
    cin >> tam;

    // Lê os valores dos participantes
    int vet[tam];
    for (int i = 0; i < tam; i++)
    {
        cin >> vet[i];
    }

    // Cria um objeto torneio com os participantes e encontra o vice-campeão
    torneio participantes(vet, tam);
    cout << participantes.viceCampeao() << endl;

    return 0;
}
