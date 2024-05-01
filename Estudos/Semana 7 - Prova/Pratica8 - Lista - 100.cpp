/*
Faça um procedimento para remover o elemento da lista com maior tempo para execução total.

Você pode (e deve!) utilizar o código que você desenvolveu na atividade "Lista Duplamente Encadeada - Ações de usuários em um programa" como base.

Com essa finalidade, você deverá adicionar mais um comando, como segue:

t : retira e imprime o elemento da lista com maior tempo para execução total.
Saídas:

Todas as saídas de comandos já estão implementadas na função principal código entregue, somente falta implementar a chamada para retirada e impressão do elemento da lista com maior tempo para execução total. Ao terminar a execução do programa, todos os itens da listas são escritos.
*/

#include <iostream>
#include <cstdlib>

using namespace std;

// Definição da estrutura de dados para representar uma ação do programa
struct acaoPrograma{
    int identificador;
    string nomeAcao;
    int tempoExecucao; 
    int tempoConsumido;
};

// Função para imprimir uma ação do programa
void imprimeAcao(acaoPrograma acao) {
    cout << "(" << acao.identificador << ", " << acao.nomeAcao << ", " << acao.tempoExecucao << ", " << acao.tempoConsumido << ")\n";
}

// Definição da classe nó
class noh {
friend class listadup;
private: 
    acaoPrograma acao; // poderia ser outro tipo de variável
    noh* proximo;
    noh* anterior;
public:
    noh(acaoPrograma d);
};

// Construtor da classe nó
noh::noh(acaoPrograma d){
    acao = d;
    proximo = NULL;
    anterior = NULL;
}

// Definição da classe lista duplamente encadeada
class listadup {
private:
    noh* primeiro;
    noh* ultimo;
    int tamanho;
    void removeTodos(); // remove todos os elementos da lista    
public:
    listadup();
    listadup(const listadup& umaLista);
    ~listadup();
    listadup& operator=(const listadup& umaLista);  
    void insereNoFim(acaoPrograma acao);
    void insereNoInicio(acaoPrograma acao);
    void insereNaPosicao(int posicao, acaoPrograma acao);
    int procura(string valor); // retorna a posicao
    void imprime();
    inline bool vazia();
    acaoPrograma removeNoFim();
    acaoPrograma removeNoInicio();    
    void removeMaiorTempo();
};

// Construtor da lista duplamente encadeada
listadup::listadup() {
    primeiro = NULL;
    ultimo = NULL;
    tamanho = 0;
}

// Construtor de cópia da lista duplamente encadeada
listadup::listadup(const listadup& umaLista) {
    primeiro = NULL;
    ultimo = NULL;
    tamanho = 0;
    noh* aux = umaLista.primeiro;

    // Copia os elementos da lista umaLista para a nova lista
    while (aux != NULL) {
        insereNoFim(aux->acao);
        aux = aux->proximo;
    }
}

// Destrutor da lista duplamente encadeada
listadup::~listadup( ) {
    removeTodos();
}    

// Função privada para remover todos os elementos da lista
void listadup::removeTodos( ) {
    while (!vazia()) {
        removeNoFim();
    }
}    

// Sobrecarga do operador de atribuição
listadup& listadup::operator=(const listadup& umaLista){
    // Limpa a lista atual
    removeTodos();
    
    // Percorre a lista recebida como parâmetro, copiando os dados
    noh* aux = umaLista.primeiro;
    
    while (aux != NULL) {
        insereNoFim(aux->acao);
        aux = aux->proximo;  
    }
    
    return *this; 
}  

// Insere um elemento no final da lista
void listadup::insereNoFim(acaoPrograma acao) {
    if (vazia()) {
        // Se a lista estiver vazia, insere como único elemento
        primeiro = new noh(acao);
        ultimo = primeiro;
    } else {
        // Caso contrário, insere após o último elemento
        noh* novo = new noh(acao);
        ultimo->proximo = novo;
        novo->anterior = ultimo;
        ultimo = novo;
    }
    tamanho++;
}

// Insere um elemento no início da lista
void listadup::insereNoInicio(acaoPrograma acao) {
    if (vazia()) {
        // Se a lista estiver vazia, insere como único elemento
        primeiro = new noh(acao);
        ultimo = primeiro;
    } else {
        // Caso contrário, insere antes do primeiro elemento
        noh* novo = new noh(acao);
        primeiro->anterior = novo;
        novo->proximo = primeiro;
        primeiro = novo;
    }
    tamanho++; 
}

// Insere um elemento em uma determinada posição da lista
void listadup::insereNaPosicao(int posicao, acaoPrograma acao) {
    if (posicao < 0 || posicao > tamanho) {
        cout << "Posição Inexistente!\n";
        return;
    }

    if (posicao == 0) {
        insereNoInicio(acao);
    } else if (posicao == tamanho) {
        insereNoFim(acao);
    } else {
        noh* novo = new noh(acao);
        // Verifica se a posição está na primeira metade da lista
        if (posicao <= tamanho / 2) {
            // Inserção na primeira metade (avançando com próximo)
            noh* aux = primeiro;

            for (int i = 0; i < posicao - 1; i++) {
                aux = aux->proximo;
            }

            novo->proximo = aux->proximo;
            novo->anterior = aux;
            aux->proximo->anterior = novo;
            aux->proximo = novo;
        } else {
            // Inserção na segunda metade (recuando com anterior)
            noh* aux = ultimo;

            for (int i = tamanho - 1; i > posicao; i--) {
                aux = aux->anterior;
            }

            novo->proximo = aux;
            novo->anterior = aux->anterior;
            aux->anterior->proximo = novo;
            aux->anterior = novo;
        }

        tamanho++;
    }
}

