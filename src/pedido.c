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
  pedido->prox = tabelaHash[indice];
  tabelaHash[indice] = pedido;
}

void removerPedido(Heap *heap, int id) {
  for (int i = 0; i < heap->tamanho; i++) {
    if (heap->pedidos[i]->id == id) {
      heap->pedidos[i] = heap->pedidos[heap->tamanho - 1];
      heap->tamanho--;
      break;
    }
  }
}

void listarPedidosTabelaHash() {
  for (int i = 0; i < TAMANHO_HASH; i++) {
    Pedido *atual = tabelaHash[i];
    while (atual != NULL) {
      printf("ID: %d\n", atual->id);
      printf("Descrição: %s\n", atual->descricao);
      printf("Timestamp: %ld\n", atual->timestamp);
      atual = atual->prox;
    }
  }
}

Heap *inicializarHeap(int capacidade) {
  Heap *heap = (Heap *)malloc(sizeof(Heap));
  heap->capacidade = capacidade;
  heap->tamanho = 0;
  heap->pedidos = (Pedido **)malloc(heap->capacidade * sizeof(Pedido *));
  return heap;
}

int gerarId() {
  return rand();
}

Pedido* criarPedido(const char* descricao) {
  Pedido *pedido = (Pedido *)malloc(sizeof(Pedido));
  pedido->id = gerarId();
  strcpy(pedido->descricao, descricao);
  pedido->timestamp = time(NULL);
  pedido->prox = NULL;
  return pedido;
}

void inserirPedidoHeap(Heap *heap, Pedido *pedido) {
  if (heap->tamanho == heap->capacidade) {
    return;
  }
  int indice = heap->tamanho;
  heap->pedidos[indice] = pedido;
  heap->tamanho++;
  while (indice > 0) {
    int pai = (indice - 1) / 2;
    if (heap->pedidos[pai]->timestamp > heap->pedidos[indice]->timestamp) {
      Pedido *temp = heap->pedidos[pai];
      heap->pedidos[pai] = heap->pedidos[indice];
      heap->pedidos[indice] = temp;
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

void minimizarHeap(Heap *heap, int indice) {
  int esquerda = 2 * indice + 1;
  int direita = 2 * indice + 2;
  int menor = indice;

  if (esquerda < heap->tamanho && heap->pedidos[esquerda]->timestamp < heap->pedidos[menor]->timestamp) {
    menor = esquerda;
  }
  if (direita < heap->tamanho && heap->pedidos[direita]->timestamp < heap->pedidos[menor]->timestamp) {
    menor = direita;
  }

  if (menor != indice) {
    trocarPedidos(&heap->pedidos[indice], &heap->pedidos[menor]);
    minimizarHeap(heap, menor);
  }
}

Pedido* extrairMinimo(Heap *heap) {
  if (heap->tamanho <= 0) {
    return NULL;
  }

  Pedido* minimo = heap->pedidos[0];
  heap->pedidos[0] = heap->pedidos[heap->tamanho - 1];
  heap->tamanho--;
  minimizarHeap(heap, 0);

  return minimo;
}