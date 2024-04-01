/*
Questão 3: Minheap - Organização de um robô domestico - Alterar prioridade de um dado
Modifique a sua estrutura heap para que considere a maior prioridade de execução de uma tarefa. No caso considere a tarefa com maior prioridade indicada pelo valor 1 e a medida que o valor aumenta a prioridade diminui. Implemente o método
alteraPrioridade()
nessa minheap. A alteração de prioridade implica que o dado alterado deva ser rearranjado, de forma a manter as propriedades do heap.
Você pode (
e deve!
) utilizar o código que você desenvolveu na atividade "Heap - Organização de um robô domestico" como base.
Com essa finalidade, você deverá adicionar mais um comando, como segue:
a seguindo de uma string e um inteiro: altera a prioridade da atividade com o nome informado com o novo valor.
Exemplo de Entrada e Saída juntas:
10
r
Erro ao retirar raiz
p
Heap vazia!
i livingroom r 35 58 5
i tvroom t 18 28 8
i kitchen c 180 200 1
i bedroom1 x 99 90 2
i bedroom2 x 33 50 5
i bedroom3 v 56 80 8
i MasterBedroom x 56 70 9
i Bathroom1 n 32 56 7
i Bathroom2 n 44 80 5
i LaundryRoom h 15 7 1
i entrace a 10 5 2
Erro ao inserir
p
[kitchen/c/180/200/1] [LaundryRoom/h/15/7/1] [livingroom/r/35/58/5] [Bathroom2/n/44/80/5] [bedroom1/x/99/90/2] [bedroom3/v/56/80/8] [MasterBedroom/x/56/70/9] [tvroom/t/18/28/8] [Bathroom1/n/32/56/7]
[bedroom2/x/33/50/5] 
a kitchen 5
p
[LaundryRoom/h/15/7/1] [bedroom1/x/99/90/2] [livingroom/r/35/58/5] [Bathroom2/n/44/80/5] [kitchen/c/180/200/5] [bedroom3/v/56/80/8] [MasterBedroom/x/56/70/9] [tvroom/t/18/28/8] [Bathroom1/n/32/56/7] 
[bedroom2/x/33/50/5] 
r
LaundryRoom
p
[bedroom1/x/99/90/2] [bedroom2/x/33/50/5] [livingroom/r/35/58/5] [Bathroom2/n/44/80/5] [kitchen/c/180/200/5] [bedroom3/v/56/80/8] [MasterBedroom/x/56/70/9] [tvroom/t/18/28/8] [Bathroom1/n/32/56/7] 
f
*/

#include <iostream>
#include <utility>   // para usar swap
#include <stdexcept> // para usar exceção com runtime_error

using namespace std;

struct dado
{
    string nomeTarefa;
    char tipoTarefa;
    int energiaGasta;
    int tempoEstimado;
    int prioridade;
};

bool operator>(dado d1, dado d2)
{
    return d1.prioridade < d2.prioridade;
}

bool operator<(dado d1, dado d2)
{
    return d1.prioridade > d2.prioridade;
}

ostream &operator<<(ostream &output, const dado &d)
{
    output << "[" << d.nomeTarefa << "/" << d.tipoTarefa << "/" << d.energiaGasta << "/" << d.tempoEstimado << "/" << d.prioridade << "]";
    return output;
}

class MaxHeap
{
private:
    dado *heap;
    int capacidade;
    int tamanho;
    inline int pai(int i);
    inline int esquerdo(int i);
    inline int direito(int i);
    void corrigeDescendo(int i);
    void corrigeSubindo(int i);

public:
    MaxHeap(int cap);
    ~MaxHeap();
    void imprime();
    dado retiraRaiz();
    void insere(dado d);
    int getTamanho();
    void alteraPrioridade(string nome, int prioridade);
};

MaxHeap::MaxHeap(int cap)
{
    capacidade = cap;
    heap = new dado[cap];
    tamanho = 0;
}

MaxHeap::~MaxHeap()
{
    capacidade = 0;
    delete[] heap;
}

int MaxHeap::pai(int i)
{
    return (i - 1) / 2;
}

int MaxHeap::esquerdo(int i)
{
    return 2 * i + 1;
}

int MaxHeap::direito(int i)
{
    return 2 * i + 2;
}

void MaxHeap::corrigeDescendo(int i)
{
    int esq = esquerdo(i);
    int dir = direito(i);
    int maior = i;

    if (esq < tamanho && heap[esq] > heap[maior])
    {
        maior = esq;
    }

    if (dir < tamanho && heap[dir] > heap[maior])
    {
        maior = dir;
    }

    if (maior != i)
    {
        swap(heap[i], heap[maior]);
        corrigeDescendo(maior);
    }
}

void MaxHeap::corrigeSubindo(int i)
{
    int p = pai(i);

    if (heap[i] > heap[p])
    {
        swap(heap[i], heap[p]);
        corrigeSubindo(p);
    }
}

void MaxHeap::imprime()
{
    if (tamanho > 0)
    {
        for (int i = 0; i < tamanho; i++)
        {
            if (heap[i].nomeTarefa != " ")
                cout << heap[i] << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "Heap vazia!" << endl;
    }
}

dado MaxHeap::retiraRaiz()
{
    dado aux = heap[0];
    swap(heap[0], heap[tamanho - 1]);
    tamanho--;
    corrigeDescendo(0);
    return aux;
}

void MaxHeap::insere(dado d)
{
    if (tamanho == capacidade)
    {
        cout << "Erro ao inserir" << endl;
    }
    else
    {
        heap[tamanho] = d;
        corrigeSubindo(tamanho);
        tamanho++;
    }
}

int MaxHeap::getTamanho()
{
    return tamanho;
}

void MaxHeap::alteraPrioridade(string nome, int prioridade)
{
    bool encontrado = false;

    int i = 0;
    while (i < tamanho && !encontrado)
    {
        if (heap[i].nomeTarefa == nome)
        {
            heap[i].prioridade = prioridade;
            encontrado = true;
        }
        i++;
    }

    if (encontrado)
    {
        corrigeDescendo(i - 1);
        corrigeSubindo(i - 1);
    }
    else
    {
        cout << "Erro ao alterar prioridade" << endl;
    }
}

int main()
{
    int capacidade;
    dado info;
    char comando;

    cin >> capacidade;
    MaxHeap meuHeap(capacidade);

    do
    {
        try
        {
            cin >> comando;
            switch (comando)
            {
            case 'i': // inserir
                cin >> info.nomeTarefa >> info.tipoTarefa >> info.energiaGasta >> info.tempoEstimado >> info.prioridade;
                meuHeap.insere(info);
                break;
            case 'r': // remover
                if (meuHeap.getTamanho() > 0)
                {
                    cout << meuHeap.retiraRaiz().nomeTarefa << endl;
                }
                else
                {
                    cout << "Erro ao retirar raiz" << endl;
                }
                break;
            case 'p': // limpar tudo
            {
                meuHeap.imprime();
                break;
            }
            case 'a':
            {
                string nomeTarefa;
                int prioridade;
                cin >> nomeTarefa >> prioridade;
                meuHeap.alteraPrioridade(nomeTarefa, prioridade);
                break;
            }
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
    cout << endl;
    return 0;
}