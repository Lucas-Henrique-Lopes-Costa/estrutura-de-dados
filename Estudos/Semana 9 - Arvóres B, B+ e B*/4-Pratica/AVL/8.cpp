/*
Questão 8: Estrutura de dados AVL recursiva - Pokemon
Está chegando o próximo mega-híper-super campeonato de Pokemon Come e você resolve colocar à prova os seus fabulosos conhecimentos. Para isso, você resolveu fazer um programinha para cadastrar os seus pokemons  e, para maior eficiência, você optou pelo uso de uma árvore binária de busca balanceada - AVL. Utilizando o
código fornecido
, implemente um árvore AVL com as funções de inserir e remover elementos. A ideia principal do problema é que implementação da remoção seja utilizando recursão, não sendo necessário o uso da função transplanta. A estratégia de remoção de elementos que não estejam em nós folhas é a substituição pelo elemento posterior (sucessor).
O código fornecido já tem o menu de entrada e o método de impressão.
Não
altere essas funções. O caminho mais fácil para a solução do exercício é não alterar a assinaturas das funções, dessa forma, não resultará em conflito com o código fornecido. 
O dado a ser armazenado na árvore é composto por um
id
do tipo
inteiro
, o
nome do pokemon
do tipo
string
, o
tipo principal do pokemon
do tipo
string
e o
nível alcançado
do tipo
inteiro
.
Entradas:
i - para
inserir
elemento : deve ler id [inteiro] , nome do pokemon [string], tipo [string] e nível [inteiro]
r - para
remover
elemento : deve ler id [inteiro]
b - para
buscar
elemento : deve ler id [inteiro]
l - para fazer o
levantamento
de pokemons de um determinado tipo e nível: deve ler uma string e um inteiro
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
b - buscar elemento : A operação de busca escreve a frase: "Elemento buscado: ([id],[nome],[tipo],[nível])", em que [id], [nome], [tipo] e [nível] devem ser substituídos pelo respectivo id, nome do pokemon, tipo principal e nível alcançado."
l - levantamento por tipo e nível: Imprime: "Levantamento de pokemons tipo [tipo] e nível [nível]:  [quantidade]", em que [tipo] é o tipo de pokemon, [nível] o nível alcançado e  [quantidade] é a quantidade de pokemons atendendo esses dois requisitos.
e - imprimir árvore : imprime a árvore seguindo o padrão de formatação tree
f - finalizar : finaliza o programa
Exemplo de Entrada 1:
i 12 pikachu eletrico 25
i 51 charizard fogo 30
i 302 bulbassauro agua 40
i 14 eevee normal 45
i 96 magmar fogo 25
i 301 flareon fogo 30
i 13 jolteon eletrico 25
i 55 raichu eletrico 30
l fogo 30
l eletrico 25
l fogo 25
e
f
Exemplo de Saída1 :
Levantamento de pokemons tipo fogo e nível 30: 2
Levantamento de pokemons tipo eletrico e nível 25: 2
Levantamento de pokemons tipo fogo e nível 25: 1
(51,charizard)
 ├e─(13,jolteon)
 │   ├e─(12,pikachu)
 │   └d─(14,eevee)
 └d─(301,flareon)
     ├e─(96,magmar)
     │   └e─(55,raichu)
     └d─(302,bulbassauro)
Exemplo de Entrada 2:
i 12 pikachu eletrico 25
i 51 charizard fogo 30
i 302 bulbassaur agua 40
i 14 eevee normal 45
i 96 magmar fogo 25
i 102 cleffairy normal 45
i 402 snorlax normal 45
i 9 rattata normal 45
i 77 ditto normal 42
i 66 meowth normal 23
i 88 ponyta fogo 30
i 2 charmander fogo 30
i 301 flareon fogo 30
i 13 jolteon eletrico 25
i 55 raichu eletrico 30
e
l fogo 30
r 9
r 96
r 402
b 14
b 9
l normal 45
l fogo 25
e
f
Exemplo de Saída 2:
(77,ditto)
 ├e─(12,pikachu)
 │   ├e─(9,rattata)
 │   │   └e─(2,charmander)
 │   └d─(51,charizard)
 │       ├e─(14,eevee)
 │       │   └e─(13,jolteon)
 │       └d─(66,meowth)
 │           └e─(55,raichu)
 └d─(102,cleffairy)
     ├e─(96,magmar)
     │   └e─(88,ponyta)
     └d─(302,bulbassaur)
         ├e─(301,flareon)
         └d─(402,snorlax)
Levantamento de pokemons tipo fogo e nível 30: 4
Elemento buscado: (14,eevee,normal,45)
Erro na busca: elemento não encontrado!
Levantamento de pokemons tipo normal e nível 45: 2
Levantamento de pokemons tipo fogo e nível 25: 0
(77,ditto)
 ├e─(51,charizard)
 │   ├e─(12,pikachu)
 │   │   ├e─(2,charmander)
 │   │   └d─(14,eevee)
 │   │       └e─(13,jolteon)
 │   └d─(66,meowth)
 │       └e─(55,raichu)
 └d─(102,cleffairy)
     ├e─(88,ponyta)
     └d─(302,bulbassaur)
         └e─(301,flareon)
Observação
: para baixar o arquivo, clique com o botão direito do mouse, depois clique em "salvar link como" e escolha uma pasta do seu computador. Não tente abrir o código no navegar e copiar o texto. Isso resultará em mudança na codificação do texto de UTF-8 para ISO, deformando a saída formatada da árvore.
*/

#include <iostream>
using namespace std;

int main() {
    // Seu código aqui
    return 0;
}
