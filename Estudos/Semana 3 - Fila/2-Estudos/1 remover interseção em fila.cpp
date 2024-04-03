/*
Questão 1: Remover interseção em fila.
Dadas duas filas F1 e F2, implemente o método que remove os elementos de F2, presentes em F1. F1 deve estar disponível após a remoção dos elementos de F2 para outras operações.
As propriedades de fila devem ser estritamente respeitadas, ou seja: não é permitido o acesso aleatório aos elementos da fila.
A fila deve ser implementada utilizando encadeamento.
Entradas:
Número de elementos a serem inseridos em F1.
Elementos de F1 em ordem de inserção (inserção no fim da fila).
Número de elementos a serem inseridos em F2.
Elementos de F2 em ordem de inserção (inserção no fim da fila).
Saídas:
Elementos restantes em F1 após a remoção.
Exemplo de Entrada:
11
4 6 9 10 1 9 2 13 7 3 5
4
9 2 7 3
Exemplo de Saída:
4 6 10 1 13 5
*/

#include <iostream>
using namespace std;

class noh
{
    friend class fila;

private:
    int nValor;
    noh *nProximo;

public:
    noh(int valor);
};

noh::noh(int valor)
{
    nValor = valor;
    nProximo = NULL;
}

class fila
{
private:
    noh *mInicio;
    noh *mFim;
    int mTamanho;

public:
    fila();
    ~fila();
    int tamanho();
    void enfileira(int valor);
    int desenfileira();
    void limpaFila();
    bool vazia();
    void removeIntersecao(fila &f2);
};

fila::fila()
{
    mInicio = NULL;
    mFim = NULL;
    mTamanho = 0;
}

fila::~fila()
{
    limpaFila();
}

void fila::limpaFila()
{
    while (!vazia())
    {
        desenfileira();
    };
}

int fila::tamanho()
{
    return mTamanho;
}

bool fila::vazia()
{
    return (mTamanho == 0);
}


void fila::enfileira(int valor)
{
    noh *novo = new noh(valor);
    if (mFim != NULL)
    {
        mFim->nProximo = novo;
    }
    else
    {
        mInicio = novo;
    }
    mFim = novo;
    ++mTamanho;
}

int fila::desenfileira()
{
    int valor = mInicio->nValor;
    noh *temp = mInicio;
    mInicio = mInicio->nProximo;
    if (mInicio == NULL)
    {
        mFim = NULL;
    }
    delete temp;
    --mTamanho;
    return valor;
}

void fila::removeIntersecao(fila &f2)
{
    noh *aux = mInicio;
    noh *aux2 = f2.mInicio;
    fila f3;
    while (aux != NULL)
    {
        bool intersecao = false;
        while (aux2 != NULL && !intersecao)
        {
            if (aux->nValor == aux2->nValor)
            {
                intersecao = true;
            }
            aux2 = aux2->nProximo;
        }
        if (!intersecao)
        {
            f3.enfileira(aux->nValor);
        }
        aux2 = f2.mInicio;
        aux = aux->nProximo;
    }
    while (!f3.vazia())
    {
        cout << f3.desenfileira() << " ";
    }
}

int main()
{
    int n;
    cin >> n;

    fila f1;
    for (int i = 0; i < n; i++)
    {
        int valor;
        cin >> valor;
        f1.enfileira(valor);
    }

    int m;
    cin >> m;

    fila f2;
    for (int i = 0; i < m; i++)
    {
        int valor;
        cin >> valor;
        f2.enfileira(valor);
    }

    f1.removeIntersecao(f2);

    return 0;
}
