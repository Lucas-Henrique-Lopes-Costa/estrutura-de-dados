/*
Questão 1: Lista Simplesmente Encadeada - Equipes de Maratona
Crie um programa que seja capaz de armazenar em uma lista encadeada as equipes de uma maratona de programação. Para cada equipe deverá ser informado o seu nome, o nome do líder da equipe, a linguagem de programação que será utilizada e a quantidade de membros. Você poderá utilizar o
código fornecido
como base de implementação.
Os comandos que deverão ser utilizados para execução do programa são:
i: inserir uma nova equipe no inicio da lista. O formato de entrada é:
NomeEquipe Lider Linguagem QtdMembros
h: inserir uma nova equipe no fim da lista. O formato de entrada é:
NomeEquipe Lider Linguagem QtdMembros
m: inserir uma nova equipe na posição informada pelo usuário através de um número inteiro. Considere 0 como a posição inicial da lista. Caso não seja possível inserir na posição indicada imprima "Posição Inexistente!". O formato de entrada é:
posiçãoASerInserida NomeEquipe Lider Linguagem QtdMembros
r: apagar uma determinada equipe do início da lista. Caso não exista a equipe deverá imprimir
Remoção em lista vazia!
a: apagar uma determinada equipe do fim da lista. Caso não exista a equipe deverá imprimir
Remoção em lista vazia!
p: imprimir lista de equipes cadastradas. Imprimir
Lista vazia!
quando não tiver elemento a ser impresso.
s: buscar por uma equipe a partir de seu nome. Imprimir
Nao encontrado
quando a busca não obtiver sucesso.
Nota: o formato de saída das equipes deve ser:
(Nome, Lider, Linguagem, QtdMembros)
. Para mais instâncias de equipes (comando de impressão), cada uma delas devem ser separadas por quebras de linha.
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
s Thundercats
Lista vazia!
i Vingadores Stark Ruby 3
h LigaDaJustica Batman C++ 4
m 1 MuppetBabies Kermit Phyton 9
p
(Vingadores, Stark, Ruby, 3)
(MuppetBabies, Kermit, Phyton, 9)
(LigaDaJustica, Batman, C++, 4)
s Thundercats
Nao encontrado
r
p
(MuppetBabies, Kermit, Phyton, 9)
(LigaDaJustica, Batman, C++, 4)
a
p
(MuppetBabies, Kermit, Phyton, 9)
f
*/

/*
 * Classe lista, uma lista dinamicamente encadeada
 *
 * by Lucas
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
                        // imprime reverso a partir de um nó -> exemplo de uso de recursão
    void imprimeReversoAux(noh *umNoh);

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
};

// constrói uma lista inicialmente vazia
lista::lista()
{
    primeiro = NULL;
    ultimo = NULL;
    tamanho = 0;
}

// construtor de cópia
lista::lista(const lista &umaLista)
{
    primeiro = NULL;
    ultimo = NULL;
    tamanho = 0;
    noh *aux = umaLista.primeiro;

    // Copia os elementos da lista umaLista para a nova lista
    while (aux != NULL)
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

    while (aux != NULL)
    {
        temp = aux;
        aux = aux->proximo;
        delete temp;
    }

    primeiro = NULL;
    ultimo = NULL;
    tamanho = 0;
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

// insere em uma determinada posição da lista
void lista::insereNaPosicao(int posicao, equipe elenco)
{
    if (posicao >= 0 && posicao <= tamanho)
    {
        noh *novo = new noh(elenco);

        if (vazia())
        {
            primeiro = novo;
            ultimo = novo;
        }
        else if (posicao == 0)
        {
            novo->proximo = primeiro;
            primeiro = novo;
        }
        else if (posicao == tamanho)
        {
            ultimo->proximo = novo;
            ultimo = novo;
        }
        else
        {
            noh *aux = primeiro;
            int posAux = 0;

            while (posAux < posicao - 1)
            {
                aux = aux->proximo;
                posAux++;
            }

            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }

        tamanho++;
    }
    else
    {
        throw runtime_error("Remoção em lista vazia!");
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
    int pos = 0;

    while (aux != NULL && aux->elenco.nomeEquipe != valor)
    {
        aux = aux->proximo;
        pos++;
    }

    if (aux == NULL)
    {
        return -1;
    }
    return pos;
}

// método básico que *percorre* uma lista, imprimindo seus elementos
// poderia percorrer fazendo outra ação (multiplicando valores, por exemplo)
void lista::imprime()
{
    if (vazia())
    {
        throw runtime_error("Lista vazia!");
    }
    else
    {
        noh *aux = primeiro;
        while (aux != NULL)
        {
            cout << "(" << aux->elenco.nomeEquipe << ", " << aux->elenco.lider << ", " << aux->elenco.linguagem << ", " << aux->elenco.qtdMembros << ")" << endl;
            aux = aux->proximo;
        }
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
    else
    {
        noh *aux = primeiro;
        noh *anterior;

        while (aux->proximo != ultimo)
        {
            anterior = aux;
            aux = aux->proximo;
        }

        delete ultimo;
        anterior->proximo = NULL;
        ultimo = anterior;
        tamanho--;

        if (vazia())
        {
            primeiro = NULL;
        }
    }
}

void lista::removeNoInicio()
{
    if (vazia())
    {
        throw runtime_error("Remoção em lista vazia!");
    }
    else
    {
        noh *removido = primeiro;
        primeiro = primeiro->proximo;
        delete removido;
        tamanho--;

        if (vazia())
        {
            ultimo = NULL;
        }
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
            case 'm': // inserir
                cin >> posicao;
                cin >> info.nomeEquipe >> info.lider >> info.linguagem >> info.qtdMembros;
                minhaLista.insereNaPosicao(posicao, info);
                break;
            case 's': // remover
                cin >> nomeEquipe;
                if (minhaLista.procura(nomeEquipe) == -1)
                {
                    cout << "Nao encontrado" << endl;
                }
                else
                {
                    cout << minhaLista.procura(nomeEquipe) << endl;
                }
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
