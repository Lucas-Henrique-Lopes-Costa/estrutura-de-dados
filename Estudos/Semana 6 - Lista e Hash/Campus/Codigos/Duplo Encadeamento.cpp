#include <iostream>

using namespace std;

typedef int Dado;

class noh
{
  friend class lista;

private:
  const Dado dado;
  noh *proximo;
  noh *anterior;

public:
  noh(Dado d = 0);
};

noh::noh(Dado d) : dado(d)
{
  proximo = NULL;
  anterior = NULL;
}

class lista
{
private:
  noh *primeiro;
  noh *ultimo;
  int tamanho;
  void removeTodos();
  void imprimeReversoAux(noh *umNoh);

public:
  lista();
  lista(const lista &umaLista);
  ~lista();
  lista &operator=(const lista &umaLista);
  inline void inserir(Dado d);
  void insereNaPosicao(int pos, Dado d);
  void insereNoFim(Dado d);
  void insereNoInicio(Dado d);
  void removeNoInicio();
  void removeNoFim();
  int procura(Dado d);
  void imprimir();
  void imprimeReverso();
  inline bool vazia();
  void removeValor(Dado d);
};

lista::lista()
{
  tamanho = 0;
  primeiro = NULL;
  ultimo = NULL;
}

lista::lista(const lista &umaLista)
{
  tamanho = 0;
  primeiro = NULL;
  ultimo = NULL;

  noh *aux = umaLista.primeiro;
  while (aux != NULL)
  {
    insereNoFim(aux->dado);
    aux = aux->proximo;
  }
}

lista::~lista()
{
  removeTodos();
}

void lista::removeTodos()
{
  noh *aux = primeiro;
  noh *temp;

  while (aux != NULL)
  {
    temp = aux;
    aux = aux->proximo;
    delete temp;
  }

  tamanho = 0;
  primeiro = NULL;
  ultimo = NULL;
}

lista &lista::operator=(const lista &umaLista)
{
  removeTodos();

  noh *aux = umaLista.primeiro;
  while (aux != NULL)
  {
    insereNoFim(aux->dado);
    aux = aux->proximo;
  }

  return *this;
}

void lista::inserir(Dado d)
{
  insereNoFim(d);
}

void lista::insereNoFim(Dado d)
{
  noh *novo = new noh(d);

  if (vazia())
  {
    primeiro = novo;
    ultimo = novo;
  }
  else
  {
    ultimo->proximo = novo;
    novo->anterior = ultimo;
    ultimo = novo;
  }

  tamanho++;
}

void lista::insereNoInicio(Dado d)
{
  noh *novo = new noh(d);

  if (vazia())
  {
    primeiro = novo;
    ultimo = novo;
  }
  else
  {
    novo->proximo = primeiro;
    primeiro->anterior = novo;
    primeiro = novo;
  }

  tamanho++;
}

void lista::insereNaPosicao(int pos, Dado d)
{
  if (pos >= 0 && pos <= tamanho)
  {
    noh *novo = new noh(d);

    if (vazia())
    {
      primeiro = novo;
      ultimo = novo;
    }
    else if (pos == 0)
    {
      novo->proximo = primeiro;
      primeiro->anterior = novo;
      primeiro = novo;
    }
    else if (pos == tamanho)
    {
      ultimo->proximo = novo;
      novo->anterior = ultimo;
      ultimo = novo;
    }
    else
    {
      noh *aux = primeiro;
      int posAux = 0;

      while (posAux < pos - 1)
      {
        aux = aux->proximo;
        posAux++;
      }

      novo->proximo = aux->proximo;
      aux->proximo->anterior = novo;
      aux->proximo = novo;
      novo->anterior = aux;
    }

    tamanho++;
  }
  else
  {
    cerr << "Posição inválida" << endl;
    exit(EXIT_FAILURE);
  }
}

void lista::removeNoInicio()
{
  if (vazia())
  {
    cerr << "Lista vazia" << endl;
    exit(EXIT_FAILURE);
  }
  else
  {
    noh *removido = primeiro;
    primeiro = primeiro->proximo;

    if (primeiro != NULL)
      primeiro->anterior = NULL;

    delete removido;
    tamanho--;

    if (vazia())
    {
      ultimo = NULL;
    }
  }
}

