/*
Questão 6: Torneio - Torneio alternado
Um torneio é uma árvore estritamente binária na qual cada nó não folha contém uma cópia do maior elemento entre seus dois filhos. O conteúdo das folhas de um torneio determina o conteúdo de todos os seus nós. Um torneio com n folhas representa um conjunto de n elementos.
Implemente um torneio utilizando uma estratégia semelhante a um Heap. Entretanto, a cada etapa, a condição de vitória (maior elemento ou menor elemento) é alternada. A primeira etapa sempre começa com a condição de vitória sendo o maior elemento, a segunda é o menor valor, a terceira volta a ser o maior, e continua sucessivamente.
Note que normalmente um torneio é uma árvore estritamente binária, cheia. Como, neste problema, temos que o tamanho da entrada pode não ser uma potência de 2, será necessário fazer ajustes para trabalhar com o que costumamos chamar de torneio incompleto. Uma das abordagens possíveis é apresentada nos slides e vídeo do assunto, verifique.
Faça um programa que funcione como um torneio alternado, onde a cada etapa, alterna a condição de vitória (maior ou menor). A primeira etapa sempre começa com a condição de vitória sendo o maior valor, a segunda é o menor valor, a terceira volta a ser o maior, e continua nessa ordem.
A entrada deve conter o número de participantes seguido dos participantes. A saída apresenta o participante campeão do torneio.
Entradas:
Quantidade de participantes
Identificação dos participantes
Saídas:
Campeão do torneio
Exemplo de Entrada:
8
2 7 4 1 3 9 6 8
Exemplo de Saída:
8
Exemplo de Entrada:
13
11 5 3 4 2 15 7 9 10 8 12 6 16
Exemplo de Saída:
9
*/

#include <iostream>
using namespace std;

int main() {
    // Seu código aqui
    return 0;
}
