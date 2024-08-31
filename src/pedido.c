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
}

Heap *inicializarHeap(int capacidade) {
  Heap *heap = (Heap *)malloc(sizeof(Heap));
  heap->capacidade = capacidade;
  heap->tamanho = 0;
  heap->pedidos = (Pedido **)malloc(heap->capacidade * sizeof(Pedido *));
  return heap;
}
