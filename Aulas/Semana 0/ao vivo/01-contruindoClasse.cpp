/*
O dono de um sebo decidiu controlar melhor seu acervo e seus negócios. Ele gostaria de manter as informações sobre com quem ele negociou, armazenando nome e telefone para contato, qual foi o tipo de negócio (compra ou venda), o valor do negócio (o quanto foi pago ou recebido) e o dia da semana em que o negócio ocorreu.
*/

#include <iostream>
using namespace std;

class transacao
{
private:
  string nome;
  string telefone;
  char tipo;
  float valor;
  int dia; // 1 - segunda, 2 - terça, 3 - quarta, 4 - quinta, 5 - sexta, 6 - sábado, 7 - domingo
public:
  transacao();
  ~transacao();
  void atualizarTransacao(string n, string t, char tp, float v, int d);
  void calcularMovimentacao(float &totalCompra, float &totalVenda);
  int retornarDia() { return dia; };
  void imprimirTransacao();
  int obterDiaMaiorVendas(int numTransacoes, transacao transacoes[]);
};

// Construtor
transacao::transacao()
{
  nome = "-";
  telefone = "-";
  tipo = '-';
  valor = 0;
  dia = 0;
};

// Destrutor
transacao::~transacao()
{
  nome = "0";
  telefone = "0";
  tipo = '0';
  valor = 0.0;
  dia = 0;
};

// Método para cadastrar transação
void transacao::atualizarTransacao(string n, string t, char tp, float v, int d)
{
  nome = n;
  telefone = t;
  tipo = tp;
  valor = v;
  dia = d;
};

void transacao::calcularMovimentacao(float &totalCompra, float &totalVenda)
{
  if (tipo == 'C' || tipo == 'c')
  {
    totalCompra += valor;
  }
  else
  {
    totalVenda += valor;
  }
};

void transacao::imprimirTransacao()
{
  cout << nome << "\t" << telefone << endl;
  cout << tipo << "\t" << valor << endl
       << dia;
}

int main()
{
  transacao negocios[10];
  char operacao, tipo;
  int contador = 0, dia;
  string nome, telefone;
  float valor, totalCompra = 0, totalVenda = 0;

  cout << "Realizar operação? (S/N): ";
  cin >> operacao;

  while ((operacao == 'S' || operacao == 's') && contador < 10) // lembrar do limite do vetor
  {
    cout << "Nome: ";
    cin >> nome;

    cout << "Telefone: ";
    cin >> telefone;

    cout << "Operação (C/V): ";
    cin >> tipo;

    cout << "Valor: ";
    cin >> valor;

    cout << "Dia da semana (1-7): ";
    cin >> dia;

    negocios[contador].atualizarTransacao(nome, telefone, tipo, valor, dia);

    contador++;

    cout << "Realizar operação? (S/N): ";
    cin >> operacao;
  }

  for (int i = 0; i < contador; i++)
  {
    negocios[i].calcularMovimentacao(totalCompra, totalVenda);
  }

  cout << "Total de compras: " << totalCompra << endl;
  cout << "Total de vendas: " << totalVenda << endl;

  // imprimir transações
  cout << "Transações: " << endl;
  cout << "###############" << endl;
  for (int i = 0; i < contador; i++)
  {
    negocios[i].imprimirTransacao();
    cout << "-----------" << endl
         << endl;
  }
  cout << "###############" << endl;

  return 0;
}