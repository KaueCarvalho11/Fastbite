#include "../include/pedido.h"

#define TAMANHO_HASH 50

// Variável global para gerar IDs dos pedidos
unsigned long long idCounter = 0;

Pedido *tabelaHash[TAMANHO_HASH];

void inicializarTabelaHash() {
  for (int i = 0; i < TAMANHO_HASH; i++) {
    tabelaHash[i] = NULL;
  }
}

unsigned int hash(int id) {
  unsigned int valorHash = id ^ (id >> 4);
  valorHash = valorHash & (TAMANHO_HASH - 1);
  return valorHash;
}

void adicionarPedido(Pedido *pedido) {
    unsigned int indice = hash(pedido->id);
    unsigned int originalIndice = indice;

    // Sondagem linear para encontrar uma posição disponível
    while (tabelaHash[indice] != NULL) {
        indice = (indice + 1) % TAMANHO_HASH;
        // Se voltarmos ao índice original, a tabela está cheia
        if (indice == originalIndice) {
            printf("Tabela hash está cheia, não é possível adicionar o pedido.\n");
            return;
        }
    }

    // Inserir o pedido na posição encontrada
    tabelaHash[indice] = pedido;
}

void removerPedido(Heap *heap, int id) {
    // Itera pelo heap para encontrar o pedido com o id fornecido
    for (int i = 0; i < heap->tamanho; i++) {
        if (heap->pedidos[i]->id == id) {
            // Libera a memória alocada para o pedido encontrado
            free(heap->pedidos[i]);

            // Substitui o pedido encontrado pelo último pedido no heap
            heap->pedidos[i] = heap->pedidos[heap->tamanho - 1];
            // Diminui o tamanho do heap
            heap->tamanho--;
            // Reorganiza o heap para manter as propriedades do heap
            minimizarHeap(heap, i);
            break;
        }
    }
}

void minimizarHeap(Heap *heap, int indice) {
    int maior = indice;
    int esquerda = 2 * indice + 1;
    int direita = 2 * indice + 2;

    if (esquerda < heap->tamanho && heap->pedidos[esquerda]->id > heap->pedidos[maior]->id) {
        maior = esquerda;
    }

    if (direita < heap->tamanho && heap->pedidos[direita]->id > heap->pedidos[maior]->id) {
        maior = direita;
    }

    if (maior != indice) {
        Pedido *temp = heap->pedidos[indice];
        heap->pedidos[indice] = heap->pedidos[maior];
        heap->pedidos[maior] = temp;
        minimizarHeap(heap, maior);
    }
}


Heap *inicializarHeap(int capacidade) {
    // Aloca memória para a estrutura Heap
    Heap *heap = (Heap *)malloc(sizeof(Heap));
    if (heap == NULL) {
        fprintf(stderr, "Erro ao alocar memória para o heap.\n");
        exit(EXIT_FAILURE);
    }

    heap->capacidade = capacidade;
    heap->tamanho = 0;

    // Aloca memória para o array de pedidos
    heap->pedidos = (Pedido **)malloc(capacidade * sizeof(Pedido *));
    if (heap->pedidos == NULL) {
        fprintf(stderr, "Erro ao alocar memória para os pedidos do heap.\n");
        free(heap);
        exit(EXIT_FAILURE);
    }

    return heap;
}

int gerarId() {
    return rand();
}

Pedido* criarPedido(const char* descricao) {
    Pedido *novoPedido = (Pedido *)malloc(sizeof(Pedido));
    if (novoPedido == NULL) {
        fprintf(stderr, "Erro ao alocar memória para o pedido.\n");
        exit(EXIT_FAILURE);
    }

    // Inicializa os campos do pedido
    novoPedido->id = gerarId();
    strncpy(novoPedido->descricao, descricao, sizeof(novoPedido->descricao) - 1);
    novoPedido->descricao[sizeof(novoPedido->descricao) - 1] = '\0'; // Garante terminação nula
    novoPedido->timestamp = time(NULL);
    novoPedido->prox = NULL;

    return novoPedido;
}

