Considere as seguintes afirmativas:

I) Um Sequence Set é um arquivo binário que encontra-se dividido em pedaços de tamanhos iguais, cada uma contendo uma sequência de registros ordenados.

II) Cada pedaço do Sequence Set está ordenado em relação aos outros pedaços. Dessa forma, os registros de um Sequence Set A possuem chaves que são sempre maiores que um Sequence Set B. Além disso, cada pedaço indica o próximo pedaço, aquele com os registros com chaves na sequência.

III)  Um cabeçalho de um Sequence Set costuma possuir as seguintes informações: número de pedaços que ele possui e qual a posição relativa do primeiro pedaço.

IV) Cada pedaço de um Sequence Set possui os dados ordenados. O cabeçalho do arquivo indica o primeiro pedaço e qual a posição do primeiro pedaço disponível. Em cada pedaço, um cabeçalho local aponta a próxima sequência e informa o número de registros válidos. Essas informações são necessárias para manter o Sequence Set otimizado após alterações

V) A solução para a inserção de um novo elemento em um pedaço cheio é  criação de um novo pedaço (no final do arquivo) inicialmente vazio para dividir o Sequence Set cheio. A divisão é feita com a inserção em memória e dividindo a sequência na metade.

É correto afirmar que:

<!-- Somente as afirmativas II, III, IV e V estão corretas. -->
<!-- Somente as afirmativas I, II e V estão corretas. -->
Somente as afirmativas I, II, III e IV estão corretas.
<!-- Todas as afirmativas estão corretas. -->
Somente as afirmativas I, III e IV estão corretas.
Somente as afirmativas I, III, IV e V estão corretas.

Resposta: Somente as afirmativas I, III, IV e V estão corretas.

---

Considere as seguintes afirmativas sobre vetores expansíveis:

I) Quando se remove o último elemento de uma sequência em um Sequence Set, o pedaço é removido! 

II) Implementações mais eficientes de sequence sets utilizam a ideia de não permitir que cada pedaço possua menos que um número mínimo de elementos (em geral, a metade). Nesse caso, quando um pedaço fica com menos que a metade, tenta-se emprestar um elemento do pedaço anterior ou posterior. Caso não seja possível o empréstimo (pelo fato que ambos estão com o número mínimo de elemento), une-se então o pedaço atual com um desses pedaços.

III) O uso de Sequence Sets otimiza a manipulação de dados em arquivos binários com vários registros. Pode ocorrer de, com o passar do tempo, os pedaços ficarem muito subutilizados… No nosso exemplo, o pedaço 0 não irá receber novos valores,... Nesse caso, pode-se reconstruir o Sequence Set, unificando pedaços menores em pedaços maiores.

IV) Outra abordagem para diminuir a existência de espaços subutilizados é estabelecer um limite máximo de ocupação de cada pedaço, desmembrando dois pedaços subsequentes. Sequence sets tem seu uso potencializado por meio de índices, como em árvores B+.




É correto afirmar que:
<!-- Somente as afirmativas II e IV estão corretas. -->
Somente as afirmativas I e III estão corretas.
Somente as afirmativas II e III estão corretas.
<!-- Todas as afirmativas estão corretas. -->
<!-- Somente as afirmativas I e II estão corretas. -->
<!-- Somente as afirmativas I e IV estão corretas. -->

Reposta: Somente as afirmativas II e III estão corretas.
