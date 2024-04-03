/*
Questão 2: Pilha com encadeamento - Inventário de itens de jogo - ordenação por nome
Implemente uma função que realize a ordenação dos dados da estrutura pilha utilizando
somente
como estrutura auxiliar outra pilha. O item com maior nome deve estar na parte inferior da pilha e o menor nome no topo. Para saber a ordem, utilize o alfabeto, sendo a letra "a" a de menor valor e a letra "z" a de maior valor.
Você pode (
e deve!
) utilizar o código que você desenvolveu na atividade "Pilha com encadeamento - Inventário de itens de jogo" como base.
Entradas:
Com essa finalidade, você deverá adicionar mais um comando, como segue:
o: para ordenar a pilha
Saídas:
Todas as saídas de comandos já estão implementadas na função principal código entregue, somente falta implementar a chamada para a ordenação. Ao terminar a execução do programa, todos os itens da pilha são desempilhados e escritos.
Exemplo de Entrada e Saída juntas:
r
Erro: pilha vazia!
i um a 1
i dois b 2
i dez j 10
i quatro d 4
i sete g 7
i oito h 8
r
Nome: oito Tipo: h Valor: 8
e
Nome: sete Tipo: g Valor: 7
o
f
Nome: dez Tipo: j Valor: 10
Nome: dois Tipo: b Valor: 2
Nome: quatro Tipo: d Valor: 4
Nome: sete Tipo: g Valor: 7
Nome: um Tipo: a Valor: 1
*/

#include <iostream>
#include <stdexcept>

using namespace std;

// Definição da estrutura de dado armazenada na pilha
struct Dado
{
    string nome;
    char tipo;
    int valor;
};

// Função para imprimir as informações de um dado
void imprimir_dado(const Dado &umDado)
{
    cout << "Nome: " << umDado.nome << " ";
    cout << "Tipo: " << umDado.tipo << " ";
    cout << "Valor: " << umDado.valor << " ";
    cout << endl;
}

// Classe para o nó da pilha
class Noh
{
    friend class Pilha;

private:
    Dado mDado; // Dado armazenado no nó
    Noh *mProx; // Ponteiro para o próximo nó
public:
    // Construtor do nó
    Noh(Dado v)
    {
        mDado = v;
        mProx = NULL;
    }
};

// Classe para a pilha
class Pilha
{
public:
    // Construtor da pilha
    Pilha();

    // Destrutor da pilha
    ~Pilha();

    // Desempilha o elemento do topo da pilha
    Dado Desempilhar(); // retorna o mPtTopo da Pilha.

    // Empilha um dado na pilha
    void Empilhar(const Dado &d);

    // Limpa todos os elementos da pilha
    void LimparTudo();

    // Ordena os elementos da pilha
    void ordenar();

    // Retorna o dado no topo da pilha
    Dado espiar();

    // Informa se a pilha está vazia
    inline bool Vazia();

private:
    Noh *mTopo;   // Ponteiro para o topo da pilha
    int mTamanho; // Tamanho atual da pilha
};

// Construtor da pilha
Pilha::Pilha()
{
    mTopo = NULL;
    mTamanho = 0;
}

// Destrutor da pilha
Pilha::~Pilha()
{
    LimparTudo();
}

// Desempilha o elemento do topo da pilha e retorna o valor
Dado Pilha::Desempilhar()
{
    if (this->Vazia())
        throw runtime_error("Erro: pilha vazia!");

    else
    {
        Dado valor = mTopo->mDado; // Salva o valor do topo da pilha
        Noh *aux = mTopo;          // Salva o endereço do topo da pilha
        mTopo = mTopo->mProx;      // Atualiza o topo da pilha com o próximo elemento
        delete aux;                // Deleta o elemento do topo da pilha
        mTamanho--;                // Atualiza o tamanho da pilha
        return valor;              // Retorna o valor do topo da pilha
    }
}

