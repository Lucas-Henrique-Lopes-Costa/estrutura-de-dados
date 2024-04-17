/*
Questão 6: Lista Duplamente Encadeada - Ações de usuários em um programa - Remoção por nome da ação
Implemente duas funções que realizem a remoção de um determinado elemento da lista duplamente encadeada. A primeira função deve realizar a remoção de um elemento pelo nome da ação, informado pelo usuário. A segunda função deve remover um elemento da lista pelo seu id, também informado pelo usuário.   Caso a lista não possua elementos imprima
Remoção em lista vazia!
. Caso a lista possua elementos mas o informado para a remoção pelo usuário não faça parte da mesma, imprima
Erro: remoção de valor não encontrado!
Você pode (
e deve!
) utilizar o código que você desenvolveu na atividade "Lista Duplamente Encadeada - Ações de usuários em um programa" como base.
Com essa finalidade, você deverá adicionar os seguintes comandos, como segue:
x seguido de uma string: remove o elemento da lista que cujo nome da ação está de acordo com o especificado pela string.
w seguido de um inteiro: remove o elemento da lista que cujo id da ação está de acordo com o especificado pelo inteiro.
Saídas:
Todas as saídas de comandos já estão implementadas na função principal código entregue, somente falta implementar a chamada para as remoções solicitadas. Ao terminar a execução do programa, todos os itens da listas são escritos.
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
p
(1, limparCache, 123, 99)
(3, paralelismoProc, 65, 23)
(2, semaforoProc, 32, 11)
 IMPRIMINDO REVERSO 
(2, semaforoProc, 32, 11)
(3, paralelismoProc, 65, 23)
(1, limparCache, 123, 99)
x paralelismoProc
s empilharProcessos
Nao encontrado
p
(1, limparCache, 123, 99)
(2, semaforoProc, 32, 11)
 IMPRIMINDO REVERSO 
(2, semaforoProc, 32, 11)
(1, limparCache, 123, 99)
w 2
p
(1, limparCache, 123, 99)
 IMPRIMINDO REVERSO
(1, limparCache, 123, 99)
f
*/

#include <iostream>
using namespace std;

int main() {
    // Seu código aqui
    return 0;
}
