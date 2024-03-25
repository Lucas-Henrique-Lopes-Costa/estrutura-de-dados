/*
Questão 6: Pilha - Pilha dupla em um mesmo arranjo
Suponha que um dado problema requer o uso de duas pilhas (identificadas pelo números 1 e 2), onde cada pilha suporta no máximo 50 elementos e em nenhum momento as duas pilhas terão juntas mais do que os mesmos 50 elementos. Sendo assim, é possível implementar as duas pilhas em um único vetor usando apenas 50 posições ao invés de 100. Utilizando a estrutura sugerida no
código fornecido
, implemente as operações de
empilhar()
e
desempilhar()
. As operações de empilhar (identificada pela letra E) e desempilhar (identificada pela letra D) devem ser descritas da seguinte forma:
Operação a ser realizada, seguida da identificação da pilha. No caso da operação
empilhar
, deve ser informado, ainda, o dado a ser armazenado. T é usado para terminar o programa.
Utilize um arranjo de 50 posições para armazenar estas duas pilhas
.
Caso seja solicitada uma operação de
desempilhar
e a respectiva pilha esteja vazia, deve ser impressa a palavra "VAZIA".
Caso seja solicitada a inserção de mais de 50 elementos em uma das pilha, deve ser impressa a palavra "INVALIDO" (sem acentos).
Obs: sinta-se a vontade para modificar o código caso prefira utilizar outra estrutura.
A única restrição é que as duas pilhas devem ser armazenadas em um mesmo ARRANJO de 50 posições.
Dica: utilize o início do arranjo para armazenar uma das pilhas e final do arranjo para armazenar a outra pilha.
Entradas:
Conjunto de operações de inserção e remoção de dados em cada uma das pilhas
Saídas:
Resultado das remoções em cada uma das pilhas.
Exemplos de Entrada e Saída:
Entrada
E 1 7
E 2 4
E 1 2
E 1 15
E 2 21
D 1
D 2
E 2 5
E 2 7
D 2
D 1
D 1
T
Exemplo de Saída:
15 21 7 2 7
Entrada
E 1 71
E 2 45
E 1 20
E 2 21
D 1
D 1
E 2 5
E 2 7
D 2
D 1
D 2
T
Exemplo de Saída:
20 71 7 VAZIA 5
*/

#include <iostream>
using namespace std;

int main() {
    // Seu código aqui
    return 0;
}
