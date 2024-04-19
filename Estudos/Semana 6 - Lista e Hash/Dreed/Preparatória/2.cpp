/*
Questão 2: Lista Duplamente Encadeada - Ações de usuários em um programa
Crie um programa que seja capaz de armazenar em uma lista duplamente encadeada as ações de usuários em um programa. Cada elemento da lista deve ter um identificador, o nome da ação, tempo para execução total e tempo já consumido de processamento. Você poderá utilizar o
código fornecido
como base de implementação.
Os comandos que deverão ser utilizados para execução do programa são:
i: inserir uma nova ação no inicio da lista. O formato de entrada é:
Identificador NomeAcao TempoExecução TempoConsumido
h: inserir uma nova ação no final da lista. O formato de entrada é:
Identificador NomeAcao TempoExecução TempoConsumido
m: inserir uma nova equipe na posição informada pelo inteiro. Considere 0 como no início e imprima "Posição Inexistente!" caso não seja possível inserir na posição indicada. O formato de entrada é:
posiçãoASerInserida Identificador NomeAcao TempoExecução TempoConsumido
r: apagar uma determinada ação do início da lista. Caso não exista a equipe deverá imprimir
Remoção em lista vazia!
a: apagar uma determinada ação do fim da lista. Caso não exista a equipe deverá imprimir
Remoção em lista vazia!
p: imprimir lista de ações cadastradas em ordem de inserção e, em seguida, em ordem inversa. Imprimir
Lista vazia!
quando não tiver elemento a ser impresso.
s: buscar por uma ação a partir de seu nome. Imprimir
Nao encontrado
quando a busca não obtiver sucesso.
Nota: o formato de saída das ações deve ser:
(Identificador, NomeAcao, TempoExecução, TempoConsumido)
. Para mais instâncias de ações (comando de impressão), separar cada uma delas por quebras de linha.
Entradas:
Comandos detalhados no exercício
Saídas:
Impressões detalhadas no exercício
Exemplo de Entrada e Saída misturados:
r
Remoção em lista vazia!
a
Remoção em lista vazia!
p
Lista vazia!
s empilharProcessos
Lista vazia!
i 1 limparCache 123 99
h 2 semaforoProc 32 11
m 1 3 paralelismoProc 65 23
p
(1, limparCache, 123, 99)
(3, paralelismoProc, 65, 23)
(2, semaforoProc, 32, 11)
 IMPRIMINDO REVERSO
(2, semaforoProc, 32, 11)
(3, paralelismoProc, 65, 23)
(1, limparCache, 123, 99)
s empilharProcessos
Nao encontrado
r
p
(3, paralelismoProc, 65, 23)
(2, semaforoProc, 32, 11)
 IMPRIMINDO REVERSO
(2, semaforoProc, 32, 11)
(3, paralelismoProc, 65, 23)
a
p
(3, paralelismoProc, 65, 23)
 IMPRIMINDO REVERSO
(3, paralelismoProc, 65, 23)
f
*/

#include <iostream>
#include <cstdlib>

using namespace std;

struct acaoPrograma
{
    int identificador;
    string nomeAcao;
    int tempoExecucao;
    int tempoConsumido;
};

class noh
{
    friend class listadup;

private:
    acaoPrograma acao; // poderia ser outro tipo de variável
    noh *proximo;
    noh *anterior;

public:
    // noh();
    noh(acaoPrograma d);
};

// construindo dado chamando seu construtor
noh::noh(acaoPrograma d)
{
    acao = d;
    proximo = NULL;
    anterior = NULL;
}

// lista dinamicamente encadeada
class listadup
{
private:
    noh *primeiro;
    noh *ultimo;
    int tamanho;
    void removeTodos(); // remove todos os elementos da lista
public:
    listadup();
    listadup(const listadup &umaLista);
    ~listadup();
    // sobrecarga do operador de atribuição
    listadup &operator=(const listadup &umaLista);
    // inserção, remoção e procura
    void insereNoFim(acaoPrograma acao);
    void insereNoInicio(acaoPrograma acao);
    void insereNaPosicao(int posicao, acaoPrograma acao);
    int procura(string valor); // retorna a posicao
    void imprime();
    inline bool vazia();
    void removeNoFim();
    void removeNoInicio();
};

// constrói uma lista inicialmente vazia
listadup::listadup()
{
    primeiro = NULL;
    ultimo = NULL;
    tamanho = 0;
}

// construtor de cópia
listadup::listadup(const listadup &umaLista)
{
    primeiro = NULL;
    ultimo = NULL;
    tamanho = 0;
    noh* aux = umaLista.primeiro;

    // Copia os elementos da lista umaLista para a nova lista
    while (aux != NULL) {
        insereNoFim(aux->acao);
        aux = aux->proximo;
    }
}

// destrutor da lista (chama função privada auxiliar)
listadup::~listadup()
{
    removeTodos();
}

// remove todos os elementos da lista
void listadup::removeTodos()
{
    
}

// sobrecarga do operador de atribuição
listadup &listadup::operator=(const listadup &umaLista)
{
    // limpa a lista atual
    removeTodos();
    // percorre a lista recebida como parâmetro, copiando os dados
    noh *aux = umaLista.primeiro;

    while (aux != NULL)
    {
        insereNoFim(aux->acao);
        aux = aux->proximo;
    }

    return *this;
}

// insere por no final da lista
void listadup::insereNoFim(acaoPrograma acao)
{
}

// insere no início da lista
void listadup::insereNoInicio(acaoPrograma acao)
{
}

// insere em uma determinada posição da lista
void listadup::insereNaPosicao(int posicao, acaoPrograma acao)
{
}

int listadup::procura(string valor)
{
}

// método básico que *percorre* uma lista, imprimindo seus elementos
void listadup::imprime()
{
}

// verifica se a lista está vazia
inline bool listadup::vazia()
{
}

void listadup::removeNoInicio()
{
}

void listadup::removeNoFim()
{
}

int main()
{
    listadup minhaLista;
    acaoPrograma info;
    char comando;
    int posicao;
    string nomeEquipe;

    do
    {
        try
        {
            cin >> comando;
            switch (comando)
            {
            case 'i': // inserir
                cin >> info.identificador >> info.nomeAcao >> info.tempoExecucao >> info.tempoConsumido;
                minhaLista.insereNoInicio(info);
                break;
            case 'h': // inserir
                cin >> info.identificador >> info.nomeAcao >> info.tempoExecucao >> info.tempoConsumido;
                minhaLista.insereNoFim(info);
                break;
            case 'm': // inserir
                cin >> posicao;
                cin >> info.identificador >> info.nomeAcao >> info.tempoExecucao >> info.tempoConsumido;
                minhaLista.insereNaPosicao(posicao, info);
                break;
            case 's': // procurar
                cin >> nomeEquipe;
                posicao = minhaLista.procura(nomeEquipe);
                if (posicao == -1)
                    cout << "Nao encontrado" << endl;
                else
                    cout << posicao << endl;
                break;
            case 'r': // remover
                minhaLista.removeNoInicio();
                break;
            case 'a': // remover
                minhaLista.removeNoFim();
                break;
            case 'p': // limpar tudo
                minhaLista.imprime();
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
    cout << endl;
    return 0;
}