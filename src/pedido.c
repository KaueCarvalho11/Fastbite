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
