/*
Questão 2: Árvore ABB - Altura de um Nó
O
código fornecido
implementa uma Árvore Binária de Busca, com operações de inserir, buscar e percorrer escrevendo. Crie um método (e seus auxiliares) para calcular a altura de um nó. A figura à direita mostra uma árvore com anotação da altura de cada nó em vermelho. A altura de uma folha é zero.
Usando esses métodos, o programa deverá ser modificado para ler vários valores e escrever a altura dos nós em que os valores estão. Suponha que os nós sempre estarão na árvore. A operação de escrita da altura deve estar no programa e não na classe.
A operação de percorrer escrevendo, está disponível para ajudar na depuração, se necessário.
Entradas:
A quantidade de valores a inserir na árvore.
Os valores (inteiros) a serem inseridos.
A quantidade de valores a serem buscados na árvore.
Os valores (inteiros, pertencentes à árvore) a serem buscados.
Saídas:
A altura do nó que contém cada um dos valores buscados.
Exemplo de Entrada:
7
5 1 10 8 3 7 9
3
7 8 10
Exemplo de Saída:
0 1 2
*/

#include <iostream>
#include <cstdlib>

using namespace std;

typedef int Dado; // Facilita a troca de tipo, se necessário, por exemplo, para float ou string

// Classe que representa um nó da árvore binária de busca (ABB)
class noh
{
    friend class abb; // A classe abb pode acessar os membros privados de noh
private:
    Dado valor; // Valor armazenado no nó
    noh *esq;   // Ponteiro para o filho à esquerda
    noh *dir;   // Ponteiro para o filho à direita
    noh *pai;   // Ponteiro para o pai do nó
public:
    noh(Dado d = 0); // Construtor que inicializa o nó com um valor
    ~noh();          // Destrutor que desaloca memória dos filhos
};

// Implementação do construtor da classe noh
noh::noh(Dado d)
{
    valor = d;
    esq = NULL; // Inicializa o ponteiro da esquerda como NULL
    dir = NULL; // Inicializa o ponteiro da direita como NULL
    pai = NULL; // Inicializa o ponteiro do pai como NULL
}

// Implementação do destrutor da classe noh
noh::~noh()
{
    // Chama recursivamente o destrutor para os nós filhos
    delete esq;
    delete dir;
}

// Classe que representa a árvore binária de busca (ABB)
class abb
{
private:
    noh *raiz; // Ponteiro para a raiz da árvore
    // Métodos auxiliares privados para percorrer a árvore e encontrar um nó específico
    noh *buscaAux(noh *atual, Dado d);              // Método auxiliar para busca
    int calculaAlturaAux(noh *atual);               // Método auxiliar para calcular a altura de um nó
    void percorreEmOrdemAux(noh *atual, int nivel); // Método auxiliar para percorrer em ordem
public:
    abb() { raiz = NULL; }     // Construtor inicializa a árvore vazia
    ~abb();                    // Destrutor que desaloca a memória da árvore
    void insere(Dado d);       // Método para inserir um elemento na árvore
    noh *busca(Dado d);        // Método para buscar um elemento na árvore
    int calculaAltura(Dado d); // Método para calcular a altura de um nó específico
    void percorreEmOrdem();    // Método para percorrer a árvore em ordem (in-order)
};

// Destrutor da classe abb que deleta a raiz e, consequentemente, todos os nós
abb::~abb()
{
    delete raiz;
}

// Método auxiliar que busca um nó com determinado valor na árvore, começando do nó atual
noh *abb::buscaAux(noh *atual, Dado d)
{
    if (atual == NULL || atual->valor == d)
    {
        return atual; // Retorna o nó se encontrar o valor ou NULL se não encontrar
    }
    else if (d < atual->valor)
    {
        return buscaAux(atual->esq, d); // Busca na subárvore esquerda se o valor é menor
    }
    else
    {
        return buscaAux(atual->dir, d); // Busca na subárvore direita se o valor é maior
    }
}

