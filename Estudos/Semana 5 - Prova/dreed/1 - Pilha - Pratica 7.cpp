/*
Questão 7: Pilha com armazenamento em vetor - Lista de tarefas para robô doméstico - inserção em pilha cheia
Implemente uma função de inserção que ao inserir um elemento em pilha cheia, o mesmo remove o elemento mais antigo, imprimindo na tela.
Você pode (
e deve!
) utilizar o código que você desenvolveu na atividade "Pilha com armazenamento em vetor - Lista de tarefas para robô doméstico" como base.
Entradas:
Com essa finalidade, você não precisará adicionar mais um comando, somente alterar a função de inserção para tratamento do que foi solicitado.
Saídas:
Todas as saídas de comandos já estão implementadas na função principal código entregue, somente falta implementar a chamada para a remoção. Ao terminar a execução do programa, todos os itens da pilha são desempilhados e escritos.
Exemplo de Entrada e Saída juntas:
r
Erro: pilha vazia!
i sala s 150
i quarto1 q 45
i quarto2 q 60
i quarto3 q 45
i cozinha c 130
r
Nome: cozinha Tipo: c Valor: 130
i cozinha c 143
e
Nome: cozinha Tipo: c Valor: 143
i varanda v 111
i banheiro b 33
Nome: sala Tipo: s Valor: 150
i lavabo l 12
Nome: quarto1 Tipo: q Valor: 45
f
Nome: lavabo Tipo: l Valor: 12
Nome: banheiro Tipo: b Valor: 33
Nome: varanda Tipo: v Valor: 111
Nome: cozinha Tipo: c Valor: 143
Nome: quarto3 Tipo: q Valor: 45
Nome: quarto2 Tipo: q Valor: 60
*/

#include <iostream>

using namespace std;

struct Dado
{
    string nome;
    char tipo;
    int valor;
};

void imprimir_dado(const Dado &umDado)
{
    cout << "Nome: " << umDado.nome << " ";
    cout << "Tipo: " << umDado.tipo << " ";
    cout << "Valor: " << umDado.valor << endl;
}

class Pilha
{
private:
    Dado *mPilha;
    int posTopo;

public:
    Pilha();                      // Construtor da classe Pilha
    ~Pilha();                     // Destrutor da classe Pilha
    Dado Desempilhar();           // Desempilha um elemento da pilha
    void Empilhar(const Dado &d); // Empilha um elemento na pilha
    void LimparTudo();            // Limpa todos os elementos da pilha
    inline void Topo();           // Imprime o elemento do topo da pilha
    inline bool Vazia();          // Verifica se a pilha está vazia
    inline bool Cheia();          // Verifica se a pilha está cheia
};

Pilha::Pilha()
{
    mPilha = new Dado[6]; // Aloca espaço para a pilha
    posTopo = -1;         // Inicializa a posição do topo da pilha
}

Pilha::~Pilha()
{
    delete[] mPilha; // Libera a memória alocada para a pilha
}

Dado Pilha::Desempilhar()
{
    if (this->Vazia())
        throw runtime_error("Erro: pilha vazia!"); // Verifica se a pilha está vazia

    else
    {
        Dado d = mPilha[posTopo]; // Armazena o elemento do topo da pilha
        posTopo--;                // Atualiza a posição do topo da pilha
        return d;                 // Retorna o elemento desempilhado
    }
}

void Pilha::Empilhar(const Dado &d)
{
    // Verifica se a pilha está cheia
    if (this->Cheia())
    {
        Pilha aux; // Cria uma pilha auxiliar

        // Desempilha todos os elementos da pilha original e empilha na pilha auxiliar
        while (!this->Vazia())
        {
            aux.Empilhar(this->Desempilhar()); // Empilha o elemento desempilhado na pilha auxiliar
        }

        imprimir_dado(aux.Desempilhar()); // Imprime o elemento desempilhado da pilha auxiliar

        // Empilha todos os elementos da pilha auxiliar de volta na pilha original
        while (!aux.Vazia())
        {
            this->Empilhar(aux.Desempilhar());
        }
    }

    posTopo++;           // Atualiza a posição do topo da pilha
    mPilha[posTopo] = d; // Empilha o elemento na pilha
}

void Pilha::LimparTudo()
{
    // Enquanto a pilha não estiver vazia
    while (!Vazia())
    {
        Desempilhar(); // Desempilha um elemento
    }
}

void Pilha::Topo()
{
    if (this->Vazia())
        throw runtime_error("Erro: pilha vazia!"); // Verifica se a pilha está vazia

    else
    {
        imprimir_dado(mPilha[posTopo]); // Imprime o elemento do topo da pilha
    }
}

bool Pilha::Vazia()
{
    return posTopo == -1; // Retorna true se a pilha estiver vazia, caso contrário, retorna false
}

bool Pilha::Cheia()
{
    return posTopo == 5; // Retorna true se a pilha estiver cheia, caso contrário, retorna false
}

int main()
{
    Pilha pilha;  // Cria um objeto da classe Pilha
    Dado info;    // Cria um objeto da struct Dado
    char comando; // Variável para armazenar o comando do usuário

    do
    {
        try
        {
            cin >> comando; // Lê o comando do usuário
            switch (comando)
            {
            case 'i':                                        // Comando para empilhar um elemento
                cin >> info.nome >> info.tipo >> info.valor; // Lê as informações do elemento
                pilha.Empilhar(info);                        // Empilha o elemento na pilha
                break;
            case 'r':                               // Comando para desempilhar um elemento
                imprimir_dado(pilha.Desempilhar()); // Imprime o elemento desempilhado
                break;
            case 'l':               // Comando para limpar a pilha
                pilha.LimparTudo(); // Limpa todos os elementos da pilha
                break;
            case 'e': // Comando para imprimir o elemento do topo da pilha
                if (!pilha.Vazia())
                    pilha.Topo(); // Imprime o elemento do topo da pilha
                else
                    cout << " Pilha vazia!" << endl; // Mensagem de pilha vazia
                break;
            case 'f': // Comando para finalizar o programa
                break;
            default:
                cerr << "comando inválido\n"; // Mensagem de comando inválido
            }
        }
        catch (runtime_error &e)
        {
            cout << e.what() << endl; // Imprime a mensagem de erro
        }
    } while (comando != 'f'); // Repete o loop até o comando 'f' ser digitado

    while (!pilha.Vazia())
    {                                       // Enquanto a pilha não estiver vazia
        imprimir_dado(pilha.Desempilhar()); // Desempilha e imprime um elemento
    }

    cout << endl;
    return 0;
}