#include <iostream>

using namespace std;

class Itens
{
private:
  int valor;
  string nome;
  char tipo;

public:
  Itens();

  Itens(int valor, string nome, char tipo)
  {
    this->valor = valor;
    this->nome = nome;
    this->tipo = tipo;
  }
  ~Itens();

  string getNome()
  {
    return nome;
  }

  int getValor()
  {
    return valor;
  }

  char getTipo()
  {
    return tipo;
  }
};

class Pilha
{
private:
  int topo;
  int tamanho;
  Itens itens[10];

public:
  Pilha()
  {
    topo = -1;
  };
  ~Pilha();

  Itens pop()
  {
    Itens item = itens[topo];
    topo--;
    return item;
  }

  void push(string nome, char tipo, int valor)
  {
    topo++;
    Itens item(valor, nome, tipo);
    itens[topo] = item;
  }

  void clear()
  {
    topo = -1;
  }

  Itens getTopo()
  {
    return itens[topo];
  }
};

int main()
{
  Pilha pilha;

  char i = '0';
  string s;
  int v;
  char c;
  Itens item;

  while (i != 'f')
  {
    cin >> i;

    switch (i)
    {
    case 'i':

      cin >> s >> c >> v;
      pilha.push(s, c, v);

      break;
    case 'r':

      item = pilha.pop();
      cout << "Nome: " << item.getNome() << "Tipo: " << item.getTipo() << "Valor: " << item.getValor() << endl;
      break;

    case 'l':
      pilha.clear();
      break;

    case 'e':
      item = pilha.getTopo();
      cout << "Nome: " << item.getNome() << "Tipo: " << item.getTipo() << "Valor: " << item.getValor() << endl;
      break;

    default:
      break;
    }
  }
}
