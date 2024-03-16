/*
Questão 4: Pilha com armazenamento dinâmico
Usando
o código com as especificações de métodos e atributos mais um programa que usa a classe Pilha
, crie uma classe pilha com armazenamento dinâmico.
O método Desempilhar deve escrever alguma mensagem de erro na saída de erros quando não for possível desempilhar.
Entradas:
O programa passado aceita os seguintes comandos:
i seguido de um valor inteiro: para inserir um item na pilha
r: para remover um item da pilha
l: para limpar (remover todos) os itens da pilha
t: para consultar o tamanho da pilha
e: para espiar o topo da pilha (escreve o topo sem removê-lo)
f: para finalizar a execução do programa
Saídas:
Todas as saídas de comandos já estão implementadas na função principal. Ao terminar a execução do programa, todos os itens da pilha são desempilhados e escritos, mesmo assim, o destrutor deve desalocar memória de todos os itens da pilha.
Exemplo de Entrada e Saída juntas:
i 2
i 4
i 6
r
6
t
2
l
i 8
i 10
e
10
f
10 8
*/
#include <iostream>
using namespace std;

typedef int Dado;

class Noh
{
    friend class Pilha;

private:
    Dado mDado; // poderia ser outro tipo de variável
    Noh *mPtProx;
};

class Pilha
{
public:
    // Constrói pilha vazia.
    Pilha();
    // Destrutor que desaloca memória.
    ~Pilha();
    // Retira e retorna o valor que estiver no mPtTopo da pilha.
    // Escreve uma mensagem de erro se não for possível desempilhar.
    Dado Desempilhar(); // retorna o mPtTopo da Pilha
    // Insere um valor na pilha.
    void Empilhar(const Dado &d);
    // Apagar todos os dados da pilha.
    void LimparTudo();
    // Informa quantos valores existem na pilha.
    unsigned Tamanho() { return mTamanho; }
    // Retorna o valor que está no mPtTopo sem desempilhar.
    Dado Topo() const;
    // Informa se a pilha está Vazia.
    bool Vazia() const;

private:
    Noh *mPtTopo;
    unsigned mTamanho;
};

Pilha::Pilha()
{
    mPtTopo = NULL;
    mTamanho = 0;
}

Pilha::~Pilha()
{
    LimparTudo();
}

void Pilha::LimparTudo()
{
    Noh *nAux = mPtTopo;
    while (nAux != NULL) // desalocando todos os nós
    {
        Noh *nRemover = nAux; // armazena o nó a ser removido
        nAux = nAux->mPtProx; // avança na lista
        delete nRemover;      // apaga o nó
    }
    mTamanho = 0;
    mPtTopo = NULL;
}

bool Pilha::Vazia() const
{
    return (mPtTopo == NULL);
}

Dado Pilha::Desempilhar()
{
    if (Vazia())
    {
        cerr << "Pilha vazia" << endl;
    }
    else
    {
        Noh *nAux = mPtTopo;
        Dado valor = nAux->mDado;   // armazena o dado a ser retornado
        mPtTopo = mPtTopo->mPtProx; // atualiza o topo
        delete nAux;                // apaga o ex-mPtTopo
        --mTamanho;
        return valor;
    }
    return false;
}

void Pilha::Empilhar(const Dado &d)
{
    Noh *novo = new Noh;
    novo->mDado = d;
    novo->mPtProx = mPtTopo;
    mPtTopo = novo;
    ++mTamanho;
}

Dado Pilha::Topo() const
{
    if (Vazia())
    {
        cerr << "Pilha vazia" << endl;
    }
    else
    {
        return mPtTopo->mDado;
    }
    return false;
}

int main()
{
    Pilha pilha;
    Dado valor;
    char comando;
    do
    {
        cin >> comando;
        switch (comando)
        {
        case 'i': // inserir
            cin >> valor;
            pilha.Empilhar(valor);
            break;
        case 'r': // remover
            cout << pilha.Desempilhar() << endl;
            break;
        case 'l': // limpar tudo
            pilha.LimparTudo();
            break;
        case 't': // consultar tamanho
            cout << pilha.Tamanho() << endl;
            break;
        case 'e': // espiar
            cout << pilha.Topo() << endl;
            break;
        case 'f': // finalizar
            // checado no do-while
            break;
        default:
            cerr << "comando inválido\n";
        }
    } while (comando != 'f'); // finalizar execução
    while (not pilha.Vazia())
    {
        cout << pilha.Desempilhar() << ' ';
    }
    cout << endl;
    return 0;
}
