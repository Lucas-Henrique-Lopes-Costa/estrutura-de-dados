/*
O jogador resolveu realizar o maior número de tarefas da lista abaixo de um determinado tempo que é informado (valor inteiro positivo). Para isso ele resolveu fazer primeiro as tarefas que tem menor custo até atingir o valor especificado (mas este não incluso). Implemente uma função que imprima o maior número de tarefas da fila em que a soma das tarefas seja menor que o valor informado. Além disso, elimine as atividades da fila.

Você pode (e deve!) utilizar o código que você desenvolveu na atividade "Fila com encadeamento - Lista de tarefas do jogador" como base.

Com essa finalidade, você deverá adicionar mais um comando, como segue:

t seguido de um inteiro: para contabilizar (e imprimir) as atividades que foram realizadas dentro do valor determinado.
Saídas:

Todas as saídas de comandos já estão implementadas na função principal código entregue, somente falta implementar a chamada para a remoção. Ao terminar a execução do programa, todos os itens da pilha são desempilhados e escritos.

Exemplo de Entrada e Saída juntas:

r
Erro: Fila vazia!
i destruirArmazen jaqueta f 100
i salvarDonzela hb20 e 300
i montarObservatorioMonteM2 binoculo d 400
i eliminarChefao milDolares a 2000
i eliminarBando dezmilDolares a 30000
t 800
Nome: destruirArmazen Premio: jaqueta Tipo: f tempo: 100
Nome: salvarDonzela Premio: hb20 Tipo: e tempo: 300
r
Nome: montarObservatorioMonteM2 Premio: binoculo Tipo: d tempo: 400
e
Nome: eliminarChefao Premio: milDolares Tipo: a tempo: 2000
f
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
    cout << "Nome: " << umDado.nome << " ";
    cout << "Premio: " << umDado.premio << " ";
    cout << "Tipo: " << umDado.tipo << " ";
    cout << "tempo: " << umDado.tempo << " ";
    cout << endl;
}

class Noh
{
    friend class Fila;

private:
    Dado mDado;
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

    // Informa se a Fila está Vazia.
    inline bool Vazia();

    // Realiza as tarefas de acordo com o tempo
    void realizarTarefas(int tempo);

    // Retorna o elemento que está na frente da Fila, sem desenfileirar.
    inline Dado Primeiro();

private:
    Noh *mPtPrimeiro;
    Noh *mPtrUltimo;
    int tamanho;
};

Fila::Fila()
{
    mPtPrimeiro = mPtrUltimo = NULL;
    tamanho = 0;
}

Fila::~Fila()
{
    LimparTudo();
}

// Retira e retorna o elemento que estiver na frente da Fila.
// Escreve uma mensagem de erro se não for possível desenfileirar.
Dado Fila::Desenfileirar()
{
    if (this->Vazia())
        throw runtime_error("Erro: Fila vazia!");
    else
    {
        Noh *aux = mPtPrimeiro;
        Dado valor = mPtPrimeiro->mDado;
        mPtPrimeiro = mPtPrimeiro->mProx;
        delete aux;
        tamanho--;
        return valor;
    }
}

// Insere um elemento na Fila.
void Fila::Enfileirar(const Dado &d)
{
    Noh *novo = new Noh(d);
    if (mPtPrimeiro == NULL)
    {
        mPtPrimeiro = novo;
    }
    else
    {
        mPtrUltimo->mProx = novo;
    }
    mPtrUltimo = novo;
    tamanho++;
}

// Apagar todos os dados da Fila.
void Fila::LimparTudo()
{
    while (!Vazia())
    {
        Desenfileirar();
    }
}

// Informa se a Fila está Vazia.
bool Fila::Vazia()
{
    return tamanho == 0;
}

// Retorna o elemento que está na frente da Fila, sem desenfileirar.
Dado Fila::Primeiro()
{
    if (this->Vazia())
        throw runtime_error("Erro: Fila vazia!");
    return mPtPrimeiro->mDado;
}

// Realiza as tarefas de acordo com o menor tempo até o tempo limite
void Fila::realizarTarefas(int tempo)
{
    if (this->Vazia())
        throw runtime_error("Erro: Fila vazia!");
    int soma = 0;
    int tamAux = tamanho;
    int menorTempo;
    Dado aux;
    while (soma < tempo && !Vazia())
    {
        menorTempo = Primeiro().tempo; // Inicializa com o primeiro tempo
        // Encontrar o menor tempo
        for (int i = 0; i < tamAux; i++)
        {
            aux = Desenfileirar(); // Desenfileira
            Enfileirar(aux);       // Enfileira novamente
            if (aux.tempo < menorTempo)
            {
                menorTempo = aux.tempo;
            }
        }
        soma += menorTempo;
        // Verifica se é possivel realizar a tarefa
        if (soma < tempo)
        {
            // Procura a tarefa para retirar
            for (int i = 0; i < tamAux; i++)
            {
                aux = Desenfileirar();
                if (aux.tempo == menorTempo)
                {
                    imprimir_dado(aux);
                }
                else
                {
                    Enfileirar(aux);
                }
            }
            tamAux = tamanho;
        }
    }
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
                imprimir_dado(fila.Primeiro());
                break;
            case 't': // realizar tarefas
                int tempo;
                cin >> tempo;
                fila.realizarTarefas(tempo);
                break;
            case 'f': // finalizar
                // checado no do-while
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