/*
Questão 7: Estrutura de dados AVL recursiva  - PeguePague
Um estabelecimento comercial decidiu disponibilizar diversos pontos de consulta para que os próprios clientes consultem a disponibilidade de um produto, sirvam-se da quantidade desejada e dirijam-se ao caixa para o pagamento. Para que essa estratégia seja bem sucedida, ele o contratou para desenvolver o sistema de busca ao produtos, e, para maior eficiência, você optou pelo uso de uma árvore binária de busca balanceada - AVL.
Utilizando o
código fornecido
implemente um árvore AVL com as funções de inserir e remover elementos. A ideia principal do problema é que implementação da remoção seja utilizando recursão, não sendo necessário o uso da função transplanta. A estratégia de remoção de elementos que não estejam em nós folhas é a substituição pelo elemento posterior (sucessor).
O código fornecido já tem o menu de entrada e o método de impressão.
Não
altere essas funções. O caminho mais fácil para a solução do exercício é não alterar a assinaturas das funções, dessa forma, não resultará em conflito com o código fornecido. 
O dado a ser armazenado na árvore é composto por uma
chave
do tipo
inteiro
, o
nome do produto
do tipo
string
, a
marca do produto
do tipo
string
e a
quantidade disponível
do tipo
inteiro
.
Entradas:
i - para
inserir
elemento : deve ler chave [inteiro] , nome do produto [string], marca [string] e quantidade disponível [inteiro]
r - para
remover
elemento : deve ler chave [inteiro]
b - para
buscar
elemento : deve ler chave [inteiro]
l - para fazer o
levantamento
da quantidade de produtos de uma dada marca: deve ler uma string
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
b - buscar elemento : A operação de busca escreve a frase: "Elemento buscado: ([chave],[nome],[marca],[quantidade])", em que [chave], [nome], [local] e [quantidade] devem ser substituídos pela respectiva chave, nome do produto, marca e quantidade disponível."
l - levantamento por marca: Imprime: "Levantamento da marca [marca]: [quantidade]", em que [marca] é a marca pesquisada e [quantidade] é a quantidade de produtos dessa marca.
e - imprimir árvore : imprime a árvore seguindo o padrão de formatação tree
f - finalizar : finaliza o programa
Exemplo de Entrada:
i 100 chocolate SrCacau 30
i 187 sal MarSalgado 15 
i 210 sorvete LeiGelato 28
i 130 biscoito CreckCrack 111
i 304 azeite MarSalgado 21
i 214 capuccino SrCacau 12
i 402 sardinha MarSalgado 21
l MarSalgado
l SrCacau
e
f
Exemplo de Saída:
Levantamento da marca MarSalgado: 57
Levantamento da marca SrCacau: 42
(187,sal)
 ├e─(100,chocolate)
 │   └d─(130,biscoito)
 └d─(214,capuccino)
     ├e─(210,sorvete)
     └d─(304,azeite)
         └d─(402,sardinha)
Exemplo de Entrada 2:
i 100 chocolate SrCacau 30
i 187 sal MarSalgado 15 
i 210 sorvete LeiGelato 28
i 130 biscoito CreckCrack 111
i 187 sal MarSalgado 15 
i 304 azeite MarSalgado 21
i 214 capuccino SrCacau 12
i 402 sardinha MarSalgado 21
i 87 pacoquinha DaDinda 13
i 55 azeitonas Filistao 24
i 13 macarrao Filistao 12
i 803 lasanha Filistao 21
i 255 mocaccinho SrCacau 13
b 210
r 210
r 210
b 210
l SrCacau
l Filistao
e
f
Exemplo de Saída 2:
Erro na inserção: chave já existente!
Elemento buscado: (210,sorvete,LeiGelato,28)
Erro na remoção: chave não encontrada!
Erro na busca: elemento não encontrado!
Levantamento da marca SrCacau: 55
Levantamento da marca Filistao: 57
(187,sal)
 ├e─(100,chocolate)
 │   ├e─(55,azeitonas)
 │   │   ├e─(13,macarrao)
 │   │   └d─(87,pacoquinha)
 │   └d─(130,biscoito)
 └d─(304,azeite)
     ├e─(214,capuccino)
     │   └d─(255,mocaccinho)
     └d─(402,sardinha)
         └d─(803,lasanha)
Observação
: para baixar o arquivo, clique com o botão direito do mouse, depois clique em "salvar link como" e escolha uma pasta do seu computador. Não tente abrir o código no navegador e copiar o texto. Isso resultará em mudança na codificação do texto de UTF-8 para ISO, deformando a saída formatada da árvore.
*/

#include <iostream>
using namespace std;

int main() {
    // Seu código aqui
    return 0;
}
