#include <iostream>
#include <cstdlib>

using namespace std;

typedef int Dado; // Facilita a troca de tipo, se necessário, por exemplo, para float ou string

// Enumeração para identificar a posição do nó na árvore
enum posicao
{
  dir,
  esq
};

// Classe que representa um nó da árvore binária de busca (ABB)
class noh
{
  friend class abb; // A classe abb pode acessar os membros privados de noh
private:
  Dado valor; // Valor armazenado no nó
  noh *esq;   // Ponteiro para o filho à esquerda
  noh *dir;   // Ponteiro para o filho à direita
  noh *pai;   // Ponteiro para o pai do nó
public:
  noh(Dado d = 0); // Construtor que inicializa o nó com um valor
  ~noh();          // Destrutor que desaloca memória dos filhos
};

// Implementação do construtor da classe noh
noh::noh(Dado d)
{
  valor = d;
  esq = NULL; // Inicializa o ponteiro da esquerda como NULL
  dir = NULL; // Inicializa o ponteiro da direita como NULL
  pai = NULL; // Inicializa o ponteiro do pai como NULL
}

// Implementação do destrutor da classe noh
noh::~noh()
{
  // Chama recursivamente o destrutor para os nós filhos
  delete esq;
  delete dir;
}

// Classe que representa a árvore binária de busca (ABB)
class abb
{
private:
  noh *raiz; // Ponteiro para a raiz da árvore
  // Métodos auxiliares privados para percorrer a árvore e encontrar mínimo/máximo
  void percorreEmOrdemAux(noh *atual, int nivel);
  void percorrePreOrdemAux(noh *atual);
  void percorrePosOrdemAux(noh *atual);
  noh *minimoAux(noh *raizSub);
  noh *maximoAux(noh *raizSub);
  // Método auxiliar privado para substituir um nó na árvore
  void transplanta(noh *antigo, noh *novo);
  // Método auxiliar privado para calcular a altura de um nó na árvore
  int calculaAlturaAux(noh *atual);

public:
  abb() { raiz = NULL; }   // Construtor inicializa a árvore vazia
  ~abb();                  // Destrutor que desaloca a memória da árvore
  void insere(Dado d);     // Método para inserir um elemento na árvore
  void remove(Dado d);     // Método para remover um elemento da árvore
  noh *busca(Dado d);      // Método para buscar um elemento na árvore
  Dado minimo();           // Método para encontrar o menor valor na árvore
  Dado maximo();           // Método para encontrar o maior valor na árvore
  void percorreEmOrdem();  // Método para percorrer a árvore em ordem (in-order)
  void percorrePreOrdem(); // Método para percorrer a árvore em pré-ordem (pre-order)
  void percorrePosOrdem(); // Método para percorrer a árvore em pós-ordem (post-order)
  int calculaAltura();     // Método para calcular a altura da árvore
};

// Destrutor da classe abb que deleta a raiz e, consequentemente, todos os nós
abb::~abb()
{
  delete raiz;
}

// Método auxiliar recursivo que calcula a altura da subárvore enraizada em 'atual'
int abb::calculaAlturaAux(noh *atual)
{
  if (atual == NULL)
  {
    // Retorna 0 para que folhas tenham altura 1
    return 0;
  }
  else
  {
    // Calcula a altura das subárvores esquerda e direita
    int alturaEsq = calculaAlturaAux(atual->esq);
    int alturaDir = calculaAlturaAux(atual->dir);
    // A altura do nó atual é 1 + a maior altura entre seus filhos
    return 1 + max(alturaEsq, alturaDir);
  }
}

// Método público que chama o auxiliar para calcular a altura da árvore a partir da raiz
int abb::calculaAltura()
{
  return calculaAlturaAux(raiz);
}

