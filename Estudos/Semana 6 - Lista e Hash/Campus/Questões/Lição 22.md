Considere as seguintes afirmativas sobre lista encadeada:

I)Uma lista, em geral, costuma disponibilizar uma série de métodos similares aos existentes em um vetor, como o percorrimento dos dados, por exemplo. Por outro lado, existem métodos que, mesmo quando são disponibilizados, devem ser evitados, como o acesso direto a uma posição. Em um vetor isso é feito sem custo, em uma lista, é necessário percorrer os nós anteriores.

II) O construtor de uma lista deve realizar os apontamentos, início e fim (caso exista) da lista, para nulo. E, caso exista, a variável tamanho, ajustá-la.

III) Para realizar a inserção em uma lista vazia deve-se criar o nó, realizar os apontamentos para o nó criado e, caso exista, a variável tamanho, ajustá-la.

IV) Um método para inserção em lista vazia ou não é implementado ou é inserido como método auxiliar, não invocado pelo usuário. Em geral, se utilizam métodos mais gerais, como inserir no início, no fim ou em posição específica.

V) Para realizar a inserção no início de uma lista deve-se criar o nó e realizar o apontamento do nó criado para o início da lista. Em seguida, o apontamento do início da lista deve ser atualizado (passa a appontar para o novo nó)  e por fim, caso exista, ajustar a variável tamanho.

É correto afirmar que:

Somente as afirmativas II, IV e V estão corretas.
Todas as afirmativas estão corretas.
Somente as afirmativas III, IV e VI estão corretas.
Somente as afirmativas I, II e III estão corretas.
Somente as afirmativas IV, V e VI estão corretas.
Somente as afirmativas I, III e IV estão corretas.

Resposta: Todas as afirmativas estão corretas.

---

Faça a associação que entender pertinente:

Inicializa os dados e aponta os ponteiros primeiro e último para nulo.
Construtor

Finaliza a lista, liberando memória que tenha sido alocada (percorre a lista apagando os nós).
Destrutor

Percorre os nós da lista, um por um, realizando alguma ação.
Caminhamento

Percorre a lista buscando um nó com dado valor
Busca

Percorre os nós da lista, um por um, até uma determinada posição.
Acesso a posição

---

Considere as seguintes afirmativas sobre lista encadeada:

I) Para realizar a inserção no fim de uma lista deve-se, nessa ordem: criar o nó, realizar o apontamento do último elemento da lista para o novo nó, alterar o apontamento do fim da lista para o novo nó e por fim, caso exista, atualizar a variável tamanho, ajusta-la.

II) Para realizar a inserção no fim de uma lista, sem o ponteiro para o fim da lista, deve-se criar o nó. A segunda etapa seria a utilização de um ponteiro auxiliar inicialmente apontado para o primeiro elemento da lista. Realizar o percorrimento da lista com o nó auxiliar até que este aponte para o último elemento e realizar o apontamento do fim da lista para o novo nó. poor fim, caso exista, ajustar a variável tamanho.

III) Para realizar a inserção em uma posição específica da lista  deve-se, inicialmente, criar o nó. A seguir, com a utilização de um ponteiro auxiliar inicialmente apontado para o primeiro elemento da lista, é necessário percorrer a lista com o ponteiro auxiliar até a posição desejada. O próximo passo é realizar o apontamento do nó que está sendo apontado pelo auxiliar para o novo nó, e  novo nó para o próximo elemento da lista. Caso exista, a variável tamanho deve ser ajustada.

IV) São verificações importantes do método de inserção, que deve ser avaliada a necessidade de utilização em cada método:

O método de inserção em posição específica pode ser chamado em uma lista vazia. Assim, é necessário verificar e tratar essa situação. 
Adicionalmente, pode ser que a posição seja o início ou fim da lista, o que também exige tratamento diferenciado. 
É necessário também avaliar se as posições irão começar em zero ou em um.


V) Em geral, implementações tradicionais de listas para uso geral costumam utilizar o duplo encadeamento e disponibilizar os três métodos de inserção aqui apresentados. Entretanto, usos específicos podem exigir implementações em que apenas um dos três métodos de inserção sejam realmente implementados e utilizados. O duplo encadeamento também não é necessário em boa parte dos problemas.

É correto afirmar que:

Somente as afirmativas III, IV e V estão corretas.
Somente as afirmativas II, III e V  estão corretas.
Somente as afirmativas I, II e III estão corretas.
Somente as afirmativas I, III e IV estão corretas.
Somente as afirmativas II, IV e V estão corretas.
Somente as afirmativas I, IV e V estão corretas.

Resposta: Somente as afirmativas I, IV e V estão corretas.

---

Considere as seguintes afirmativas:

I) Para realizar o percorrimento, cria-se um ponteiro auxiliar (iniciado no primeiro) que acessa um nó e depois move-se para o próximo desse nó. Ao acessar cada nó, efetua-se a ação pretendida. Esse movimento é repetido até chegar ao final da lista.

