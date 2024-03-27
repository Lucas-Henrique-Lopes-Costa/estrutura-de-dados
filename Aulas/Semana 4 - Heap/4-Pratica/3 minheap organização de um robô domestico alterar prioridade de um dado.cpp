/*
Questão 3: Minheap - Organização de um robô domestico - Alterar prioridade de um dado
Modifique a sua estrutura heap para que considere a maior prioridade de execução de uma tarefa. No caso considere a tarefa com maior prioridade indicada pelo valor 1 e a medida que o valor aumenta a prioridade diminui. Implemente o método
alteraPrioridade()
nessa minheap. A alteração de prioridade implica que o dado alterado deva ser rearranjado, de forma a manter as propriedades do heap.
Você pode (
e deve!
) utilizar o código que você desenvolveu na atividade "Heap - Organização de um robô domestico" como base.
Com essa finalidade, você deverá adicionar mais um comando, como segue:
a seguindo de uma string e um inteiro: altera a prioridade da atividade com o nome informado com o novo valor.
Exemplo de Entrada e Saída juntas:
10
r
Erro ao retirar raiz
p
Heap vazia!
i livingroom r 35 58 5
i tvroom t 18 28 8
i kitchen c 180 200 1
i bedroom1 x 99 90 2
i bedroom2 x 33 50 5
i bedroom3 v 56 80 8
i MasterBedroom x 56 70 9
i Bathroom1 n 32 56 7
i Bathroom2 n 44 80 5
i LaundryRoom h 15 7 1
i entrace a 10 5 2
Erro ao inserir
p
[kitchen/c/180/200/1] [LaundryRoom/h/15/7/1] [livingroom/r/35/58/5] [Bathroom2/n/44/80/5] [bedroom1/x/99/90/2] [bedroom3/v/56/80/8] [MasterBedroom/x/56/70/9] [tvroom/t/18/28/8] [Bathroom1/n/32/56/7]
[bedroom2/x/33/50/5] 
a kitchen 5
p
[LaundryRoom/h/15/7/1] [bedroom1/x/99/90/2] [livingroom/r/35/58/5] [Bathroom2/n/44/80/5] [kitchen/c/180/200/5] [bedroom3/v/56/80/8] [MasterBedroom/x/56/70/9] [tvroom/t/18/28/8] [Bathroom1/n/32/56/7] 
[bedroom2/x/33/50/5] 
r
LaundryRoom
p
[bedroom1/x/99/90/2] [bedroom2/x/33/50/5] [livingroom/r/35/58/5] [Bathroom2/n/44/80/5] [kitchen/c/180/200/5] [bedroom3/v/56/80/8] [MasterBedroom/x/56/70/9] [tvroom/t/18/28/8] [Bathroom1/n/32/56/7] 
f
*/

#include <iostream>
using namespace std;

int main() {
    // Seu código aqui
    return 0;
}