// Método para inserir um novo nó na árvore
void abb::insere(Dado d)
{
  noh *novo = new noh(d); // Cria um novo nó com o valor fornecido
  posicao posInsercao;    // Variável para guardar a posição de inserção

  // Primeiro caso: se a árvore está vazia, o novo nó será a raiz
  if (raiz == NULL)
  {
    raiz = novo;
  }
  else
  {
    noh *atual = raiz;
    noh *anterior;

    // Loop para encontrar o ponto de inserção
    while (atual != NULL)
    {
      anterior = atual;
      if (atual->valor > d)
      { // Se o valor é menor, vá para a esquerda
        atual = atual->esq;
        posInsercao = esq;
      }
      else
      { // Se o valor é maior ou igual, vá para a direita
        atual = atual->dir;
        posInsercao = dir;
      }
    }

    // Conecta o novo nó ao pai
    novo->pai = anterior;
    if (posInsercao == dir)
    {
      anterior->dir = novo;
    }
    else
    {
      anterior->esq = novo;
    }
  }

  // Após a inserção, imprime a altura atual da árvore
  cout << calculaAltura() << " ";
}

// Método para buscar um nó com determinado valor na árvore
noh *abb::busca(Dado d)
{
  noh *atual = raiz;

  // Loop para percorrer a árvore até encontrar o valor ou chegar ao fim
  while (atual != NULL)
  {
    if (atual->valor == d)
    {
      return atual; // Retorna o nó se encontrar o valor
    }
    else if (atual->valor > d)
    {
      atual = atual->esq; // Vá para a esquerda se o valor é menor
    }
    else
    {
      atual = atual->dir; // Vá para a direita se o valor é maior
    }
  }

  return atual; // Retorna NULL se o valor não está na árvore
}

// Método para encontrar o menor valor na árvore
Dado abb::minimo()
{
  if (raiz == NULL)
  {
    cerr << "Árvore vazia!" << endl;
    exit(EXIT_FAILURE);
  }
  else
  {
    noh *nohMin = minimoAux(raiz); // Chama o auxiliar para encontrar o mínimo
    return nohMin->valor;
  }
}

// Método auxiliar que encontra o menor valor em uma subárvore
noh *abb::minimoAux(noh *raizSub)
{
  while (raizSub->esq != NULL)
  {
    raizSub = raizSub->esq;
  }
  return raizSub;
}

// Método para encontrar o maior valor na árvore
Dado abb::maximo()
{
  if (raiz == NULL)
  {
    cerr << "Árvore vazia!" << endl;
    exit(EXIT_FAILURE);
  }
  else
  {
    noh *nohMax = maximoAux(raiz); // Chama o auxiliar para encontrar o máximo
    return nohMax->valor;
  }
}

// Método auxiliar que encontra o maior valor em uma subárvore
noh *abb::maximoAux(noh *raizSub)
{
  while (raizSub->dir != NULL)
  {
    raizSub = raizSub->dir;
  }
  return raizSub;
}

// Método para substituir um nó antigo por um novo na árvore
void abb::transplanta(noh *antigo, noh *novo)
{
  if (raiz == antigo)
  {
    raiz = novo;
  }
  else if (antigo == antigo->pai->esq)
  {
    antigo->pai->esq = novo;
  }
  else
  {
    antigo->pai->dir = novo;
  }
  if (novo != NULL)
  {
    novo->pai = antigo->pai;
  }
}

