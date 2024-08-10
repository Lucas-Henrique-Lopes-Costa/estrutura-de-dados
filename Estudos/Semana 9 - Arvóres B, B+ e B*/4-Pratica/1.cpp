/*
Questão 1: Altura de Árvore Binária (ABB)
Utilizando como base o
código fornecido
pelos professores, implemente um método para calcular a altura de uma árvore binária. Utilize o método implementado para apresentar a altura de uma dada árvore, a cada inserção ou remoção feita. A aplicação principal já faz os testes necessários, faltando apenas o método solicitado. Você pode implementar métodos auxiliares privados, se necessário.
Entradas:
Número de elementos a serem inseridos na árvore.
Elementos a serem inseridos na árvore.
Número de elementos a serem removidos da árvore.
Elementos a serem removidos da árvore.
Saídas:
Impressão da altura da árvore após cada inserção.
Impressão da árvore final  (usando percorreEmOrdem) após inserções.
Impressão da altura da árvore após cada remoção.
Impressão da árvore final (usando percorreEmOrdem) após remoções.
Exemplo de Entrada:
20
1 23 83 4 2 11 20 30 40 50 8 9 18 12 13 15 17 31 41 51
10
23 4 11 30 50 9 12 17 83 2
Exemplo de Saída:
1 2 3 3 4 4 5 5 5 6 6 6 6 7 8 9 10 10 10 10
1/0 2/3 4/2 8/4 9/5 11/3 12/6 13/7 15/8 17/9 18/5 20/4 23/1 30/3 31/5 40/4 41/6 50/5 51/6 83/2
10 10 9 9 9 9 8 7 7 7
1/0 8/2 13/5 15/6 18/4 20/3 31/1 40/2 41/4 51/3
Exemplo de Entrada:
10
10 9 8 7 6 5 4 3 2 1
5
9 7 5 3 1
Exemplo de Saída:
1 2 3 4 5 6 7 8 9 10
1/9 2/8 3/7 4/6 5/5 6/4 7/3 8/2 9/1 10/0
9 8 7 6 5
2/4 4/3 6/2 8/1 10/0
*/

#include <iostream>
#include <cstdlib>

using namespace std;

typedef int Dado; // para facilitar a troca de int para outro tipo

enum posicao
{
    dir,
    esq
};

class noh
{
    friend class abb;

private:
    Dado valor;
    noh *esq;
    noh *dir;
    noh *pai;

public:
    noh(Dado d = 0);
    ~noh();
};

noh::noh(Dado d)
{
    valor = d;
    esq = NULL;
    dir = NULL;
    pai = NULL;
}

noh::~noh()
{
    delete esq; // não precisa checar se é nulo em C++
    delete dir;
}

class abb
{
private:
    noh *raiz;
    void percorreEmOrdemAux(noh *atual, int nivel);
    void percorrePreOrdemAux(noh *atual);
    void percorrePosOrdemAux(noh *atual);
    // menor e maior valor de uma subárvore com pai em raizSub
    noh *minimoAux(noh *raizSub);
    noh *maximoAux(noh *raizSub);
    // transplanta o nó novo para o local onde estava o nó antigo
    void transplanta(noh *antigo, noh *novo);

public:
    abb() { raiz = NULL; }
    ~abb();
    void insere(Dado d);
    void remove(Dado d);
    noh *busca(Dado d);
    Dado minimo();
    Dado maximo();
    void percorreEmOrdem();
    void percorrePreOrdem();
    void percorrePosOrdem();
    int calculaAltura(); // IMPLEMENTAR ESTE MÉTODO!
};

abb::~abb()
{
    delete raiz;
}

void abb::insere(Dado d)
{
    noh *novo = new noh(d);
    posicao posInsercao;

    // primeiro caso: árvore vazia
    if (raiz == NULL)
    {
        raiz = novo;
    }
    else
    {
        noh *atual = raiz;
        noh *anterior;

        // encontrando ponto de inserção
        while (atual != NULL)
        {
            anterior = atual;

            // trocar por >=, se quiser elementos iguais
            if (atual->valor > d)
            {
                atual = atual->esq;
                posInsercao = esq;
            }
            else
            {
                atual = atual->dir;
                posInsercao = dir;
            }
        }

        // inserindo o novo nó na árvore
        novo->pai = anterior;

        if (posInsercao == dir)
        {
            anterior->dir = novo;
        }
        else
        {
            anterior->esq = novo;
        }
    }
}

noh *abb::busca(Dado d)
{
    noh *atual = raiz;

    while (atual != NULL)
    {
        if (atual->valor == d)
        {
            return atual;
        }
        else if (atual->valor > d)
        {
            atual = atual->esq;
        }
        else
        {
            atual = atual->dir;
        }
    }

    return atual;
}

