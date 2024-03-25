#include <iostream>
using namespace std;

class filaCircular
{
private:
  int mInicio;
  int mFim;
  int *mDados;
  int mCapacidade;
  int mTamanho;

public:
  filaCircular(int capacidade = 10);
  ~filaCircular();
  int tamanho(); // usa para dar somente positivos
  void enfileira(int valor);
  int desenfileira();
  void limpaFila();
  bool vazia();
  void depura();
};

filaCircular::filaCircular(int capacidade)
{
  mInicio = -1;
  mFim = -1;
  mCapacidade = capacidade;
  mTamanho = 0;
  mDados = new int[capacidade];
}

filaCircular::~filaCircular()
{
  delete[] mDados;
  limpaFila();
}

void filaCircular::limpaFila()
{
  while (!vazia())
  {
    desenfileira();
  }
}

int filaCircular::tamanho()
{
  return mTamanho;
}

bool filaCircular::vazia()
{
  return (mTamanho == 0);
}

void filaCircular::enfileira(int valor)
{
  if (mTamanho <= mCapacidade)
  {
    mFim++;
    mFim = mFim % mCapacidade;
    mDados[mFim] = valor;
    if (mTamanho == 0)
    {
      mInicio++;
    }
    mTamanho++;
  }
  else
  {
    cerr << "Fila cheia" << endl;
  }
}

int filaCircular::desenfileira()
{
  if (tamanho() > 0)
  {
    int valor = mDados[mInicio];
    mTamanho--;
    if (mTamanho > 0)
    {
      mInicio++;
      mFim = mFim % mCapacidade;
    }
    else
    {
      mInicio = -1;
      mFim = -1;
    }
    return valor;
  }
  else
  {
    cerr << "Fila vazia" << endl;
    return -1;
  }
}

void filaCircular::depura()
{
  cout << "Inicio: " << mInicio << " Fim: " << mFim << endl;
  cout << "Tamanho: " << mTamanho << endl;

  cout << "Debug fila: ";
  for (int i = 0; i < mCapacidade; i++)
  {
    cout << mDados[i] << " ";
  }
  cout << endl;
}

int main()
{
  filaCircular f1(12);
  int num;

  for (int i = 0; i < 8; i++)
  {
    cin >> num;
    f1.enfileira(i);
  }

  cout << "Tamanho: " << f1.tamanho() << endl;

  cout << "5 elementos:" << endl;

  for (int i = 0; i < 5; i++)
  {
    cout << f1.desenfileira() << " ";
  }

  cout << endl;

  for (int i = 0; i < 8; i++)
  {
    cin >> num;
    f1.enfileira(i);
  }

  cout << "Tamanho: " << f1.tamanho() << endl;

  cout << "8 elementos:" << endl;

  for (int i = 0; i < 8; i++)
  {
    cout << f1.desenfileira() << " ";
  }

  cout << endl;

  f1.depura();

  return 0;
}