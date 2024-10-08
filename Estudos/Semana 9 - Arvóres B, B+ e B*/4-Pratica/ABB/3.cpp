/*
Questão 3: Árvore binária (ABB) – Contagem de nós folha
A partir do
código fornecido
, implemente os métodos que calculam a quantidade de nós folhas em uma árvore binária. Não é necessário manter o projeto do programa exemplo. Métodos auxiliares podem ser criados. Métodos da contagem de folhas que não forem usados devem ser apagados.
A quantidade de folhas numa árvore vazia é zero.
Entradas:
Número de valores a serem lidos.
Valores (inteiros) a inserir na árvore.
Saídas:
Quantidade de nós folha.
Exemplo de Entrada:
8
30 15 50 41 10 60 32 45
Exemplo de Saída:
4
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