/*
Questão 6: Torneio - Torneio alternado
Um torneio é uma árvore estritamente binária na qual cada nó não folha contém uma cópia do maior elemento entre seus dois filhos. O conteúdo das folhas de um torneio determina o conteúdo de todos os seus nós. Um torneio com n folhas representa um conjunto de n elementos.
Implemente um torneio utilizando uma estratégia semelhante a um Heap. Entretanto, a cada etapa, a condição de vitória (maior elemento ou menor elemento) é alternada. A primeira etapa sempre começa com a condição de vitória sendo o maior elemento, a segunda é o menor valor, a terceira volta a ser o maior, e continua sucessivamente.
Note que normalmente um torneio é uma árvore estritamente binária, cheia. Como, neste problema, temos que o tamanho da entrada pode não ser uma potência de 2, será necessário fazer ajustes para trabalhar com o que costumamos chamar de torneio incompleto. Uma das abordagens possíveis é apresentada nos slides e vídeo do assunto, verifique.
Faça um programa que funcione como um torneio alternado, onde a cada etapa, alterna a condição de vitória (maior ou menor). A primeira etapa sempre começa com a condição de vitória sendo o maior valor, a segunda é o menor valor, a terceira volta a ser o maior, e continua nessa ordem.
A entrada deve conter o número de participantes seguido dos participantes. A saída apresenta o participante campeão do torneio.
Entradas:
Quantidade de participantes
Identificação dos participantes
Saídas:
Campeão do torneio
Exemplo de Entrada:
8
2 7 4 1 3 9 6 8
Exemplo de Saída:
8
Exemplo de Entrada:
13
11 5 3 4 2 15 7 9 10 8 12 6 16
Exemplo de Saída:
9
*/

#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

typedef int dado;
const int INVALIDO = -1;

class torneio
{
private:
    dado *heap;
    int capacidade;
    bool alterna;
    int tamanho;
    int inicioDados;
    inline int pai(int i)
    {
        return (i - 1) / 2;
    };
    inline int esquerdo(int i)
    {
        return 2 * i + 1;
    }
    inline int direito(int i)
    {
        return 2 * i + 2;
    }
    void arruma();
    void copiaMaior(int i, bool alterna);
    void copiaSubindo(int i);

public:
    torneio(dado vet[], int tam);
    torneio(int numFolhas);
    ~torneio();
    void insere(dado d);
    void imprime();
};

torneio::torneio(dado vet[], int tam)
{
    alterna = true;

    capacidade = 1;
    while (capacidade < tam)
    {
        capacidade *= 2;
    }

    capacidade = capacidade - 1 + tam;

    heap = new dado[capacidade];
    inicioDados = capacidade - tam;

    cout << "inicioDados: " << inicioDados << endl;
    cout << "capacidade: " << capacidade << endl;

    memcpy(&heap[inicioDados], vet, tam * sizeof(dado));

    tamanho = tam;
    arruma();
}

torneio::torneio(int numFolhas)
{
    capacidade = 1;
    while (capacidade < numFolhas)
    {
        capacidade *= 2;
    }

    capacidade = capacidade - 1 + numFolhas;
    heap = new dado[capacidade];
    inicioDados = capacidade - numFolhas;

    cout << "inicioDados: " << inicioDados << endl;
    cout << "capacidade: " << capacidade << endl;

    for (int i = 0; i < capacidade; i++)
    {
        heap[i] = INVALIDO;
    }
}

torneio::~torneio()
{
    delete[] heap;
}

void torneio::copiaMaior(int i, bool alterna)
{
    int esq = esquerdo(i);
    int dir = direito(i);

    cout << "i: " << i << " esq: " << esq << " dir: " << dir << endl;

    int maior = INVALIDO;

    if (alterna)
    {

        if (esq < capacidade)
        {
            if ((dir < capacidade) && (heap[dir] > heap[esq]))
            {
                maior = dir;
            }
            else
            {
                maior = esq;
            }
            heap[i] = heap[maior];
        }
        else
        {
            heap[i] = INVALIDO;
        }
    }
    else
    {
        if (esq < capacidade)
        {
            if ((dir < capacidade) && (heap[dir] < heap[esq]))
            {
                maior = dir;
            }
            else
            {
                maior = esq;
            }
            heap[i] = heap[maior];
        }
        else
        {
            heap[i] = INVALIDO;
        }
    }

    alterna = !alterna;
}

void torneio::copiaSubindo(int i)
{
    int p = pai(i);

    if (heap[i] > heap[p])
    {
        heap[p] = heap[i];
        copiaSubindo(p);
    }
}

void torneio::insere(dado d)
{
    if (tamanho == capacidade)
    {
        cout << "Heap cheio" << endl;
        exit(EXIT_FAILURE);
    }

    heap[inicioDados + tamanho] = d;
    copiaSubindo(inicioDados + tamanho);
    tamanho++;
}

void torneio::imprime()
{
    for (int i = 0; i < capacidade; i++)
    {
        cout << heap[i] << " ";
    }
    cout << endl;
}

int main()
{
    int tam;
    cin >> tam;

    dado vet[tam];

    for (int i = 0; i < tam; i++)
    {
        cin >> vet[i];
    }

    torneio *h = new torneio(vet, tam);
    h->imprime();
    delete h;
}