
#include "../include/cardapio.h"

No *criarNo(char *nome, float preco) {
  No *novoNo = (No *)malloc(sizeof(No));
  strcpy(novoNo->nome, nome);
  novoNo->preco = preco;
  novoNo->esquerda = NULL;
  novoNo->direita = NULL;
  return novoNo;
}

No *inserirNo(No *raiz, char *nome, float preco) {
  if (raiz == NULL) {
    return criarNo(nome, preco);
  }

  if (strcmp(nome, raiz->nome) < 0) {
    raiz->esquerda = inserirNo(raiz->esquerda, nome, preco);
  } else if (strcmp(nome, raiz->nome) > 0) {
    raiz->direita = inserirNo(raiz->direita, nome, preco);
  }

  return raiz;
}

No *buscarNo(No *raiz, char *nome) {
  if (raiz == NULL || strcmp(raiz->nome, nome) == 0) {
    return raiz;
  }

  if (strcmp(nome, raiz->nome) < 0) {
    return buscarNo(raiz->esquerda, nome);
  }

  return buscarNo(raiz->direita, nome);
}

No *removerNo(No *raiz, char *nome) {
  if (raiz == NULL) {
    return raiz;
  }

  if (strcmp(nome, raiz->nome) < 0) {
    raiz->esquerda = removerNo(raiz->esquerda, nome);
  } else if (strcmp(nome, raiz->nome) > 0) {
    raiz->direita = removerNo(raiz->direita, nome);
  } else {
    if (raiz->esquerda == NULL) {
      No *temp = raiz->direita;
      free(raiz);
      return temp;
    } else if (raiz->direita == NULL) {
      No *temp = raiz->esquerda;
      free(raiz);
      return temp;
    }

    No *temp = raiz->direita;
    while (temp->esquerda != NULL) {
      temp = temp->esquerda;
    }

    strcpy(raiz->nome, temp->nome);
    raiz->preco = temp->preco;
    raiz->direita = removerNo(raiz->direita, temp->nome);
  }

  return raiz;
}

void modificarNo(No *raiz, char *nome, float novoPreco, char *novoNome) {
  No *no = buscarNo(raiz, nome);
  if (no != NULL) {
    no->preco = novoPreco;
    strcpy(no->nome, novoNome);
  }
}

void imprimirCardapio(No *raiz) {
  if (raiz != NULL) {
    imprimirCardapio(raiz->esquerda);
    printf("%s: R$ %.2f\n", raiz->nome, raiz->preco);
    imprimirCardapio(raiz->direita);
  }
}

void alterarCardapio(No **raiz) {
  int opcao;
  char nome[50];
  float preco;

  do {
    printf("\n ---- Alterar Cardápio ----\n");
    printf("1 - Adicionar item\n");
    printf("2 - Remover item\n");
    printf("3 - Modificar item\n");
    printf("4 - Listar cardápio\n");
    printf("5 - Sair\n");
    printf("Digite a opção desejada: ");
    scanf("%d", &opcao);

    switch (opcao) {
    case 1:
      printf("Digite o nome do item: ");
      scanf("%s", nome);
      printf("Digite o preço do item: ");
      scanf("%f", &preco);
      *raiz = inserirNo(*raiz, nome, preco);
      break;
    case 2:
      printf("Digite o nome do item a ser removido: ");
      scanf("%s", nome);
      *raiz = removerNo(*raiz, nome);
      break;
    case 3:
      printf("Digite o nome do item a ser modificado: ");
      scanf("%s", nome);
      printf("Digite o novo nome do item: ");
      char novoNome[50];
      scanf("%s", novoNome);
      printf("Digite o novo preço do item: ");
      float novoPreco;
      scanf("%f", &novoPreco);
      modificarNo(*raiz, nome, novoPreco, novoNome);
      break;
    case 4:
      imprimirCardapio(*raiz);
      break;
    case 5:
      break;
    default:
      printf("Opção inválida.\n");
    }

  } while (opcao != 5);
}