// Método público que busca um nó com determinado valor na árvore
noh *abb::busca(Dado d)
{
    return buscaAux(raiz, d); // Chama o auxiliar de busca começando da raiz
}

// Método auxiliar recursivo que calcula a altura da subárvore enraizada em 'atual'
int abb::calculaAlturaAux(noh *atual)
{
    if (atual == NULL)
    {
        return -1; // Retorna -1 para que folhas tenham altura 0
    }
    else
    {
        // Calcula a altura das subárvores esquerda e direita
        int alturaEsq = calculaAlturaAux(atual->esq);
        int alturaDir = calculaAlturaAux(atual->dir);
        // A altura do nó atual é 1 + a maior altura entre seus filhos
        return 1 + max(alturaEsq, alturaDir);
    }
}

// Método público que calcula a altura de um nó específico na árvore
int abb::calculaAltura(Dado d)
{
    noh *nohDesejado = busca(d); // Busca o nó com o valor 'd'
    if (nohDesejado == NULL)
    {
        return -1; // Se o nó não for encontrado, retorna -1
    }
    else
    {
        return calculaAlturaAux(nohDesejado); // Calcula a altura do nó encontrado
    }
}

// Método para inserir um novo nó na árvore
void abb::insere(Dado d)
{
    noh *novo = new noh(d); // Cria um novo nó com o valor fornecido
    if (raiz == NULL)
    {
        raiz = novo; // Se a árvore está vazia, o novo nó é a raiz
    }
    else
    {
        noh *atual = raiz;
        noh *anterior = NULL;

        // Loop para encontrar o ponto de inserção
        while (atual != NULL)
        {
            anterior = atual;
            if (d < atual->valor)
            {
                atual = atual->esq; // Vá para a esquerda se o valor é menor
            }
            else
            {
                atual = atual->dir; // Vá para a direita se o valor é maior ou igual
            }
        }

        // Conecta o novo nó ao pai
        novo->pai = anterior;
        if (d < anterior->valor)
        {
            anterior->esq = novo; // Insere como filho à esquerda
        }
        else
        {
            anterior->dir = novo; // Insere como filho à direita
        }
    }
}

// Método para percorrer a árvore em ordem (in-order) e imprimir os valores
void abb::percorreEmOrdem()
{
    percorreEmOrdemAux(raiz, 0); // Chama o auxiliar com a raiz e nível inicial 0
    cout << endl;
}

// Método auxiliar que percorre a árvore em ordem (in-order)
void abb::percorreEmOrdemAux(noh *atual, int nivel)
{
    if (atual != NULL)
    {
        percorreEmOrdemAux(atual->esq, nivel + 1);   // Primeiro visita a subárvore esquerda
        cout << atual->valor << "/" << nivel << " "; // Depois processa o nó atual, mostrando o valor e o nível (nível é para depuração)
        percorreEmOrdemAux(atual->dir, nivel + 1);   // Finalmente, visita a subárvore direita
    }
}

// Função principal (main) que realiza a leitura dos dados, inserção e busca na árvore
int main()
{
    abb minhaArvore; // Cria uma nova árvore
    int numInsercoes, numBuscas, valor;

    // Leitura do número de elementos a serem inseridos
    cin >> numInsercoes;

    // Loop para inserir os elementos na árvore
    for (int i = 0; i < numInsercoes; i++)
    {
        cin >> valor;
        minhaArvore.insere(valor); // Insere o valor na árvore
    }

    // Leitura do número de elementos a serem buscados
    cin >> numBuscas;

    // Loop para buscar os elementos na árvore e imprimir a altura dos nós
    for (int i = 0; i < numBuscas; i++)
    {
        cin >> valor;
        // Para cada valor, busca na árvore e imprime a altura do nó correspondente
        cout << minhaArvore.calculaAltura(valor) << " ";
    }
    cout << endl;

    return 0; // Retorna 0 para indicar que o programa terminou com sucesso
}
