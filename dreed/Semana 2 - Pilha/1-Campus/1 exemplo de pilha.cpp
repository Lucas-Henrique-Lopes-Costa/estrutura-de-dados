#include <iostream>
using namespace std;

class noh
{
  friend class pilha;

private:
  int nValor;
  noh *nProximo;

public:
  noh(int valor);
};

noh::noh(int valor)
{
  nValor = valor;
  nProximo = NULL;
}

class pilha
{
private:
  noh *topo;
  int mTamanho;

public:
  pilha();
  ~pilha();
  int tamanho(); // usa para dar somente positivos
  void empilha(int valor);
  int desempilha();
  void limpaPilha();
  bool vazia();
};

pilha::pilha()
{
  topo = NULL;
  mTamanho = 0;
}

pilha::~pilha()
{
  limpaPilha();
}

void pilha::limpaPilha()
{
  while (!vazia())
  {
    desempilha();
  };
}

int pilha::tamanho()
{
  return mTamanho;
}

bool pilha::vazia()
{
  return (mTamanho == 0);
}

void pilha::empilha(int valor)
{
  cout << "topo (antes): " << topo << endl;

  noh *novo = new noh(valor);
  novo->nProximo = topo; // o no que acabou de criar agora é o topo
  topo = novo;
  mTamanho++;

  cout << "topo (depois): " << topo << endl;
  cout << "Proximo topo: " << topo->nProximo << endl; 
}

int pilha::desempilha()
{
  int valor = topo->nValor;
  noh *temp = topo;
  topo = topo->nProximo;
  delete temp;
  mTamanho--;
  return valor;
}

int main()
{
  pilha p1;
  int num;

  cin >> num;

  while (num >= 0)
  {
    p1.empilha(num);
    cin >> num;
  }

  cout << "Tamanho: " << p1.tamanho() << endl;

  cout << "Elementos:" << endl;

  while (!p1.vazia())
  {
    cout << p1.desempilha() << " ";
  }

  cout << endl;

  return 0;
}