void lista::removeNoFim()
{
  if (vazia())
  {
    cerr << "Lista vazia" << endl;
    exit(EXIT_FAILURE);
  }
  else
  {
    noh *aux = ultimo;

    ultimo = ultimo->anterior;

    if (ultimo != NULL)
      ultimo->proximo = NULL;

    delete aux;

    tamanho--;

    if (vazia())
    {
      ultimo = NULL;
    }
  }
}

int lista::procura(Dado d)
{
  noh *aux = primeiro;
  int pos = 0;

  while (aux != NULL && aux->dado != d)
  {
    aux = aux->proximo;
    pos++;
  }

  if (aux == NULL)
  {
    return -1;
  }
  return pos;
}

void lista::imprimir()
{
  noh *aux = primeiro;

  while (aux != NULL)
  {
    cout << aux->dado << " ";
    aux = aux->proximo;
  }

  cout << endl;
}

void lista::imprimeReverso()
{
  noh *aux = ultimo;

  while (aux != NULL)
  {
    cout << aux->dado << " ";
    aux = aux->anterior;
  }

  cout << endl;
}

inline bool lista::vazia()
{
  return (tamanho == 0);
}

void lista::removeValor(Dado d)
{
  noh *aux = primeiro;

  while (aux != NULL && aux->dado != d)
  {
    aux = aux->proximo;
  }

  if (aux != NULL)
  {
    if (aux == primeiro)
    {
      removeNoInicio();
    }
    else if (aux == ultimo)
    {
      removeNoFim();
    }
    else
    {
      noh *anterior = aux->anterior;
      noh *proximo = aux->proximo;

      if (anterior != NULL)
        anterior->proximo = proximo;
      else
        primeiro = aux->proximo;

      if (proximo != NULL)
        proximo->anterior = anterior;
      else
        ultimo = aux->anterior;

      delete aux;
      tamanho--;
    }
  }
}

int main()
{
  lista minhaLista;

  cout << "*** Teste da Lista Encadeada ***" << endl;
  cout << "Quantidade de valores a inserir" << endl;

  // int valor;
  // int num;
  // cin >> num;

  // for (int i = 0; i < num; i++)
  // {
  //   cin >> valor;
  //   minhaLista.inserir(valor);
  // }

  minhaLista.inserir(5);
  minhaLista.inserir(3);
  minhaLista.inserir(1);
  minhaLista.inserir(0);
  minhaLista.inserir(6);
  minhaLista.insereNoInicio(18);
  minhaLista.insereNaPosicao(3, 25);

  minhaLista.imprimir();

  cout << minhaLista.procura(3) << endl;
  cout << minhaLista.procura(50) << endl;
  cout << minhaLista.procura(6) << endl;

  // Construtor cópia
  cout << "Sobrecarga do construtuor de cópia" << endl;
  lista outraLista(minhaLista);
  outraLista.insereNoInicio(99);
  outraLista.insereNoFim(10);

  // Sobrecarga do operador de atribuição
  cout << "Sobrecarga do operador de atribuição" << endl;
  lista maisUmaLista;
  maisUmaLista = outraLista;
  maisUmaLista.insereNoInicio(31);
  maisUmaLista.insereNoFim(13);

  minhaLista.imprimir();
  maisUmaLista.imprimir();
  outraLista.imprimir();

  minhaLista.removeNoFim();
  minhaLista.removeNoInicio();

  minhaLista.removeNoFim();
  minhaLista.removeNoInicio();

  minhaLista.removeNoFim();
  minhaLista.removeNoInicio();

  minhaLista.imprimir();
  minhaLista.imprimeReverso();

  minhaLista.removeValor(25);
  minhaLista.imprimir();

  outraLista.removeValor(10);
  outraLista.imprimir();

  maisUmaLista.removeValor(31);
  maisUmaLista.imprimir();

  return 0;
}