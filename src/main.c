#include "../include/cardapio.h"
#include "../include/pedido.h"
#include <stdio.h>

void menuLoja(No **raiz, Heap *heap) {
  int opcao;
  do {
    printf("\n--- Menu Loja ---\n");
    printf("1. Enviar pedido\n");
    printf("2. Listar pedidos\n");
    printf("3. Cancelar pedido\n");
    printf("4. Alterar cardapio\n");
    printf("5. Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    switch (opcao) {
    case 1:
      enviarPedido(heap);
      break;
    case 2:
        imprimirPedidos(heap);
      break;
    case 3: {
      int id;
      printf("Digite o ID do pedido para cancelar: ");
      scanf("%d", &id);
      removerPedido(heap, id);
      break;
    }
    case 4:
      alterarCardapio(raiz);
      break;
    case 5:
      printf("Saindo do modo loja...\n");
      break;
    default:
      printf("Opcao invalida! Tente novamente.\n");
    }
  } while (opcao != 5);
}
void menuCliente(Heap *heap, No *raiz) {
  int opcao;
  do {
    printf("\n--- Menu Cliente ---\n");
    printf("1. Ver cardapio\n");
    printf("2. Fazer pedido\n");
    printf("3. Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    switch (opcao) {
    case 1:
      imprimirCardapio(raiz);
      break;
    case 2:
      fazerPedido(heap);
      break;
    case 3:
      printf("Saindo do modo cliente...\n");
      break;
    default:
      printf("Opcao invalida! Tente novamente.\n");
    }
  } while (opcao != 3);
}
int main() {
  No *raiz = NULL;
  Heap *heap = inicializarHeap(100);
  inicializarTabelaHash();

  int opcao;
  do {
    printf("\n--- Menu Principal ---\n");
    printf("1. Modo loja\n");
    printf("2. Modo cliente\n");
    printf("3. Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    switch (opcao) {
    case 1:
      menuLoja(&raiz, heap);
      break;
    case 2:
      menuCliente(heap, raiz);
      break;
    case 3:
      printf("Saindo do programa...\n");
      break;
    default:
      printf("Opcao invalida! Tente novamente.\n");
    }
  } while (opcao != 3);

  return 0;
}
