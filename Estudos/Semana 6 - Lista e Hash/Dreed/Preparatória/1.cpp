/*
Questão 1: Lista Simplesmente Encadeada - Equipes de Maratona
Crie um programa que seja capaz de armazenar em uma lista encadeada as equipes de uma maratona de programação. Para cada equipe deverá ser informado o seu nome, o nome do líder da equipe, a linguagem de programação que será utilizada e a quantidade de membros. Você poderá utilizar o
código fornecido
como base de implementação.
Os comandos que deverão ser utilizados para execução do programa são:
i: inserir uma nova equipe no inicio da lista. O formato de entrada é:
NomeEquipe Lider Linguagem QtdMembros
h: inserir uma nova equipe no fim da lista. O formato de entrada é:
NomeEquipe Lider Linguagem QtdMembros
m: inserir uma nova equipe na posição informada pelo usuário através de um número inteiro. Considere 0 como a posição inicial da lista. Caso não seja possível inserir na posição indicada imprima "Posição Inexistente!". O formato de entrada é:
posiçãoASerInserida NomeEquipe Lider Linguagem QtdMembros
r: apagar uma determinada equipe do início da lista. Caso não exista a equipe deverá imprimir
Remoção em lista vazia!
a: apagar uma determinada equipe do fim da lista. Caso não exista a equipe deverá imprimir
Remoção em lista vazia!
p: imprimir lista de equipes cadastradas. Imprimir
Lista vazia!
quando não tiver elemento a ser impresso.
s: buscar por uma equipe a partir de seu nome. Imprimir
Nao encontrado
quando a busca não obtiver sucesso.
Nota: o formato de saída das equipes deve ser:
(Nome, Lider, Linguagem, QtdMembros)
. Para mais instâncias de equipes (comando de impressão), cada uma delas devem ser separadas por quebras de linha.
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
s Thundercats
Lista vazia!
i Vingadores Stark Ruby 3
h LigaDaJustica Batman C++ 4
m 1 MuppetBabies Kermit Phyton 9
p
(Vingadores, Stark, Ruby, 3)
(MuppetBabies, Kermit, Phyton, 9)
(LigaDaJustica, Batman, C++, 4)
s Thundercats
Nao encontrado
r
p
(MuppetBabies, Kermit, Phyton, 9)
(LigaDaJustica, Batman, C++, 4)
a
p
(MuppetBabies, Kermit, Phyton, 9)
f
*/

#include <iostream>
using namespace std;

int main() {
    // Seu código aqui
    return 0;
}
