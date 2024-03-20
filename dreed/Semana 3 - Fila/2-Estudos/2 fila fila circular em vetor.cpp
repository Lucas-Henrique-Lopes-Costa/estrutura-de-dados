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

class filaCircular
{
private:
    int mInicio;
    int mFim;
    int *mDados;
    int mCapacidade;
    int mTamanho;

public:
    filaCircular(int capacidade = 10);
    ~filaCircular();
    int tamanho();
    void enfileira(int valor);
    int desenfileira();
    void limpaFila();
    bool vazia();
    void depura();
};

filaCircular::filaCircular(int capacidade)
{
    mInicio = -1;
    mFim = -1;
    mCapacidade = capacidade;
    mTamanho = 0;
    mDados = new int[capacidade];
}

filaCircular::~filaCircular()
{
    delete[] mDados;
    limpaFila();
}

void filaCircular::limpaFila()
{
    while (!vazia())
    {
        desenfileira();
    }
}

int filaCircular::tamanho()
{
    return mTamanho;
}

bool filaCircular::vazia()
{
    return (mTamanho == 0);
}

void filaCircular::enfileira(int valor)
{
    if (mTamanho <= mCapacidade)
    {
        mFim++;
        mFim = mFim % mCapacidade;
        mDados[mFim] = valor;
        if (mTamanho == 0)
        {
            mInicio++;
        }
        mTamanho++;
    }
    else
    {
        cerr << "Fila cheia" << endl;
    }
}

int filaCircular::desenfileira()
{
    if (tamanho() > 0)
    {
        int valor = mDados[mInicio];
        mTamanho--;
        if (mTamanho > 0)
        {
            mInicio++;
            mFim = mFim % mCapacidade;
        }
        else
        {
            mInicio = -1;
            mFim = -1;
        }
        return valor;
    }
    else
    {
        cerr << "Fila vazia" << endl;
        return -1;
    }
}

void filaCircular::depura()
{
    cout << "tamanho=" << mTamanho << " capacidade=" << mCapacidade << " inicio=" << mInicio << " fim=" << mFim << endl;

    int i = mInicio;
    do
    {
        cout << mDados[i] << " ";
        i = (i + 1) % mCapacidade;
    } while (i != (mFim + 1) % mCapacidade);

    cout << endl;
}

int main()
{
    int capacidade;
    cin >> capacidade;

    filaCircular fila(capacidade);
    char comando;

    do
    {
        cin >> comando;
        switch (comando)
        {
        case 'e': // enfileirar
            int valor;
            cin >> valor;
            fila.enfileira(valor);
            break;
        case 'd': // desenfileirar
            cout << fila.desenfileira() << endl;
            break;
        case 'i': // informações
            fila.depura();
            break;
        case 't': // terminar
            // checado no do-while
            break;
        default:
            cerr << "comando inválido\n";
        }
    } while (comando != 't');

    return 0;
}
