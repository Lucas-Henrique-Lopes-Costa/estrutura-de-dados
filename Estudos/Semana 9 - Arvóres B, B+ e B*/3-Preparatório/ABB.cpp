#include <iostream>
using namespace std;

// Classe que representa um objeto armazenado na árvore
class objeto
{
private:
  int numero; // Valor inteiro associado ao objeto

public:
  // Construtor padrão que inicializa o valor como -1
  objeto()
  {
    numero = -1;
  }

  // Construtor que inicializa o valor com um número inteiro específico
  objeto(int n)
  {
    numero = n;
  }

  // Método de acesso para obter o valor do objeto
  int getNumero()
  {
    return numero;
  }
};

// Classe que representa um nó na árvore binária de busca (ABB)
class noh
{
  friend class ABB; // Permite que a classe ABB acesse os membros privados de noh

private:
  objeto elemento;    // Objeto armazenado no nó
  noh *filhoEsquerda; // Ponteiro para o filho à esquerda
  noh *filhoDireita;  // Ponteiro para o filho à direita

public:
  // Construtor que inicializa o nó com um objeto e define os filhos como nulos
  noh(objeto o)
  {
    elemento = o;
    filhoEsquerda = NULL;
    filhoDireita = NULL;
  }
};

// Classe que implementa a árvore binária de busca (ABB)
class ABB
{
private:
  noh *raiz; // Ponteiro para a raiz da árvore

  // Métodos auxiliares privados para operações na árvore
  void removerBusca(int n, noh *&atual);             // Auxilia na remoção de um nó
  void deletarNoh(noh *&atual);                      // Deleta um nó específico
  void obterSucessor(objeto &objSucessor, noh *aux); // Encontra o sucessor de um nó

public:
  // Construtor e destrutor da árvore
  ABB();
  ~ABB();

  // Métodos públicos para manipulação da árvore
  void deletaTudo(noh *atual);                 // Deleta todos os nós da árvore
  noh *getRaiz();                              // Retorna a raiz da árvore
  bool vazia();                                // Verifica se a árvore está vazia
  void inserir(int n);                         // Insere um novo nó na árvore
  void remover(int n);                         // Remove um nó da árvore
  bool buscar(int n, objeto &objRetorno);      // Busca um nó na árvore
  void imprimePreOrdem(noh *atual, int nivel); // Imprime a árvore em pré-ordem
  void imprimeEmOrdem(noh *atual, int nivel);  // Imprime a árvore em ordem
  void imprimePosOrdem(noh *atual, int nivel); // Imprime a árvore em pós-ordem
};

// Construtor da árvore ABB que inicializa a raiz como nula
ABB::ABB()
{
  raiz = NULL;
}

// Destrutor da árvore ABB que deleta todos os nós
ABB::~ABB()
{
  deletaTudo(raiz);
}

// Método auxiliar para deletar todos os nós da árvore de forma recursiva
void ABB::deletaTudo(noh *atual)
{
  if (atual != NULL)
  {
    deletaTudo(atual->filhoEsquerda);
    deletaTudo(atual->filhoDireita);
    delete atual;
  }
}

// Retorna o ponteiro para a raiz da árvore
noh *ABB::getRaiz()
{
  return raiz;
}

// Verifica se a árvore está vazia
bool ABB::vazia()
{
  return raiz == NULL;
}

