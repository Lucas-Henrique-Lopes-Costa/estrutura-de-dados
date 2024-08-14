#include <iostream>
#include <stdexcept>

using namespace std;

struct contato
{
  string nome;
  string telefone;
  string descricao;
};

class noh
{
  friend class abb;

private:
  contato dadosDoContato;
  noh *esq;
  noh *dir;

public:
  noh(const contato &umContato) : dadosDoContato(umContato), esq(NULL), dir(NULL) {}
  ~noh() {}
};

class abb
{
private:
  noh *raiz;
  void percorrerEmOrdemAux(noh *atual, int nivel);
  noh *insereAux(noh *umNoh, const contato &umContato);
  noh *buscaAux(noh *raiz, string chave);
  void destruirRecursivamente(noh *umNoh);

public:
  abb() { raiz = NULL; }
  ~abb();
  void imprime();
  void insere(const contato &umContato);
  contato busca(string chave);
};

abb::~abb()
{
  destruirRecursivamente(raiz);
}

void abb::destruirRecursivamente(noh *umNoh)
{
  if (umNoh)
  {
    destruirRecursivamente(umNoh->esq);
    destruirRecursivamente(umNoh->dir);
    delete umNoh;
  }
}

void abb::insere(const contato &umContato)
{
  insereAux(raiz, umContato);
}

noh *abb::insereAux(noh *umNoh, const contato &umContato)
{
  if (umNoh == NULL)
  {
    noh *novoNoh = new noh(umContato);
    return novoNoh;
  }
  else if (umContato.nome < umNoh->dadosDoContato.nome)
  {
    umNoh->esq = insereAux(umNoh->esq, umContato);
    return umNoh;
  }
  else if (umContato.nome > umNoh->dadosDoContato.nome)
  {
    umNoh->dir = insereAux(umNoh->dir, umContato);
    return umNoh;
  }
  else
  {
    throw runtime_error("cahve repetida na insersão");
  }
}

void abb::imprime()
{
  percorrerEmOrdemAux(raiz, 0);
}

void abb::percorrerEmOrdemAux(noh *atual, int nivel)
{
  if (atual == NULL)
  {
    percorrerEmOrdemAux(atual->esq, nivel + 1);
    cout << atual->dadosDoContato.nome << "/" << nivel << endl;
    percorrerEmOrdemAux(atual->dir, nivel + 1);
  }
}

contato abb::busca(string chave)
{
  noh *nohComDados = buscaAux(raiz, chave);

  if (nohComDados != NULL)
    return nohComDados->dadosDoContato;
  else
    throw runtime_error("chave não encontrada na busca");
}

noh *abb::buscaAux(noh *raiz, string chave)
{
  if (raiz == NULL)
    return NULL;
  else if (chave < raiz->dadosDoContato.nome)
    return buscaAux(raiz->esq, chave);
  else if (chave > raiz->dadosDoContato.nome)
    return buscaAux(raiz->dir, chave);
  else
    return raiz;
}

int main()
{
  abb arvore;
  string chave;
  contato umContato;

  char operacao;

  do
  {
    cin >> operacao;

    switch (operacao)
    {
    case 'i':
      cin >> umContato.nome >> umContato.telefone >> umContato.descricao;
      arvore.insere(umContato);
      break;
    case 'b':
      cin >> chave;
      umContato = arvore.busca(chave);
      cout << umContato.nome << " " << umContato.telefone << " " << umContato.descricao << endl;
      break;
    case 'p':
      arvore.imprime();
      break;
    }
  } while (operacao != 'e');
}