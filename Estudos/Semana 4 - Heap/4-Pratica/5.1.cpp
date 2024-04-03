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
#include <cmath>
using namespace std;

// Função auxiliar para realizar a competição entre dois participantes
int compete(int a, int b, bool isMaxRound)
{
    if (isMaxRound)
    {
        return max(a, b);
    }
    else
    {
        return min(a, b);
    }
}

// Classe para o Torneio
class TorneioAlternado
{
private:
    vector<int> participantes;
    int campeao;

    void construirTorneio()
    {
        bool isMaxRound = true; // A condição de vitória começa como o maior valor
        int n = participantes.size();
        while (n > 1)
        {
            for (int i = 0; i < n; i += 2)
            {
                // Para evitar comparação fora dos limites do vetor
                if (i + 1 < n)
                {
                    participantes[i / 2] = compete(participantes[i], participantes[i + 1], isMaxRound);
                }
                else
                {
                    participantes[i / 2] = participantes[i];
                }
            }
            n = (n + 1) / 2;          // Ajusta o tamanho do vetor para a próxima rodada
            isMaxRound = !isMaxRound; // Alterna a condição de vitória
        }
        campeao = participantes[0]; // O campeão é o último elemento restante
    }

public:
    TorneioAlternado(vector<int> &vals) : participantes(vals)
    {
        campeao = 0;
        construirTorneio();
    }

    int getCampeao() const
    {
        return campeao;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> valores(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> valores[i];
    }

    TorneioAlternado torneio(valores);
    cout << torneio.getCampeao() << endl;

    return 0;
}