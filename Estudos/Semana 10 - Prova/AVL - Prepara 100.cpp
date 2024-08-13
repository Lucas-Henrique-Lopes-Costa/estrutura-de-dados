/*
Questão 1: AVL - implementação completa
Implemente uma classe para representar árvores AVL, que contém operações para inserir, buscar, remover e escrever a estrutura da árvore. O código fornecido contém a implementação para escrever a estrutura e também uma sugestão de atributos e métodos necessários. O atributo altura da classe nó é obrigatório e é usado no método de escrita. Também já está implementado o programa que usa a classe AVL.

Entradas:

O programa lê códigos de comandos a executar. Sempre um caractere identificando o comando, seguido dos parâmetros necessários para executar o comando, se houverem. Os códigos de comandos são:

i: para inserir um elemento (string / número real) à árvore, sendo que os dados são ordenados pela string;
b: para buscar um valor (número real) associado a uma chave (string);
r: para remover um elemento, seguido da chave (string) do elemento;
e: para escrever a estrutura da árvore.
Saídas:

Somente o comando para escrever produz saída no formato especificado, que já está implementado.

Exemplo de Entrada:

i andre 19
e
i antonio 29
e
i carla 28
e
i diego 52
e
i eduardo 63
e
r diego
e
r antonio
e
b eduardo
f
Exemplo de Saída:

[1:andre/19]
[] []

[2:andre/19]
[] [1:antonio/29]
[] []

[2:antonio/29]
[1:andre/19] [1:carla/28]
[] [] [] []

[3:antonio/29]
[1:andre/19] [2:carla/28]
[] [] [] [1:diego/52]
[] []

[3:antonio/29]
[1:andre/19] [2:diego/52]
[] [] [1:carla/28] [1:eduardo/63]
[] [] [] []

[3:antonio/29]
[1:andre/19] [2:eduardo/63]
[] [] [1:carla/28] []
[] []

[2:carla/28]
[1:andre/19] [1:eduardo/63]
[] [] [] []

63
*/

#include <iostream>
#include <queue>
#include <stdexcept>
using namespace std;

// Classe que representa o objeto armazenado em cada nó da árvore AVL
class objeto
{
private:
  string chave;  // Chave usada para ordenar os nós na árvore
  double numero; // Valor associado à chave

public:
  // Construtor padrão
  objeto()
  {
    chave = "";
    numero = -1;
  }

  // Construtor com parâmetros
  objeto(string c, double n)
  {
    chave = c;
    numero = n;
  }

  // Métodos de acesso para obter o valor do número
  double getNumero()
  {
    return numero;
  }

  // Método de acesso para obter a chave
  string getChave()
  {
    return chave;
  }
};

// Classe que representa um nó na árvore AVL
class noh
{
  // Permite que a classe AVL acesse membros privados de noh
  friend class AVL;
  // Sobrecarga do operador de saída para facilitar a impressão de nós
  friend std::ostream &operator<<(std::ostream &saida, noh *ptNoh);

private:
  objeto elemento;    // Elemento armazenado no nó
  noh *filhoEsquerda; // Ponteiro para o filho à esquerda
  noh *filhoDireita;  // Ponteiro para o filho à direita
  int fatorB;         // Fator de balanceamento do nó
  int altura;         // Altura do nó na árvore

public:
  // Construtor do nó que inicializa o objeto, filhos como nulos, e define o fator de balanceamento e altura
  noh(objeto o)
  {
    elemento = o;
    filhoEsquerda = nullptr;
    filhoDireita = nullptr;
    fatorB = 0;
    altura = 1;
  }
};

// Classe que implementa a árvore AVL
class AVL
{
private:
  noh *raiz; // Ponteiro para a raiz da árvore

  // Métodos auxiliares privados para remoção e balanceamento
  void removerBusca(string c, noh *&atual, bool &diminuiu);
  void deletarNoh(noh *&atual, bool &diminuiu);
  void obterSucessor(objeto &objSucessor, noh *aux);

public:
  // Construtor que inicializa a árvore como vazia e destrutor que libera memória
  AVL();
  ~AVL();

