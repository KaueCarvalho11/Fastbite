
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
