#ifndef CARDAPIO_H
#define CARDAPIO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
  char nome[50];
  float preco;
  struct No *esquerda;
  struct No *direita;
} No;

/**
 * @brief Cria um novo nó para a árvore.
 *
 * Esta função aloca memória para um novo nó e inicializa seus campos
 * com os valores fornecidos.
 *
 * @param nome O nome do produto.
 * @param preco O preço do produto.
 * @return Um ponteiro para o novo nó alocado.
 */
No *criarNo(char *nome, float preco);
/**
 * @brief Insere um nó na árvore.
 *
 * Esta função insere um nó na árvore binária de busca, mantendo a
 * propriedade de ordenação dos nós.
 *
 * @param raiz A raiz da árvore onde o nó será inserido.
 * @param nome O nome do produto.
 * @param preco O preço do produto.
 * @return A raiz da árvore após a inserção.
 */
No *inserirNo(No *raiz, char *nome, float preco);

/**
 * @brief Busca um nó na árvore.
 *
 * Esta função busca um nó na árvore binária de busca com base no nome
 * fornecido.
 *
 * @param raiz A raiz da árvore onde o nó será buscado.
 * @param nome O nome do produto a ser buscado.
 * @return Um ponteiro para o nó encontrado, ou NULL se o nó não existir.
 */
No *buscarNo(No *raiz, char *nome);
/**
 * @brief Remove um nó da árvore.
 *
 * Esta função remove um nó da árvore binária de busca com base no nome
 * fornecido.
 *
 * @param raiz A raiz da árvore onde o nó será removido.
 * @param nome O nome do produto a ser removido.
 * @return A raiz da árvore após a remoção.
 */
No *removerNo(No *raiz, char *nome);

/**
 * @brief Modifica o nome e o preço de um nó existente.
 *
 * Esta função busca um nó na árvore binária de busca pelo nome original,
 * e, se encontrado, modifica tanto o nome quanto o preço do item.
 *
 * @param raiz A raiz da árvore na qual será realizada a busca e modificação.
 * @param nome O nome do item a ser modificado.
 * @param novoPreco O novo preço a ser atribuído ao item.
 * @param novoNome O novo nome a ser atribuído ao item.
 */
void modificarNo(No *raiz, char *nome, float novoPreco, char *novoNome);

/**
 * @brief Imprime o cardápio
 *
 * Esta função percorre a árvore binária de busca e imprime todos os nós
 * nela.
 *
 * @param raiz A raiz da árvore a ser listada.
 */
void imprimirCardapio(No *raiz);

/**
 * @brief Menu para alterar o cardapio
 *
 *
 * @param raiz A raiz da árvore a ser alterada.
 *
 */
void alterarCardapio(No **raiz);

#endif // CARDAPIO_H
