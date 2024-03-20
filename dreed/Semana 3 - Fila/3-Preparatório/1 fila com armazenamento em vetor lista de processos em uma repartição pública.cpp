/*
Questão 1: Fila com armazenamento em vetor - Lista de processos em uma repartição pública
Implemente uma estrutura de dados fila, utilizando armazenamento em vetor, para implementar uma lista de processos para uma repartição pública, utilizando como base o
código fornecido
. A estrutura deve possibilitar, pelo menos, as seguintes ações: enfileiramento e desenfileiramento de itens, verificação do item no topo da pilha e limpeza de processos (remoção de todos os elementos da fila). O desenfileiramento deve escrever mensagem de erro na saída ("
Erro: fila vazia!
"), quando a fila já estiver vazia. O enfileiramento também deve gerar mensagem de erro ("
Erro: fila cheia!
"), quanto todas as posições do vetor estiverem ocupadas. Os itens da lista de processos possuem os seguintes atributos: assunto (uma string sem espaços), nome do interessado(uma string sem espaços), tipo (um único caracter) e numero do processo (um inteiro). Além disso, essa repartição tem capacidade para trabalhar com
apenas seis processos por vez
.
Entradas:
O programa deve aceitar os seguintes comandos:
i seguido de uma string, um caracter e um inteiro: para inserir um item na lista de processos
r: para retirar um item da lista de processos
l: para limpar (remover todos) os itens da lista de processos
e: para espiar o topo da lista de processo (escreve o topo sem removê-lo)
f: para finalizar a execução do programa
Saídas:
Todas as saídas de comandos já estão implementadas na função principal desse código exemplo fornecido. Ao terminar a execução do programa, todos os itens da fila são desempilhados e escritos.
Exemplo de Entrada e Saída juntas:
r
Erro: fila vazia!
i processo1 Joao a 2
i processo2 Maria c 5
i processo3 Severino d 9
i processo4 Marcos f 12
i processo5 Barnabe a 10
i processo6 Tiao z 22
i processo7 Marlon a 40
Erro: fila cheia!
r
Nome: processo1 Assunto: Joao Tipo: a Processo: 2
e
Nome: processo2 Assunto: Maria Tipo: c Processo: 5
i processo7 Marlon a 40
f
Nome: processo2 Assunto: Maria Tipo: c Processo: 5
Nome: processo3 Assunto: Severino Tipo: d Processo: 9
Nome: processo4 Assunto: Marcos Tipo: f Processo: 12
Nome: processo5 Assunto: Barnabe Tipo: a Processo: 10
Nome: processo6 Assunto: Tiao Tipo: z Processo: 22
Nome: processo7 Assunto: Marlon Tipo: a Processo: 40
*/

#include <iostream>

using namespace std;

const int FILAVAZIA = -1;
const int CAPACIDADE_FILA = 6;

struct Dado
{
    string nome;
    string assunto;
    char tipo;
    int nProcesso;
};

// Imprime informações de um dado qualquer.
void imprimir_dado(const Dado &umDado)
{
    cout << "Nome: " << umDado.nome << " Assunto: " << umDado.assunto << " Tipo: " << umDado.tipo << " Processo: " << umDado.nProcesso << endl;
}

class Fila
{
private:
    Dado *mFila;
    int posPrimeiro, posUltimo;

public:
    // Constrói fila vazia.
    Fila();
    // Destrutor que desaloca memória.
    ~Fila();
    // Retira e retorna o elemento que estiver na primeira posição.
    Dado Desenfileirar();
    // Insere um elemento na fila.
    void Enfileirar(const Dado &d);
    // Apagar todos os dados da fila.
    void LimparTudo();
    // Imprime os valores do elemento que está na frente da fila, sem Desenfileirar.
    inline void PrimeiroDaFila();
    // Informa se a fila está Vazia.
    inline bool Vazia();
    // Informa se a fila está Cheia.
    inline bool Cheia();
};

Fila::Fila()
{
    mFila = new Dado[CAPACIDADE_FILA];
    posPrimeiro = posUltimo = FILAVAZIA;
}

Fila::~Fila()
{
    delete[] mFila;
}

Dado Fila::Desenfileirar()
{
    if (this->Vazia())
        throw runtime_error("Erro: fila vazia!");
    // completar com código necessário caso fila não esteja vazia
    Dado temp = mFila[posPrimeiro];
    if (posPrimeiro == posUltimo)
        posPrimeiro = posUltimo = FILAVAZIA;
    else
        posPrimeiro = (posPrimeiro + 1) % CAPACIDADE_FILA;
    return temp;
}

void Fila::Enfileirar(const Dado &d)
{
    if (this->Cheia())
        throw runtime_error("Erro: fila cheia!");
    // completar com código necessário caso fila não esteja vazia
    posUltimo = (posUltimo + 1) % CAPACIDADE_FILA;
    mFila[posUltimo] = d;
    if (posPrimeiro == FILAVAZIA)
        posPrimeiro = 0;
}

void Fila::LimparTudo()
{
    posPrimeiro = posUltimo = FILAVAZIA;
}

void Fila::PrimeiroDaFila()
{
    if (this->Vazia())
        throw runtime_error("Erro: fila vazia!");
    // completar com código necessário caso fila não esteja vazia
    imprimir_dado(mFila[posPrimeiro]);
}

bool Fila::Vazia()
{
    return posPrimeiro == FILAVAZIA;
}

bool Fila::Cheia()
{
    return (posUltimo + 1) % CAPACIDADE_FILA == posPrimeiro; // se o valor do próximo elemento é igual ao primeiro, a fila está cheia
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
                cin >> info.nome >> info.assunto >> info.tipo >> info.nProcesso;
                fila.Enfileirar(info);
                break;
            case 'r': // remover
                imprimir_dado(fila.Desenfileirar());
                break;
            case 'l': // limpar tudo
                fila.LimparTudo();
                break;
            case 'e': // espiar
                if (!fila.Vazia())
                    fila.PrimeiroDaFila();
                else
                    cout << "Erro: fila vazia!" << endl;
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
    while (not fila.Vazia())
    {
        imprimir_dado(fila.Desenfileirar());
    }
    cout << endl;
    return 0;
}