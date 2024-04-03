/*
Questão 8: Fila com armazenamento em vetor - Lista de processos em uma repartição pública - retirar da fila todos os processos de um dado assunto
Após uma mudança na legislação, todos os processos de um dado assunto devem ser encaminhados para outra repartição pública. Dessa maneira, implemente uma função que exclua da fila de processos atual, todos aqueles que abordam um mesmo assunto.
Você pode (
e deve!
) utilizar o código que você desenvolveu na atividade "Fila com armazenamento em vetor - Lista de processos em uma repartição pública" como base.
Com essa finalidade, você deverá adicionar mais um comando, como segue:
x seguindo de uma string: retirar da fila todos os processos de um dado assunto.
Saídas:
Todas as saídas de comandos já estão implementadas na função principal código entregue, somente falta implementar a chamada para a remoção. Ao terminar a execução do programa, todos os itens da pilha são desempilhados e escritos.
Exemplo de Entrada e Saída juntas:
r
Erro: fila vazia!
i processo2 Assassinato c 5
i processo1 Furto a 2
i processo3 Divorcio d 9
i processo5 ImpostoRenda a 10
i processo6 Furto z 22
i processo7 ImpostoRenda a 40
i processo4 RuaEsburacada f 12
Erro: fila cheia!
r
Nome: processo2 Assunto: Assassinato Tipo: c Processo: 5
e
Nome: processo1 Assunto: Furto Tipo: a Processo: 2
i processo4 RuaEsburacada f 12
x ImpostoRenda
f
Nome: processo1 Assunto: Furto Tipo: a Processo: 2
Nome: processo3 Assunto: Divorcio Tipo: d Processo: 9
Nome: processo6 Assunto: Furto Tipo: z Processo: 22
Nome: processo4 Assunto: RuaEsburacada Tipo: f Processo: 12
*/

#include <iostream>
using namespace std;

int main() {
    // Seu código aqui
    return 0;
}
