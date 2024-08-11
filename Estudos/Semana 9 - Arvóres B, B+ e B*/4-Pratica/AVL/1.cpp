/*
Questão 1: Estrutura de dados AVL recursiva - Ferramentas
Uma loja de ferramentas decidiu mudar sua estratégia de vendas e, sempre que um cliente pergunta por uma ferramenta, o vendedor oferece a de maior potência que tiver na loja. As ferramentas estão cadastradas com uma chave, o nome da ferramenta, a marca e a potência. Utilizando o
código fornecido
, implemente um árvore AVL com as funções de inserir e remover elementos. A ideia principal do problema é que implementação da remoção seja utilizando recursão, não sendo necessário o uso da função transplanta. A estratégia de remoção de elementos que não estejam em nós folhas é a substituição pelo elemento posterior (sucessor).
O código fornecido já tem o menu de entrada e o método de impressão.
Não
altere essas funções. O caminho mais fácil para a solução do exercício é não alterar a assinaturas das funções, dessa forma, não resultará em conflito com o código fornecido.
O dado a ser armazenado na árvore é composto por uma
chave
do tipo
inteiro
, o
nome da ferramenta
do tipo
string
, a
marca
do tipo
string
e  a
potência
do tipo
inteiro
. Não existem ferramentas diferentes com a mesma chave.
Entradas:
i - para
inserir
elemento : deve ler chave [inteiro] , nome da ferramenta [string], marca [string] e a potência [inteiro]
r - para
remover
elemento : deve ler chave [inteiro]
b - para
buscar
elemento : deve ler chave [inteiro]
l - para fazer o
levantamento
da marca com maior potência de uma dada ferramenta : deve ler nome da ferramenta [string]
e - para
imprimir
árvore
f - finalizar
Saídas:
i - inserir elemento : A operação de inserção
não
produz saída
r - remover elemento : A operação de remoção
não
produz saída
b - buscar elemento : A operação de busca escreve a frase: "Informações sobre a ferramenta: ([chave],[nome],[marca],[potencia])", em que [chave], [nome], [marca] e [potencia] devem ser substituídos pela respectiva chave, nome da ferramenta, marca da ferramenta e potência da ferramenta
l - levantamento de ferramenta: Imprime: "Levantamento do ferramenta [ferramenta]: [marca]", em que [ferramenta] é dada como entrada para o levantamento e  [marca] deve ser substituída pela marca da ferramenta mais potente -- no caso de haver mais de uma marca com a mesma potência, o resultado deverá mostrar a marca da ferramenta de menor chave
e - imprimir árvore : imprime a árvore seguindo o padrão de formatação tree
f - finalizar : finaliza o programa
Exemplo de Entrada:
i 5 tupia Makita 650
i 7 serra_circular DeWalt 200
i 9 lixadeira Vonder 275
i 6 tupia Fort 1200
i 11 lixadeira Skill 250
i 42 serra_sabre Makita 850
i 43 serra_circular Bosch 200
i 44 furadeira Fort 650
i 45 esmerilhadeira Black&Decker 650
i 46 furadeira  Schulz 500
i 101 martelete DeWalt 500
i 103 serra_circular Fort 200
e
b 45
l lixadeira
l serra_circular
f
Exemplo de Saída:
(43,serra_circular)
 ├e─(7,serra_circular)
 │   ├e─(5,tupia)
 │   │   └d─(6,tupia)
 │   └d─(11,lixadeira)
 │       ├e─(9,lixadeira)
 │       └d─(42,serra_sabre)
 └d─(45,esmerilhadeira)
     ├e─(44,furadeira)
     └d─(101,martelete)
         ├e─(46,furadeira)
         └d─(103,serra_circular)
Elemento buscado: (45,esmerilhadeira,Black&Decker,650)
Levantamento do ferramenta lixadeira: Vonder
Levantamento do ferramenta serra_circular: DeWalt
Exemplo de Entrada 2:
i 5 tupia Makita 650
i 7 serra_circular DeWalt 200
i 9 lixadeira Vonder 275
i 6 tupia Fort 1200
i 11 lixadeira Skill 250
i 42 serra_sabre Makita 850
i 43 serra_circular Bosch 200
i 44 furadeira Fort 650
i 45 esmerilhadeira Black&Decker 650
i 46 furadeira  Schulz 500
i 101 martelete DeWalt 500
i 103 serra_circular Fort 200
e
b 45
r 45
b 45
r 43
r 7
i 303 martelete Fort 600
i 404 martelete Schulz 500
i 505 martelete Makita 550
e
l lixadeira
l serra_circular
l martelete
f
Exemplo de Saída 2:
(43,serra_circular)
 ├e─(7,serra_circular)
 │   ├e─(5,tupia)
 │   │   └d─(6,tupia)
 │   └d─(11,lixadeira)
 │       ├e─(9,lixadeira)
 │       └d─(42,serra_sabre)
 └d─(45,esmerilhadeira)
     ├e─(44,furadeira)
     └d─(101,martelete)
         ├e─(46,furadeira)
         └d─(103,serra_circular)
Elemento buscado: (45,esmerilhadeira,Black&Decker,650)
Erro na busca: elemento não encontrado!
(44,furadeira)
 ├e─(9,lixadeira)
 │   ├e─(5,tupia)
 │   │   └d─(6,tupia)
 │   └d─(11,lixadeira)
 │       └d─(42,serra_sabre)
 └d─(303,martelete)
     ├e─(101,martelete)
     │   ├e─(46,furadeira)
     │   └d─(103,serra_circular)
     └d─(404,martelete)
         └d─(505,martelete)
Levantamento do ferramenta lixadeira: Vonder
Levantamento do ferramenta serra_circular: Fort
Levantamento do ferramenta martelete: Fort
Exemplo de Entrada 3:
i 5 tupia Makita 1200
i 7 serra_circular DeWalt 200
i 9 lixadeira Vonder 250
i 6 tupia Fort 1200
i 11 lixadeira Skill 250
i 42 serra_sabre Makita 850
i 43 serra_circular Bosch 250
i 44 furadeira Fort 650
l lixadeira
l tupia
e
f
Exemplo de Saída 3:
Levantamento do ferramenta lixadeira: Vonder
Levantamento do ferramenta tupia: Makita
(7,serra_circular)
 ├e─(5,tupia)
 │   └d─(6,tupia)
 └d─(11,lixadeira)
     ├e─(9,lixadeira)
     └d─(43,serra_circular)
         ├e─(42,serra_sabre)
         └d─(44,furadeira)
Observação
: para baixar o arquivo, clique com o botão direito do mouse, depois clique em "salvar link como" e escolha uma pasta do seu computador. Não tente abrir o código no navegador e copiar o texto. Isso resultará em mudança na codificação do texto de UTF-8 para ISO, deformando a saída formatada da árvore.
*/