Dado abb::minimo()
{
    if (raiz == NULL)
    {
        cerr << "Árvore vazia!" << endl;
        exit(EXIT_FAILURE);
    }
    else
    {
        noh *nohMin = minimoAux(raiz);
        return nohMin->valor;
    }
}

noh *abb::minimoAux(noh *raizSub)
{
    while (raizSub->esq != NULL)
    {
        raizSub = raizSub->esq;
    }
    return raizSub;
}

Dado abb::maximo()
{
    if (raiz == NULL)
    {
        cerr << "Árvore vazia!" << endl;
        exit(EXIT_FAILURE);
    }
    else
    {
        noh *nohMax = maximoAux(raiz);
        return nohMax->valor;
    }
}

noh *abb::maximoAux(noh *raizSub)
{
    while (raizSub->dir != NULL)
    {
        raizSub = raizSub->dir;
    }
    return raizSub;
}

// transplanta muda uma árvore com raiz em novo para o local onde
// antes estava o nó antigo
void abb::transplanta(noh *antigo, noh *novo)
{
    if (raiz == antigo)
    {
        raiz = novo;
    }
    else if (antigo == antigo->pai->esq)
    {
        antigo->pai->esq = novo;
    }
    else
    { // antigo == antigo.pai.dir
        antigo->pai->dir = novo;
    }
    if (novo != NULL)
    {
        novo->pai = antigo->pai;
    }
}

void abb::remove(Dado dado)
{
    // achamos o nó na árvore
    noh *nohRemover = busca(dado);

    if (nohRemover == NULL)
    {
        cerr << "valor não está na árvore!" << endl;
        // exit(EXIT_FAILURE);
    }
    else
    {
        // nó não tem filhos à esquerda
        if (nohRemover->esq == NULL)
        {
            transplanta(nohRemover, nohRemover->dir);
        }
        // nó não tem filhos à direita
        else if (nohRemover->dir == NULL)
        {
            transplanta(nohRemover, nohRemover->esq);
        }

        // nó tem dois filhos... substituímos pelo sucessor
        else
        { // ((nohRemover->esq) and (nohRemover->dir))
            noh *sucessor = minimoAux(nohRemover->dir);

            if (sucessor->pai != nohRemover)
            {
                transplanta(sucessor, sucessor->dir);
                sucessor->dir = nohRemover->dir;
                sucessor->dir->pai = sucessor;
            }

            transplanta(nohRemover, sucessor);
            sucessor->esq = nohRemover->esq;
            sucessor->esq->pai = sucessor;
        }

        // ponteiros ajustados, apagamos o nó
        nohRemover->esq = NULL;
        nohRemover->dir = NULL;
        delete nohRemover;
    }
}

void abb::percorreEmOrdem()
{
    percorreEmOrdemAux(raiz, 0);
    cout << endl;
}

void abb::percorreEmOrdemAux(noh *atual, int nivel)
{
    if (atual != NULL)
    {
        percorreEmOrdemAux(atual->esq, nivel + 1);
        cout << atual->valor << "/" << nivel << " ";
        percorreEmOrdemAux(atual->dir, nivel + 1);
    }
}

void abb::percorrePreOrdem()
{
    percorrePreOrdemAux(raiz);
    cout << endl;
}

void abb::percorrePreOrdemAux(noh *atual)
{
    if (atual != NULL)
    {
        cout << atual->valor << " ";
        percorrePreOrdemAux(atual->esq);
        percorrePreOrdemAux(atual->dir);
    }
}

void abb::percorrePosOrdem()
{
    percorrePosOrdemAux(raiz);
    cout << endl;
}

void abb::percorrePosOrdemAux(noh *atual)
{
    if (atual != NULL)
    {
        percorrePosOrdemAux(atual->esq);
        percorrePosOrdemAux(atual->dir);
        cout << atual->valor << " ";
    }
}

int main()
{
    abb minhaArvore;
    int valor;
    int num;

    cin >> num;

    for (int i = 0; i < num; i++)
    {
        cin >> valor;
        minhaArvore.insere(valor);
        cout << minhaArvore.calculaAltura() << " ";
    }
    cout << endl;
    minhaArvore.percorreEmOrdem();

    cin >> num;

    for (int i = 0; i < num; i++)
    {
        cin >> valor;
        minhaArvore.remove(valor);
        cout << minhaArvore.calculaAltura() << " ";
    }
    cout << endl;
    minhaArvore.percorreEmOrdem();

    return 0;
}