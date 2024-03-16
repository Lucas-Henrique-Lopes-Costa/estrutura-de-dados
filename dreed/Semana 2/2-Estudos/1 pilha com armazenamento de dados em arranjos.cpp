/*
Questão 1: Pilha com armazenamento de dados em arranjos
Implemente uma pilha, utilizando armazenamento dos dados em arranjos (vetores). Segue esboço da implementação:
typedef int Dado; // para facilitar a troca de int para outro tipo

// pilha implementada em arranjo
class pilhav {
    private:
        int capacidade;
        Dado *dados;
        int tamanho;
        int posTopo;
    public:
        pilhav(int cap = 100);
        ~pilhav();
        void empilha(Dado valor);
        Dado desempilha();
        Dado espia(); // acessa elemento do topo, mas não retira
        void depura(); // imprime os dados do vetor da pilha sem removê-los (desempilhar)
        void info();  // imprime informações da pilha (tamanho e  posição do topo)
};
Não é necessário tratar problemas do tipo retirada de elemento de pilha vazia ou empilhamento em pilha cheia. A aplicação principal deverá criar uma pilha com capacidade para 20 elementos e realizar as seguintes operações na ordem apresentada:

Empilhar cinco elementos
Desempilhar três elementos (imprimindo-os)
Empilhar mais quatro elementos
Desempilhar três elementos (imprimindo-os)
Imprime o topo da pilha, sem desempilhar (espia())
Imprime os elementos restantes da pilha (depura())
Imprime tamanho e posição do topo (info())

Entradas:
Cinco valores a serem empilhados
Quatro valores a serem empilhados

Saídas:
Três elementos desempilhados
Três elementos desempilhados
Topo da pilha
Elementos restantes da pilha
Tamanho e posição do topo

Exemplo de Entrada:
8 9 1 3 5
12 23 0 3

Exemplo de Saída:
5 3 1
3 0 23
12
8 9 12
3 2
*/

#include <iostream>
using namespace std;

typedef int Dado;

// pilha implementada em arranjo
class pilhav
{
private:
    int capacidade;
    Dado *dados;
    int tamanho;
    int posTopo;

public:
    pilhav(int cap = 100);
    ~pilhav();
    void empilha(Dado valor);
    Dado desempilha();
    Dado espia();  // acessa elemento do topo, mas não retira
    void depura(); // imprime os dados do vetor da pilha sem removê-los (desempilhar)
    void info();   // imprime informações da pilha (tamanho e  posição do topo)
};

pilhav::pilhav(int cap)
{
    capacidade = cap;
    dados = new Dado[capacidade];
    tamanho = 0;
    posTopo = -1;
}

pilhav::~pilhav()
{
    delete[] dados;
}

void pilhav::info()
{
    cout << tamanho << " " << posTopo << endl;
}

void pilhav::depura()
{
    for (int i = 0; i < tamanho; i++)
    {
        cout << dados[i] << " ";
    }
    cout << endl;
}

Dado pilhav::espia()
{
    return dados[posTopo];
}

void pilhav::empilha(Dado valor)
{
    if (tamanho < capacidade)
    {
        dados[++posTopo] = valor; // Primeiro incrementa posTopo, depois usa para atribuir o valor
        tamanho++;
    }
}

Dado pilhav::desempilha()
{
    if (tamanho > 0)
    {
        tamanho--;
        return dados[posTopo--]; // Retorna o valor e depois decrementa posTopo
    }
    else
    {
        // Apenas um placeholder, idealmente deve-se tratar o caso de pilha vazia de forma mais adequada
        return -1;
    }
}

int main()
{
    pilhav pilha(20);

    // Empilhar cinco elementos
    int valor;
    for (int i = 0; i < 5; i++)
    {
        cin >> valor;
        pilha.empilha(valor);
    }

    // Desempilhar três elementos (imprimindo-os)
    for (int i = 0; i < 3; i++)
    {
        cout << pilha.desempilha() << " ";
    }

    // Empilhar mais quatro elementos
    for (int i = 0; i < 4; i++)
    {
        cin >> valor;
        pilha.empilha(valor);
    }

    // Desempilhar três elementos (imprimindo-os)
    for (int i = 0; i < 3; i++)
    {
        cout << pilha.desempilha() << " ";
    }

    // Imprime o topo da pilha, sem desempilhar (espia())
    cout << pilha.espia() << endl;

    // Imprime os elementos restantes da pilha (depura())
    pilha.depura();

    // Imprime tamanho e posição do topo (info())
    pilha.info();

    return 0;
}
