/*
Questão 5: Pilha - Verificação de uma sentença (v2)
Em Linguagens Formais e Autômatos um reconhecedor é um meio formal de verificar se uma dada sentença pertence ou não a uma determinada linguagem. Pilhas são estruturas usadas com frequência em reconhecedores.
Uma linguagem pode ser definida com um subconjunto de S*, a partir de um alfabeto S, onde S é um conjunto finito, não vazio, de símbolos. Considere o alfabeto S = {A,B,C} e a linguagem
L = {A*i B C*2i | i > 0}
, ou seja, as sequências  ABCC, AABCCCC, AAABCCCCCC são todas pertencentes ao conjunto de sentenças válidas de L. Faça um programa utilizando
somente
a estrutura de dado
pilha encadeada
,
respeitando todas as suas propriedades e não utilizando a STL
, que, dada uma sequência w de caracteres A, B e C, verifique se
w
faz parte ou não do conjunto de sentenças de L. O valor X indica fim da leitura.
O processamento deve ser interrompido assim que for possível dizer se
w
faz parte ou não do conjunto.
Ao final, o programa deve escrever se o padrão da linguagem foi reconhecido e os tamanhos das pilhas.
Sugestão: Usando duas pilhas, seu programa deve ler As e a cada A lido, empilhar um A numa e dois Cs na outra. Após ler um B, cada A desempilhado faz com que dois C sejam desempilhados. Ao final da iteração, a sentença foi reconhecida se todas as letras foram processadas e todos os desempilhamentos foram bem sucedidos e se as duas pilhas estão vazias.
Entradas:
Palavra a ser verificada.
Saídas:
A palavra
sim
ou
nao
(sem acento), indicando se a sentença foi reconhecida.
O tamanho da pilha de As.
O tamanho da pilha de Cs.
Exemplo de Entrada:
A A B C C C C X
Exemplo de Saída:
sim 0 0
Exemplo de Entrada:
A A B C C X
Exemplo de Saída:
nao 1 0
*/

#include <iostream>
using namespace std;

int main() {
    // Seu código aqui
    return 0;
}
