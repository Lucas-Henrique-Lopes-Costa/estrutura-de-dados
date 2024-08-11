/*
Questão 9: Estrutura de dados AVL recursiva - Checagem CPF
Uma empresa está tentando se adaptar a rotina de distanciamento social vigente. Uma das medidas é restringir a entrada de funcionários ao espaço físico da empresa de acordo com o número do CPF. Em dias pares, somente funcionários com CPF finalizando em número par pode entrar, em casos de dias ímpares, somente funcionários com CPF finalizando em número ímpar. Para agilizar o controle de acesso, você deve criar um sistema para fazer buscas rápidas na base, para isso, utilizando árvores binárias de buscas balanceadas.
Utilizando o
código fornecido
, implemente uma árvore AVL com as funções de inserir, remover e buscar elementos. A idea principal do problema é que implementação da remoção seja utilizando recursão, não sendo necessário o uso da função transplanta. A estratégia de remoção de elementos, em casos que precise de substituição, é a substituição pelo elemento posterior (sucessor). Além disso, você deve desenvolver uma função, que, ao receber a chave de acesso do funcionário e o dia do mês, retorna se o funcionário está autorizado a entrar ou não. Outra função necessária é listar todos os funcionários que podem acessar a empresa, para isso, a função recebe o dia do mês como entrada, e realiza a impressão
em ordem
na AVL.
O código fornecido já tem o menu de entrada e o método de impressão.
Não
altere essas funções. O caminho mais fácil para a solução do exercício é não alterar a assinaturas das funções, dessa forma, não resultará em conflito com o código fornecido.
O dado a ser armazenado na árvore é composto por uma
chave
do tipo
inteiro
, um
nome
do tipo
string
, e um
CPF
do tipo
unsigned long long int
.
Entradas:
i - para
inserir
elemento : deve ler chave [inteiro] e valor [string]
r - para
remover
elemento : deve ler chave [inteiro]
b - para
buscar
elemento : deve ler chave [inteiro]
v - para
verificar
funcionario : deve ler chave [inteiro] e dia do mês [inteiro]
l - para
listar
funcionários : deve ler dia do mês [inteiro]
e - para
imprimir
árvore
f - finalizar
Saídas:
i - inserir elemento : A operação de inserção
não
produz saída
r - remover elemento : A operação de remoção
não
produz saída
b - buscar elemento : A operação de busca escreve a frase: "Nome: [nome] | CPF: [cpf] | Cod: [chave] ", em que [nome], [cpf] e [chave] são as informações armazenadas do funcionário.". Caso o elemento não seja encontrado, imprime a mensagem: "Erro na busca: elemento não encontrado!".
v - verificar funcionario : imprime a frase: "Autorizado.", caso a paridade seja a mesma entre o CPF e o dia do mês, caso contrário imprime "Não autorizado.", ou ainda, imprime "Erro na verificacao: chave inexistente!", caso a chave informada não esteja cadastrada.
l - listar funcionários  : deve listar os funcionários permitidos a trabalhar no dia informado, um por linha, segundo a formatação "Nome: [nome] | CPF: [cpf] | Cod: [chave] ", em que [nome], [cpf] e [chave] são as informações armazenadas do funcionário.
e - imprimir árvore : imprime a árvore seguindo o padrão de formatação tree
f - finalizar : finaliza o programa
Exemplo de Entrada 1:
i 1 Gelo_Tancredo 11111111111
i 2 Sauna_Jose 22222222222
i 3 Gray_Fernando 33333333333
i 4 Liar_Itamar 44444444444
i 5 Rico_Fernando 55555555555
i 6 Hino_Luiz 66666666666
i 7 Huck_Dilma 77777777777
i 8 Coragem_Michel 88888888888
i 9 Naro_Jair 99999999999
e
f
Exemplo de Saída 1:
(4,Liar_Itamar)
 ├e─(2,Sauna_Jose)
 │   ├e─(1,Gelo_Tancredo)
 │   └d─(3,Gray_Fernando)
 └d─(6,Hino_Luiz)
     ├e─(5,Rico_Fernando)
     └d─(8,Coragem_Michel)
         ├e─(7,Huck_Dilma)
         └d─(9,Naro_Jair)
Exemplo de Entrada 2:
i 1 Gelo_Tancredo 11111111111
i 2 Sauna_Jose 22222222222
i 3 Gray_Fernando 33333333333
i 4 Liar_Itamar 44444444444
i 5 Rico_Fernando 55555555555
i 6 Hino_Luiz 66666666666
i 7 Huck_Dilma 77777777777
i 8 Coragem_Michel 88888888888
i 9 Naro_Jair 99999999999
v 3 21
v 3 12
v 10 12 
l 11
b 5
r 5
b 5
l 22
v 5 12
r 9
f
Exemplo de Saída 2:
Autorizado.
Não autorizado.
Erro na verificacao: chave inexistente!
Nome: Gelo_Tancredo | CPF: 11111111111 | Cod: 1
Nome: Gray_Fernando | CPF: 33333333333 | Cod: 3
Nome: Rico_Fernando | CPF: 55555555555 | Cod: 5
Nome: Huck_Dilma | CPF: 77777777777 | Cod: 7
Nome: Naro_Jair | CPF: 99999999999 | Cod: 9
Nome: Rico_Fernando | CPF: 55555555555 | Cod: 5
Erro na busca: elemento não encontrado!
Nome: Sauna_Jose | CPF: 22222222222 | Cod: 2
Nome: Liar_Itamar | CPF: 44444444444 | Cod: 4
Nome: Hino_Luiz | CPF: 66666666666 | Cod: 6
Nome: Coragem_Michel | CPF: 88888888888 | Cod: 8
Erro na verificacao: chave inexistente!
Observação
: para baixar o arquivo, clique com o botão direito do mouse, depois clique em "salvar link como" e escolha uma pasta do seu computador. Não tente abrir o código no navegar e copiar o texto. Isso resultará em mudança na codificação do texto de UTF-8 para ISO, deformando a saída formatada da árvore.
*/

#include <iostream>
using namespace std;

int main() {
    // Seu código aqui
    return 0;
}
