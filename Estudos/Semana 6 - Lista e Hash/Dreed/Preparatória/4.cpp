/*
Questão 4: Hash com endereçamento aberto - Lista de processos em uma repartição pública
Implemente uma tabela hash, utilizando tratamento de colisão por endereçamento aberto, para implementar uma lista de processos para uma repartição pública, utilizando como base o
código fornecido
. A estrutura deve possibilitar, pelo menos, as seguintes ações: inserção e remoção de um determinado item, localização de um processo na estrutura hash. A remoção ou busca deve escrever mensagem de erro na saída ("
Erro: hash vazia!
"), quando a hash estiver vazia. Na remoção ou na busca, caso a hash contenha elementos mas o item da busca não se encontra na tabela, o usuário deve ser informado da seguinte forma: ("
Elemento inexistente!
"). O enfileiramento também deve gerar mensagem de erro ("
Erro: hash cheia!
"), quanto todas as posições do vetor estiverem ocupadas. Os itens da lista de processos possuem os seguintes atributos: assunto (uma string sem espaços), nome do interessado(uma string sem espaços), tipo (um único caracter) e numero do processo (um inteiro). Além disso, essa repartição tem capacidade para trabalhar com
apenas seis processos por vez
.
Entradas:
O programa deve aceitar os seguintes comandos:
i seguido de uma string, um caracter e um inteiro: para inserir um item na lista de processos
r seguido de um inteiro: para retirar um item da lista de processos
l seguido de um inteiro: para localizar um item na hash
f: para finalizar a execução do programa
Saídas:
Todas as saídas de comandos já estão implementadas na função principal desse código exemplo fornecido. Ao terminar a execução do programa, todos os itens da hash são escritos.
Exemplo de Entrada e Saída juntas:
r Joao
Impossível remover de hash vazia.
i processo1 Joao a 2
i processo2 Maria c 5
i processo3 Severino d 9
i processo4 Marcos f 12
i processo5 Barnabe a 10
i processo6 Tiao z 22
i processo7 Marlon a 40
Tabela hash cheia.
p
[0:Severino/9] [1:Barnabe/10] [2:Marcos/12] [3:Tiao/22] [4:Joao/2] [5:Maria/5] 
r Severino
p
[0:] [1:Barnabe/10] [2:Marcos/12] [3:Tiao/22] [4:Joao/2] [5:Maria/5] 
i processo7 Marlon a 40
f
[0:Marlon/40] [1:Barnabe/10] [2:Marcos/12] [3:Tiao/22] [4:Joao/2] [5:Maria/5]
*/

#include <iostream>
using namespace std;

int main() {
    // Seu código aqui
    return 0;
}
