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
      listarPedidosTabelaHash();
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