  // Métodos para manipulação da árvore
  void deletaTudo(noh *atual);                 // Apaga todos os nós da árvore
  noh *getRaiz();                              // Retorna a raiz da árvore
  bool vazia();                                // Verifica se a árvore está vazia
  void inserir(string c, double n);            // Insere um novo elemento na árvore
  void remover(string c);                      // Remove um elemento da árvore
  bool buscar(string c, objeto &objRetorno);   // Busca por um elemento na árvore
  void imprimePreOrdem(noh *atual, int nivel); // Imprime a árvore em pré-ordem
  void imprimeEmOrdem(noh *atual, int nivel);  // Imprime a árvore em ordem
  void imprimePosOrdem(noh *atual, int nivel); // Imprime a árvore em pós-ordem
  void escreverNivelANivel(ostream &saida);    // Escreve a árvore nível a nível

  // Métodos para rotação e balanceamento
  void rotacaodireita(noh *&tree);         // Rotação simples à direita
  void rotacaoesquerda(noh *&tree);        // Rotação simples à esquerda
  void rotacaoesquerdadireita(noh *&tree); // Rotação dupla esquerda-direita
  void rotacaodireitaesquerda(noh *&tree); // Rotação dupla direita-esquerda
  void realizarotacao(noh *&tree);         // Realiza a rotação apropriada para balancear a árvore

  // Métodos auxiliares para cálculo de altura
  void insererecursivo(noh *&atual, objeto o, bool &cresceu); // Inserção recursiva
  int getAltura(noh *atual);                                  // Obtém a altura de um nó
  void atualizaAltura(noh *atual);                            // Atualiza a altura de um nó
};

// Construtor da árvore AVL
AVL::AVL()
{
  raiz = nullptr; // Inicia com a árvore vazia
}

// Destrutor da árvore AVL
AVL::~AVL()
{
  deletaTudo(raiz); // Libera toda a memória alocada para a árvore
}

// Método auxiliar para deletar todos os nós da árvore
void AVL::deletaTudo(noh *atual)
{
  if (atual != nullptr)
  {
    deletaTudo(atual->filhoEsquerda);
    deletaTudo(atual->filhoDireita);
    delete atual; // Deleta o nó atual após deletar seus filhos
  }
}

// Retorna o ponteiro para a raiz da árvore
noh *AVL::getRaiz()
{
  return raiz;
}

// Verifica se a árvore está vazia
bool AVL::vazia()
{
  return raiz == nullptr; // Retorna verdadeiro se a raiz for nula
}

// Método público para inserir um elemento na árvore
void AVL::inserir(string c, double n)
{
  objeto o(c, n);                    // Cria um objeto com a chave e valor
  bool cresceu;                      // Flag para verificar se a árvore cresceu em altura
  insererecursivo(raiz, o, cresceu); // Chama a função de inserção recursiva
}

// Método auxiliar recursivo para inserir um elemento na árvore
void AVL::insererecursivo(noh *&atual, objeto o, bool &cresceu)
{
  if (atual == nullptr)
  {
    atual = new noh(o); // Cria um novo nó se o local correto for encontrado
    cresceu = true;     // Marca que a árvore cresceu
    return;
  }

  // Decisão de inserção na subárvore esquerda ou direita
  if (o.getChave() < atual->elemento.getChave())
  {
    insererecursivo(atual->filhoEsquerda, o, cresceu);
    if (cresceu)
    {
      atual->fatorB -= 1; // Atualiza o fator de balanceamento
    }
  }
  else
  {
    insererecursivo(atual->filhoDireita, o, cresceu);
    if (cresceu)
    {
      atual->fatorB += 1; // Atualiza o fator de balanceamento
    }
  }

  atualizaAltura(atual); // Atualiza a altura do nó atual
  realizarotacao(atual); // Verifica e realiza a rotação se necessário

  // Se a árvore não cresceu, ajusta a flag
  if (cresceu && atual->fatorB == 0)
  {
    cresceu = false;
  }
}

// Método público para remover um elemento da árvore
void AVL::remover(string c)
{
  bool diminuiu;                   // Flag para verificar se a árvore diminuiu em altura
  removerBusca(c, raiz, diminuiu); // Chama a função de remoção recursiva
}

