/*
Questão 5: Estrutura de dados AVL recursiva - ONG de Adoção de Animais
Uma ONG para adoção de animais resolveu catalogar os animais sob seu cuidado. Para isso, cada animal será registrado com seu nome, espécie e raça.  Utilizando o
código fornecido
, implemente um árvore AVL com as funções de inserir e remover elementos. A ideia principal do problema é que implementação da remoção seja utilizando recursão, não sendo necessário o uso da função transplanta. A estratégia de remoção de elementos que não estejam em nós folhas é a substituição pelo elemento posterior (sucessor).
O código fornecido já tem o menu de entrada e o método de impressão.
Não
altere essas funções. O caminho mais fácil para a solução do exercício é não alterar a assinaturas das funções, dessa forma, não resultará em conflito com o código fornecido. 
O dado a ser armazenado na árvore é composto por uma
chave
do tipo
inteiro
, o
nome do animal
do tipo
string
, a
espécie (gato, cachorro, etc.) do animal
do tipo
string
,
raça (pequinês, vira-lata, etc.) do animal
do tipo
string
.
Entradas:
i - para
inserir
elemento : deve ler chave [inteiro] , nome do animal [string], espécie [string], raça [string]
r - para
remover
elemento : deve ler chave [inteiro]
b - para
buscar
elemento : deve ler chave [inteiro]
l - para fazer o
levantamento
de quantidade de animais de uma dada espécie e raça: deve ler duas strings (espécie e raça)
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
b - buscar elemento : A operação de busca escreve a frase: "Elemento buscado: ([chave],[nome],[espécie],[raça])", em que [chave], [nome], [espécie] e [raça] devem ser substituídos pela respectiva chave, nome do animal, sua espécie e raça
l - levantamento por localização: Imprime: "Levantamento de animais: [quantidade]", em que [quantidade] é número de animais de uma dada espécie e raça.
e - imprimir árvore : imprime a árvore seguindo o padrão de formatação tree
f - finalizar : finaliza o programa
Exemplo de Entrada:
i 5 doguo cao viralata
i 10 mieco gato persa
i 15 tanin gato persa
i 3 xicao cao viralata
i 2 pepe cao pequines
i 1 popo cao pequines
i 200 drum cao fila
i 201 bitao cao viralata
i 399 bigorna cao pequines
i 12 baran gato viralata
i 31 xaxau gato persa
i 32 xupita cao pequines
e
l cao pequines
l cao russo
l gato persa
f
Exemplo de Saída:
(10,mieco)
 ├e─(3,xicao)
 │   ├e─(2,pepe)
 │   │   └e─(1,popo)
 │   └d─(5,doguo)
 └d─(200,drum)
     ├e─(15,tanin)
     │   ├e─(12,baran)
     │   └d─(31,xaxau)
     │       └d─(32,xupita)
     └d─(201,bitao)
         └d─(399,bigorna)
Levantamento de animais: 4
Levantamento de animais: 0
Levantamento de animais: 3
Exemplo de Entrada 2:
i 5 doguo cao viralata
i 10 mieco gato persa
i 15 tanin gato persa
i 3 xicao cao viralata
i 2 pepe cao pequines
i 1 popo cao pequines
i 200 drum cao fila
i 201 bitao cao viralata
i 399 bigorna cao pequines
i 12 baran gato viralata
i 31 xaxau gato persa
i 32 xupita cao pequines
e
r 1 
r 2 
r 10
i 1 popo cao fila
i 2 pepe cao russo
i 10 mieco gato siames
e
l cao pequines
l cao russo
l gato persa
f
Exemplo de Saída 2:
(10,mieco)
 ├e─(3,xicao)
 │   ├e─(2,pepe)
 │   │   └e─(1,popo)
 │   └d─(5,doguo)
 └d─(200,drum)
     ├e─(15,tanin)
     │   ├e─(12,baran)
     │   └d─(31,xaxau)
     │       └d─(32,xupita)
     └d─(201,bitao)
         └d─(399,bigorna)
(15,tanin)
 ├e─(5,doguo)
 │   ├e─(2,pepe)
 │   │   ├e─(1,popo)
 │   │   └d─(3,xicao)
 │   └d─(12,baran)
 │       └e─(10,mieco)
 └d─(200,drum)
     ├e─(31,xaxau)
     │   └d─(32,xupita)
     └d─(201,bitao)
         └d─(399,bigorna)
Levantamento de animais: 2
Levantamento de animais: 1
Levantamento de animais: 2
Observação
: para baixar o arquivo, clique com o botão direito do mouse, depois clique em "salvar link como" e escolha uma pasta do seu computador. Não tente abrir o código no navegador e copiar o texto. Isso resultará em mudança na codificação do texto de UTF-8 para ISO, deformando a saída formatada da árvore.
*/

#include <iostream>
using namespace std;

int main() {
    // Seu código aqui
    return 0;
}
