/*
Questão 2: Fila - Fila circular em vetor
Filas podem ser implementadas com armazenamento de dados em vetor, se a capacidade fixa não for um problema. Nesse caso, é importante controlar os índices para "dar a volta" no vetor sempre que for necessário. Uma fila assim pode ser chamada de
fila circular
.
Faça a implementação de uma fila circular fazendo com que a inserção (método Enfileirar) sempre use o início do vetor (posição zero) quando a
fila
estiver vazia.
Entradas:
Inicialmente, o programa lê um número inteiro que é capacidade da fila a ser criada.
Depois, o programa lê códigos de comandos a executar. Sempre um caractere identificando o comando seguido dos parâmetros necessários para executar o comando, se houverem. Os códigos de comandos são:
t - para
t
erminar a execução do programa
e - para
e
nfileirar um valor - seguido do valor (número inteiro)
d - para
d
esenfileirar um valor
i - para escrever as
i
nformações da fila (atributos e conteúdo)
Saídas:
Os comandos d e i são os únicos que produzem saída de dados. Cada um pode ser observado no exemplo.
Exemplo de Entrada e Saída juntos:
3
e 1
e 2
e 3
i
tamanho=3 capacidade=3 inicio=0 fim=2
1 2 3
d
1
e 4
i
tamanho=3 capacidade=3 inicio=1 fim=0
2 3 4
d
2
d
3
i
tamanho=1 capacidade=3 inicio=0 fim=0
4
t
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
    nProximo == NULL;
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
    void info();
};

fila::fila()
{
    mInicio == NULL;
    mFim = NULL;
    mTamanho = 0;
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

int main()
{
    // Seu código aqui
    return 0;
}