// Método para remover um nó da árvore
void abb::remove(Dado dado)
{
  noh *nohRemover = busca(dado); // Busca o nó a ser removido

  if (nohRemover == NULL)
  {
    cerr << "valor não está na árvore!" << endl;
  }
  else
  {
    if (nohRemover->esq == NULL)
    { // Se não tem filho à esquerda
      transplanta(nohRemover, nohRemover->dir);
    }
    else if (nohRemover->dir == NULL)
    { // Se não tem filho à direita
      transplanta(nohRemover, nohRemover->esq);
    }
    else
    {                                             // Nó tem dois filhos
      noh *sucessor = minimoAux(nohRemover->dir); // Encontra o sucessor

      if (sucessor->pai != nohRemover)
      {
        transplanta(sucessor, sucessor->dir);
        sucessor->dir = nohRemover->dir;
        sucessor->dir->pai = sucessor;
      }

      transplanta(nohRemover, sucessor);
      sucessor->esq = nohRemover->esq;
      sucessor->esq->pai = sucessor;
    }

    // Após a remoção, desconecta os ponteiros e deleta o nó
    nohRemover->esq = NULL;
    nohRemover->dir = NULL;
    delete nohRemover;
  }

  // Após a remoção, imprime a altura atual da árvore
  cout << calculaAltura() << " ";
}

// Método para percorrer a árvore em ordem (in-order) e imprimir os valores
void abb::percorreEmOrdem()
{
  percorreEmOrdemAux(raiz, 0); // Chama o auxiliar com a raiz e nível inicial 0
  cout << endl;
}

// Método auxiliar que percorre a árvore em ordem (in-order)
void abb::percorreEmOrdemAux(noh *atual, int nivel)
{
  if (atual != NULL)
  {
    percorreEmOrdemAux(atual->esq, nivel + 1);   // Primeiro visita a subárvore esquerda
    cout << atual->valor << "/" << nivel << " "; // Depois processa o nó atual
    percorreEmOrdemAux(atual->dir, nivel + 1);   // Finalmente, visita a subárvore direita
  }
}

// Método para percorrer a árvore em pré-ordem (pre-order) e imprimir os valores
void abb::percorrePreOrdem()
{
  percorrePreOrdemAux(raiz);
  cout << endl;
}

// Método auxiliar que percorre a árvore em pré-ordem (pre-order)
void abb::percorrePreOrdemAux(noh *atual)
{
  if (atual != NULL)
  {
    cout << atual->valor << " ";     // Primeiro processa o nó atual
    percorrePreOrdemAux(atual->esq); // Depois visita a subárvore esquerda
    percorrePreOrdemAux(atual->dir); // Finalmente, visita a subárvore direita
  }
}

// Método para percorrer a árvore em pós-ordem (post-order) e imprimir os valores
void abb::percorrePosOrdem()
{
  percorrePosOrdemAux(raiz);
  cout << endl;
}

// Método auxiliar que percorre a árvore em pós-ordem (post-order)
void abb::percorrePosOrdemAux(noh *atual)
{
  if (atual != NULL)
  {
    percorrePosOrdemAux(atual->esq); // Primeiro visita a subárvore esquerda
    percorrePosOrdemAux(atual->dir); // Depois visita a subárvore direita
    cout << atual->valor << " ";     // Finalmente, processa o nó atual
  }
}

// Função principal (main) que realiza a leitura dos dados, inserção e remoção na árvore
int main()
{
  abb minhaArvore; // Cria uma nova árvore
  int valor;       // Variável para armazenar os valores de entrada
  int num;         // Variável para armazenar a quantidade de elementos

  // Leitura do número de elementos a serem inseridos
  cin >> num;

  // Loop para inserir os elementos na árvore
  for (int i = 0; i < num; i++)
  {
    cin >> valor;
    minhaArvore.insere(valor); // Insere o valor e imprime a altura após cada inserção
  }
  cout << endl;
  minhaArvore.percorreEmOrdem(); // Imprime a árvore em ordem após todas as inserções

  // Leitura do número de elementos a serem removidos
  cin >> num;

  // Loop para remover os elementos da árvore
  for (int i = 0; i < num; i++)
  {
    cin >> valor;
    minhaArvore.remove(valor); // Remove o valor e imprime a altura após cada remoção
  }
  cout << endl;
  minhaArvore.percorreEmOrdem(); // Imprime a árvore em ordem após todas as remoções

  return 0; // Retorna 0 para indicar que o programa terminou com sucesso
}