/* avl - Árvore Binária de Busca com Balanceamento AVL
 *
 * by Joukim, Outubro de 2020 - Estrutura de Dados (GCC216)
 * Caracteristicas de implementação outubro de 2020:
 * -> tratamento de exceção
 * -> usa dado na forma chave/valor
 * -> uso de métodos recursivos
 * -> sem duplo encadeamento
 * -> invés de transplanta, usa removeMenor
 */

#include <iostream>
#include <stdexcept>

using namespace std;

// Estrutura para armazenar os dados de uma ferramenta
struct dado
{
    unsigned chave;    // Chave única da ferramenta
    string ferramenta; // Nome da ferramenta
    string marca;      // Marca da ferramenta
    short potencia;    // Potência da ferramenta
};

// Sobrecarga do operador de saída para facilitar a impressão de um dado
ostream &operator<<(ostream &saida, const dado &e)
{
    saida << "(" << e.chave << "," << e.ferramenta << "," << e.marca << "," << e.potencia << ")";
    return saida;
}

// Sobrecarga do operador de entrada para facilitar a leitura de um dado
istream &operator>>(istream &entrada, dado &e)
{
    entrada >> e.chave >> e.ferramenta >> e.marca >> e.potencia;
    return entrada;
}

// Definição do tipo de chave utilizado na árvore
typedef unsigned tipoChave;

// Classe nó da árvore AVL
class noh
{
    friend class avl;

private:
    dado elemento;   // Dado armazenado no nó
    noh *esq;        // Ponteiro para o filho à esquerda
    noh *dir;        // Ponteiro para o filho à direita
    unsigned altura; // Altura do nó na árvore

public:
    noh(const dado &umDado) : elemento(umDado), esq(nullptr), dir(nullptr), altura(1) {}
    ~noh() {}
    int fatorBalanceamento(); // Calcula o fator de balanceamento do nó
};

