#include "../include/cardapio.h"

No *criarNo(char *nome, float preco) {
  No *novoNo = (No *)malloc(sizeof(No));
  if (novoNo == NULL) {
    return NULL; // Lidar com falha de alocação de memória
  }
  novoNo->nome = (char *)malloc(strlen(nome) + 1);
  if (novoNo->nome == NULL) {
    free(novoNo); // Liberar memória previamente alocada
    return NULL;  // Lidar com falha de alocação de memória
  }
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

  int cmp = strcmp(nome, raiz->nome);

  if (cmp < 0) {
    raiz->esquerda = inserirNo(raiz->esquerda, nome, preco);
  } else if (cmp > 0) {
    raiz->direita = inserirNo(raiz->direita, nome, preco);
  }

  return raiz;
}

No *buscarNo(No *raiz, char *nome) {
  if (raiz == NULL) {
    return NULL;
  }

  // Armazena o resultado de strcmp para evitar múltiplas chamadas
  int cmp = strcmp(nome, raiz->nome);

  if (cmp == 0) {
    return raiz;
  } else if (cmp < 0) {
    return buscarNo(raiz->esquerda, nome);
  } else {
    return buscarNo(raiz->direita, nome);
  }
}

No *removerNo(No *raiz, char *nome) {
  if (raiz == NULL) {
    return raiz;
  }

  int cmp = strcmp(nome, raiz->nome);

  if (cmp < 0) {
    raiz->esquerda = removerNo(raiz->esquerda, nome);
  } else if (cmp > 0) {
    raiz->direita = removerNo(raiz->direita, nome);
  } else {
    // Nó a ser removido encontrado
    if (raiz->esquerda == NULL) {
      No *temp = raiz->direita;
      free(raiz->nome); // Liberar memória alocada para nome
      free(raiz);
      return temp;
    } else if (raiz->direita == NULL) {
      No *temp = raiz->esquerda;
      free(raiz->nome); // Liberar memória alocada para nome
      free(raiz);
      return temp;
    }

    // Nó com dois filhos: Obter o sucessor em ordem (menor na subárvore
    // direita)
    No *temp = raiz->direita;
    while (temp && temp->esquerda != NULL) {
      temp = temp->esquerda;
    }

    // Copiar o conteúdo do sucessor em ordem para este nó
    free(raiz->nome); // Liberar memória alocada para nome
    raiz->nome = (char *)malloc(strlen(temp->nome) + 1);
    if (raiz->nome == NULL) {
      // Lidar com falha de alocação de memória
      return raiz;
    }
    strcpy(raiz->nome, temp->nome);
    raiz->preco = temp->preco;

    // Deletar o sucessor em ordem
    raiz->direita = removerNo(raiz->direita, temp->nome);
  }

  return raiz;
}

void modificarNo(No *raiz, char *nome, float novoPreco, char *novoNome) {
  // Buscar o nó com o nome especificado
  No *no = buscarNo(raiz, nome);
  if (no != NULL) {
    // Atualizar o preço
    no->preco = novoPreco;

    // Verificar se o novo nome é diferente do nome atual
    if (strcmp(no->nome, novoNome) != 0) {
      // Realocar memória se necessário
      no->nome = (char *)realloc(no->nome, strlen(novoNome) + 1);
      if (no->nome == NULL) {
        // Lidar com falha de realocação de memória
        return;
      }
      // Copiar o novo nome
      strcpy(no->nome, novoNome);
    }
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
    if (scanf("%d", &opcao) != 1) {
      printf("Entrada inválida. Por favor, digite um número.\n");
      while (getchar() != '\n')
        ; // Limpa o buffer de entrada
      continue;
    }

    switch (opcao) {
    case 1:
      printf("Digite o nome do item: ");
      while (getchar() != '\n')
        ; // Limpa o buffer de entrada
      fgets(nome, sizeof(nome), stdin);
      nome[strcspn(nome, "\n")] = '\0'; // Remove o caractere de nova linha

      printf("Digite o preço do item: ");
      if (scanf("%f", &preco) != 1) {
        printf("Entrada inválida. Por favor, digite um número para o preço.\n");
        while (getchar() != '\n')
          ; // Limpa o buffer de entrada
        continue;
      }
      *raiz = inserirNo(*raiz, nome, preco);
      break;
    case 2:
      printf("Digite o nome do item a ser removido: ");
      while (getchar() != '\n')
        ; // Limpa o buffer de entrada
      fgets(nome, sizeof(nome), stdin);
      nome[strcspn(nome, "\n")] = '\0'; // Remove o caractere de nova linha
      *raiz = removerNo(*raiz, nome);
      break;
    case 3:
      printf("Digite o nome do item a ser modificado: ");
      while (getchar() != '\n')
        ; // Limpa o buffer de entrada
      fgets(nome, sizeof(nome), stdin);
      nome[strcspn(nome, "\n")] = '\0'; // Remove o caractere de nova linha

      printf("Digite o novo nome do item: ");
      char novoNome[50];
      fgets(novoNome, sizeof(novoNome), stdin);
      novoNome[strcspn(novoNome, "\n")] =
          '\0'; // Remove o caractere de nova linha

      printf("Digite o novo preço do item: ");
      float novoPreco;
      if (scanf("%f", &novoPreco) != 1) {
        printf("Entrada inválida. Por favor, digite um número para o preço.\n");
        while (getchar() != '\n')
          ; // Limpa o buffer de entrada
        continue;
      }
      while (getchar() != '\n')
        ; // Limpa o buffer de entrada

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
