Considere as seguintes afirmativas:

I) A tabela Hash é uma Estrutura de dados que, indiferente da forma implementada, sempre permite a busca por elementos em ordem constante: O(1).

II) Para se conseguir alta velocidade de acesso, o hash utiliza o acesso direto em posições de arranjo. Assim, para cada valor armazenado, utiliza-se algum mecanismo (uma função de hash) que encontra a posição desse valor no arranjo. 

III)  Uma função de espalhamento é um algoritmo que mapeia dados de comprimento variável para dados de comprimento fixo.

IV) Uma função de hashing não possuem inversa, ou seja, dado um valor de hash, não é possível determinar com certeza o valor que o gerou. 

V) Por conta das suas características, alta velocidade de acesso e baixíssimo consumo de memória, faz com que a tabela hash seja amplamente utilizada em todas as aplicações seguras.

É correto afirmar que:

Somente as afirmativas II, III e IV estão corretas.
<!-- Somente as afirmativas I, II e IV estão corretas. -->
Somente as afirmativas II, IV e V estão corretas.
<!-- Somente as afirmativas I, II e V estão corretas. -->
<!-- Todas as afirmativas estão corretas. -->
<!-- Somente as afirmativas I, III e IV estão corretas. -->

Reposta: Somente as afirmativas II, III e IV estão corretas.

---

Considere as seguintes afirmativas sobre vetores expansíveis:

I) Por conta das característica das tabelas hash, funções de hash são a base para armazenamento de senhas em sistemas seguros. O sistema não armazena a senha, e sim o hash dela. Para autenticar o usuário, o sistema verifica se o hash da senha digitada é idêntico ao hash armazenado.

II) Funções de hash também são ferramentas básicas para implementação de verificações de integridade (como checksum de arquivos). Ao fazer um download, por exemplo, caso o checksum seja diferente do informado pelo site, o arquivo não deve ter sido transferido corretamente. Funções de hash também são base para uma tecnologia em auge atualmente: o blockchain.

III) Outro uso efetivo de funções de hash são as tabelas hash (ou tabelas de dispersão) para encontrar a posição de uma dada chave no vetor de armazenamento. Uma função bastante utilizada para chaves baseadas em números inteiro positivos é o operador de quociente (h(k) = k dividido m). Em que k é o valor da chave e m é a capacidade da tabela.

IV) Uma boa função de hash pode ajudar em muito a economizar espaço na memória e a evitar colisões.


É correto afirmar que:
<!-- Somente as afirmativas II, III e IV estão corretas. -->
<!-- Somente as afirmativas III e IV estão corretas. -->
<!-- Todas as afirmativas estão corretas. -->
<!-- Somente as afirmativas I, III e IV estão corretas. -->
<!-- Somente as afirmativas I, II e III estão corretas. -->
Somente as afirmativas I, II e IV estão corretas.

Reposta: Somente as afirmativas I, II e IV estão corretas.

---

Considere as seguintes afirmativas sobre vetores expansíveis:

I) Dizemos que houve colisão em uma tabela hash quando ocorre de duas chaves receberem o mesmo endereço em uma tabela hash.

II) A colisão em uma tabela hash é um fenômeno desejado e que pode ser maximizado ou até multiplicado com a escolha de uma boa função de hash, e essa escolha é trivial.

III) Um dos fatores a ser considerado no momento de escolha de uma função de hash é o tamanho do conjunto de dados de entrada. E o primeiro passo é conhecer o problema a ser tratado.

IV) O objetivo de uma tabela hash é possibilitar armazenar os dados e identificar, através de uma chave de busca, a posição na tabela ocupada por determinado dado. Usa-se função de espalhamento (hash function) para transformar uma chave K em uma posição na tabela. A função de espalhamento (hash function) associa uma chave de busca a um índice na tabela. Uma boa função de hash satisfaz a suposição de que é possível que cada chave seja atribuída a uma posição diferente da tabela independentemente da posição em que as demais chaves foram atribuídas.

V) É tarefa fácil encontrar a função de hash mais adequada para um dado problema. Diante disso, para a escolha de uma função de hash mais adequada, em geral, são utilizadas funções de hash tradicionais, como a de quociente, já apresentada anteriormente (h(k) = k dividido m), onde k é o valor da chave e m é a quantidade de posições da tabela. Na prática, costuma-se adotar um valor primo como divisor para minimizar colisões.



É correto afirmar que:

<!-- Todas as afirmativas estão corretas. -->
<!-- Somente as afirmativas III, IV e V estão corretas. -->
Somente as afirmativas I, III e IV estão corretas.
<!-- Somente as afirmativas II, III e V estão corretas. -->
<!-- Somente as afirmativas I, III e V estão corretas. -->
<!-- Somente as afirmativas I, II e III estão corretas. -->

Reposta: Somente as afirmativas I, III e IV estão corretas.

---

Considere as seguintes afirmativas sobre tabelas hash:

I) Tabelas hash são comumente implementadas em arranjos, com tamanho definido de forma estática. Valores retornados pela função hash correspondem aos índices do arranjo. Não se tem conhecimento prévio da dimensão necessária. Mesmo com estratégias para tratamento de colisões, a estrutura pode ser descaracterizada se a taxa de ocupação for muito alta.

II) Algumas abordagens permitem o redimensionamento da tabela quando a taxa de ocupação ultrapassa determinada limite. O redimensionamento é um processo caro, mas mantém o desempenho médio da tabela.

III) Após o redimensionamento de uma tabela hash, todos os dados precisam ser realocados (copiar dados de um arranjo para outro). Alguns autores chamam essa técnica de tabela hash dinâmica (mesmo com dados armazenados em arranjos).

É correto afirmar que:

<!-- Somente as afirmativas II e III estão corretas. -->
<!-- Somente a afirmativa III está correta. -->
<!-- Somente a afirmativa II está correta. -->
<!-- Somente as afirmativas I e III estão corretas. -->
As afirmativas I e II  estão corretas.
<!-- Todas as afirmativas estão corretas. -->

Resposta: Somente as afirmativas I e II estão corretas.
