/*
Questão 5: Lista Duplamente Encadeada - Ações de usuários em um programa - Deque
Utilizando como base o código que você desenvolveu na atividade "Lista Simplesmente Encadeada - Equipes de Maratona" faça as adaptações necessárias para que ela funcione como deque.  Todos os métodos que não devem ser permitidos para uso em uma deque devem retornar ao usuário que o procedimento não é permitido.
Uma deque é uma estrutura de dados lista em que a remoção e inserção só é permitida em suas pontas (ou seja: no início e no final da lista).
Feito isso, você deverá adicionar mais um procedimento fora da classe, que recebe uma deque e uma string e remove um elemento qualquer,
mas sem quebrar a estrutura
. Ou seja: a remoção deverá ser implementada de maneira similar à remoção em uma pilha ou fila. Utilizando esse procedimento, adicione a seguinte opção no menu da função principal:
x seguido de uma string: remove da lista o elemento que possui o nome da ação informado pelo usuário. Imprimir
Remoção em lista vazia!
caso a chamada ao procedimento seja chamada com a lista vazia. Imprimir
Nao encontrado
caso não encontre o elemento em uma lista que possua pelo menos um elemento
Lembrando novamente: esse comando deverá ser implementado
sem quebra de estrutura
.
Saídas:
Todas as saídas de comandos já estão implementadas na função principal código entregue, somente falta implementar a chamada para remover o elemento solicitado. Ao terminar a execução do programa, todos os itens da listas são escritos.
Exemplo de Entrada e Saída juntas:
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
Operação não permitida!
i 3 paralelismoProc 65 23
p
(3, paralelismoProc, 65, 23)
(1, limparCache, 123, 99)
(2, semaforoProc, 32, 11)
 IMPRIMINDO REVERSO
(2, semaforoProc, 32, 11)
(1, limparCache, 123, 99)
(3, paralelismoProc, 65, 23)
s empilharProcessos
Nao encontrado
x limparCache
p
(3, paralelismoProc, 65, 23)
(2, semaforoProc, 32, 11)
 IMPRIMINDO REVERSO
(2, semaforoProc, 32, 11)
(3, paralelismoProc, 65, 23)
r
p
(2, semaforoProc, 32, 11)
 IMPRIMINDO REVERSO
(2, semaforoProc, 32, 11)
f
*/

#include <iostream>
#include <cstdlib>

using namespace std;

struct equipe
{
    string nomeEquipe;
    string lider;
    string linguagem;
    int qtdMembros;
};

class noh
{
    friend class lista;

private:
    equipe elenco; // poderia ser outro tipo de variável
    noh *proximo;

public:
    // noh();
    noh(equipe d);
};

// construindo time chamando seu construtor
noh::noh(equipe d)
{
    elenco = d;
    proximo = NULL;
}

// lista dinamicamente encadeada
class lista
{
private:
    noh *primeiro;
    noh *ultimo;
    int tamanho;
    void removeTodos(); // remove todos os elementos da lista

public:
    // construtores e destrutor
    lista();
    lista(const lista &umaLista);
    ~lista();
    // sobrecarga do operador de atribuição
    lista &operator=(const lista &umaLista);
    // inserção, remoção e procura
    inline void insere(equipe elenco);
    void insereNoFim(equipe elenco);
    void insereNoInicio(equipe elenco);
    void insereNaPosicao(int posicao, equipe elenco);
    int procura(string valor); // retorna a posição do nó com va
    // métodos adicionais (impressão, vazia)
    void imprime();
    void imprimeReverso();
    inline bool vazia();
    void removeNoFim();
    void removeNoInicio();
    void removeEspecifico(int index);
    int Tamanho();
};

int lista::Tamanho()
{
    if (vazia())
        return 0;

    noh *aux = primeiro;

    int tam = 0;

    while (aux != nullptr)
    {
        aux = aux->proximo;
        tam++;
    }
    return tam;
}
// constrói uma lista inicialmente vazia
lista::lista()
{
    tamanho = 0;
    primeiro = nullptr;
    ultimo = nullptr;
}

// construtor de cópia
lista::lista(const lista &umaLista)
{
    tamanho = 0;
    primeiro = nullptr;
    ultimo = nullptr;

    noh *aux = umaLista.primeiro;

    while (aux != nullptr)
    {
        insereNoFim(aux->elenco);
        aux = aux->proximo;
    }
}

// destrutor da lista (chama função privada auxiliar)
lista::~lista()
{
    removeTodos();
}

// remove todos os elementos da lista
void lista::removeTodos()
{

    noh *aux = primeiro;
    noh *temp;

    while (aux != nullptr)
    {
        temp = aux;
        aux = aux->proximo;
        delete temp;
    }

    tamanho = 0;
    primeiro = nullptr;
    ultimo = nullptr;
}

// sobrecarga do operador de atribuição
lista &lista::operator=(const lista &umaLista)
{
    // limpa a lista atual
    removeTodos();
    // percorre a lista recebida como parâmetro, copiando os dados
    noh *aux = umaLista.primeiro;

    while (aux != NULL)
    {
        insereNoFim(aux->elenco);
        aux = aux->proximo;
    }

    return *this;
}

// insere no final da lista
void lista::insereNoFim(equipe elenco)
{

    noh *novo = new noh(elenco);

    if (vazia())
    {
        primeiro = novo;
        ultimo = novo;
    }
    else
    {
        ultimo->proximo = novo;
        ultimo = novo;
    }
    tamanho++;
}

// insere no início da lista
void lista::insereNoInicio(equipe elenco)
{
    noh *novo = new noh(elenco);
    if (vazia())
    {
        primeiro = novo;
        ultimo = novo;
    }
    else
    {
        novo->proximo = primeiro;
        primeiro = novo;
    }
    tamanho++;
}

