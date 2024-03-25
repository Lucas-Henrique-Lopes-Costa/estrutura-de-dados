/*
Questão 1: Heap - Organização de um robô domestico
Uma empresa desenvolveu um robô de limpeza domestica e precisa que você desenvolva uma um sistema para robô saber qual tarefa ele deve resolver. Você deve considerar como característica: nome da tarefa, tipo da tarefa, a quantidade de energia gasta pela atividade, o tempo estimado para a atividade ser realizada e prioridade.
Com seus conhecimentos de Estrutura de Dados, implemente uma estrutura para definir corretamente qual tarefa ele deve executar. Para este caso, você deve considerar a maior quantidade de energia gasta pela atividade como fator principal para a limpeza do local. Você poderá utilizar o
código fornecido
como base de implementação.
Comandos de utilização do programa:
i: inserir uma nova atividade, seguido de uma string (nome da tarefa), um carácter (tipo da tarefa), três inteiros (a quantidade de energia gasta pela atividade, o tempo estimado para a atividade ser realizada e a prioridade, respectivamente) das tarefas.
r: obter a atividade que deverá ser tratada. Causa a retirada da atividade mais prioritário do sistema e o programa escreve seu nome. Caso não tenha uma atividade para ser realizada, o programa escreve "
Erro ao retirar raiz
".
p: imprime a estrutura.
f: sair do programa.
No início da execução, o programa lê a capacidade máxima de atividades para trabalhar. Caso o usuário tente inserir um elemento além da capacidade máxima informada, informe a seguinte mensagem de erro: "
Erro ao inserir
" .Em seguida começa a processar os comandos acima.
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
p
[kitchen/c/180/200/1] [bedroom1/x/99/90/2] [bedroom3/v/56/80/8] [tvroom/t/18/28/8] [bedroom2/x/33/50/5] [livingroom/r/35/58/5] 
r
kitchen
p
[bedroom1/x/99/90/2] [livingroom/r/35/58/5] [bedroom3/v/56/80/8] [tvroom/t/18/28/8] [bedroom2/x/33/50/5] 
f
*/

#include <iostream>
using namespace std;

int main() {
    // Seu código aqui
    return 0;
}
