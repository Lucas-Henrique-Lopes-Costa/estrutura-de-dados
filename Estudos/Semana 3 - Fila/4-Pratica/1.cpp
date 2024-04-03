/*
Questão 1: Fila com encadeamento - Lista de tarefas do jogador - Maior recompensa no prazo
Modifique o tipo do campo prêmio para inteiro, sendo o valor a ser recebido em moedas digitais pela atividade realizada pelo jogador. Implemente uma função que imprima a soma das recompensas das atividades com tempo menor que o informado e coloque essas atividade no início da fila. Caso não exista nenhuma atividade menor que o valor informado, deve ser impresso o valor 0.
Você pode (
e deve!
) utilizar o código que você desenvolveu na atividade "Fila com encadeamento - Lista de tarefas do jogador" como base.
Com essa finalidade, você deverá adicionar mais um comando, como segue:
p seguido de um inteiro: para contabilizar (e imprimir)  o valor total do premio das atividades que foram realizadas dentro do valor determinado.
Saídas:
Todas as saídas de comandos já estão implementadas na função principal código entregue, somente falta implementar a chamada para a remoção. Ao terminar a execução do programa, todos os itens da pilha são desempilhados e escritos.
Exemplo de Entrada e Saída juntas:
r
Erro: Fila vazia!
i destruirArmazen 252 f 100
i salvarDonzela 888 e 300
i montarObservatorioMonteM2 582 d 400
i eliminarChefao 12585 a 2000
i eliminarBando 25354 a 30000
p 500
1722
r
Nome: destruirArmazen Premio: 252 Tipo: f tempo: 100
e
Nome: salvarDonzela Premio: 888 Tipo: e tempo: 300
f
Nome: salvarDonzela Premio: 888 Tipo: e tempo: 300
Nome: montarObservatorioMonteM2 Premio: 582 Tipo: d tempo: 400
Nome: eliminarChefao Premio: 12585 Tipo: a tempo: 2000
Nome: eliminarBando Premio: 25354 Tipo: a tempo: 30000
*/

/* Classe Fila encadeada
 *
 * by Renato Ramos da Silva, 2023, Estruturas de Dados
 * Editada por Pedro Gonçalves, 2024
 *
 */

#include <iostream>
#include <stdexcept>

using namespace std;

struct Dado
{
    string nome;
    int premio;
    char tipo;
    int tempo;
};

// Imprime as informações de um dado qualquer
void imprimir_dado(const Dado &umDado)
{

    cout << "Nome: " << umDado.nome << " Premio: " << umDado.premio << " Tipo: " << umDado.tipo << " tempo: " << umDado.tempo << endl;
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
        mProx = nullptr;
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
    void imprimirFaixa(int faixa);
    void Topo();

private:
    Noh *mPtPrimeiro;
    Noh *mPtrUltimo;
    int tamanho;
};

Fila::Fila()
{
    tamanho = 0;
    mPtrUltimo = nullptr;
    mPtPrimeiro = nullptr;
}

Fila::~Fila()
{
    LimparTudo();
}

Dado Fila::Desenfileirar()
{
    if (this->Vazia())
        throw runtime_error("Erro: Fila vazia!");

    Dado dado = mPtPrimeiro->mDado;
    Noh *aux = mPtPrimeiro;
    mPtPrimeiro = mPtPrimeiro->mProx;
    delete aux;

    tamanho--;

    if (Vazia())
        mPtrUltimo = nullptr;

    return dado;
}

void Fila::Enfileirar(const Dado &d)
{
    Noh *novo = new Noh(d);
    if (Vazia())
        mPtPrimeiro = novo;
    else
        mPtrUltimo->mProx = novo;

    mPtrUltimo = novo;
    tamanho++;
}
void Fila::Topo()
{
    if (this->Vazia())
        throw runtime_error("Erro: fila vazia!");

    cout << "Nome: " << mPtPrimeiro->mDado.nome << " Premio: " << mPtPrimeiro->mDado.premio << " Tipo: " << mPtPrimeiro->mDado.tipo << " Tempo: " << mPtPrimeiro->mDado.tempo << endl;
}

void Fila::LimparTudo()
{
    while (!Vazia())
    {
        Desenfileirar();
    }
}

void Fila::Primeiro()
{
    if (this->Vazia())
        throw runtime_error("Erro: Fila vazia!");
    // completar com o código, caso não esteja vazia
}

bool Fila::Vazia()
{
    return (mPtPrimeiro == nullptr);
}

void Fila::imprimirFaixa(int faixa)
{
    Fila f2;

    int auxTamanho = tamanho;

    int soma = 0;
    for (int i = 0; i < auxTamanho; i++)
    {
        // ordernar f1
        Dado temp = Desenfileirar();
        if (temp.tempo < faixa)
        {
            soma += temp.premio;
            f2.Enfileirar(temp);
        }
        else
        {
            Enfileirar(temp);
        }
    }

    cout << soma << endl;

    // enviar o que restou da f1 para f2
    while (!Vazia())
    {
        Dado temp2 = Desenfileirar();
        f2.Enfileirar(temp2);
    }

    // pegar f2 e enviar para f1
    while (!f2.Vazia())
    {
        Dado temp3 = f2.Desenfileirar();
        Enfileirar(temp3);
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
                fila.Topo();
                break;
            case 'p':
                int faixa;
                cin >> faixa;
                fila.imprimirFaixa(faixa);
                break;
            case 'f':
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
    while (not fila.Vazia())
    {
        imprimir_dado(fila.Desenfileirar());
    }
    cout << endl;
    return 0;
}