// Calcula o fator de balanceamento do nó
int noh::fatorBalanceamento()
{
    int alturaEsq = (esq) ? esq->altura : 0;
    int alturaDir = (dir) ? dir->altura : 0;
    return alturaEsq - alturaDir;
}

// Classe da árvore AVL
class avl
{
    friend ostream &operator<<(ostream &output, avl &arvore);

private:
    noh *raiz; // Ponteiro para a raiz da árvore

    // Funções auxiliares para inserção e remoção usando método recursivo
    noh *insereAux(noh *umNoh, const dado &umDado); // Inserção recursiva
    noh *removeAux(noh *umNoh, tipoChave chave);    // Remoção recursiva
    noh *encontraMenor(noh *raizSub);               // Encontra o menor nó da subárvore
    noh *removeMenor(noh *raizSub);                 // Remove o menor nó da subárvore

    // Funções para manutenção do balanceamento
    noh *rotacaoEsquerda(noh *umNoh);     // Rotação à esquerda
    noh *rotacaoDireita(noh *umNoh);      // Rotação à direita
    noh *arrumaBalanceamento(noh *umNoh); // Ajusta o balanceamento do nó

    // Busca recursiva de um elemento
    noh *buscaAux(tipoChave chave); // Busca auxiliar recursiva

    // Percorrimento em ordem
    void percorreEmOrdemAux(noh *atual, int nivel); // Percorre a árvore em ordem (não usado)

    // Funções auxiliares para destruição da árvore
    void destruirRecursivamente(noh *umNoh); // Destrói a árvore recursivamente

    // Funções auxiliares para impressão da árvore
    void imprimirDir(const string &prefixo, const noh *meuNoh);                // Imprime a subárvore direita
    void imprimirEsq(const string &prefixo, const noh *meuNoh, bool temIrmao); // Imprime a subárvore esquerda

    // Função auxiliar para levantamento
    void levantamentoAux(noh *umNoh, dado &ferramentaMaiorPotencia, string nomeFerramenta);

public:
    avl() { raiz = nullptr; } // Construtor
    ~avl();                   // Destrutor

    // Funções públicas para inserção, remoção, busca e levantamento
    void insere(const dado &umDado);
    void remove(tipoChave chave);
    dado busca(tipoChave chave);
    string levantamento(string nomeFerramenta);

    // Função para imprimir a árvore
    void imprimir();
};

// Destrutor da árvore AVL
avl::~avl()
{
    destruirRecursivamente(raiz);
}

// Destrói a árvore recursivamente em pós-ordem
void avl::destruirRecursivamente(noh *umNoh)
{
    if (umNoh != nullptr)
    {
        destruirRecursivamente(umNoh->esq);
        destruirRecursivamente(umNoh->dir);
        delete umNoh;
    }
}

// Insere um novo nó na árvore
void avl::insere(const dado &umDado)
{
    raiz = insereAux(raiz, umDado);
}

// Inserção recursiva na árvore AVL
noh *avl::insereAux(noh *umNoh, const dado &umDado)
{
    if (umNoh == nullptr)
    {
        return new noh(umDado);
    }

    if (umDado.chave < umNoh->elemento.chave)
    {
        umNoh->esq = insereAux(umNoh->esq, umDado);
    }
    else if (umDado.chave > umNoh->elemento.chave)
    {
        umNoh->dir = insereAux(umNoh->dir, umDado);
    }
    else
    {
        throw runtime_error("Chave já inserida!");
    }

    return arrumaBalanceamento(umNoh);
}

