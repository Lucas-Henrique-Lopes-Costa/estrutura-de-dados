/*
Questão 2: Pilha - Ordenar uma pilha
Implemente um estrutura de dados do tipo pilha com as operações de empilhar e desempilhar. Adicione um método que, utilizando uma pilha auxiliar, faça a ordenação crescente da pilha original, com o menor elemento no topo da pilha.
Nenhuma outra estrutura pode ser utilizada além da pilha auxiliar.
Entradas:
Quantidade de elementos a serem armazenados na pilha
Elementos da pilha
Saídas:
Elementos da pilha ordenados
Exemplo de Entrada:
10
3 8 5 10 2 0 4 11 21 7
Exemplo de Saída:
0 2 3 4 5 7 8 10 11 21
Exemplo de Entrada:
15
3 8 5 10 -2 0 14 11 21 75 6 34 -1 9 -5
Exemplo de Saída:
-5 -2 -1 0 3 5 6 8 9 10 11 14 21 34 75
*/

#include <iostream>
using namespace std;

typedef int Dado;

class pilha
{
private:
    int capacidade;
    Dado *dados;
    int tamanho;
    int posTopo;

public:
    pilha(int cap);
    ~pilha();
    bool vazia();
    bool estaCheia();
    void empilhar(Dado valor);
    Dado desempilhar();
    int espia();
    void ordena();
};

pilha::pilha(int cap)
{
    capacidade = cap;
    dados = new Dado[capacidade];
    tamanho = 0;
    posTopo = -1;
}

pilha::~pilha()
{
    delete[] dados;
}

bool pilha::vazia()
{
    return posTopo == -1;
}

bool pilha::estaCheia()
{
    return posTopo == capacidade;
}

void pilha::empilhar(Dado valor)
{
    if (!estaCheia())
    {
        posTopo++;
        dados[posTopo] = valor;
        tamanho++;
    }
    else
    {
        // // aloca dinamicamente mais espaço para o vetor
        // Dado *aux = new Dado[capacidade++];
        // for (int i = 0; i < tamanho; i++)
        // {
        //     aux[i] = dados[i];
        // }
        // delete[] dados;
        // dados = aux;
        // posTopo++;
        // dados[posTopo] = valor;
        // tamanho++;
    }
}

Dado pilha::desempilhar()
{
    if (!vazia())
    {
        tamanho--;
        return dados[posTopo--];
    }
    else
    {
        return -1;
    }
}

int pilha::espia()
{
    if (!vazia())
    {
        return dados[posTopo];
    }
    return -1;
}

void pilha::ordena()
{
    pilha aux(capacidade);
    while (!vazia())
    {
        int temp = desempilhar(); // vai desempilhando
        while (!aux.vazia() && aux.espia() > temp)
        {
            empilhar(aux.desempilhar());
        }
        aux.empilhar(temp);
    }
    while (!aux.vazia())
    {
        empilhar(aux.desempilhar());
    }
}

int main()
{
    int n;
    cin >> n;
    pilha p(n);

    for (int i = 0; i < n; i++)
    {
        int valor;
        cin >> valor;
        p.empilhar(valor);
    }

    // ordenação
    p.ordena();

    for (int i = 0; i < n; i++)
    {
        cout << p.desempilhar() << " ";
    }

    cout << endl;

    return 0;
}
