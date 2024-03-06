// Implemente um programa que contém uma função que recebe um vetor e devolve um novo vetor, só que com os elementos em ordem inversa.
// Ex. de entrada:    1 4 5 9 12 3 0 99
// Ex. de saída:      99 0 3 12 9 5 4 1

#include <iostream>
using namespace std;

int *inverteVetor(int vetor[], int tamanho)
{
  int *novoVetor = new int[tamanho];

  for (int i = 0; i <= tamanho; i++)
  {
    novoVetor[i] = 0;
  }

  for (int i = 0; i < tamanho; i++)
  {
    novoVetor[i] = vetor[tamanho - i - 1];
  }

  return novoVetor;
}

int main()
{
  int num;
  cin >> num;

  int vetor[num];

  for (int i = 0; i < num; i++)
  {
    cin >> vetor[i]; // leitura dos dados
  }

  for (int i = 0; i < num; i++)
  {
    cout << vetor[i] << " ";
  }

  cout << endl;

  int *novoVetor = inverteVetor(vetor, num);

  for (int i = 0; i < num; i++)
  {
    cout << novoVetor[i] << " ";
  }

  return 0;
}