// Método público para inserir um novo elemento na árvore
void ABB::inserir(int n)
{
  noh *novo = new noh(objeto(n)); // Cria um novo nó com o valor n
  if (vazia())
  {
    raiz = novo; // Se a árvore estiver vazia, o novo nó se torna a raiz
  }
  else
  {
    noh *aux = raiz;
    // Procura a posição correta para inserir o novo nó
    while (aux != NULL)
    {
      if (n < aux->elemento.getNumero())
      {
        // Inserção no filho esquerdo
        if (aux->filhoEsquerda == NULL)
        {
          aux->filhoEsquerda = novo;
          aux = NULL;
        }
        else
        {
          aux = aux->filhoEsquerda;
        }
      }
      else
      {
        // Inserção no filho direito
        if (aux->filhoDireita == NULL)
        {
          aux->filhoDireita = novo;
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

// Método público para remover um elemento da árvore
void ABB::remover(int n)
{
  removerBusca(n, raiz);
}

// Método auxiliar recursivo para encontrar e remover um nó na árvore
void ABB::removerBusca(int n, noh *&atual)
{
  if (atual == NULL)
  {
    cout << "ERRO" << endl; // Se o nó não for encontrado, imprime "ERRO"
    return;
  }

  if (n == atual->elemento.getNumero())
  {
    // Se o valor for encontrado, deleta o nó
    deletarNoh(atual);
  }
  else if (n < atual->elemento.getNumero())
  {
    // Procura no filho esquerdo
    removerBusca(n, atual->filhoEsquerda);
  }
  else
  {
    // Procura no filho direito
    removerBusca(n, atual->filhoDireita);
  }
}

// Método auxiliar que deleta o nó especificado
void ABB::deletarNoh(noh *&atual)
{
  noh *aux = atual;
  if (atual->filhoEsquerda == NULL)
  {
    // Caso 1: Nó sem filho esquerdo (ou sem filhos)
    atual = atual->filhoDireita;
    delete aux;
  }
  else if (atual->filhoDireita == NULL)
  {
    // Caso 2: Nó sem filho direito
    atual = atual->filhoEsquerda;
    delete aux;
  }
  else
  {
    // Caso 3: Nó com dois filhos
    objeto objSucessor;
    obterSucessor(objSucessor, atual);
    atual->elemento = objSucessor;
    removerBusca(objSucessor.getNumero(), atual->filhoDireita);
  }
}

// Método auxiliar que encontra o sucessor de um nó (o menor nó da subárvore direita)
void ABB::obterSucessor(objeto &objSucessor, noh *aux)
{
  aux = aux->filhoDireita;
  while (aux->filhoEsquerda != NULL)
  {
    aux = aux->filhoEsquerda;
  }
  objSucessor = aux->elemento;
}

// Método público para buscar um elemento na árvore
bool ABB::buscar(int n, objeto &objRetorno)
{
  if (vazia())
  {
    return false; // Retorna falso se a árvore estiver vazia
  }
  else
  {
    noh *aux = raiz;
    // Procura pelo elemento na árvore
    while (aux != NULL)
    {
      if (n == aux->elemento.getNumero())
      {
        objRetorno = aux->elemento;
        return true;
      }
      else if (n < aux->elemento.getNumero())
      {
        aux = aux->filhoEsquerda;
      }
      else
      {
        aux = aux->filhoDireita;
      }
    }
    return false; // Retorna falso se o elemento não for encontrado
  }
}

// Método público para imprimir a árvore em pré-ordem
void ABB::imprimePreOrdem(noh *atual, int nivel)
{
  if (atual != NULL)
  {
    cout << atual->elemento.getNumero() << "/" << nivel << " ";
    imprimePreOrdem(atual->filhoEsquerda, nivel + 1);
    imprimePreOrdem(atual->filhoDireita, nivel + 1);
  }
}

// Método público para imprimir a árvore em ordem
void ABB::imprimeEmOrdem(noh *atual, int nivel)
{
  if (atual != NULL)
  {
    imprimeEmOrdem(atual->filhoEsquerda, nivel + 1);
    cout << atual->elemento.getNumero() << "/" << nivel << " ";
    imprimeEmOrdem(atual->filhoDireita, nivel + 1);
  }
}

// Método público para imprimir a árvore em pós-ordem
void ABB::imprimePosOrdem(noh *atual, int nivel)
{
  if (atual != NULL)
  {
    imprimePosOrdem(atual->filhoEsquerda, nivel + 1);
    imprimePosOrdem(atual->filhoDireita, nivel + 1);
    cout << atual->elemento.getNumero() << "/" << nivel << " ";
  }
}

// Função principal que executa o programa
int main()
{
  ABB abb;
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
      case 'i': // Inserir
        cin >> valor;
        abb.inserir(valor);
        break;
      case 'r': // Remover
        cin >> valor;
        if (abb.buscar(valor, objAux))
        {
          abb.remover(valor);
        }
        else
        {
          cout << "ERRO" << endl; // Imprime "ERRO" se o valor não for encontrado
        }
        break;
      case 'o': // Imprimir em ordem
        abb.imprimeEmOrdem(abb.getRaiz(), 0);
        cout << endl;
        break;
      case 'p': // Imprimir em pré-ordem
        abb.imprimePreOrdem(abb.getRaiz(), 0);
        cout << endl;
        break;
      case 'z': // Imprimir em pós-ordem (não especificado, mas incluído)
        abb.imprimePosOrdem(abb.getRaiz(), 0);
        cout << endl;
        break;
      case 'b': // Buscar
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
      case 'f': // Finalizar
        // Checado no do-while
        break;
      default:
        cerr << "Comando inválido\n";
      }
    }
    catch (runtime_error &e)
    {
      cout << e.what() << endl;
    }
  } while (comando != 'f'); // Finaliza a execução do programa

  return 0;
}
