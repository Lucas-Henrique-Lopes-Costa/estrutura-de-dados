#include <iostream>

using namespace std;

typedef int Dado;

class noh
{
  friend class lista;

private:
  const Dado dado;
  noh *proximo;

public:
  noh(Dado d = 0);
};

noh::noh(Dado d) : dado(d)
{
  proximo = NULL;
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
};

lista::lista()
{
  primeiro = NULL;
  ultimo = NULL;
  tamanho = 0;
}

lista::lista(const lista &umaLista)
{
  primeiro = NULL;
  ultimo = NULL;
  tamanho = 0;

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

  primeiro = NULL;
  ultimo = NULL;
  tamanho = 0;
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
      primeiro = novo;
    }
    else if (pos == tamanho)
    {
      ultimo->proximo = novo;
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
      aux->proximo = novo;
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
    delete removido;
    tamanho--;
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
    noh *aux = primeiro;

    while (aux->proximo != ultimo)
    {
      aux = aux->proximo;
    }

    delete ultimo;
    aux->proximo = NULL;
    ultimo = aux;

    if (vazia())
    {
      primeiro = NULL;
    }

    tamanho--;
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
  imprimeReversoAux(primeiro);
  cout << endl;
}

void lista::imprimeReversoAux(noh *umNoh)
{
  if (umNoh != NULL)
  {
    imprimeReversoAux(umNoh->proximo);
    cout << umNoh->dado << " ";
  }
}

inline bool lista::vazia()
{
  return (primeiro == NULL);
}

int main()
{
  lista minhaLista;

  cout << "*** Teste da Lista Encadeada ***" << endl;
  cout << "Quantidade de valores a inserir" << endl;

  int valor;
  int num;
  cin >> num;

  for (int i = 0; i < num; i++)
  {
    cin >> valor;
    minhaLista.inserir(valor);
  }

  minhaLista.imprimir();

  minhaLista.insereNoInicio(18);
  minhaLista.insereNaPosicao(3, 25);
  minhaLista.imprimir();

  minhaLista.imprimeReverso();

  cout << minhaLista.procura(0) << endl;
  cout << minhaLista.procura(50) << endl;
  cout << minhaLista.procura(12) << endl;

  // Construtor cópia
  cout << "Sobrecarga do construtuor de cópia" << endl;
  lista outraLista(minhaLista);
  outraLista.imprimir();
  outraLista.imprimeReverso();

  // Sobrecarga do operador de atribuição
  cout << "Sobrecarga do operador de atribuição" << endl;
  lista maisUmaLista;
  maisUmaLista = outraLista;

  maisUmaLista.imprimir();
  maisUmaLista.imprimeReverso();

  maisUmaLista.removeNoFim();
  maisUmaLista.removeNoFim();
  maisUmaLista.imprimir();
  maisUmaLista.imprimeReverso();

  return 0;
}