// Método auxiliar recursivo para remover um elemento da árvore
void AVL::removerBusca(string c, noh *&atual, bool &diminuiu)
{
  if (c < atual->elemento.getChave())
  {
    removerBusca(c, atual->filhoEsquerda, diminuiu);
    if (diminuiu)
    {
      atual->fatorB += 1; // Atualiza o fator de balanceamento
    }
  }
  else if (c > atual->elemento.getChave())
  {
    removerBusca(c, atual->filhoDireita, diminuiu);
    if (diminuiu)
    {
      atual->fatorB -= 1; // Atualiza o fator de balanceamento
    }
  }
  else
  {
    deletarNoh(atual, diminuiu); // Encontra e deleta o nó
  }

  if (atual != nullptr)
  {
    atualizaAltura(atual); // Atualiza a altura do nó atual
    realizarotacao(atual); // Verifica e realiza a rotação se necessário
    if (diminuiu && atual->fatorB != 0)
    {
      diminuiu = false; // Ajusta a flag se necessário
    }
  }
}

// Método auxiliar para deletar um nó da árvore
void AVL::deletarNoh(noh *&atual, bool &diminuiu)
{
  noh *aux = atual;
  if (atual->filhoEsquerda == nullptr)
  {
    atual = atual->filhoDireita; // Substitui o nó pelo seu filho direito
    diminuiu = true;             // Marca que a árvore diminuiu em altura
    delete aux;                  // Libera a memória do nó
  }
  else if (atual->filhoDireita == nullptr)
  {
    atual = atual->filhoEsquerda; // Substitui o nó pelo seu filho esquerdo
    diminuiu = true;              // Marca que a árvore diminuiu em altura
    delete aux;                   // Libera a memória do nó
  }
  else
  {
    objeto objSucessor;
    obterSucessor(objSucessor, atual);                                   // Obtém o sucessor
    atual->elemento = objSucessor;                                       // Substitui o elemento pelo sucessor
    removerBusca(objSucessor.getChave(), atual->filhoDireita, diminuiu); // Remove o sucessor da subárvore direita
    if (diminuiu)
    {
      atual->fatorB -= 1; // Atualiza o fator de balanceamento
    }
  }
}

// Obtém o sucessor de um nó na árvore
void AVL::obterSucessor(objeto &objSucessor, noh *aux)
{
  aux = aux->filhoDireita;
  while (aux->filhoEsquerda != nullptr)
  {
    aux = aux->filhoEsquerda; // Procura o menor valor na subárvore direita
  }
  objSucessor = aux->elemento; // Define o sucessor como o menor valor encontrado
}

// Método público para buscar um elemento na árvore
bool AVL::buscar(string c, objeto &objRetorno)
{
  if (vazia())
  {
    return false; // Retorna falso se a árvore estiver vazia
  }
  else
  {
    noh *aux = raiz;
    while (aux != nullptr)
    {
      if (c == aux->elemento.getChave())
      {
        objRetorno = aux->elemento; // Retorna o objeto se encontrado
        return true;
      }
      else if (c < aux->elemento.getChave())
      {
        aux = aux->filhoEsquerda; // Continua a busca na subárvore esquerda
      }
      else
      {
        aux = aux->filhoDireita; // Continua a busca na subárvore direita
      }
    }
    return false; // Retorna falso se o objeto não for encontrado
  }
}

// Métodos para imprimir a árvore em diferentes ordens
void AVL::imprimePreOrdem(noh *atual, int nivel)
{
  if (atual != nullptr)
  {
    cout << atual->elemento.getChave() << "/" << nivel << " "; // Imprime a chave e o nível
    imprimePreOrdem(atual->filhoEsquerda, nivel + 1);          // Percorre a subárvore esquerda
    imprimePreOrdem(atual->filhoDireita, nivel + 1);           // Percorre a subárvore direita
  }
}

void AVL::imprimeEmOrdem(noh *atual, int nivel)
{
  if (atual != nullptr)
  {
    imprimeEmOrdem(atual->filhoEsquerda, nivel + 1);           // Percorre a subárvore esquerda
    cout << atual->elemento.getChave() << "/" << nivel << " "; // Imprime a chave e o nível
    imprimeEmOrdem(atual->filhoDireita, nivel + 1);            // Percorre a subárvore direita
  }
}

