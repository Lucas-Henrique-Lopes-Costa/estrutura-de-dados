/*
Questão 31: Ponteiros - Redução do vetor (arquivos, modularização)
Faça um programa para ler vários números de um arquivo texto. A primeira linha do arquivo contém a quantidade de dados a serem lidos. Aloque,
dinamicamente
, a quantidade necessária, não sendo permitido o uso de alocação na pilha, ou seja, devem ser utilizados ponteiros para esta alocação. Cada dois números consecutivos no arquivo devem ser transformados num único número pela média dos dois. Se houver quantidade ímpar de números, o último deve permanecer inalterado.
Depois do processamento, os valores devem ser escritos na saída padrão em ordem inversa.
O processamento e as operações de entrada/saída devem ser separados pela criação de ao menos um subprograma. Um bom planejamento dos subprogramas e das passagens de parâmetros é parte da avaliação.
Entradas:
O nome do arquivo com números (não terá mais que 80 caracteres, não terá espaços).
Número inteiro representando o total de valores a serem lidos.
Números reais contidos no arquivo.
Saídas:
Os números reduzidos, na ordem inversa do cálculo.
Exemplo de Entrada (entrada padrão):
numeros.txt
Exemplo de Entrada (arquivo numeros.txt):
5
2.3
8.1
5.2
-1.1
3.14
Exemplo de Saída:
3.14 2.05 5.2
Observe que a média dos dois primeiros números é 5.2, dos dois outros é 2.05 e o último (3.14) permanece inalterado. Esse valores são escritos em ordem inversa.
*/

#include <iostream>
using namespace std;

int main() {
    // Seu código aqui
    return 0;
}
