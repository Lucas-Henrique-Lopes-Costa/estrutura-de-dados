/*
Questão 12: Hash com encadeamento - Inventário de itens de jogo - Hash com Vetor de Quatro Posições
A implementação de Hash com encadeamento é uma das mais utilizadas. Para o encadeamento, a implementação tradicional faz uso de uma lista encadeada. Entretanto, várias implementações utilizam estruturas diferenciadas para o encadeamento das colisões. Por exemplo, a classe HashMap no Java 8 utiliza uma árvore binária para essa tarefa.
Utilizando como base o código que você desenvolveu na atividade "Hash com encadeamento - Inventário de itens de jogo", implemente uma tabela hash com um número genérico n de posições, informado durante a construção da tabela, com resolução de colisões utilizando um vetor de quatro posições. Inclusive, o primeiro elemento na posição deverá ser armazenado também nesse vetor, na posição 0. Não é necessário implementar métodos para alteração ou remoção de dados, apenas inserção e recuperação. Chaves não utilizadas devem ser mantidas como -1, tendo a string vazia como valor associado.
Exemplo de Entrada e Saída juntas:
5
r dez
Erro na remoção: chave não encontrada!
i um a 1
chave 'um' inserida na posicao 3
i dois b 2
chave 'dois' inserida na posicao 4
i quatro d 4
chave 'quatro' inserida na posicao 2
i sete g 7   
chave 'sete' inserida na posicao 2
i oito h 8
chave 'oito' inserida na posicao 1
i dez j 10
chave 'dez' inserida na posicao 4
i tres c 3
chave 'tres' inserida na posicao 1
i onze k 11
chave 'onze' inserida na posicao 3
i doze l 12
chave 'doze' inserida na posicao 4
i treze m 1
chave 'treze' inserida na posicao 2
p
0: 
1: [tres/3][oito/8]
2: [treze/1][sete/7][quatro/4]
3: [onze/11][um/1]
4: [doze/12][dez/10][dois/2]
i quinze o 15
chave 'quinze' inserida na posicao 3
i vinte w 20
chave 'vinte' inserida na posicao 1
i trinta x 30
chave 'trinta' inserida na posicao 0
i quarenta z 40
chave 'quarenta' inserida na posicao 2
i cinco e 5
chave 'cinco' inserida na posicao 3
i cem t 100
Posição na tabela já possui 4 elementos!
f
0: [trinta/30]
1: [vinte/20][tres/3][oito/8]
2: [quarenta/40][treze/1][sete/7][quatro/4]
3: [cinco/5][quinze/15][onze/11][um/1]
4: [doze/12][dez/10][dois/2]
*/

#include <iostream>
using namespace std;

int main() {
    // Seu código aqui
    return 0;
}