// Procura um elemento na lista e retorna a posição
int listadup::procura(string valor) {
    if (vazia()) {
        throw runtime_error("Lista vazia!");
    }
    int posicao = -1;
    for (int i = 0; i<tamanho; i++){
        acaoPrograma info = removeNoInicio();
        if (info.nomeAcao == valor) posicao = i;
        insereNoFim(info);
    }
    return posicao;
}

// Imprime os elementos da lista
void listadup::imprime() {
   if (vazia()) {
        throw runtime_error("Lista vazia!");
    }

    noh* aux = primeiro;
    while (aux != NULL) {
        imprimeAcao(aux->acao);
        aux = aux->proximo;
    }

    cout << " IMPRIMINDO REVERSO \n";

    aux = ultimo;
    while (aux != NULL) {
        imprimeAcao(aux->acao);
        aux = aux->anterior;
    }
}

// Verifica se a lista está vazia
inline bool listadup::vazia() {
    return (primeiro == NULL);
}

// Remove o elemento do início da lista
acaoPrograma listadup::removeNoInicio() {
    if (vazia()) {
        throw runtime_error("Remoção em lista vazia!");
    }

    acaoPrograma acao = primeiro->acao;
    if (primeiro == ultimo) {
        // Lista com apenas um elemento
        delete primeiro;
        primeiro = NULL;
        ultimo = NULL;
    } 
    else {
        // Lista com mais de um elemento
        noh* aux = primeiro;
        primeiro = primeiro->proximo;
        primeiro->anterior = NULL;
        delete aux;
    }
    tamanho--;
    return acao;
}

// Remove o elemento do final da lista
acaoPrograma listadup::removeNoFim() {
    if (vazia()) {
        throw runtime_error("Remoção em lista vazia!");
    }

    acaoPrograma acao = ultimo->acao;
    if (primeiro == ultimo) {
        // Lista com apenas um elemento
        delete primeiro;
        primeiro = NULL;
        ultimo = NULL;
    } 
    else {
        // Lista com mais de um elemento
        noh* aux = ultimo;
        ultimo = ultimo->anterior;
        ultimo->proximo = NULL;
        delete aux;
    }
    tamanho--;
    return acao;
}

// Função para remover o elemento da lista com maior tempo para execução total
void listadup::removeMaiorTempo() {
    if (vazia()) {
        throw runtime_error("Remoção em lista vazia!");
    }
    noh* aux = primeiro;
    int maior = aux->acao.tempoExecucao;
    while(aux->proximo != NULL){
        aux = aux->proximo;
        if (aux->acao.tempoExecucao > maior) maior = aux->acao.tempoExecucao;
    }
    while (aux->acao.tempoExecucao != maior){
        aux = aux->anterior;
    }
    if (aux == primeiro) imprimeAcao(removeNoInicio());
    else if (aux == ultimo) imprimeAcao(removeNoFim());
    else{
        aux->anterior->proximo = aux->proximo;
        aux->proximo->anterior = aux->anterior;
        imprimeAcao(aux->acao);
        delete aux;
        tamanho--;
    }
}
// Função principal
int main() {
    listadup minhaLista;
    acaoPrograma info;
    char comando;
    int posicao;
    string nomeEquipe;

    do {
        try {
            cin >> comando;
            switch (comando) {
                case 'i': // inserir no início
                    cin >> info.identificador >> info.nomeAcao >> info.tempoExecucao >> info.tempoConsumido;
                    minhaLista.insereNoInicio(info);
                    break;
                case 'h': // inserir no fim
                    cin >> info.identificador >> info.nomeAcao >> info.tempoExecucao >> info.tempoConsumido;
                    minhaLista.insereNoFim(info);
                    break;             
                case 'm': // inserir em uma posição específica
                    cin >> posicao;
                    cin >> info.identificador >> info.nomeAcao >> info.tempoExecucao >> info.tempoConsumido;
                    minhaLista.insereNaPosicao(posicao,info);
                    break;             
                case 's': // procurar
                    cin >> nomeEquipe;
                    posicao = minhaLista.procura(nomeEquipe);
                    if(posicao == -1)
                        cout << "Nao encontrado"<< endl;
                    else
                        cout << posicao << endl;
                    break;                    
                case 'r': // remover do início
                    minhaLista.removeNoInicio();
                    break;
                case 'a': // remover do fim
                    minhaLista.removeNoFim();
                    break;
                case 't': // remover do fim
                    minhaLista.removeMaiorTempo();
                    break;                                  
                case 'p': // imprimir lista
                    minhaLista.imprime();
                    break;
                case 'f': // finalizar
                    // checado no do-while
                    break;
                default:
                    cerr << "comando inválido\n";
            }
        } catch (runtime_error& e) {
            cout << e.what() << endl;
        }
    } while (comando != 'f'); // finalizar execução
    cout << endl;
    return 0;
}