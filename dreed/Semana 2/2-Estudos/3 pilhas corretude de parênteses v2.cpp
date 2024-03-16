/*
Questão 3: Pilhas - Corretude de parênteses (v2)
Faça um programa que lê uma linha de texto e verifica se todo parênteses tem um correspondente.  Assuma que cada sinal de "fecha parênteses" fecha o último "abre parênteses".
Caso não existam parênteses correspondentes em todos os casos, o programa deve escrever a posição do erro. A posição do primeiro caractere é zero. Se todos os parênteses têm correspondentes, o programa deverá escrever "correto" (letras minúsculas). A posição do erro no caso de um "fecha parênteses" sem correspondente é a dele mesmo, pois não é preciso olhar o resto do texto para saber que há erro. A posição do erro no caso de um "abre parênteses" sem correspondente é a do último "abre parênteses" visto, pois só é possível saber que ele não tem correspondente ao final do texto.
Este é um exercício de solução de problema
usando
pilha. A pilha deve ser parte importante da solução. Faça um programa utilizando
somente a estrutura de dado pilha, respeitando todas as suas propriedades e não utilizando a STL
.
Entradas:
Uma linha de texto (não mais do que 254 caracteres).
Saídas:
A palavra "correto" se todos tiverem correspondentes ou então a posição do erro.
Exemplo de Entrada 1:
func(x, (y+3)*4)
Exemplo de Saída 1:
correto
Exemplo de Entrada 2:
(idw ( dpq() sho
Exemplo de Saída 2:
5
Exemplo de Entrada 3:
(12 + 3) * 4 - 2)
Exemplo de Saída 3:
16
*/

#include <iostream>
#include <cstring>
using namespace std;

typedef int DadoIndice;
class pilhaIndice
{
private:
    int capacidade;
    DadoIndice *dados;
    int tamanho;
    int posTopo;

public:
    pilhaIndice(int cap) : capacidade(cap), dados(new DadoIndice[cap]), tamanho(0), posTopo(-1) {}
    ~pilhaIndice() { delete[] dados; }
    bool vazia() const { return tamanho == 0; }
    bool estaCheia() const { return tamanho == capacidade; }
    void empilhar(DadoIndice valor)
    {
        if (!estaCheia())
        {
            dados[++posTopo] = valor;
            tamanho++;
        }
    }
    DadoIndice desempilhar()
    {
        if (!vazia())
        {
            tamanho--;
            return dados[posTopo--];
        }
        return -1; // Retorna -1 se tentar desempilhar uma pilha vazia
    }
    DadoIndice topo() const { return dados[posTopo]; } // Método para acessar o topo sem desempilhar
};

typedef char Dado;

class pilha
{
private:
    int capacidade;
    Dado *dados;
    int tamanho;
    int posTopo;

public:
    pilha(int cap);
    ~pilha();
    bool vazia();
    bool estaCheia();
    void empilhar(Dado valor);
    Dado desempilhar();
    void pegarUltimo();
    void imprimirPilha();
};

pilha::pilha(int cap)
{
    capacidade = cap;
    dados = new Dado[capacidade];
    tamanho = 0;
    posTopo = -1;
}

pilha::~pilha()
{
    delete[] dados;
}

bool pilha::vazia()
{
    return posTopo == -1;
}

bool pilha::estaCheia()
{
    return posTopo == capacidade;
}

void pilha::empilhar(Dado valor)
{
    if (!estaCheia())
    {
        posTopo++;
        dados[posTopo] = valor;
        tamanho++;
    }
}

Dado pilha::desempilhar()
{
    if (!vazia())
    {
        tamanho--;
        return dados[posTopo--];
    }
    return -1;
}

void pilha::pegarUltimo()
{
    cout << dados[posTopo] << endl;
}

int main()
{
    string linha;
    getline(cin, linha);

    int tamanhoPilha = linha.length();
    pilha p(tamanhoPilha);
    pilhaIndice p2(tamanhoPilha);

    for (int i = 0; i < tamanhoPilha; i++) // percorre a linha
    {
        // cout << "i: " << i << endl;
        // cout << "linha[i]: " << linha[i] << endl;

        if (linha[i] == '(') // se for abertura
        {
            p.empilhar(linha[i]); // empilha
            p2.empilhar(i);       // empilha a posição
        }
        else if (linha[i] == ')') // se for fechamento
        {
            if (p.vazia()) // se a pilha estiver vazia
            {
                cout << i << endl; // imprime a posição, porque não tem abertura correspondente
                return 0;
            }
            else
            {
                p.desempilhar(); // desempilha, porque tem abertura correspondente
                p2.desempilhar(); // desempilha, porque tem abertura correspondente
            }
        }
    }

    if (p.vazia())
    {
        cout << "correto" << endl;
    }
    else
    {
        cout << p2.desempilhar() << endl;
    }

    return 0;
}
