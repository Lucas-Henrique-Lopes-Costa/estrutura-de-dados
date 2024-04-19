Considere as seguintes afirmativas:

I) Em geral, vetores expansíveis são implementados como uma lista em que seus elementos são vetores menores.

II) Em implementações mais simples de vetores expansíveis, os pedaços (packets) costumam ter o mesmo tamanho. Esse tamanho é definido geralmente como atributo do vetor ou valor constante. Cada pedaço contém, além do vetor de dados, um ponteiro para o próximo pedaço.

III)  Quando da inserção de um elemento em vetores expansíveis, caso o pedaço esteja cheio, é alocado um novo pedaço para a tarefa. Pedaços vazios, após remoção do último elemento, são simplesmente desalocados da memória com ajustes dos ponteiros dos pedaços vizinhos.

IV) Algumas implementações de vetores expansíveis possuem pedaços de tamanho variável, atendendo a demandas específicas de redimensionamento. Nesse caso, cada pedaço possui, além dos dados e ponteiros, um atributo para armazenar a capacidade de toda estrutura.

V)Apesar que conceitualmente não há restrição quanto ao tipo de objeto armazenados, a menos que o problema não precise de remoção, os dados não precisam estar ordenados. Com a ordenação dos dados, a remoção torna inviável ou ineficiente o uso do vetor expansível.

É correto afirmar que:

Somente as afirmativas II, III e IV estão corretas.
<!-- Somente as afirmativas I, III e IV estão corretas. -->
Somente as afirmativas I, II e III estão corretas.
<!-- Somente as afirmativas I, III e IV estão corretas. -->
<!-- Todas as afirmativas estão corretas. -->
Somente as afirmativas I, II e V estão corretas.

Resposta: Somente as afirmativas I, II e III estão corretas.

---

Considere as seguintes afirmativas sobre vetores expansíveis:

I) A melhor técnica e mais simples de tratar um pacote cheio é empurrar um dado para o próximo pacote. Isso vai dar mais  eficiência à estrutura, que irá funcionar de forma superior a um vetor normal. A única implicação neste técnica é que a estrutura pode ter vários pacotes que não estão completos. 

II) Se os pacotes não estão cheios, isso tem dois impactos para o vetor expansível: primeiro, cada pacote terá que controlar quantos elementos são válidos. Segundo, só será possível acessar o vetor expansível como um todo por posição. Isso é possível se for considerado  uma implementação de lista encadeada em cada packet.

III) Quando a inserção é entre elementos de um pacote, o ajuste dos elementos é feito dentro do pacote. Quando o dado a ser inserido poderia ser armazenado em um pacote, no próximo ou anterior, por regra, é sempre feito no pacote mais próximo do inicio do vetor expansível. Isso decorre do fato de que avaliar em qual pacote inserir o elemento irá gerar grandes impactos computacionais, torando inviável mensurar tal métrica. 


É correto afirmar que:
<!-- Somente as afirmativas I e II estão corretas. -->
Todas as afirmativas estão incorretas.
<!-- Somente as afirmativas I e III estão corretas. -->
Somente as afirmativas II e III estão corretas.
<!-- Todas as afirmativas estão corretas. -->

Resposta: 

---

