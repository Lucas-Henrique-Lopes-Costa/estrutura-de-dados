/*
Questão 12: Hash com encadeamento - Inventário de itens de jogo - Hash com Vetor de Quatro Posições
A implementação de Hash com encadeamento é uma das mais utilizadas. Para o encadeamento, a implementação tradicional faz uso de uma lista encadeada. Entretanto, várias implementações utilizam estruturas diferenciadas para o encadeamento das colisões. Por exemplo, a classe HashMap no Java 8 utiliza uma árvore binária para essa tarefa.
Utilizando como base o código que você desenvolveu na atividade "Hash com encadeamento - Inventário de itens de jogo", implemente uma tabela hash com um número genérico n de posições, informado durante a construção da tabela, com resolução de colisões utilizando um vetor de quatro posições. Inclusive, o primeiro elemento na posição deverá ser armazenado também nesse vetor, na posição 0. Não é necessário implementar métodos para alteração ou remoção de dados, apenas inserção e recuperação. Chaves não utilizadas devem ser mantidas como -1, tendo a string vazia como valor associado.
Exemplo de Entrada e Saída juntas:
5
r dez
Erro na remoção: chave não encontrada!
i um a 1
chave 'um' inserida na posicao 3
i dois b 2
chave 'dois' inserida na posicao 4
i quatro d 4
chave 'quatro' inserida na posicao 2
i sete g 7
chave 'sete' inserida na posicao 2
i oito h 8
chave 'oito' inserida na posicao 1
i dez j 10
chave 'dez' inserida na posicao 4
i tres c 3
chave 'tres' inserida na posicao 1
i onze k 11
chave 'onze' inserida na posicao 3
i doze l 12
chave 'doze' inserida na posicao 4
i treze m 1
chave 'treze' inserida na posicao 2
p
0:
1: [tres/3][oito/8]
2: [treze/1][sete/7][quatro/4]
3: [onze/11][um/1]
4: [doze/12][dez/10][dois/2]
i quinze o 15
chave 'quinze' inserida na posicao 3
i vinte w 20
chave 'vinte' inserida na posicao 1
i trinta x 30
chave 'trinta' inserida na posicao 0
i quarenta z 40
chave 'quarenta' inserida na posicao 2
i cinco e 5
chave 'cinco' inserida na posicao 3
i cem t 100
Posição na tabela já possui 4 elementos!
f
0: [trinta/30]
1: [vinte/20][tres/3][oito/8]
2: [quarenta/40][treze/1][sete/7][quatro/4]
3: [cinco/5][quinze/15][onze/11][um/1]
4: [doze/12][dez/10][dois/2]
*/

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

const int UMPRIMO = 7;

// Um noh guarda um par (chave / valor)
class noh
{
    friend class lista;
    friend class tabelaHash;

private:
    string chave;
    char tipo;
    int valor;
    noh *proximo;
    noh(const string &c = "", const char &t = 'a', const int &v = 0, noh *prox = NULL) : chave(c), tipo(t), valor(v), proximo(prox) {}
};

// Uma lista guarda todos os Nos cuja chave foi mapeada na mesma posição.
class lista
{
    friend class tabelaHash;

private:
    noh *primeiro;               // primeiro nó da lista
    unsigned short numElementos; // quantidade de valores na lista
public:
    lista() {}                                        // Construtor
    ~lista() {}                                       // Destrutor
    unsigned short tamanho() { return numElementos; } // Consulta do Tamanho
    // Adiciona um novo par (chave, valor) na lista
    // Insere no início, para não precisar de ponteiro para o fim
    void insere(const string &c, const char &t, const int &v)
    {
        noh *novo = new noh(c, t, v, primeiro);
        primeiro = novo;
        ++numElementos;
    }

