/*
Questão 2: Lista Duplamente Encadeada - Ações de usuários em um programa
Crie um programa que seja capaz de armazenar em uma lista duplamente encadeada as ações de usuários em um programa. Cada elemento da lista deve ter um identificador, o nome da ação, tempo para execução total e tempo já consumido de processamento. Você poderá utilizar o
código fornecido
como base de implementação.
Os comandos que deverão ser utilizados para execução do programa são:
i: inserir uma nova ação no inicio da lista. O formato de entrada é:
Identificador NomeAcao TempoExecução TempoConsumido
h: inserir uma nova ação no final da lista. O formato de entrada é:
Identificador NomeAcao TempoExecução TempoConsumido
m: inserir uma nova equipe na posição informada pelo inteiro. Considere 0 como no início e imprima "Posição Inexistente!" caso não seja possível inserir na posição indicada. O formato de entrada é:
posiçãoASerInserida Identificador NomeAcao TempoExecução TempoConsumido
r: apagar uma determinada ação do início da lista. Caso não exista a equipe deverá imprimir
Remoção em lista vazia!
a: apagar uma determinada ação do fim da lista. Caso não exista a equipe deverá imprimir
Remoção em lista vazia!
p: imprimir lista de ações cadastradas em ordem de inserção e, em seguida, em ordem inversa. Imprimir
Lista vazia!
quando não tiver elemento a ser impresso.
s: buscar por uma ação a partir de seu nome. Imprimir
Nao encontrado
quando a busca não obtiver sucesso.
Nota: o formato de saída das ações deve ser:
(Identificador, NomeAcao, TempoExecução, TempoConsumido)
. Para mais instâncias de ações (comando de impressão), separar cada uma delas por quebras de linha.
Entradas:
Comandos detalhados no exercício
Saídas:
Impressões detalhadas no exercício
Exemplo de Entrada e Saída misturados:
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
s empilharProcessos
Nao encontrado
r
p
(3, paralelismoProc, 65, 23)
(2, semaforoProc, 32, 11)
 IMPRIMINDO REVERSO 
(2, semaforoProc, 32, 11)
(3, paralelismoProc, 65, 23)
a
p
(3, paralelismoProc, 65, 23)
 IMPRIMINDO REVERSO 
(3, paralelismoProc, 65, 23)
f
*/

#include <iostream>
using namespace std;

int main() {
    // Seu código aqui
    return 0;
}
