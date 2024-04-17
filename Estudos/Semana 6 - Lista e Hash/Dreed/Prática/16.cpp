/*
Questão 16: Hash com endereçamento aberto - Lista de processos em uma repartição pública - Defragmentação da estrutura
Implemente uma função que realize a defragmentação de estrutura Hash. Para essa atividade é assumido que a flag de REMOVIDO é utilizado e os elementos não foram reorganizados. Ao executar a função de defragmentação, as flagas de removidos devem ser convertidos para INVALIDO e os elementos devem ser reposicionados.
Você pode (
e deve!
) utilizar o código que você desenvolveu na atividade "Hash com endereçamento aberto - Lista de processos em uma repartição pública" como base.
Entradas:
Com essa finalidade, você deverá adicionar mais um comando, como segue:
d: para defragmentar a estrutura.
Saídas:
Todas as saídas de comandos já estão implementadas na função principal código entregue, somente falta implementar a chamada para a modificação. Ao terminar a execução do programa, todos os itens da hash são escritos.
Exemplo de Entrada e Saída juntas:
r Joao
Impossível remover de hash vazia.
i processo1 Joao a 2
i processo2 Maria c 5
i processo3 Severino d 9
i processo4 Marcos f 12
i processo5 Barnabe a 10
i processo6 Tiao z 22
i processo7 Marlon a 40
Tabela hash cheia.
p
[0:Severino/9] [1:Barnabe/10] [2:Marcos/12] [3:Tiao/22] [4:Joao/2] [5:Maria/5] 
r Severino
r Marcos
p
[0:REMOVIDO] [1:Barnabe/10] [2:REMOVIDO] [3:Tiao/22] [4:Joao/2] [5:Maria/5]
d
[0:Barnabe/10] [1:] [2:Tiao/22] [3:] [4:Joao/2] [5:Maria/5]
f
[0:Barnabe/10] [1:] [2:Tiao/22] [3:] [4:Joao/2] [5:Maria/5]
*/

#include <iostream>
using namespace std;

int main() {
    // Seu código aqui
    return 0;
}