II) Para realizar a busca, cria-se um ponteiro auxiliar (iniciado no primeiro) que acessa um nó e depois move-se para o próximo desse nó. O movimento é repetido até chegar ao nó com valor desejado ou chegar ao final da lista sem encontrar o elemento.

III)  Métodos de busca geralmente são utilizados para acessar ou retornar um elemento com um dado valor. No caso de final da lista, retorna-se nó nulo, posição inválida, ou erro, de acordo com o desejado. Em alguns problemas, basta que a busca informe que o valor encontra-se presente na lista, nesse caso basta retornar verdadeiro ou falso de acordo com a situação.

IV) Em outros problemas é necessário retornar a posição do nó encontrado. Nesse caso, é preciso ter em mente que isso pode trazer problemas de eficiência, caso o objetivo seja acessar o nó novamente (uma vez que será necessário percorrer novamente a lista).

V) Caso seja necessário retornar o dado em si, é  possível retornar uma cópia, uma referência ou um ponteiro para o elemento armazenado no nó. Algumas implementações optam por retornar um ponteiro para o dado e para o nó que contém o elemento buscado. Essa opção pode prejudicar severamente o encapsulamento dos dados, se não implementada adequadamente. É melhor retornar apenas o dado armazenado, por cópia, referência ou ponteiro, de acordo com a necessidade.

É correto afirmar que:

Somente as afirmativas I, IV e V estão corretas.
Somente as afirmativas II, III e IV estão corretas.
Somente as afirmativas II, III, IV e V estão corretas.
Somente as afirmativas I, II, III e  IV estão corretas.
Somente as afirmativas I, III, IV e V estão corretas.
Somente as afirmativas I, II, IV e V estão corretas.

Resposta: Somente as afirmativas I, II, III e  IV estão corretas.

---

Considere as seguintes afirmativas:

I) Para realizar o acesso a uma determinada posição, cria-se um ponteiro auxiliar (iniciado no primeiro) que acessa um nó e depois move-se para o próximo desse nó. Esse movimento é repetido até chegar ao nó especificado.

II) O acesso a uma posição geralmente é realizado para efetuar uma ação específica. O operador [ ] é geralmente sobrecarregado com esse método. Em alguns casos essa ação implica em retornar um ponteiro ou referência para o nó. Caso seja ponteiro ou referência, deve-se ter cuidado com a quebra de encapsulamento. É necessário definir se posições começam em zero ou um.

III)  Em linhas gerais, um iterador é um objeto que permite percorrer uma coleção de elementos, especialmente vetores e listas. Podem ser implementados de diferentes maneiras em diferentes linguagens de programação. Um iterador pode ser implementado, por exemplo, como um tipo de ponteiro que possui duas operações primárias: referenciar um elemento particular e modificar a si mesmo para apontar para o próximo elemento.

É correto afirmar que:

Todas as afirmativas estão corretas.
Somente a afirmativa II está correta.
Somente a afirmativa I está correta.
Somente as afirmativas II e III estão corretas.

Resposta: Todas as afirmativas estão corretas.

---

Considere as seguintes afirmativas:

I) Caso a remoção seja chamada em uma lista vazia, é necessário gerar erro para a aplicação. O ideal é que isso seja feito usando tratamento de exceções. Caso a lista fique vazia após remover o primeiro (e último) elemento, então é necessário fazer o ponteiro fim apontar para NULO.

II) Para realiza a remoção no início de uma lista deve-se criar um ponteiro auxiliar que acessa o primeiro nó. Isso é feito para poder mover o início da lista sem perder o acesso ao antigo primeiro nó. Movemos o início da lista. O antigo primeiro nó agora só pode ser acessado pelo ponteiro auxiliar. Agora, basta alocar memória para o antigo primeiro nó.

III)  Para realizar a remoção no fim de uma lista será necessário acessar o penúltimo elemento. A menos que a lista tenha duplo encadeamento, isso implica em percorrer a lista, usando um ponteiro auxiliar, até chegar ao penúltimo nó. Após percorrimento, tem-se o ponteiro auxiliar apontando para o penúltimo nó. Salvamos o conteúdo do antigo último nó e deletamos esse nó para liberar espaço na memória. Direcionamos o ponteiro próximo do penúltimo nó para NULO. Configuramos o novo fim da lista para o penúltimo nó (acessado por meio do ponteiro auxiliar). 

IV) A remoção de um nó específico pode ser feita por valor ou posição. Mostraremos a remoção por valor, sendo que ela pode ser modificada para remover uma posição específica, alterando a forma de busca. A remoção na primeira posição precisa ser tratada separadamente. Caso a lista também tenha um ponteiro para o último elemento, a remoção da última posição também deve ser tratada separadamente.

É correto afirmar que:

Todas as afirmativas estão corretas.
Somente as afirmativas I e IV estão corretas.
Somente as afirmativas II e III estão corretas.
Somente as afirmativas III e IV estão corretas.
Somente as afirmativas I e II estão corretas.
Somente as afirmativas II, III e IV estão corretas.

Resposta: Somente as afirmativas I e IV estão corretas.