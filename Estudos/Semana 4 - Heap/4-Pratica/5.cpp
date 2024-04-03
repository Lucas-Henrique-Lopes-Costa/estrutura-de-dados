/*
Questão 5: Torneio - Torneio residual
Um torneio é uma árvore estritamente binária na qual cada nó não folha contém uma cópia do maior elemento entre seus dois filhos. O conteúdo das folhas de um torneio determina o conteúdo de todos os seus nós. Um torneio com n folhas representa um conjunto de n elementos.
Implemente um torneio utilizando uma estratégia semelhante a um Heap. Entretanto, a cada etapa, o elemento vencedor irá para a próxima etapa com o seu valor reduzido do valor do oponente. Neste caso, a estrutura de dados utilizada para representar um elemento deve possuir um valor base, que é o valor inicial e, caso ele vença o torneio, o valor que será utilizado é um valor relativo que será utilizado para contabilizar a progressão. Caso exista um empate, o elemento com maior valor base avança. O vencedor do torneio deverá ter seu valor base impresso.
Note que normalmente um torneio é uma árvore estritamente binária, cheia. Como, neste problema, temos que o tamanho da entrada pode não ser uma potência de 2, será necessário fazer ajustes para trabalhar com o que costumamos chamar de torneio incompleto. Uma das abordagens possíveis é apresentada nos slides e vídeo do assunto, verifique.
Faça um programa que funcione como um torneio.
A entrada deve conter o número de participantes seguido dos participantes. A saída apresenta o valor base do participante campeão do torneio.
Entradas:
Quantidade de participantes
Identificação dos participantes
Saídas:
Valor base do campeão do torneio
Exemplo de Entrada:
8
2 7 4 1 3 9 6 8
Exemplo de Saída:
9
Exemplo de Entrada:
13
11 5 3 4 2 15 7 9 10 8 12 6 13
Exemplo de Saída:
13
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Participante
{
    int valorBase;
    int valorRelativo;

    Participante(int valor) : valorBase(valor), valorRelativo(valor) {}
};

class Torneio
{
private:
    vector<Participante> participantes;
    void competir(int i);

public:
    Torneio(const vector<int> &valores);
    void executarTorneio();
    void verBaseMaior();
};

Torneio::Torneio(const vector<int> &valores)
{
    for (size_t i = 0; i < valores.size(); ++i)
    {
        int valor = valores[i];
        participantes.push_back(Participante(valor));
    }
}

void Torneio::competir(int i)
{
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;
    int vencedor = i;

    if (esq < static_cast<int>(participantes.size()))
    {
        vencedor = esq;

        if (dir < static_cast<int>(participantes.size()))
        {
            if (participantes[dir].valorRelativo > participantes[esq].valorRelativo ||
                (participantes[dir].valorRelativo == participantes[esq].valorRelativo && participantes[dir].valorBase > participantes[esq].valorBase))
            {
                vencedor = dir;
            }
        }

        if (vencedor != i)
        {
            participantes[i].valorRelativo = participantes[vencedor].valorRelativo - (participantes[vencedor].valorRelativo - participantes[esq + (dir - esq) * (vencedor == dir)].valorRelativo);
            participantes[i].valorBase = participantes[vencedor].valorBase;
        }
    }
}

void Torneio::executarTorneio()
{
    for (int i = participantes.size() / 2 - 1; i >= 0; --i)
    {
        competir(i);
    }
}

void Torneio::verBaseMaior()
{
    cout << participantes[0].valorBase << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<int> valores(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> valores[i];
    }

    Torneio torneio(valores);
    torneio.executarTorneio();
    torneio.verBaseMaior();

    return 0;
}