void AVL::imprimePosOrdem(noh *atual, int nivel)
{
  if (atual != nullptr)
  {
    imprimePosOrdem(atual->filhoEsquerda, nivel + 1);          // Percorre a subárvore esquerda
    imprimePosOrdem(atual->filhoDireita, nivel + 1);           // Percorre a subárvore direita
    cout << atual->elemento.getChave() << "/" << nivel << " "; // Imprime a chave e o nível
  }
}

// Sobrecarga do operador de saída para imprimir um nó
ostream &operator<<(ostream &saida, noh *ptNoh)
{
  if (ptNoh == nullptr)
    saida << "[]"; // Imprime nó vazio
  else
    saida << '[' << ptNoh->altura << ':' << ptNoh->elemento.getChave() << '/' << ptNoh->elemento.getNumero() << ']'; // Imprime a altura, chave e número do nó
  return saida;
}

// Escreve a estrutura da árvore nível a nível
void AVL::escreverNivelANivel(ostream &saida)
{
  queue<noh *> filhos;
  noh *fimDeNivel = new noh(objeto()); // Nó especial para marcar o fim de um nível
  filhos.push(raiz);
  filhos.push(fimDeNivel);

  while (not filhos.empty())
  {
    noh *ptNoh = filhos.front();
    filhos.pop();

    if (ptNoh == fimDeNivel)
    {
      saida << "\n"; // Nova linha ao final de cada nível
      if (not filhos.empty())
        filhos.push(fimDeNivel); // Adiciona o marcador de fim de nível para a próxima linha
    }
    else
    {
      cout << ptNoh << ' '; // Imprime o nó atual
      if (ptNoh != nullptr)
      {
        filhos.push(ptNoh->filhoEsquerda); // Adiciona o filho esquerdo à fila
        filhos.push(ptNoh->filhoDireita);  // Adiciona o filho direito à fila
      }
    }
  }

  delete fimDeNivel; // Libera a memória do nó marcador
}

// Obtém a altura de um nó na árvore
int AVL::getAltura(noh *atual)
{
  if (atual == nullptr)
  {
    return 0; // Retorna 0 se o nó for nulo
  }
  else
  {
    return atual->altura; // Retorna a altura do nó
  }
}

// Atualiza a altura de um nó na árvore
void AVL::atualizaAltura(noh *atual)
{
  if (atual != nullptr)
  {
    int altEsq = getAltura(atual->filhoEsquerda); // Obtém a altura da subárvore esquerda
    int altDir = getAltura(atual->filhoDireita);  // Obtém a altura da subárvore direita
    atual->altura = 1 + max(altEsq, altDir);      // Define a nova altura do nó
  }
}

// Rotação simples à direita
void AVL::rotacaodireita(noh *&pai)
{
  noh *novopai = pai->filhoEsquerda;          // Define o novo pai
  pai->filhoEsquerda = novopai->filhoDireita; // Ajusta o filho esquerdo
  novopai->filhoDireita = pai;                // Ajusta o filho direito do novo pai
  atualizaAltura(pai);                        // Atualiza a altura do pai original
  atualizaAltura(novopai);                    // Atualiza a altura do novo pai
  pai = novopai;                              // Redefine o ponteiro pai
}

// Rotação simples à esquerda
void AVL::rotacaoesquerda(noh *&pai)
{
  noh *novopai = pai->filhoDireita;           // Define o novo pai
  pai->filhoDireita = novopai->filhoEsquerda; // Ajusta o filho direito
  novopai->filhoEsquerda = pai;               // Ajusta o filho esquerdo do novo pai
  atualizaAltura(pai);                        // Atualiza a altura do pai original
  atualizaAltura(novopai);                    // Atualiza a altura do novo pai
  pai = novopai;                              // Redefine o ponteiro pai
}

// Rotação dupla (esquerda-direita)
void AVL::rotacaoesquerdadireita(noh *&pai)
{
  noh *filho = pai->filhoEsquerda;
  rotacaoesquerda(filho); // Primeira rotação à esquerda
  pai->filhoEsquerda = filho;
  rotacaodireita(pai); // Segunda rotação à direita
}

// Rotação dupla (direita-esquerda)
void AVL::rotacaodireitaesquerda(noh *&pai)
{
  noh *filho = pai->filhoDireita;
  rotacaodireita(filho); // Primeira rotação à direita
  pai->filhoDireita = filho;
  rotacaoesquerda(pai); // Segunda rotação à esquerda
}

