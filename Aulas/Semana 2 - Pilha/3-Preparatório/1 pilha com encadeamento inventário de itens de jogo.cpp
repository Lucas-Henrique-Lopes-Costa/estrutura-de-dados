/*
Questão 1: Pilha com encadeamento - Inventário de itens de jogo
Implemente uma estrutura de dados pilha, utilizando encadeamento de nós, para implementar um inventário de itens em um jogo digital. A estrutura deve possibilitar, pelo menos, as seguintes ações: empilhamento e desempilhamento de itens, verificação do item no topo da pilha e limpeza do inventário (remoção de todos os elementos da pilha). O desempilhamento deve escrever mensagem de erro na saída ("
Erro: pilha vazia!
"), quando a pilha já estiver vazia. Os itens do inventários possuem os seguintes atributos: nome (uma string sem espaços), tipo (um único caracter) e valor (um inteiro).
Entradas:
O programa deve aceitar os seguintes comandos:
i: seguido de uma string, um caracter e um inteiro: para inserir um item no inventário
r: para retirar um item do inventário
l: para limpar (remover todos) os itens do inventário
e: para espiar o topo do inventário (escreve o topo sem removê-lo)
f: para finalizar a execução do programa
Saídas:
Todas as saídas de comandos já estão implementadas na função principal desse
código exemplo fornecido
. Ao terminar a execução do programa, todos os itens da pilha são desempilhados e escritos.
Exemplo de Entrada e Saída juntas:
r
Erro: pilha vazia!
i um a 1
i dois b 2
i quatro d 4
i sete g 7
i oito h 8
r
Nome: oito Tipo: h Valor: 8
e
Nome: sete Tipo: g Valor: 7
r
Nome: sete Tipo: g Valor: 7
f
Nome: quatro Tipo: d Valor: 4
Nome: dois Tipo: b Valor: 2
Nome: um Tipo: a Valor: 1
*/

#include <iostream>
using namespace std;

struct Item
{
    string nome;
    char tipo;
    int valor;
    Item *proximo;
    Item(string nome, char tipo, int valor, Item *proximo = nullptr)
    {
        this->nome = nome;
        this->tipo = tipo;
        this->valor = valor;
        this->proximo = proximo;
    }
};

class Pilha
{
private:
    Item *topo;

public:
    Pilha() : topo(nullptr) {} // Definição do construtor

    ~Pilha()
    {
        limpar();
    }

    void adicionarPilha(string nome, char tipo, int valor)
    {
        Item *novoItem = new Item(nome, tipo, valor, topo);
        topo = novoItem;
    }

    void desempilhar()
    {
        if (topo == nullptr)
        {
            cout << "Erro: pilha vazia!" << endl;
        }
        else
        {
            Item *itemRemovido = topo;
            topo = topo->proximo;
            cout << "Nome: " << itemRemovido->nome << " Tipo: " << itemRemovido->tipo << " Valor: " << itemRemovido->valor << endl;
            delete itemRemovido;
        }
    }

    void getTopo()
    {
        if (topo == nullptr)
        {
            cout << "Pilha Vazia!" << endl;
        }
        else
        {
            cout << "Nome: " << topo->nome << " Tipo: " << topo->tipo << " Valor: " << topo->valor << endl;
        }
    }

    void limpar()
    {
        while (topo != nullptr)
        {
            desempilhar();
        }
    }
};

int main()
{
    Pilha itens;
    char comando;

    string nome;
    char tipo;
    int valor;

    while (cin >> comando)
    {
        switch (comando)
        {
        case 'i':
            cin >> nome >> tipo >> valor;
            itens.adicionarPilha(nome, tipo, valor);
            break;
        case 'r':
            itens.desempilhar();
            break;
        case 'l':
            itens.limpar();
            break;
        case 'e':
            itens.getTopo();
            break;
        case 'f':
            itens.limpar();
            break;
        default:
            break;
        }
    }

    return 0;
}
