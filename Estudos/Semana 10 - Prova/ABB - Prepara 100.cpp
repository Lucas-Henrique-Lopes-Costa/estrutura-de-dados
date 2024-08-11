#include <iostream>
using namespace std;

// Classe 'objeto' representa o tipo de dado que será armazenado na ABB.
// Neste caso, ela contém apenas um número inteiro.
class objeto
{
private:
  int numero; // Chave armazenada no objeto.

public:
  // Construtor padrão inicializa a chave com -1.
  objeto()
  {
    numero = -1;
  }
  // Construtor que inicializa a chave com um valor fornecido.
  objeto(int n)
  {
    numero = n;
  }
  // Método que retorna o valor da chave.
  int getNumero()
  {
    return numero;
  }
};

// Classe 'noh' representa um nó da ABB.
// Cada nó possui um elemento e dois filhos (esquerda e direita).
class noh
{
  friend class ABB;

private:
  objeto elemento;    // Elemento armazenado no nó.
  noh *filhoEsquerda; // Ponteiro para o filho à esquerda.
  noh *filhoDireita;  // Ponteiro para o filho à direita.

public:
  // Construtor que inicializa um nó com um objeto e filhos nulos.
  noh(objeto o)
  {
    elemento = o;
    filhoEsquerda = NULL;
    filhoDireita = NULL;
  }
};

// Classe 'ABB' implementa a Árvore Binária de Busca.
// Contém métodos para inserir, remover e buscar elementos, além de imprimir a árvore em diferentes ordens.
class ABB
{
private:
  noh *raiz; // Ponteiro para a raiz da árvore.
  // Métodos auxiliares para remoção de nós, obtenção do sucessor e deleção.
  void removerBusca(int n, noh *&atual);
  void deletarNoh(noh *&atual);
  void obterSucessor(objeto &objSucessor, noh *aux);

public:
  ABB();                                       // Construtor padrão.
  ~ABB();                                      // Destrutor para liberar memória.
  void deletaTudo(noh *atual);                 // Deleta todos os nós da árvore.
  noh *getRaiz();                              // Retorna a raiz da árvore.
  bool vazia();                                // Verifica se a árvore está vazia.
  void inserir(int n);                         // Insere um novo elemento na árvore.
  void remover(int n);                         // Remove um elemento da árvore.
  bool buscar(int n, objeto &objRetorno);      // Busca um elemento na árvore.
  void imprimePreOrdem(noh *atual, int nivel); // Imprime a árvore em pré-ordem.
  void imprimeEmOrdem(noh *atual, int nivel);  // Imprime a árvore em ordem.
  void imprimePosOrdem(noh *atual, int nivel); // Imprime a árvore em pós-ordem.
};

// Construtor da classe ABB, inicializa a árvore vazia (raiz nula).
ABB::ABB()
{
  raiz = NULL;
}

// Destrutor da classe ABB, libera toda a memória alocada pelos nós.
ABB::~ABB()
{
  deletaTudo(raiz);
}

// Método recursivo para deletar todos os nós da árvore.
void ABB::deletaTudo(noh *atual)
{
  if (atual != NULL)
  {
    deletaTudo(atual->filhoEsquerda);
    deletaTudo(atual->filhoDireita);
    delete atual;
  }
}

// Retorna o ponteiro para a raiz da árvore.
noh *ABB::getRaiz()
{
  return raiz;
}

// Verifica se a árvore está vazia.
bool ABB::vazia()
{
  return raiz == NULL;
}

// Método para inserir um novo elemento na árvore.
void ABB::inserir(int n)
{
  noh *novo = new noh(objeto(n)); // Cria um novo nó com o valor fornecido.
  if (vazia())
  {
    raiz = novo; // Se a árvore estiver vazia, o novo nó se torna a raiz.
  }
  else
  {
    noh *aux = raiz;
    while (aux != NULL)
    {
      if (n < aux->elemento.getNumero())
      {
        if (aux->filhoEsquerda == NULL)
        {
          aux->filhoEsquerda = novo; // Insere à esquerda se for menor.
          aux = NULL;
        }
        else
        {
          aux = aux->filhoEsquerda;
        }
      }
      else
      {
        if (aux->filhoDireita == NULL)
        {
          aux->filhoDireita = novo; // Insere à direita se for maior ou igual.
          aux = NULL;
        }
        else
        {
          aux = aux->filhoDireita;
        }
      }
    }
  }
}

// Método para remover um elemento da árvore.
void ABB::remover(int n)
{
  removerBusca(n, raiz); // Chama o método auxiliar para buscar e remover o nó.
}

// Método recursivo para buscar e remover um nó na árvore.
void ABB::removerBusca(int n, noh *&atual)
{
  if (n == atual->elemento.getNumero())
  {
    deletarNoh(atual); // Se o nó for encontrado, chama o método para deletar.
  }
  else if (n < atual->elemento.getNumero())
  {
    removerBusca(n, atual->filhoEsquerda); // Busca à esquerda se for menor.
  }
  else
  {
    removerBusca(n, atual->filhoDireita); // Busca à direita se for maior.
  }
}

