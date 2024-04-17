Considere as seguintes afirmativas:

I) Uma deque é uma estrutura de dados em que a remoção e inserção só são permitidas no início e no final da lista.

II) Em geral, as deques são implementadas como listas duplamente encadeadas, adicionando suporte para busca, percorrimento, bem como inserção e remoção em posições intermediárias.

III)  A inserção em deque vazia é utilizada tanto para inserção à esquerda ou à direita, desde que se constate que a estrutura não possui ainda elementos.

IV) A remoção do último elemento da deque será sempre a esquerda, isso se deve ao fato do ajustes dos ponteiros esq e dir para NULO, serem sempre realizados nesta sequencia.

É correto afirmar que:

Somente as afirmativas III e IV estão corretas.
Somente as afirmativas I e III estão corretas.
Somente as afirmativas I e II estão corretas.
Somente as afirmativas I, III e IV estão corretas.
Somente as afirmativas II e IV estão corretas.
Todas as afirmativas estão corretas.

Resposta: Somente as afirmativas I e III estão corretas.

---

Considerando os slides apresentados e as seguintes afirmativas sobre as operações em uma deque simplesmente encadeada:

I) A inserção em uma deque vazia se inicia com a criação de um elemento. A segunda etapa parte é a realizar o ajuste do apontador esquerdo da deque para que o mesmo aponte para o elemento. Finalizando, o mesmo ajuste é feito no apontador direito. 

II) A inserção à esquerda em uma deque com pelo menos um elemento se inicia com a criação de um elemento. A segunda etapa parte é a realizar o ajuste do apontador próximo do novo nó para o elemento que o ponteiro da esquerdo da deque está apontando. Para finalizar, é realizado o ajuste do apontador direito da deque para o novo elemento. 

III) A inserção à direita em uma deque com pelo menos um elemento se inicia com a criação de um elemento. A segunda etapa parte é a realizar o ajuste do apontador próximo do ponteiro da direita da deque está apontando para o novo nó. Para finalizar, é realizado o ajuste do apontador direito da deque para o novo elemento.

IV) A remoção à esquerda em uma deque com pelo menos dois elementos se inicia com a criação de um ponteiro auxiliar e fazer o seu apontamento para o elemento que o apontador esquerda da deque está apontando. Realiza-se a movimentação do  ponteiro esquerda da deque para o próximo elemento da estrutura. Por fim, remove-se o elemento que o apontador direita da deque estiver apontando.

V) A remoção à direita em uma deque com pelo menos dois elementos se inicia com a criação de um ponteiro auxiliar e fazer o seu apontamento para o elemento que o apontador esquerda da deque está apontando. O apontador faz o percorrimento da estrutura até o penúltimo elemento. Remove-se o elemento que o apontador direita da deque estiver apontando. Por fim, ajusta-se o apontamento do ponteiro direita da deque para o elemento que o ponteiro auxiliar estiver apontando.  
É correto afirmar que:

<!-- Somente as afirmativas I, II e  V estão corretas. -->
Somente as afirmativas I, III e IV estão corretas.
<!-- Somente as afirmativas II, IV e  V estão corretas. -->
Somente as afirmativas I, III e  V estão corretas.
<!-- Somente as afirmativas II, III e  V estão corretas. -->
<!-- Somente as afirmativas I, II e IV estão corretas. -->

Resposta: Somente as afirmativas I, III e  V estão corretas.

---

