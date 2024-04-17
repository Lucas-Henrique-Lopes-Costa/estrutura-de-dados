/*
Questão 5: Lista Duplamente Encadeada - Ações de usuários em um programa - Deque
Utilizando como base o código que você desenvolveu na atividade "Lista Simplesmente Encadeada - Equipes de Maratona" faça as adaptações necessárias para que ela funcione como deque.  Todos os métodos que não devem ser permitidos para uso em uma deque devem retornar ao usuário que o procedimento não é permitido.
Uma deque é uma estrutura de dados lista em que a remoção e inserção só é permitida em suas pontas (ou seja: no início e no final da lista).
Feito isso, você deverá adicionar mais um procedimento fora da classe, que recebe uma deque e uma string e remove um elemento qualquer,
mas sem quebrar a estrutura
. Ou seja: a remoção deverá ser implementada de maneira similar à remoção em uma pilha ou fila. Utilizando esse procedimento, adicione a seguinte opção no menu da função principal:
x seguido de uma string: remove da lista o elemento que possui o nome da ação informado pelo usuário. Imprimir
Remoção em lista vazia!
caso a chamada ao procedimento seja chamada com a lista vazia. Imprimir
Nao encontrado
caso não encontre o elemento em uma lista que possua pelo menos um elemento
Lembrando novamente: esse comando deverá ser implementado
sem quebra de estrutura
.
Saídas:
Todas as saídas de comandos já estão implementadas na função principal código entregue, somente falta implementar a chamada para remover o elemento solicitado. Ao terminar a execução do programa, todos os itens da listas são escritos.
Exemplo de Entrada e Saída juntas:
r
Remoção em lista vazia!
a
Remoção em lista vazia!
p
Lista vazia!
s empilharProcessos
Lista vazia!
i 1 limparCache 123 99
h 2 semaforoProc 32 11
m 1 3 paralelismoProc 65 23
Operação não permitida!
i 3 paralelismoProc 65 23
p
(3, paralelismoProc, 65, 23)
(1, limparCache, 123, 99)
(2, semaforoProc, 32, 11)
 IMPRIMINDO REVERSO 
(2, semaforoProc, 32, 11)
(1, limparCache, 123, 99)
(3, paralelismoProc, 65, 23)
s empilharProcessos
Nao encontrado
x limparCache
p
(3, paralelismoProc, 65, 23)
(2, semaforoProc, 32, 11)
 IMPRIMINDO REVERSO 
(2, semaforoProc, 32, 11)
(3, paralelismoProc, 65, 23)
r
p
(2, semaforoProc, 32, 11)
 IMPRIMINDO REVERSO 
(2, semaforoProc, 32, 11)
f
*/

#include <iostream>
using namespace std;

int main() {
    // Seu código aqui
    return 0;
}
