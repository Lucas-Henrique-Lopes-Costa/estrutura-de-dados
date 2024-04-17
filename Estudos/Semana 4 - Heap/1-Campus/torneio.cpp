#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

typedef int dado;
const int INVALIDO = -1;

class torneio
{
private:
  dado *heap;
  int capacidade;
  int tamanho;
  int inicioDados;
  inline int pai(int i)
  {
    return (i - 1) / 2;
  }
  inline int esquerdo(int i)
  {
    return 2 * i + 1;
  }
  inline int direito(int i)
  {
    return 2 * i + 2;
  }
  void arruma();
  void copiaMaior(int i);
  void copiaSubindo(int i);

public:
  torneio(dado vet[], int tam);
  torneio(int numFolhas);
  ~torneio();
  void insere(dado d);
  void imprime();
};

torneio::torneio(dado vet[], int tam)
{
  capacidade = 1;
  while (capacidade < tam)
  {
    capacidade *= 2;
  }

  capacidade = capacidade - 1 + tam;

  heap = new dado[capacidade];
  inicioDados = capacidade - tam;

  cout << "inicioDados: " << inicioDados << endl;
  cout << "capacidade: " << capacidade << endl;

  memcpy(&heap[inicioDados], vet, tam * sizeof(dado));

  tamanho = tam;
  arruma();
}

torneio::torneio(int numFolhas)
{
  capacidade = 1;
  while (capacidade < numFolhas)
  {
    capacidade *= 2;
  }

  capacidade = capacidade - 1 + numFolhas;
  heap = new dado[capacidade];
  inicioDados = capacidade - numFolhas;

  cout << "inicioDados: " << inicioDados << endl;
  cout << "capacidade: " << capacidade << endl;

  for (int i = 0; i < capacidade; i++)
  {
    heap[i] = INVALIDO;
  }
}

void torneio::arruma()
{
  cout << "arruma: " << inicioDados - 1 << endl;

  for (int i = inicioDados - 1; i >= 0; i--)
  {
    copiaMaior(i);
  }
}

torneio::~torneio()
{
  delete[] heap;
}

void torneio::copiaMaior(int i)
{
  int esq = esquerdo(i);
  int dir = direito(i);

  cout << "i: " << i << " esq: " << esq << " dir: " << dir << endl;

  int maior = INVALIDO;

  if (esq < capacidade)
  {
    if ((dir < capacidade) && (heap[dir] > heap[esq]))
    {
      maior = dir;
    }
    else
    {
      maior = esq;
    }
    heap[i] = heap[maior];
  }
  else
  {
    heap[i] = INVALIDO;
  }
}

void torneio::copiaSubindo(int i)
{
  int p = pai(i);

  if (heap[i] > heap[p])
  {
    heap[p] = heap[i];
    copiaSubindo(p);
  }
}

void torneio::insere(dado d)
{
  if (tamanho == capacidade)
  {
    cout << "Heap cheio" << endl;
    exit(EXIT_FAILURE);
  }

  heap[inicioDados + tamanho] = d;
  copiaSubindo(inicioDados + tamanho);
  tamanho++;
}

void torneio::imprime()
{
  for (int i = 0; i < capacidade; i++)
  {
    cout << heap[i] << " ";
  }
  cout << endl;
}

int main()
{
  int tam = 8;
  dado vet[] = {1, 2, 3, 4, 5, 6, 7, 8};

  /*
  8
  4, 8
  2, 4, 6, 8
  1, 2, 3, 4, 5, 6, 7, 8
  */

  torneio *h = new torneio(vet, tam);
  h->imprime();
  delete h;
}