/*
Implemente uma função que realize a ordenação dos elementos da fila pelo número do processo. O elemento com menor número deve ficar na frente da fila e o de maior valor no fim.

Você pode (e deve!) utilizar o código que você desenvolveu na atividade "Fila com armazenamento em vetor - Lista de processos em uma repartição pública" como base.

Com essa finalidade, você deverá adicionar mais um comando, como segue:

o: para ordenar a fila.
Saídas:

Todas as saídas de comandos já estão implementadas na função principal código entregue, somente falta implementar a chamada para a remoção. Ao terminar a execução do programa, todos os itens da pilha são desempilhados e escritos.

Exemplo de Entrada e Saída juntas:

r
Erro: fila vazia!
i processo1 Joao a 2
i processo2 Maria c 5
i processo3 Severino d 9
i processo4 Marcos f 12
i processo5 Barnabe a 10
i processo6 Tiao z 22
i processo7 Marlon m 40
Erro: fila cheia!
r
Nome: processo1 Assunto: Joao Tipo: a Processo: 2
e
Nome: processo2 Assunto: Maria Tipo: c Processo: 5
i processo7 Marlon m 4
o
f
Nome: processo7 Assunto: Marlon Tipo: m Processo: 4
Nome: processo2 Assunto: Maria Tipo: c Processo: 5
Nome: processo3 Assunto: Severino Tipo: d Processo: 9
Nome: processo5 Assunto: Barnabe Tipo: a Processo: 10
Nome: processo4 Assunto: Marcos Tipo: f Processo: 12
Nome: processo6 Assunto: Tiao Tipo: z Processo: 22
*/

#include <iostream>

using namespace std;

// const int FILAVAZIA = -1;
const int CAPACIDADE_FILA = 6;

// Definição de uma estrutura de dado para armazenar informações
struct Dado
{
    string nome;
    string assunto;
    char tipo;
    int nProcesso;
};

// Função para imprimir as informações de um dado
void imprimir_dado(const Dado &umDado)
{
    cout << "Nome: " << umDado.nome << " ";
    cout << "Assunto: " << umDado.assunto << " ";
    cout << "Tipo: " << umDado.tipo << " ";
    cout << "Processo: " << umDado.nProcesso << " ";
    cout << endl;
}

// Classe para representar uma fila
class Fila
{
private:
    Dado *mFila;
    int posPrimeiro, posUltimo, tamanho;
    Dado encontrarMenor();

public:
    // Construtor
    Fila();
    // Destrutor
    ~Fila();
    // Desenfileira um elemento
    Dado Desenfileirar();
    // Enfileira um elemento
    void Enfileirar(const Dado &d);
    // Limpa toda a fila
    void LimparTudo();
    // Imprime as informações do primeiro elemento sem removê-lo
    inline void PrimeiroDaFila();
    // Verifica se a fila está vazia
    inline bool Vazia();
    // Verifica se a fila está cheia
    inline bool Cheia();
    // Ordena a fila de acordo com o número do processo
    void ordenar();
};

// Construtor da fila
Fila::Fila()
{
    mFila = new Dado[6];
    posPrimeiro = posUltimo = -1;
    tamanho = 0;
}

// Destrutor da fila
Fila::~Fila()
{
    LimparTudo();
    delete[] mFila;
}

// Remove o elemento do topo da fila
Dado Fila::Desenfileirar()
{
    if (this->Vazia())
        throw runtime_error("Erro: fila vazia!");
    else
    {
        Dado aux = mFila[posPrimeiro];
        if (posPrimeiro == posUltimo)
        {
            posPrimeiro = posUltimo = -1;
        }
        else
        {
            posPrimeiro = (posPrimeiro + 1) % CAPACIDADE_FILA;
        }
        tamanho--;
        return aux;
    }
}

// Insere um elemento na fila
void Fila::Enfileirar(const Dado &d)
{
    if (this->Cheia())
        throw runtime_error("Erro: fila cheia!");
    else
    {
        posUltimo = (posUltimo + 1) % CAPACIDADE_FILA;
        mFila[posUltimo] = d;
        tamanho++;
    }
    if (posPrimeiro == -1)
    {
        posPrimeiro++;
    }
}

// Limpa toda a fila
void Fila::LimparTudo()
{
    while (!Vazia())
    {
        Desenfileirar();
    }
}

// Imprime as informações do primeiro elemento sem removê-lo
void Fila::PrimeiroDaFila()
{
    if (this->Vazia())
        throw runtime_error("Erro: fila vazia!");
    else
        imprimir_dado(mFila[posPrimeiro]);
}

// Verifica se a fila está vazia
bool Fila::Vazia()
{
    return posPrimeiro == -1;
}

// Verifica se a fila está cheia
bool Fila::Cheia()
{
    return tamanho == CAPACIDADE_FILA;
}

// Encontra e remove o menor elemento da fila
Dado Fila::encontrarMenor()
{
    Dado aux;
    Dado menor = Desenfileirar();
    Enfileirar(menor);
    for (int i = 0; i < tamanho - 1; i++)
    {
        aux = Desenfileirar();
        if (aux.nProcesso < menor.nProcesso)
        {
            menor = aux;
        }
        Enfileirar(aux);
    }
    int tamanhoAux = tamanho;
    for (int i = 0; i < tamanhoAux; i++)
    {
        aux = Desenfileirar();
        if (aux.nProcesso != menor.nProcesso)
        {
            Enfileirar(aux);
        }
    }
    return menor;
}

// Ordena a fila de acordo com o número do processo
void Fila::ordenar()
{
    Fila *aux = new Fila();
    while (!Vazia())
    {
        aux->Enfileirar(encontrarMenor());
    }
    while (!aux->Vazia())
    {
        Enfileirar(aux->Desenfileirar());
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
            case 'o': // ordenar
                fila.ordenar();
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