// Método para deletar o nó encontrado.
void ABB::deletarNoh(noh *&atual)
{
  noh *aux = atual;
  if (atual->filhoEsquerda == NULL)
  {
    atual = atual->filhoDireita; // Caso o nó tenha só um filho à direita.
    delete aux;
  }
  else if (atual->filhoDireita == NULL)
  {
    atual = atual->filhoEsquerda; // Caso o nó tenha só um filho à esquerda.
    delete aux;
  }
  else
  {
    objeto objSucessor;
    obterSucessor(objSucessor, atual); // Substitui pelo sucessor se tiver dois filhos.
    atual->elemento = objSucessor;
    removerBusca(objSucessor.getNumero(), atual->filhoDireita);
  }
}

// Método para obter o sucessor do nó atual (menor valor na subárvore direita).
void ABB::obterSucessor(objeto &objSucessor, noh *aux)
{
  aux = aux->filhoDireita;
  while (aux->filhoEsquerda != NULL)
  {
    aux = aux->filhoEsquerda; // O sucessor é o nó mais à esquerda da subárvore direita.
  }
  objSucessor = aux->elemento;
}

// Método para buscar um elemento na árvore.
bool ABB::buscar(int n, objeto &objRetorno)
{
  if (vazia())
  {
    return false; // Retorna falso se a árvore estiver vazia.
  }
  else
  {
    noh *aux = raiz;
    while (aux != NULL)
    {
      if (n == aux->elemento.getNumero())
      {
        objRetorno = aux->elemento; // Retorna verdadeiro se o elemento for encontrado.
        return true;
      }
      else if (n < aux->elemento.getNumero())
      {
        aux = aux->filhoEsquerda; // Busca à esquerda se for menor.
      }
      else
      {
        aux = aux->filhoDireita; // Busca à direita se for maior.
      }
    }
    return false; // Retorna falso se o elemento não for encontrado.
  }
}

// Método para imprimir a árvore em pré-ordem (raiz, esquerda, direita).
void ABB::imprimePreOrdem(noh *atual, int nivel)
{
  if (atual != NULL)
  {
    cout << atual->elemento.getNumero() << "/" << nivel << " "; // Imprime a chave e o nível.
    imprimePreOrdem(atual->filhoEsquerda, nivel + 1);
    imprimePreOrdem(atual->filhoDireita, nivel + 1);
  }
}

// Método para imprimir a árvore em ordem (esquerda, raiz, direita).
void ABB::imprimeEmOrdem(noh *atual, int nivel)
{
  if (atual != NULL)
  {
    imprimeEmOrdem(atual->filhoEsquerda, nivel + 1);
    cout << atual->elemento.getNumero() << "/" << nivel << " "; // Imprime a chave e o nível.
    imprimeEmOrdem(atual->filhoDireita, nivel + 1);
  }
}

// Método para imprimir a árvore em pós-ordem (esquerda, direita, raiz).
void ABB::imprimePosOrdem(noh *atual, int nivel)
{
  if (atual != NULL)
  {
    imprimePosOrdem(atual->filhoEsquerda, nivel + 1);
    imprimePosOrdem(atual->filhoDireita, nivel + 1);
    cout << atual->elemento.getNumero() << "/" << nivel << " "; // Imprime a chave e o nível.
  }
}

int main()
{
  ABB abb; // Instancia uma Árvore Binária de Busca.
  objeto objAux;
  char comando;
  int valor = -1;
  do
  {
    try
    {
      cin >> comando;
      switch (comando)
      {
      case 'i': // Comando para inserir um elemento.
        cin >> valor;
        abb.inserir(valor);
        break;
      case 'r': // Comando para remover um elemento.
        cin >> valor;
        if (abb.buscar(valor, objAux))
        {
          abb.remover(valor);
        }
        else
        {
          cout << "ERRO" << endl; // Escreve "ERRO" se o elemento não estiver na árvore.
        }
        break;
      case 'o': // Comando para imprimir em ordem.
        abb.imprimeEmOrdem(abb.getRaiz(), 0);
        cout << endl;
        break;
      case 'p': // Comando para imprimir em pré-ordem.
        abb.imprimePreOrdem(abb.getRaiz(), 0);
        cout << endl;
        break;
      case 'z': // Comando para imprimir em pós-ordem.
        abb.imprimePosOrdem(abb.getRaiz(), 0);
        cout << endl;
        break;
      case 'b': // Comando para buscar um elemento.
        cin >> valor;
        if (abb.buscar(valor, objAux))
        {
          cout << objAux.getNumero() << endl;
        }
        else
        {
          cout << "Objeto não encontrado!" << endl;
        }
        break;
      case 'f': // Comando para finalizar a execução.
        break;
      default:
        cerr << "comando inválido\n"; // Mensagem de erro para comandos inválidos.
      }
    }
    catch (runtime_error &e)
    {
      cout << e.what() << endl;
    }
  } while (comando != 'f'); // Finaliza a execução do programa.
  return 0;
}
