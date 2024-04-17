/*
Questão 14: Hash com endereçamento aberto - Lista de processos em uma repartição pública - Redimensionamento pelo dobro
Utilizando como base o código que você desenvolveu na atividade "Hash com endereçamento aberto - Lista de processos em uma repartição pública", faça as alterações necessárias para que a tabela hash seja redimensionada, aumentando sua capacidade em 100%, quando a ocupação chegar ou ultrapassar 70%.
Exemplo de Entrada e Saída juntas:
r Joao
Impossível remover de hash vazia.
i processo1 Joao a 2
i processo2 Maria c 5
i processo3 Severino d 9
i processo4 Marcos f 12
p
[0:Severino/9] [1:] [2:Marcos/12] [3:] [4:Joao/2] [5:Maria/5] 
i processo5 Barnabe a 10
p
[0:Severino/9] [1:Barnabe/10] [2:Marcos/12] [3:] [4:] [5:] [6:] [7:] [8:] [9:] [10:Joao/2] [11:Maria/5] 
i processo6 Tiao z 22
i processo7 Marlon a 40
i processo8 Manoel m 88
p
[0:Severino/9] [1:Barnabe/10] [2:Marcos/12] [3:Tiao/22] [4:] [5:Manoel/88] [6:Marlon/40] [7:] [8:] [9:] [10:Joao/2] [11:Maria/5] 
r severino
Chave não encontrada para remoção.
r Severino
f
[0:REMOVIDO] [1:Barnabe/10] [2:Marcos/12] [3:Tiao/22] [4:] [5:Manoel/88] [6:Marlon/40] [7:] [8:] [9:] [10:Joao/2] [11:Maria/5]
*/

#include <iostream>
using namespace std;

int main() {
    // Seu código aqui
    return 0;
}