// Empilha um dado na pilha
void Pilha::Empilhar(const Dado &d)
{
    Noh *novo = new Noh(d); // Cria um novo nó com o dado a ser empilhado
    novo->mProx = mTopo;    // Atualiza o próximo do novo nó com o topo da pilha
    mTopo = novo;           // Atualiza o topo da pilha com o novo nó
    mTamanho++;             // Atualiza o tamanho da pilha
}

// Limpa todos os elementos da pilha
void Pilha::LimparTudo()
{
    while (mTamanho > 0)
    {
        Desempilhar();
    }
}

// Informa se a pilha está vazia
bool Pilha::Vazia()
{
    return (mTamanho == 0);
}

// Ordena os elementos da pilha
void Pilha::ordenar()
{
    if (this->Vazia())
        throw runtime_error("Erro: pilha vazia!");
    else
    {
        // Cria uma pilha auxiliar
        Pilha *pilhaAux = new Pilha();
        Dado dadoAux, dadoPrincipal; // Dados auxiliares

        // Transfere os elementos da pilha original para a pilha auxiliar
        while (!Vazia())
        {
            pilhaAux->Empilhar(Desempilhar()); // Empilha o elemento da pilha original na pilha auxiliar = começa

            // Verifica se a pilha auxiliar e a pilha original não estão vazias
            if (!pilhaAux->Vazia() and !Vazia())
            {
                dadoAux = pilhaAux->espiar(); // Pega o dado no topo da pilha auxiliar
                dadoPrincipal = espiar();     // Pega o dado no topo da pilha original

                // Compara os nomes dos dados na pilha auxiliar e na pilha original
                // Se o nome na pilha auxiliar for menor, realiza a troca
                if (dadoAux.nome < dadoPrincipal.nome)
                {
                    dadoAux = pilhaAux->Desempilhar(); // Desempilha o dado da pilha auxiliar
                    pilhaAux->Empilhar(Desempilhar()); // Empilha o dado da pilha original na pilha auxiliar
                    Empilhar(dadoAux);                 // Empilha o dado da pilha auxiliar na pilha original

                    // Transfere os elementos restantes da pilha auxiliar para a pilha original
                    while (!pilhaAux->Vazia())
                    {
                        Empilhar(pilhaAux->Desempilhar()); // Empilha o dado da pilha auxiliar na pilha original
                    }
                }
            }

            // Exemplo:

            // Pilha original: 1, 3, 2
            // Pilha auxiliar: 1

            // 1 < 3

            // Pilha original: 3, 2
            // Pilha auxiliar: 1

            // 1 < 3

            // Pilha original: 3, 2
            // Pilha auxiliar: 1

            // 1 < 2

            // Pilha original: 3, 2
            // Pilha auxiliar: 1, 2

            // 1 < 3

            // Pilha original: 3
            // Pilha auxiliar: 1, 2

            // 1 < 3

            // Pilha original: 3
            // Pilha auxiliar: 1, 2, 3

            // Transfere os elementos restantes da pilha auxiliar para a pilha original
        }

        // Atualiza o topo e o tamanho da pilha original com os valores da pilha auxiliar
        mTopo = pilhaAux->mTopo;
        mTamanho = pilhaAux->mTamanho;
    }
}

// Retorna o dado no topo da pilha sem remover
Dado Pilha::espiar()
{
    if (this->Vazia())
        throw runtime_error("Erro: pilha vazia!");
    else
    {
        return mTopo->mDado;
    }
}

// Função principal
int main()
{
    Pilha pilha;
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
                cin >> info.nome >> info.tipo >> info.valor;
                pilha.Empilhar(info);
                break;
            case 'r': // remover
                imprimir_dado(pilha.Desempilhar());
                break;
            case 'l': // limpar tudo
                pilha.LimparTudo();
                break;
            case 'e': // espiar
                imprimir_dado(pilha.espiar());
                break;
            case 'o': // ordenar
                pilha.ordenar();
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
    while (not pilha.Vazia())
    {
        imprimir_dado(pilha.Desempilhar());
    }
    cout << endl;
    return 0;
}