// Realiza a rotação apropriada para balancear a árvore
void AVL::realizarotacao(noh *&pai)
{
  noh *filho;
  noh *neto; // Caso precise da rotação dupla

  if (pai->fatorB == -2)
  { // Rotaciona para a direita
    filho = pai->filhoEsquerda;

    if (filho->fatorB == -1)
    { // Simples para a direita
      pai->fatorB = 0;
      filho->fatorB = 0;
      rotacaodireita(pai);
    }
    else if (filho->fatorB == 0)
    { // Simples para a direita
      pai->fatorB = -1;
      filho->fatorB = 1;
      rotacaodireita(pai);
    }
    else if (filho->fatorB == 1)
    { // Rotação dupla
      neto = filho->filhoDireita;
      if (neto->fatorB == -1)
      {
        pai->fatorB = 1;
        filho->fatorB = 0;
      }
      else if (neto->fatorB == 0)
      {
        pai->fatorB = 0;
        filho->fatorB = 0;
      }
      else if (neto->fatorB == 1)
      {
        pai->fatorB = 0;
        filho->fatorB = -1;
      }
      neto->fatorB = 0;
      rotacaodireitaesquerda(pai);
    }
  }
  else if (pai->fatorB == 2)
  { // Rotaciona para a esquerda
    filho = pai->filhoDireita;
    if (filho->fatorB == 1)
    { // Simples para a esquerda
      pai->fatorB = 0;
      filho->fatorB = 0;
      rotacaoesquerda(pai);
    }
    else if (filho->fatorB == 0)
    { // Simples para a esquerda
      pai->fatorB = 1;
      filho->fatorB = -1;
      rotacaoesquerda(pai);
    }
    else if (filho->fatorB == -1)
    { // Rotação dupla
      neto = filho->filhoEsquerda;
      if (neto->fatorB == -1)
      {
        pai->fatorB = 0;
        filho->fatorB = 1;
      }
      else if (neto->fatorB == 0)
      {
        pai->fatorB = 0;
        filho->fatorB = 0;
      }
      else if (neto->fatorB == 1)
      {
        pai->fatorB = -1;
        filho->fatorB = 0;
      }
      neto->fatorB = 0;
      rotacaodireitaesquerda(pai);
    }
  }
}

// Função principal para executar o programa
int main()
{
  AVL avl;
  objeto objAux;
  char comando;
  string chave;
  double valor = -1;

  do
  {
    try
    {
      cin >> comando;
      switch (comando)
      {
      case 'i': // Inserir
        cin >> chave;
        cin >> valor;
        avl.inserir(chave, valor); // Insere o elemento na árvore
        break;
      case 'r': // Remover
        cin >> chave;
        if (avl.buscar(chave, objAux))
        {
          avl.remover(chave); // Remove o elemento da árvore se ele for encontrado
        }
        else
        {
          cout << "ERRO" << endl; // Exibe erro se o elemento não for encontrado
        }
        break;
      case 'o':
        avl.imprimeEmOrdem(avl.getRaiz(), 0); // Imprime a árvore em ordem
        break;
      case 'p':
        avl.imprimePreOrdem(avl.getRaiz(), 0); // Imprime a árvore em pré-ordem
        break;
      case 'z':
        avl.imprimePosOrdem(avl.getRaiz(), 0); // Imprime a árvore em pós-ordem
        break;
      case 'b': // Buscar
        cin >> chave;
        if (avl.buscar(chave, objAux))
        {
          cout << objAux.getNumero() << endl; // Exibe o valor associado à chave se encontrado
        }
        else
        {
          cout << "Objeto não encontrado!" << endl; // Exibe mensagem se o elemento não for encontrado
        }
        break;
      case 'e':                        // Escrever nível a nível
        avl.escreverNivelANivel(cout); // Escreve a árvore nível a nível
        break;
      case 'f': // Finalizar
        // Verificado no do-while
        break;
      default:
        cerr << "comando inválido\n"; // Exibe erro se o comando for inválido
      }
    }
    catch (runtime_error &e)
    {
      cout << e.what() << endl; // Trata exceções em tempo de execução
    }
  } while (comando != 'f'); // Finaliza a execução se o comando for 'f'

  return 0;
}
