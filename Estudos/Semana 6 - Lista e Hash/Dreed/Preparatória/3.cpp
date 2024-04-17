/*
Questão 3: Hash com encadeamento - Inventário de itens de jogo
Implemente uma tabela hash, utilizando tratamento de colisão por encadeamento de nós, para implementar um inventário de itens em um jogo digital. A estrutura deve possibilitar, pelo menos, as seguintes ações: inserção e remoção de itens, localizar um item na estrutura hash. A remoção e busca devem escrever mensagem de erro na saída ("
Erro: hash vazia!
"), quando a hash estiver vazia. Na remoção ou na busca, caso a hash contenha elementos mas o item da busca não se encontra na tabela, o usuário deve ser informado da seguinte forma: ("
Elemento inexistente!
") . Os itens do inventários possuem os seguintes atributos: nome (uma string sem espaços), tipo (um único caracter) e valor (um inteiro).
Para essa atividade você pode utilizar as seguintes opções de código fonte base:
código fornecido 1
ou
código fornecido2
.
No início da execução, o programa lê o tamanho da tabela hash.
Entradas:
O programa deve aceitar os seguintes comandos:
i: seguido de uma string, um caracter e um inteiro: para inserir um item no inventário. Caso exista colisão, a inserção na lista deve ser no ínicio.
r seguido de um string: para retirar um item do inventário
l seguido de um string: para localizar o determinado item no inventário
p: imprimir toda a tabela hash
f: para finalizar a execução do programa
Saídas:
Todas as saídas de comandos já estão implementadas na função principal dos códigos fontes informados anteriormente. Ao terminar a execução do programa, todos os itens da hash são  escritos.
Exemplo de Entrada e Saída juntas:
6
r dez
Erro na remoção: chave não encontrada!
i um a 1
chave 'um' inserida na posicao 4
i dois b 2
chave 'dois' inserida na posicao 5
i quatro d 4
chave 'quatro' inserida na posicao 2
i sete g 7
chave 'sete' inserida na posicao 1
i oito h 8
chave 'oito' inserida na posicao 5
i dez j 10
chave 'dez' inserida na posicao 5
i tres c 3
chave 'tres' inserida na posicao 2
p
0: 
1: [sete/7]
2: [tres/3][quatro/4]
3: 
4: [um/1]
5: [dez/10][oito/8][dois/2]
l quatro
Tipo: d Valor: 4
r dez
f
0: 
1: [sete/7]
2: [tres/3][quatro/4]
3: 
4: [um/1]
5: [oito/8][dois/2]
*/

#include <iostream>
using namespace std;

int main() {
    // Seu código aqui
    return 0;
}