// Ajusta o balanceamento da árvore após uma inserção ou remoção
noh *avl::arrumaBalanceamento(noh *umNoh)
{
    if (umNoh == nullptr)
        return umNoh;

    // Atualiza a altura do nó
    umNoh->altura = 1 + max((umNoh->esq ? umNoh->esq->altura : 0), (umNoh->dir ? umNoh->dir->altura : 0));

    // Calcula o fator de balanceamento
    int fatorBal = umNoh->fatorBalanceamento();

    // Rotação à esquerda
    if (fatorBal < -1 && umNoh->dir->fatorBalanceamento() <= 0)
    {
        return rotacaoEsquerda(umNoh);
    }

    // Rotação à direita
    if (fatorBal > 1 && umNoh->esq->fatorBalanceamento() >= 0)
    {
        return rotacaoDireita(umNoh);
    }

    // Rotação esquerda-direita
    if (fatorBal > 1 && umNoh->esq->fatorBalanceamento() < 0)
    {
        umNoh->esq = rotacaoEsquerda(umNoh->esq);
        return rotacaoDireita(umNoh);
    }

    // Rotação direita-esquerda
    if (fatorBal < -1 && umNoh->dir->fatorBalanceamento() > 0)
    {
        umNoh->dir = rotacaoDireita(umNoh->dir);
        return rotacaoEsquerda(umNoh);
    }

    return umNoh;
}

// Rotação à esquerda para balancear a árvore
noh *avl::rotacaoEsquerda(noh *umNoh)
{
    noh *nohDir = umNoh->dir;
    umNoh->dir = nohDir->esq;
    nohDir->esq = umNoh;

    // Atualiza as alturas
    umNoh->altura = 1 + max((umNoh->esq ? umNoh->esq->altura : 0), (umNoh->dir ? umNoh->dir->altura : 0));
    nohDir->altura = 1 + max((nohDir->esq ? nohDir->esq->altura : 0), (nohDir->dir ? nohDir->dir->altura : 0));

    return nohDir;
}

// Rotação à direita para balancear a árvore
noh *avl::rotacaoDireita(noh *umNoh)
{
    noh *nohEsq = umNoh->esq;
    umNoh->esq = nohEsq->dir;
    nohEsq->dir = umNoh;

    // Atualiza as alturas
    umNoh->altura = 1 + max((umNoh->esq ? umNoh->esq->altura : 0), (umNoh->dir ? umNoh->dir->altura : 0));
    nohEsq->altura = 1 + max((nohEsq->esq ? nohEsq->esq->altura : 0), (nohEsq->dir ? nohEsq->dir->altura : 0));

    return nohEsq;
}

// Busca auxiliar iterativa
noh *avl::buscaAux(tipoChave chave)
{
    noh *atual = raiz;

    while (atual != nullptr)
    {
        if (chave < atual->elemento.chave)
        {
            atual = atual->esq;
        }
        else if (chave > atual->elemento.chave)
        {
            atual = atual->dir;
        }
        else
        {
            return atual;
        }
    }

    return nullptr;
}

// Busca elemento com uma dada chave na árvore e retorna o registro completo
dado avl::busca(tipoChave chave)
{
    noh *resultado = buscaAux(chave);
    if (resultado != nullptr)
        return resultado->elemento;
    else
        throw runtime_error("Erro na busca: elemento não encontrado!");
}

// Encontra o menor nó (sucessor) de uma subárvore
noh *avl::encontraMenor(noh *raizSub)
{
    while (raizSub->esq != nullptr)
    {
        raizSub = raizSub->esq;
    }
    return raizSub;
}

// Remove o menor nó de uma subárvore
noh *avl::removeMenor(noh *raizSub)
{
    if (raizSub->esq == nullptr)
    {
        return raizSub->dir;
    }
    raizSub->esq = removeMenor(raizSub->esq);
    return arrumaBalanceamento(raizSub);
}

// Remove um elemento da árvore usando recursão
noh *avl::removeAux(noh *umNoh, tipoChave chave)
{
    if (umNoh == nullptr)
    {
        throw runtime_error("Erro na busca: elemento não encontrado!");
    }

    if (chave < umNoh->elemento.chave)
    {
        umNoh->esq = removeAux(umNoh->esq, chave);
    }
    else if (chave > umNoh->elemento.chave)
    {
        umNoh->dir = removeAux(umNoh->dir, chave);
    }
    else
    {
        if (umNoh->esq == nullptr)
        {
            return umNoh->dir;
        }
        else if (umNoh->dir == nullptr)
        {
            return umNoh->esq;
        }
        else
        {
            noh *sucessor = encontraMenor(umNoh->dir);
            umNoh->elemento = sucessor->elemento;
            umNoh->dir = removeMenor(umNoh->dir);
        }
    }
    return arrumaBalanceamento(umNoh);
}

// Remove um nó da árvore AVL
void avl::remove(tipoChave chave)
{
    raiz = removeAux(raiz, chave);
}

