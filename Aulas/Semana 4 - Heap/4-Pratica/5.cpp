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
using namespace std;

int main() {
    // Seu código aqui
    return 0;
}
