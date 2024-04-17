/*
Questão 13: Hash com endereçamento aberto - Lista de processos em uma repartição pública - Redimensionamento em 50%
Utilizando como base o código que você desenvolveu na atividade "Hash com endereçamento aberto - Lista de processos em uma repartição pública", faça as alterações necessárias para que a tabela hash seja redimensionada, aumentando sua capacidade em 50%, quando a ocupação chegar ou ultrapassar 60%.
Exemplo de Entrada e Saída juntas:
r Joao
Impossível remover de hash vazia.
i processo1 Joao a 2
i processo2 Maria c 5
i processo3 Severino d 9
p
[0:Severino/9] [1:] [2:] [3:] [4:Joao/2] [5:Maria/5] 
i processo4 Marcos f 12
p
[0:Maria/5] [1:] [2:] [3:] [4:Joao/2] [5:] [6:Severino/9] [7:] [8:Marcos/12] 
i processo5 Barnabe a 10
i processo6 Tiao z 22
p
[0:] [1:] [2:] [3:] [4:] [5:] [6:Maria/5] [7:Tiao/22] [8:Joao/2] [9:] [10:Barnabe/10] [11:Severino/9] [12:Marcos/12] 
i processo7 Marlon a 40
i processo8 PeroVazCaminha f 31
i processo9 Svetlana w 55
p
[0:] [1:] [2:Marlon/40] [3:Maria/5] [4:] [5:] [6:Marcos/12] [7:] [8:Tiao/22] [9:Joao/2] [10:] [11:] [12:] [13:] [14:Svetlana/55] [15:] [16:Barnabe/10] [17:PeroVazCaminha/31] [18:Severino/9] 
r Tiao
f
[0:] [1:] [2:Marlon/40] [3:Maria/5] [4:] [5:] [6:Marcos/12] [7:] [8:REMOVIDO] [9:Joao/2] [10:] [11:] [12:] [13:] [14:Svetlana/55] [15:] [16:Barnabe/10] [17:PeroVazCaminha/31] [18:Severino/9]
*/

#include <iostream>
using namespace std;

int main() {
    // Seu código aqui
    return 0;
}
