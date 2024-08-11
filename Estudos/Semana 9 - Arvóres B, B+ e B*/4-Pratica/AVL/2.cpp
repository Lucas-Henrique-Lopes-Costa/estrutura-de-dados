/*
Questão 2: Estrutura de dados AVL recursiva - Festival de Cinema
Tubiacanga irá sediar o Festival de Cinema Brasileiro no ano de 2022 e os responsáveis pelo festival decidiram fazer uma série de levantamentos de dados para, a partir disso, organizar um belíssimo festival. Para iniciar o levantamento, todos os festivais já realizados serão cadastrados com o nome da cidade em que a edição ocorreu, o ano e a quantidade de filmes que foram apresentados. Utilizando o
código fornecido
implemente um árvore AVL com as funções de inserir e remover elementos. A ideia principal do problema é que implementação da remoção seja utilizando recursão, não sendo necessário o uso da função transplanta. A estratégia de remoção de elementos que não estejam em nós folhas é a substituição pelo elemento posterior (sucessor).
O código fornecido já tem o menu de entrada e o método de impressão.
Não
altere essas funções. O caminho mais fácil para a solução do exercício é não alterar a assinaturas das funções, dessa forma, não resultará em conflito com o código fornecido. 
O dado a ser armazenado na árvore é composto por um
ano
do tipo
inteiro
, o
nome da cidade em que o evento foi realizado
do tipo
string
e a
quantidade de filmes apresentados
do tipo
inteiro
. Não existe mais de uma edição em um dado ano.
Entradas:
i - para
inserir
elemento : deve ler ano [inteiro] , nome da cidade [string] e a quantidade de filmes apresentados [inteiro]
r - para
remover
elemento : deve ler ano [inteiro]
b - para
buscar
elemento : deve ler ano [inteiro]
l - para fazer o
levantamento
do ano com a maior quantidade de filmes apresentados
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
b - buscar elemento : A operação de busca escreve a frase: "Elemento buscado: ([ano],[nome],[quantidade])", em que [ano], [nome] e [quantidade] devem ser substituídos pelo respectivo ano, nome da cidade em que o evento ocorreu e quantidade de filmes apresentados
l - levantamento por ano: Imprime: "Edição com maior quantidade de filmes apresentados: [ano]", em que [ano]  deve ser substituído pelo ano com a maior quantidade filmes apresentados -- no caso de empate, deve ser impresso o mais antigo
e - imprimir árvore : imprime a árvore seguindo o padrão de formatação tree
f - finalizar : finaliza o programa
Exemplo de Entrada:
i 1992 Remanso 5
i 2011 Preciosa 12
i 2007 Passaperto 2
i 2002 Maramores 7
i 2005 Roseiral 3
i 1984 Sucupira 6
i 1989 Santana_do_Agreste 12
i 1998 Santana_dos_Ferros 15
i 1985 Asa_Branca 11
i 1988 Sensilvania 13
e
l 
f
Exemplo de Saída:
(2002,Maramores)
 ├e─(1989,Santana_do_Agreste)
 │   ├e─(1985,Asa_Branca)
 │   │   ├e─(1984,Sucupira)
 │   │   └d─(1988,Sensilvania)
 │   └d─(1992,Remanso)
 │       └d─(1998,Santana_dos_Ferros)
 └d─(2007,Passaperto)
     ├e─(2005,Roseiral)
     └d─(2011,Preciosa)
Edição com maior quantidade de filmes apresentados: 1998
Exemplo de Entrada:
i 1992 Remanso 5
i 2011 Preciosa 12
i 2007 Passaperto 2
i 2002 Maramores 7
i 2005 Roseiral 3
i 1984 Sucupira 6
i 1989 Santana_do_Agreste 12
i 1998 Santana_dos_Ferros 15
i 1985 Asa_Branca 11
i 1988 Sensilvania 13
e
r 2005
r 1989
e
f
Exemplo de Saída:
(2002,Maramores)
 ├e─(1989,Santana_do_Agreste)
 │   ├e─(1985,Asa_Branca)
 │   │   ├e─(1984,Sucupira)
 │   │   └d─(1988,Sensilvania)
 │   └d─(1992,Remanso)
 │       └d─(1998,Santana_dos_Ferros)
 └d─(2007,Passaperto)
     ├e─(2005,Roseiral)
     └d─(2011,Preciosa)
(2002,Maramores)
 ├e─(1992,Remanso)
 │   ├e─(1985,Asa_Branca)
 │   │   ├e─(1984,Sucupira)
 │   │   └d─(1988,Sensilvania)
 │   └d─(1998,Santana_dos_Ferros)
 └d─(2007,Passaperto)
     └d─(2011,Preciosa)
Exemplo de Entrada:
i 1992 Remanso 5
i 2011 Preciosa 12
i 2007 Passaperto 2
i 2002 Maramores 7
i 2005 Roseiral 3
i 1984 Sucupira 6
i 1989 Santana_do_Agreste 12
i 1998 Santana_dos_Ferros 15
i 1985 Asa_Branca 11
i 1988 Sensilvania 13
e
b 1984
b 2000
l
r 1992
r 2002
e
f
Exemplo de Saída:
(2002,Maramores)
 ├e─(1989,Santana_do_Agreste)
 │   ├e─(1985,Asa_Branca)
 │   │   ├e─(1984,Sucupira)
 │   │   └d─(1988,Sensilvania)
 │   └d─(1992,Remanso)
 │       └d─(1998,Santana_dos_Ferros)
 └d─(2007,Passaperto)
     ├e─(2005,Roseiral)
     └d─(2011,Preciosa)
Elemento buscado: (1984,Sucupira,6)
Erro na busca: elemento não encontrado!
Edição com maior quantidade de filmes apresentados: 1998
(2005,Roseiral)
 ├e─(1989,Santana_do_Agreste)
 │   ├e─(1985,Asa_Branca)
 │   │   ├e─(1984,Sucupira)
 │   │   └d─(1988,Sensilvania)
 │   └d─(1998,Santana_dos_Ferros)
 └d─(2007,Passaperto)
     └d─(2011,Preciosa)
Observação
: para baixar o arquivo, clique com o botão direito do mouse, depois clique em "salvar link como" e escolha uma pasta do seu computador. Não tente abrir o código no navegador e copiar o texto. Isso resultará em mudança na codificação do texto de UTF-8 para ISO, deformando a saída formatada da árvore.
*/

#include <iostream>
using namespace std;

int main() {
    // Seu código aqui
    return 0;
}
