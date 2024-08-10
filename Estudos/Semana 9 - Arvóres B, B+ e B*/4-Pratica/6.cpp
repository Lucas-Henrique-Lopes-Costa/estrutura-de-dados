/*
Questão 6: Árvore ABB - Eficiência da busca
A árvore binária de busca serve para reduzir os passos necessários na recuperação de informações de um conjunto grande. Para investigar essa eficiência você vai implementar uma árvore com as operações de inserção e busca, de tal forma que seja possível saber o número de nós visitados durante uma busca na árvore.
Este código
já tem um começo de implementação, em que a função principal já está pronta, e também está implementado um tipo de dados que o programa vai usar para armazenar na árvore. Esse tipo consiste de uma chave (número inteiro) e um valor (texto). Você pode alterar a função principal se decidir que não deseja usar manipulação de exceções, porém o programa deverá continuar funcionando do mesmo jeito.
Entradas:
O programa consiste em um laço com as opções de
inserção
,
busca
,
escrita em ordem
e
encerramento
. A operação de escrita não é importante na nota. Se você decidir implementar, adicione o comando para escrever na função principal. As opções são identificados por letras seguidas de parâmetros, a saber:
i - para
inserir
uma informação na árvore. A letra i deve ser seguida da chave (número inteiro) e valor (palavra).
b - para
buscar
uma informação na árvore. A letra b deve ser seguida da chave a ser buscada.
e - para escrever o conteúdo da árvore, em ordem.
f - para finalizar a execução do programa.
Saídas:
A operação de inserção não produz saída. A operação de busca escreve o valor associado à chave, seguida do número de nós visitados na árvore durante a busca. Caso a informação busca não esteja na árvore, a função principal escreve "INEXISTENTE" no lugar do valor. A operação de escrever escreve todos os valores da árvore e
não tem influência na avaliação
.
Exemplo de Entrada:
i 2 dois
i 5 cinco
i 6 seis
i 4 quatro
i 1 um
i 3 tres
b 1
b 3
b 7
b 2
f
Exemplo de Saída:
um 2
tres 4
INEXISTENTE 3
dois 1
*/

#include <iostream>
using namespace std;

int main() {
    // Seu código aqui
    return 0;
}
