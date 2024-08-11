/*
Questão 6: Estrutura de dados AVL recursiva  - Biblioteca
Uma biblioteca comunitária decidiu reorganizar seus livros e renovar seu sistema de consulta, facilitando a busca por títulos. Para isso, cada livro será registrado com seu nome, localização e quantidade de itens disponíveis para empréstimo. A cada empréstimo ou devolução, a quantidade de itens disponíveis para empréstimo é atualizada.  Utilizando o
código fornecido
, implemente um árvore AVL com as funções de inserir e remover elementos. A idea principal do problema é que implementação da remoção seja utilizando recursão, não sendo necessário o uso da função transplanta. A estratégia de remoção de elementos que não estejam em nohs folhas é a substituição pelo elemento posterior (sucessor).
O código fornecido já tem o menu de entrada e o método de impressão.
Não
altere essas funções. O caminho mais fácil para a solução do exercício é não alterar a assinaturas das funções, dessa forma, não resultará em conflito com o código fornecido. 
O dado a ser armazenado na árvore é composto por uma
chave
do tipo
inteiro
, o
nome do livro
do tipo
string
, a
localização
do tipo
string
e a
quantidade de itens
disponíveis do tipo
inteiro
. Não existem livros diferentes com a mesma chave.
Entradas:
i - para
inserir
elemento : deve ler chave [inteiro] , nome do livro [string], localização [string] e quantidade disponível [inteiro]
r - para
remover
elemento : deve ler chave [inteiro]
b - para
buscar
elemento : deve ler chave [inteiro]
l - para fazer o
levantamento
de livros em uma dada localização: deve ler uma string
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
b - buscar elemento : A operação de busca escreve a frase: "Elemento buscado: ([chave],[nome],[local],[quantidade])", em que [chave], [nome], [local] e [quantidade] devem ser substituídos pela respectiva chave, nome do livro, localização e quantidade disponível."
l - levantamento por localização: Imprime: "Levantamento do local [local]: [quantidade]", em que [local] é o local pesquisado e [quantidade] é a quantidade de elementos na dada localização.
e - imprimir árvore : imprime a árvore seguindo o padrão de formatação tree
f - finalizar : finaliza o programa
Exemplo de Entrada:
i 5 Memorias_Postumas_de_Bras_Cubas C6E01 3
i 7 Capitaes_de_Areia C4E02 5 
i 9 Luciola C6E05 2
i 6 Dom_Casmurro C3E01 4
i 11 Quincas_Borba C3E01 3
i 42 O_Guia_do_Mochileiro_das_Galaxias C7E42 10
i 43 O_Restaurante_no_Fim_do_Universo C7E42 8
i 44 A_Vida_o_Universo_e_Tudo_Mais C7E42 7
i 45 Ate_mais_e_Obrigado_pelos_Peixes C7E42 6
i 46 Praticamente_Inofensiva C7E42 6
e
l C7E42
l C3E01
f
Exemplo de Saída:
(7,Capitaes_de_Areia)
 ├e─(5,Memorias_Postumas_de_Bras_Cubas)
 │   └d─(6,Dom_Casmurro)
 └d─(43,O_Restaurante_no_Fim_do_Universo)
     ├e─(11,Quincas_Borba)
     │   ├e─(9,Luciola)
     │   └d─(42,O_Guia_do_Mochileiro_das_Galaxias)
     └d─(45,Ate_mais_e_Obrigado_pelos_Peixes)
         ├e─(44,A_Vida_o_Universo_e_Tudo_Mais)
         └d─(46,Praticamente_Inofensiva)
Levantamento do local C7E42: 37
Levantamento do local C3E01: 7
Exemplo de Entrada 2:
i 5 Memorias_Postumas_de_Bras_Cubas C6E01 3
i 7 Capitaes_de_Areia C4E02 5 
i 9 Luciola C6E05 2
i 6 Dom_Casmurro C3E01 4
i 14 Pedro_e_o_Lobo C6E05 8
l C6E05
b 9
r 9
r 9
b 9
e
f
Exemplo de Saída 2:
Levantamento do local C6E05: 10
Elemento buscado: (9,Luciola,C6E05,2)
Erro na remoção: chave não encontrada!
Erro na busca: elemento não encontrado!
(7,Capitaes_de_Areia)
 ├e─(5,Memorias_Postumas_de_Bras_Cubas)
 │   └d─(6,Dom_Casmurro)
 └d─(14,Pedro_e_o_Lobo)
Observação
: para baixar o arquivo, clique com o botão direito do mouse, depois clique em "salvar link como" e escolha uma pasta do seu computador. Não tente abrir o código no navegador e copiar o texto. Isso resultará em mudança na codificação do texto de UTF-8 para ISO, deformando a saída formatada da árvore.
*/

#include <iostream>
using namespace std;

int main() {
    // Seu código aqui
    return 0;
}