// Função auxiliar para levantamento
void avl::levantamentoAux(noh *umNoh, dado &ferramentaMaiorPotencia, string nomeFerramenta)
{
    if (umNoh == nullptr)
        return;

    levantamentoAux(umNoh->esq, ferramentaMaiorPotencia, nomeFerramenta);

    if (umNoh->elemento.ferramenta == nomeFerramenta)
    {
        if (umNoh->elemento.potencia > ferramentaMaiorPotencia.potencia ||
            (umNoh->elemento.potencia == ferramentaMaiorPotencia.potencia && umNoh->elemento.chave < ferramentaMaiorPotencia.chave))
        {
            ferramentaMaiorPotencia = umNoh->elemento;
        }
    }

    levantamentoAux(umNoh->dir, ferramentaMaiorPotencia, nomeFerramenta);
}

// Função para levantamento da marca da ferramenta com maior potência
string avl::levantamento(string nomeFerramenta)
{
    dado ferramentaMaiorPotencia = {0, "", "", 0};
    levantamentoAux(raiz, ferramentaMaiorPotencia, nomeFerramenta);
    if (ferramentaMaiorPotencia.chave != 0)
    {
        return ferramentaMaiorPotencia.marca;
    }
    else
    {
        throw runtime_error("Ferramenta não encontrada!");
    }
}

// Imprime a subárvore direita
void avl::imprimirDir(const string &prefixo, const noh *meuNoh)
{
    if (meuNoh != nullptr)
    {
        cout << prefixo
             << "└d─"
             << "(" << meuNoh->elemento.chave << "," << meuNoh->elemento.ferramenta << ")"
             << endl;

        imprimirEsq(prefixo + "    ", meuNoh->esq, meuNoh->dir == nullptr);
        imprimirDir(prefixo + "    ", meuNoh->dir);
    }
}

// Imprime a subárvore esquerda
void avl::imprimirEsq(const string &prefixo, const noh *meuNoh, bool temIrmao)
{
    if (meuNoh != nullptr)
    {
        cout << prefixo;

        if (temIrmao)
            cout << "└e─";
        else
            cout << "├e─";

        cout << "(" << meuNoh->elemento.chave << "," << meuNoh->elemento.ferramenta << ")"
             << endl;

        imprimirEsq(prefixo + "│   ", meuNoh->esq, meuNoh->dir == nullptr);
        imprimirDir(prefixo + "│   ", meuNoh->dir);
    }
}

// Imprime a árvore completa
void avl::imprimir()
{
    if (this->raiz != nullptr)
    {
        cout << "(" << this->raiz->elemento.chave << "," << this->raiz->elemento.ferramenta << ")" << endl;
        imprimirEsq(" ", this->raiz->esq, this->raiz->dir == nullptr);
        imprimirDir(" ", this->raiz->dir);
    }
    else
        cout << "*arvore vazia*" << endl;
}

// Sobrecarga do operador de saída para imprimir a árvore
ostream &operator<<(ostream &output, avl &arvore)
{
    arvore.imprimir();
    return output;
}

// Função principal para executar o programa
int main()
{
    avl arvore;
    tipoChave chave;
    dado umDado;
    string ferramenta;
    string marca;

    char operacao;

    do
    {
        try
        {
            cin >> operacao;
            switch (operacao)
            {
            case 'i': // Inserir recursivamente
                cin >> umDado;
                arvore.insere(umDado);
                break;
            case 'r': // Remover recursivamente
                cin >> chave;
                arvore.remove(chave);
                break;
            case 'b':                         // Buscar
                cin >> chave;                 // ler a chave
                umDado = arvore.busca(chave); // escrever os dados da ferramenta
                cout << "Elemento buscado: " << umDado << endl;
                break;
            case 'l':              // Levantamento por ferramenta
                cin >> ferramenta; // ler os dados para levantamento
                marca = arvore.levantamento(ferramenta);
                cout << "Levantamento do ferramenta " << ferramenta << ": " << marca << endl;
                break;
            case 'e': // Escrever tudo (em ordem)
                cout << arvore;
                break;
            case 'f': // Finalizar execução
                break;
            default:
                cout << "Comando invalido!\n";
            }
        }
        catch (runtime_error &e)
        {
            cout << e.what() << endl;
        }
    } while (operacao != 'f');

    return 0;
}
