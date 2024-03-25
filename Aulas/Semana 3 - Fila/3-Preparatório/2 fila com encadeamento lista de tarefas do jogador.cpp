/*
Questão 2: Fila com encadeamento - Lista de tarefas do jogador
Implemente uma estrutura de dados fila, utilizando encadeamento de nós, para implementar uma lista de tarefas do jogador, usando como base o
código fornecido
. A estrutura deve possibilitar, pelo menos, as seguintes ações: enfileiramento e desenfileiramento de itens, verificação do item no frente da fila e limpeza da lista (remoção de todos os elementos da fila). O desenfileiramento deve escrever mensagem de erro na saída ("
Erro: fila vazia!
"), quando a fila já estiver vazia. Os itens da lista possuem os seguintes atributos: nome da tarefa (uma string sem espaços), prêmio (uma string sem espaços), tipo (um único caracter) e tempo para realização (um inteiro).
Entradas:
O programa deve aceitar os seguintes comandos:
i seguido de duas string, um caracter e um inteiro: para inserir um item na lista de tarefas
r: para retirar um item da lista de tarefas
l: para limpar (remover todos) os itens da lista de tarefas
e: para espiar a frente da lista de tarefas (escreve o topo sem removê-lo)
f: para finalizar a execução do programa
Saídas:
Todas as saídas de comandos já estão implementadas na função principal desse código exemplo fornecido. Ao terminar a execução do programa, todos os itens da fila são desempilhados e escritos.
Exemplo de Entrada e Saída juntas:
r
Erro: Fila vazia!
i destruirArmazen jaqueta f 100
i salvarDonzela hb20 e 300
i montarObservatorioMonteM2 binoculo d 400
i eliminarChefao milDolares a 2000
i eliminarBando dezmilDolares a 30000
r
Nome: destruirArmazen Premio: jaqueta Tipo: f tempo: 100
e
Nome: salvarDonzela Premio: hb20 Tipo: e tempo: 300
f
Nome: salvarDonzela Premio: hb20 Tipo: e tempo: 300
Nome: montarObservatorioMonteM2 Premio: binoculo Tipo: d tempo: 400
Nome: eliminarChefao Premio: milDolares Tipo: a tempo: 2000
Nome: eliminarBando Premio: dezmilDolares Tipo: a tempo: 30000
*/

#include <iostream>
#include <stdexcept>

using namespace std;

struct Dado
{
    string nome;
    string premio;
    char tipo;
    int tempo;
};

// Imprime as informações de um dado qualquer
void imprimir_dado(const Dado &umDado)
{
    cout << "Nome: " << umDado.nome << " Premio: " << umDado.premio << " Tipo: " << umDado.tipo << " Tempo: " << umDado.tempo << endl;
}

class Noh
{
    friend class Fila;

private:
    Dado mDado; // poderia ser outro tipo de variável
    Noh *mProx;

public:
    Noh(Dado v)
    {
        mDado = v;
        mProx = NULL;
    }
};

class Fila
{
public:
    // Constrói Fila vazia.
    Fila();
    // Destrutor que desaloca memória.
    ~Fila();
    // Retira e retorna o elemento que estiver na frente da Fila.
    // Escreve uma mensagem de erro se não for possível desenfileirar.
    Dado Desenfileirar();
    // Insere um elemento na Fila.
    void Enfileirar(const Dado &d);
    // Apagar todos os dados da Fila.
    void LimparTudo();
    // Retorna o elemento que está na frente da Fila, sem desenfileirar.
    inline void Primeiro();
    // Informa se a Fila está Vazia.
    inline bool Vazia();

private:
    Noh *mPtPrimeiro;
    Noh *mPtrUltimo;
};

Fila::Fila()
{
    mPtPrimeiro = NULL;
    mPtrUltimo = NULL;
}

Fila::~Fila()
{
    delete mPtPrimeiro;
}

Dado Fila::Desenfileirar()
{
    if (this->Vazia())
        throw runtime_error("Erro: Fila vazia!");
    Dado temp = mPtPrimeiro->mDado;
    Noh *novoPrimeiro = mPtPrimeiro->mProx;
    delete mPtPrimeiro;
    mPtPrimeiro = novoPrimeiro;

    return temp;
}

void Fila::Enfileirar(const Dado &d)
{
    Noh *novo = new Noh(d);
    if (this->Vazia())
    {
        mPtPrimeiro = novo;
        mPtrUltimo = novo;
    }
    else
    {
        mPtrUltimo->mProx = novo;
        mPtrUltimo = novo;
    }
}

void Fila::LimparTudo()
{
    while (!this->Vazia())
    {
        this->Desenfileirar();
    }
}

void Fila::Primeiro()
{
    if (this->Vazia())
        throw runtime_error("Erro: Fila vazia!");
    imprimir_dado(mPtPrimeiro->mDado);
}

bool Fila::Vazia()
{
    return mPtPrimeiro == NULL;
}

int main()
{
    Fila fila;
    Dado info;
    char comando;
    do
    {
        try
        {
            cin >> comando;
            switch (comando)
            {
            case 'i': // inserir
                cin >> info.nome >> info.premio >> info.tipo >> info.tempo;
                fila.Enfileirar(info);
                break;
            case 'r': // remover
                imprimir_dado(fila.Desenfileirar());
                break;
            case 'l': // limpar tudo
                fila.LimparTudo();
                break;
            case 'e': // espiar
                fila.Primeiro();
                break;
            case 'f': // finalizar
                break;
            default:
                cerr << "comando inválido\n";
            }
        }
        catch (runtime_error &e)
        {
            cout << e.what() << endl;
        }
    } while (comando != 'f'); // finalizar execução

    while (!fila.Vazia())
    {
        imprimir_dado(fila.Desenfileirar());
    }

    cout << endl;
    return 0;
}