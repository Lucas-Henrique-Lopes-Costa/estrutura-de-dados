/*
Questão 2: Pilha com armazenamento em vetor - Lista de tarefas para robô doméstico
Implemente uma estrutura de dados pilha, utilizando armazenamento em vetor, para implementar uma lista de tarefas para um robô doméstico. A estrutura deve possibilitar, pelo menos, as seguintes ações: empilhamento e desempilhamento de itens, verificação do item no topo da pilha e limpeza da lista de afazeres (remoção de todos os elementos da pilha). O desempilhamento deve escrever mensagem de erro na saída ("
Erro: pilha vazia!
"), quando a pilha já estiver vazia. O empilhamento também deve gerar mensagem de erro (
"Erro: pilha cheia!"
), quanto todas as posições do vetor estiverem ocupadas. Os itens da lista de tarefas possuem os seguintes atributos: nome (uma string sem espaços), tipo (um único caracter) e tempo de execução em minutos (um inteiro). Além disso, sabe-se que esse robô tem capacidade de memória limitada para no
máximo seis tarefas
.
Entradas:
O programa deve aceitar os seguintes comandos:
i seguido de uma string, um caracter e um inteiro: para inserir um item na lista de tarefas
r: para retirar um item da lista de tarefas
l: para limpar (remover todos) os itens da lista de tarefas
e: para espiar o topo da  lista de tarefas (escreve o topo sem removê-lo)
f: para finalizar a execução do programa
Antes dos comandos, o  programa recebe a capacidade de armazenamento da pilha.
Saídas:
Todas as saídas de comandos já estão implementadas na função principal desse
código exemplo fornecido
. Ao terminar a execução do programa, todos os itens da pilha são desempilhados e escritos.
Exemplo de Entrada e Saída juntas:
r
Erro: pilha vazia!
i sala s 150
i quarto1 q 45
i quarto2 q 45
i quarto3 q 60
i cozinha c 130	
r
Nome: cozinha Tipo: c Valor: 130
i cozinha c 145
e
Nome: cozinha Tipo: c Valor: 145
i varanda v 100
i banheiro b 120
Erro: pilha cheia!
f
Nome: varanda Tipo: v Valor: 100
Nome: cozinha Tipo: c Valor: 145
Nome: quarto3 Tipo: q Valor: 60
Nome: quarto2 Tipo: q Valor: 45
Nome: quarto1 Tipo: q Valor: 45
Nome: sala Tipo: s Valor: 150
*/

#include <iostream>
using namespace std;

int main() {
    // Seu código aqui
    return 0;
}
