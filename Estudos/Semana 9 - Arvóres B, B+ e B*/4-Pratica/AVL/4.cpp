/*
Questão 4: Estrutura de dados AVL recursiva - Floricultura
Uma floricultura resolveu catalogar o seu estoque de sementes. Para isso, cada pacote de semente será registrado com nome do cultivar, marca da semente, ano de fabricação e a quantidade de itens disponíveis para venda.  Utilizando o
código fornecido
, implemente um árvore AVL com as funções de inserir e remover elementos. A idea principal do problema é que implementação da remoção seja utilizando recursão, não sendo necessário o uso da função transplanta. A estratégia de remoção de elementos que não estejam em nós folhas é a substituição pelo elemento posterior (sucessor).
O código fornecido já tem o menu de entrada e o método de impressão.
Não
altere essas funções. O caminho mais fácil para a solução do exercício é não alterar a assinaturas das funções, dessa forma, não resultará em conflito com o código fornecido. 
O dado a ser armazenado na árvore é composto por uma
chave
do tipo
inteiro
, o
nome do cultivar
do tipo
string
, a
marca da semente
do tipo
string
,
ano de fabricação
do tipo
inteiro
e a
quantidade de itens
disponíveis do tipo
inteiro
.
Entradas:
i - para
inserir
elemento : deve ler chave [inteiro] , nome do cultivar [string], marca [string], ano de fabricação [inteiro] e quantidade disponível [inteiro]
r - para
remover
elemento : deve ler chave [inteiro]
b - para
buscar
elemento : deve ler chave [inteiro]
l - para fazer o
levantamento
de quantidade de pacotes de sementes de um cultivar de uma  dada marca: deve ler duas strings (cultivar e marca)
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
b - buscar elemento : A operação de busca escreve a frase: "Elemento buscado: ([chave],[cultivar],[marca],[ano],[quantidade])", em que [chave], [nome], [local], [ano] e [quantidade] devem ser substituídos pela respectiva chave, nome do cultivar, marca da semente, ano de fabricação e quantidade disponível
l - levantamento por localização: Imprime: "Levantamento do cultivar [cultivar]: [quantidade]", em que [cultivar] é o cultivar pesquisado e [quantidade] é a quantidade de pacotes de sementes daquele cultivar com uma dada marca
e - imprimir árvore : imprime a árvore seguindo o padrão de formatação tree
f - finalizar : finaliza o programa
Exemplo de Entrada:
i 4 tomate astrix 2008 5
i 5 tomate panun 2009 6
i 8 rosa astrix 2010 3
i 10 rosa panu 2013 2
i 101 cravo astrix 2018 3
i 201 tomate astrix 2010 5
i 301 tomate astrix 2015 10
i 15 manjericao tafum 2018 3
i 18 manjericao tafum 2020 5
e
l manjericao tafum
l tomate astrix
f
Exemplo de Saída:
(10,rosa)
 ├e─(5,tomate)
 │   ├e─(4,tomate)
 │   └d─(8,rosa)
 └d─(201,tomate)
     ├e─(18,manjericao)
     │   ├e─(15,manjericao)
     │   └d─(101,cravo)
     └d─(301,tomate)
Levantamento do cultivar manjericao: 8
Levantamento do cultivar tomate: 20
Exemplo de Entrada 2:
i 4 tomate astrix 2008 5
i 5 tomate panun 2009 6
i 8 rosa astrix 2010 3
i 10 rosa panu 2013 2
i 101 cravo astrix 2018 3
i 201 tomate astrix 2010 5
i 301 tomate astrix 2015 10
i 15 manjericao tafum 2018 3
i 18 manjericao tafum 2020 5
e
b 201
b 142
l rosa panun
r 8
r 10
r 301
i 10 rosa panun 2013 2
i 303 rosa panun 2014 3
e
l rosa panun
f
Exemplo de Saída 2:
(10,rosa)
 ├e─(5,tomate)
 │   ├e─(4,tomate)
 │   └d─(8,rosa)
 └d─(201,tomate)
     ├e─(18,manjericao)
     │   ├e─(15,manjericao)
     │   └d─(101,cravo)
     └d─(301,tomate)
Elemento buscado: (201,tomate,astrix,2010,5)
Erro na busca: elemento não encontrado!
Levantamento do cultivar rosa: 0
(15,manjericao)
 ├e─(5,tomate)
 │   ├e─(4,tomate)
 │   └d─(10,rosa)
 └d─(101,cravo)
     ├e─(18,manjericao)
     └d─(201,tomate)
         └d─(303,rosa)
Levantamento do cultivar rosa: 5
Exemplo de Entrada 3:
e
l cenoura isla
b 13
f
Exemplo de Saída 3:
*arvore vazia*
Levantamento do cultivar cenoura: 0
Erro na busca: elemento não encontrado!
Observação
: para baixar o arquivo, clique com o botão direito do mouse, depois clique em "salvar link como" e escolha uma pasta do seu computador. Não tente abrir o código no navegador e copiar o texto. Isso resultará em mudança na codificação do texto de UTF-8 para ISO, deformando a saída formatada da árvore.
*/

#include <iostream>
using namespace std;

int main() {
    // Seu código aqui
    return 0;
}
