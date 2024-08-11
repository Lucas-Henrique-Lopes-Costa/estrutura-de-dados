/*
Questão 3: Estrutura de dados AVL recursiva - Encontro de Motociclistas
A Associação Duas Rodas está organizando um encontro de motociclistas.  Os responsáveis pelo encontro decidiram fazer uma série de levantamentos de dados para, a partir disso, organizar um encontro memorável. Assim eles, irão cadastrar todas as motocicletas que participarão do evento, armazenando para isso o modelo da motocicleta, sua marca e o ano de fabricação.  Utilizando o
código fornecido
implemente um árvore AVL com as funções de inserir e remover elementos. A ideia principal do problema é que implementação da remoção seja utilizando recursão, não sendo necessário o uso da função transplanta. A estratégia de remoção de elementos que não estejam em nós folhas é a substituição pelo elemento posterior (sucessor). Além das funções tradicionais, eles irão também implementar um método para levantamento da quantidade de motocicletas de uma dada marca que tenham sido fabricadas após um determinado ano.
O código fornecido já tem o menu de entrada e o método de impressão.
Não
altere essas funções. O caminho mais fácil para a solução do exercício é não alterar a assinaturas das funções, dessa forma, não resultará em conflito com o código fornecido. 
O dado a ser armazenado na árvore é composto por uma
chave
do tipo
inteiro
, o
modelo da motocicleta
do tipo
string
, a
marca da motocicleta
do tipo
string
e o
ano de fabricação
do tipo
inteiro
. Não existem duas motocicletas com mesma chave no sistema.
Entradas:
i - para
inserir
elemento : deve ler chave [inteiro] , modelo da motocicleta [string], marca da motocicleta [string]  e o ano de fabricação[inteiro]
r - para
remover
elemento : deve ler chave [inteiro]
b - para
buscar
elemento : deve ler chave [inteiro]
l - para fazer o
levantamento
da quantidade de motocicletas de uma mesma marca fabricadas a partir de um dado ano
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
b - buscar elemento : A operação de busca escreve a frase: "Elemento buscado:  ([modelo],[marca],[ano])", em que [modelo], [marca] e [ano] devem ser substituídos pelo respectivo modelo, marca e ano de fabricação da motocicleta
l - levantamento por ano: Imprime: "Levantamento da [marca]: [quantidade]", em que [marca]  é a marca de motocicleta informada para busca e [quantidade] e o número de motocicletas fabricadas a partir do ano (também informado para o levantamento)
e - imprimir árvore : imprime a árvore seguindo o padrão de formatação tree
f - finalizar : finaliza o programa
Exemplo de Entrada:
i 80 PBR Arruela 1998
i 3 YBR IrNaMarra 1980
i 5 TXT Ronda 1990
i 9 ZTX Rarledavisson 1993
i 11 SZK Suzuki 1998
i 160 PBZ Arruela 2002
i 15 BZB Bizon 2001
e
l IrNaMarra 1970
i 8 YBZ IrNaMarra 1990
i 22 YBW IrNaMarra 1995
l IrNaMarra 1990
l IrNaMarra 1970
e
f
Exemplo de Saída:
(11,SZK)
 ├e─(5,TXT)
 │   ├e─(3,YBR)
 │   └d─(9,ZTX)
 └d─(80,PBR)
     ├e─(15,BZB)
     └d─(160,PBZ)
Levantamento da marca IrNaMarra: 1
Levantamento da marca IrNaMarra: 2
Levantamento da marca IrNaMarra: 3
(11,SZK)
 ├e─(5,TXT)
 │   ├e─(3,YBR)
 │   └d─(9,ZTX)
 │       └e─(8,YBZ)
 └d─(80,PBR)
     ├e─(15,BZB)
     │   └d─(22,YBW)
     └d─(160,PBZ)
Exemplo de Entrada:
i 80 PBR Arruela 1998
i 3 YBR IrNaMarra 1980
i 5 TXT Ronda 1990
i 9 ZTX Rarledavisson 1993
i 11 SZK Suzuki 1998
i 160 PBZ Arruela 2002
i 15 BZB Bizon 2001
i 8 YBZ IrNaMarra 1990
i 22 YBW IrNaMarra 1995
e
r 3
r 80
r 11
e
l IrNaMarra 1990
l IrNaMarra 1970
f
Exemplo de Saída:
(11,SZK)
 ├e─(5,TXT)
 │   ├e─(3,YBR)
 │   └d─(9,ZTX)
 │       └e─(8,YBZ)
 └d─(80,PBR)
     ├e─(15,BZB)
     │   └d─(22,YBW)
     └d─(160,PBZ)
(15,BZB)
 ├e─(8,YBZ)
 │   ├e─(5,TXT)
 │   └d─(9,ZTX)
 └d─(22,YBW)
     └d─(160,PBZ)
Levantamento da marca IrNaMarra: 2
Levantamento da marca IrNaMarra: 2
Exemplo de Entrada:
i 80 PBR Arruela 1998
i 3 YBR IrNaMarra 1980
i 5 TXT Ronda 1990
i 9 ZTX Rarledavisson 1993
i 11 SZK Suzuki 1998
i 160 PBZ Arruela 2002
i 15 BZB Bizon 2001
i 8 YBZ IrNaMarra 1990
i 22 YBW IrNaMarra 1995
e
r 3
r 80
r 11
b 11
i 11 SZZ Suzuki 1998
i 80 PBRt Arruela 1998
i 3 YBRX IrNaMarra 1980
e
b 11
f
Exemplo de Saída:
(11,SZK)
 ├e─(5,TXT)
 │   ├e─(3,YBR)
 │   └d─(9,ZTX)
 │       └e─(8,YBZ)
 └d─(80,PBR)
     ├e─(15,BZB)
     │   └d─(22,YBW)
     └d─(160,PBZ)
Erro na busca: elemento não encontrado!
(15,BZB)
 ├e─(8,YBZ)
 │   ├e─(5,TXT)
 │   │   └e─(3,YBRX)
 │   └d─(9,ZTX)
 │       └d─(11,SZZ)
 └d─(80,PBRt)
     ├e─(22,YBW)
     └d─(160,PBZ)
Elemento buscado: (11,SZZ,Suzuki,1998)
Observação
: para baixar o arquivo, clique com o botão direito do mouse, depois clique em "salvar link como" e escolha uma pasta do seu computador. Não tente abrir o código no navegador e copiar o texto. Isso resultará em mudança na codificação do texto de UTF-8 para ISO, deformando a saída formatada da árvore.
*/

#include <iostream>
using namespace std;

int main() {
    // Seu código aqui
    return 0;
}