// insere um elemento em uma determinada posição da lista
void lista::insereNaPosicao(int posicao, equipe elenco)
{
    if (posicao < 0 || posicao > tamanho)
    {
        cout << "Posição Inexistente!\n";
        return;
    }

    if (posicao == 0)
    {
        insereNoInicio(elenco);
    }
    else if (posicao == tamanho)
    {
        insereNoFim(elenco);
    }
    else
    {
        // Insere na posição intermediária
        noh *novo = new noh(elenco);
        noh *aux = primeiro;
        for (int i = 0; i < posicao - 1; i++)
        {
            aux = aux->proximo;
        }
        novo->proximo = aux->proximo;
        aux->proximo = novo;
        tamanho++;
    }
}

// procura a posição de um determinado elemento
int lista::procura(string valor)
{
    if (vazia())
    {
        throw runtime_error("Lista vazia!");
    }
    noh *aux = primeiro;
    int posAux = 0;

    while ((aux != nullptr) && (aux->elenco.nomeEquipe != valor))
    {
        posAux++;
        aux = aux->proximo;
    }

    if (aux == nullptr)
    {
        posAux = -1;
    }
    return posAux;
}

// método básico que percorre uma lista, imprimindo seus elementos
// poderia percorrer fazendo outra ação (multiplicando valores, por exemplo)
void lista::imprime()
{
    if (vazia())
    {
        throw runtime_error("Lista vazia!");
    }

    noh *aux = primeiro;

    while (aux != nullptr)
    {
        cout << "(" << aux->elenco.nomeEquipe << ", " << aux->elenco.lider << ", " << aux->elenco.linguagem << ", " << aux->elenco.qtdMembros << ")" << endl;
        aux = aux->proximo;
    }

    cout << " IMPRIMINDO REVERSO" << endl;

    imprimeReverso();
}

void lista::imprimeReverso()
{
    if (vazia())
    {
        throw runtime_error("Lista vazia!");
    }

    // faça o método de imprirmir reversamente em lista simplesmente encadeada
    noh *aux = ultimo;
    lista listaAux;

    // percorre a lista do último para o primeiro, removendo e guardando os elementos
    while (tamanho > 0)
    {
        cout << "(" << aux->elenco.nomeEquipe << ", " << aux->elenco.lider << ", " << aux->elenco.linguagem << ", " << aux->elenco.qtdMembros << ")" << endl;
        removeNoFim();
        aux = ultimo;

        // insere na lista auxiliar
        listaAux.insereNoInicio(aux->elenco);
    }

    // copia os elementos de volta para a lista original
    aux = listaAux.primeiro;

    while (aux != nullptr)
    {
        insereNoFim(aux->elenco);
        aux = aux->proximo;
    }
}

// verifica se a lista está vazia
inline bool lista::vazia()
{
    return (tamanho == 0);
}

void lista::removeNoFim()
{

    if (vazia())
    {
        throw runtime_error("Remoção em lista vazia!");
    }

    noh *aux = primeiro;
    noh *anterior;

    while (aux->proximo != nullptr)
    {
        anterior = aux;
        aux = aux->proximo;
    }

    delete ultimo;
    anterior->proximo = nullptr;
    ultimo = anterior;

    tamanho--;
    if (tamanho == 0)
    {
        primeiro = nullptr;
    }
}

void lista::removeEspecifico(int index)
{
    if (index == 0)
    {
        removeNoInicio();
    }
    else if (index == Tamanho())
    {
        removeNoFim();
    }
    else
    {
        noh *anterior = primeiro;
        for (int i = 0; i < index; i++)
        {
            anterior = anterior->proximo;
        }
        noh *aux = anterior->proximo;
        anterior->proximo = aux->proximo;
        delete aux;
        tamanho--;
    }
}

void lista::removeNoInicio()
{
    if (vazia())
    {
        throw runtime_error("Remoção em lista vazia!");
    }
    noh *aux = primeiro;
    primeiro = primeiro->proximo;
    delete aux;

    tamanho--;
    if (vazia())
    {
        ultimo = nullptr;
    }
}

int main()
{
    lista minhaLista;
    equipe info;
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
                cin >> info.nomeEquipe >> info.lider >> info.linguagem >> info.qtdMembros;
                minhaLista.insereNoInicio(info);
                break;
            case 'h': // inserir
                cin >> info.nomeEquipe >> info.lider >> info.linguagem >> info.qtdMembros;
                minhaLista.insereNoFim(info);
                break;
            case 'm': // inserir em posição específica
                cin >> posicao;
                cin >> info.nomeEquipe >> info.lider >> info.linguagem >> info.qtdMembros;
                minhaLista.insereNaPosicao(posicao, info);
                break;
            case 's': // procurar
                cin >> nomeEquipe;
                if (minhaLista.procura(nomeEquipe) != -1)
                    cout << minhaLista.procura(nomeEquipe) << endl;
                else
                    cout << "Nao encontrado" << endl;
                break;
            case 'r': // remover
                minhaLista.removeNoInicio();
                break;
            case 'a': // remover
                minhaLista.removeNoFim();
                break;
            case 'x': // remover
                cin >> nomeEquipe;
                if (minhaLista.procura(nomeEquipe) != -1)
                    minhaLista.removeEspecifico(minhaLista.procura(nomeEquipe));
                else
                    cout << "Nao encontrado" << endl;
            case 'p': // limpar tudo
                minhaLista.imprime();
                break;
            case 't':
                cout << minhaLista.Tamanho() << endl;
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