    // Remove o noh com dada chave da lista.
    // Se a chave não existe, retorna informação.
    bool remove(const string &c)
    {
        noh *anterior = NULL;
        noh *atual = primeiro;
        while ((atual != NULL) and (atual->chave != c))
        {
            anterior = atual;
            atual = atual->proximo;
        }
        if (atual == NULL)
            return false;
        if (anterior == NULL)
            primeiro = atual->proximo;
        else
            anterior->proximo = atual->proximo;
        delete atual;
        --numElementos;
        return true;
    }
    // Busca um elemento na lista, retorna falso se não encontrado
    // o valor buscado é retornado por passagem por referência
    // na variável valorBuscado
    bool busca(const string &c, char &tipoBuscado, int &valorBuscado)
    {
        noh *atual = primeiro;
        while ((atual != NULL) and (atual->chave != c))
            atual = atual->proximo;
        if (atual == NULL)
            return false;
        tipoBuscado = atual->tipo;
        valorBuscado = atual->valor;
        return true;
    }
    // Verifica se já tem algum dado na lista com
    // uma dada chave
    bool verificaOcorrencia(const string &c)
    {
        noh *atual = primeiro;
        while ((atual != NULL) and (atual->chave != c))
            atual = atual->proximo;
        if (atual == NULL)
            return false;
        return true;
    }
    // Imprime o conteúdo da lista, para fins de depuração
    void imprime()
    {
        noh *atual = primeiro;
        while (atual != NULL)
        {
            cout << "[" << atual->chave << "/"
                 << atual->valor << "]";
            atual = atual->proximo;
        }
    }
};

class tabelaHash
{
private:
    // vetor de ponteiros para lista
    lista *tabela;
    // quantidade de posições na tabela hash
    unsigned numPosicoes;
    // converte uma chave (string) num endereço da tabela
    // - versão simples
    unsigned funcaoHash(const string &s)
    {
        return funcaoHash(s, numPosicoes);
    }
    // converte uma chave (string) num endereço da tabela
    // - versão para redimensionamento
    unsigned funcaoHash(const string &s, int cap)
    {
        unsigned pos = 0;
        for (unsigned int i = 0; i < s.size(); ++i)
            pos = (UMPRIMO * pos + s[i]) % cap;
        return pos;
    }

public:
    // construtor padrão
    tabelaHash(unsigned cap = 100)
    {
        numPosicoes = cap;
        tabela = new lista[numPosicoes];
    }
    ~tabelaHash()
    {
        for (unsigned i = 0; i < numPosicoes; i++)
        {
            noh *atual = tabela[i].primeiro;
            while (atual != NULL)
            {
                noh *proximo = atual->proximo;
                delete atual;
                atual = proximo;
            }
        }
        delete[] tabela;
    }
    // Insere um nó com dada chave e valor.
    bool insere(const string &c, char &t, const int &v)
    {
        unsigned posicao = funcaoHash(c);
        if (tabela[posicao].verificaOcorrencia(c))
            return false;
        tabela[posicao].insere(c, t, v);
        cout << "chave '" << c << "' inserida na posicao " << posicao << endl;
        return true;
    }
    // Retorna um valor associado a uma dada chave.
    // Se a chave não existe, retorna "NÃO ENCONTRADO!".
    bool valor(const string &c, char &tipoBuscado, int &valorRetorno)
    {
        unsigned posicao = funcaoHash(c);
        if (tabela[posicao].busca(c, tipoBuscado, valorRetorno))
            return true;
        return false;
    }
    // Retira do hash um nó com dada chave.
    bool remove(const string &c)
    {
        unsigned posicao = funcaoHash(c);
        if (tabela[posicao].remove(c))
            return true;
        return false;
    }
    // Imprime o conteúdo interno do hash (para fins de depuração)
    void imprime()
    {
        for (unsigned i = 0; i < numPosicoes; i++)
        {
            cout << i << ": ";
            tabela[i].imprime();
            cout << endl;
        }
    }
};

int main()
{
    int tamanhoTH;
    cin >> tamanhoTH;
    tabelaHash tabela(tamanhoTH);
    char comando;
    string chave;
    char tipo = 'a';
    int valor = -1;
    do
    {
        try
        {
            cin >> comando;
            switch (comando)
            {
            case 'i': // inserir
                cin >> chave >> tipo >> valor;
                if (not tabela.insere(chave, tipo, valor))
                    cout << "Erro na inserção: chave já existente!" << endl;
                break;
            case 'r': // remover
                cin >> chave;
                if (not tabela.remove(chave))
                    cout << "Erro na remoção: chave não encontrada!" << endl;
                break;
            case 'l': // remover
                cin >> chave;
                if (not tabela.valor(chave, tipo, valor))
                    cout << "Erro na busca: chave não encontrada!" << endl;
                else
                    cout << "Tipo: " << tipo << " Valor: " << valor << endl;
                break;
            case 'p': // mostrar estrutura
                tabela.imprime();
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
    tabela.imprime();
    cout << endl;
    return 0;
}