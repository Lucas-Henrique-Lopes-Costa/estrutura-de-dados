Considere as seguintes afirmativas:

I) De um modo geral, existem quatro formas de tratar as colisões em tabelas hash: encadeamento, desencadeamento, endereçamento aberto e o endereçamento fechado.

II) No tratamento por encadeamento, se a função hash mapeia a chave de busca para uma posição já ocupada, o elemento a ser armazenado nesta posição utiliza uma lista encadeada, em que são armazenados os elementos que sofreram colisão para aquela chave.

III)  No tratamento por desencadeamento, cada posição na tabela pode ser entendido como um elemento que aponta para uma lista encadeada. Alternativamente, pode-se implementar a tabela hash como um vetor de listas encadeadas.

IV) No endereçamento aberto, se a função hash mapeia a chave de busca para uma posição já ocupada, procura-se a próxima posição livre para armazenar o novo elemento. Uma tabela nunca estará completamente preenchida - estudos mostram que com a ocupação acima de 75% o número de colisões é muito grande, o que descaracterizaria a ideia principal da estrutura.

V) No endereçamento fechado, no caso de uma busca, se uma chave k for mapeada para uma determinada posição, e o elemento buscado não for o desejado, procura-se nas posições subsequentes até que seja encontrado ou que uma posição vazia seja encontrada.

É correto afirmar que:

Somente as afirmativas II e IV estão corretas.
<!-- Somente as afirmativas I, II e IV estão corretas. -->
<!-- Todas as afirmativas estão corretas. -->
<!-- Somente as afirmativas I, III e V estão corretas. -->
Somente as afirmativas III e V estão corretas.

Resposta: Somente as afirmativas II e IV estão corretas.

---

Considere as seguintes afirmativas sobre tabelas hash:

I) Em uma tabela hash utilizando encadeamento, a inserção dos elementos que geraram colisão sempre será feita no final da lista.

II) Com tratamento de colisão por encadeamento a remoção de um elemento é simples, uma vez que é uma remoção em lista.

III) Com endereçamento aberto, o esforço é relativamente maior, seja por realocação dos dados ou colocar um marcador.

IV) De um modo geral, o tratamento de colisões por endereçamento aberto é sugerido para circunstâncias com muitas inserções e remoções.


É correto afirmar que:
Somente as afirmativas III e IV estão corretas.
Somente as afirmativas II e III estão corretas.
Todas as afirmativas estão corretas.
Somente as afirmativas I e IV estão corretas.
Somente as afirmativas I e III estão corretas.
Somente as afirmativas II, III e IV estão corretas.

Resposta: Somente as afirmativas II e III estão corretas.
