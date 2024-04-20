Considere as seguintes afirmativas:

I) A implementação de tabela hash com encadeamento utiliza geralmente um vetor de listas. A lista pode ser implícita ou explícita.

II) Os elementos usualmente constituem um par (chave, valor). Dada uma chave, a intenção é recuperar o valor armazenado anteriormente associado a esta chave. Cada elemento é um nó em uma das listas no vetor de listas.

III) No construtor de uma tabela hash com encadeamento é necessário definir o tamanho da tabela e alocar espaço para a mesmo. No destrutor, somente existe a necessidade de desalocar o espaço previamente endereçado para a tabela.

IV) Para realizar a  inserção de um elemento em uma tabela hash com encadeamento é necessário, primeiramente, encontrar a chave de acordo com a posição fornecida. A posição indicada é acessada, e é feita a busca pelo elemento na lista. Caso o elemento não esteja na lista, o mesmo é inserido. Caso contrário, mostra-se uma mensagem de erro. Esta inserção é para uma tabela que não permite elementos repetidos.

V) Para realizar a remoção de um elemento em uma tabela hash com encadeamento é necessário, primeiramente, encontrar a posição de acordo com a chave fornecida. A posição indicada é acessada, e é feita a busca pelo elemento na lista. Caso o elemento não seja encontrado, mostra-se uma mensagem de erro. Caso contrário, o elemento é removido da lista.  Esta remoção é para uma tabela que não permite elementos repetidos.

É correto afirmar que:

<!-- Somente as afirmativas II, III, IV e V estão corretas. -->
<!-- Somente as afirmativas I, II e III  estão corretas. -->
<!-- Somente as afirmativas III, IV e V estão corretas. -->
Somente as afirmativas I, II, III e IV estão corretas.
Somente as afirmativas I, II, IV e V estão corretas.
<!-- Todas as afirmativas estão corretas. -->

Reposta: Somente as afirmativas I, II, IV e V estão corretas.

---

Considere as seguintes afirmativas sobre vetores expansíveis:

I)  A implementação de tabela hash com endereçamento aberto utiliza geralmente um vetor de dados. Isso é válido principalmente se os valores armazenados são inteiros positivos, facilitando a marcação de dados inválidos ou removidos. Os elementos geralmente constituem um par (chave, valor). Dada uma chave, a intenção é recuperar o valor armazenado anteriormente associado a esta chave.

II)  Na criação da tabela hash com endereçamento aberto é necessário determinar a capacidade e o tamanho da tabela.  Criar a tabela de acordo com a capacidade. Para cada posição da tabela existe a necessidade de marcação de posição inválida. O destrutor apenas desaloca o espaço previamente alocado para a tabela.

III) Na inserção de uma tabela hash com endereçamento aberto é necessário, primeiramente, encontrar a posição de acordo com a chave fornecida. Enquanto a posição for diferente dos marcadores inválido e removido, é feita a procura por uma posição de acordo com essa diretiva (posicao ← (posicao + 1) % capacidade). Ao final insere-se o elemento e aumenta-se o tamanho em uma unidade.

IV) Para realizar a remoção de um elemento em uma tabela hash com endereçamento aberto é necessário, primeiramente, encontrar a posição de acordo com a chave fornecida. Ajustar a posição com o marcador de removido e subtrair o tamanho em um elemento.


É correto afirmar que:
Somente as afirmativas III e IV estão corretas.
Somente as afirmativas I e II estão corretas.
Somente as afirmativas II e III estão corretas.
<!-- Todas as afirmativas estão corretas. -->
Somente as afirmativas I e IV estão corretas.
Somente as afirmativas II e IV estão corretas.

Resposta: Somente as afirmativas I e II estão corretas.

---