void inserirPedidoHeap(Heap *heap, Pedido *pedido) {
    // Verifica se o heap está cheio
    if (heap->tamanho == heap->capacidade) {
        return;
    }

    // Insere o novo pedido no final do heap
    int indice = heap->tamanho;
    heap->pedidos[indice] = pedido;
    heap->tamanho++;

    // Reorganiza o heap para manter as propriedades do heap
    while (indice > 0) {
        int pai = (indice - 1) / 2;
        if (heap->pedidos[pai]->timestamp > heap->pedidos[indice]->timestamp) {
            // Troca o pedido atual com o pedido do pai
            Pedido *temp = heap->pedidos[pai];
            heap->pedidos[pai] = heap->pedidos[indice];
            heap->pedidos[indice] = temp;
            // Atualiza o índice para o pai
            indice = pai;
        } else {
            break;
        }
    }
}

void trocarPedidos(Pedido **a, Pedido **b) {
  Pedido *temp = *a;
  *a = *b;
  *b = temp;
}


Pedido* extrairMinimo(Heap *heap) {
    // Verifica se o heap está vazio
    if (heap->tamanho <= 0) {
        return NULL;
    }

    // Armazena o pedido mínimo (raiz do heap)
    Pedido* pedidoMinimo = heap->pedidos[0];
    // Substitui a raiz pelo último elemento do heap
    heap->pedidos[0] = heap->pedidos[heap->tamanho - 1];
    // Diminui o tamanho do heap
    heap->tamanho--;
    // Reorganiza o heap para manter as propriedades do heap
    minimizarHeap(heap, 0);

    return pedidoMinimo;
}

void fazerPedido(Heap *heap) {
    char descricao[100];

    // Solicita a descrição do pedido ao usuário
    printf("Digite a descricao do pedido: ");
    fflush(stdout); // Garante que a mensagem seja exibida antes de esperar a entrada do usuário

    // Limpa o buffer de entrada para evitar problemas com entradas anteriores
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    if (fgets(descricao, sizeof(descricao), stdin) == NULL) {
        fprintf(stderr, "Erro ao ler a descricao do pedido.\n");
        return;
    }

    // Remove o caractere de nova linha, se presente
    size_t len = strlen(descricao);
    if (len > 0 && descricao[len - 1] == '\n') {
        descricao[len - 1] = '\0';
    }

    // Cria um novo pedido com a descrição fornecida
    Pedido *novoPedido = criarPedido(descricao);
    if (novoPedido == NULL) {
        fprintf(stderr, "Erro ao criar o pedido.\n");
        return;
    }

    // Insere o novo pedido no heap
    inserirPedidoHeap(heap, novoPedido);

    // Adiciona o novo pedido na tabela hash
    adicionarPedido(novoPedido);
}

void enviarPedido(Heap *heap) {
    // Extrai o pedido com a menor prioridade (raiz do heap)
    Pedido *pedido = extrairMinimo(heap);
    
    if (pedido) {
        // Imprime os detalhes do pedido enviado
        printf("Pedido enviado para entrega: ID %d, Descricao: %s\n", pedido->id, pedido->descricao);
        
        // Remove o pedido da tabela hash
        unsigned int indice = hash(pedido->id);
        Pedido *atual = tabelaHash[indice];
        Pedido *anterior = NULL;

        // Encontra e remove o pedido da lista encadeada na tabela hash
        while (atual != NULL && atual->id != pedido->id) {
            anterior = atual;
            atual = atual->prox;
        }

        if (atual != NULL) {
            if (anterior == NULL) {
                tabelaHash[indice] = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }
        }

        // Libera a memória alocada para o pedido
        free(pedido);
    } else {
        // Informa que não há pedidos para enviar
        printf("Nao ha pedidos para enviar.\n");
    }
}


void imprimirPedidos(Heap *heap) {
    char buffer[80];
    struct tm *timeinfo;

    // Itera sobre todos os pedidos no heap
    for (int i = 0; i < heap->tamanho; i++) {
        Pedido *pedidoAtual = heap->pedidos[i];

        // Converte o timestamp para uma estrutura de tempo
        timeinfo = localtime(&pedidoAtual->timestamp);

        // Formata a data e hora em uma string legível
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeinfo);

        // Imprime os detalhes do pedido
        printf("ID: %d\n", pedidoAtual->id);
        printf("Descrição: %s\n", pedidoAtual->descricao);
        printf("Data e Hora: %s\n", buffer);
    }
}
