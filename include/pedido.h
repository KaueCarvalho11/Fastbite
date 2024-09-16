#ifndef PEDIDO_H
#define PEDIDO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Pedido {
  int id;
  char descricao[100];
  time_t timestamp;
  struct Pedido *prox;
} Pedido;

typedef struct {
  Pedido **pedidos;
  int capacidade;
  int tamanho;
} Heap;

/**
 * @brief Inicializa a tabela hash.
 *
 * Esta função define todos os elementos da tabela hash como NULL,
 * efetivamente limpando ou inicializando a tabela para uso.
 */
void inicializarTabelaHash();

/**
 * @brief Calcula um valor de hash para um ID fornecido.
 *
 * Esta função utiliza um método de manipulação de bits para calcular
 * um valor de hash para um ID inteiro, garantindo que ele se encaixe no tamanho
 * da tabela hash.
 *
 * @param id O ID inteiro a ser hashado.
 * @return Um valor de hash inteiro sem sinal dentro do intervalo [0,
 * TAMANHO_HASH - 1].
 */
unsigned int hash(int id);

/**
 * @brief Adiciona um pedido à tabela hash.
 *
 * Esta função cria um novo pedido com o ID e a descrição fornecidos e
 * o adiciona à tabela hash.
 *
 * @param pedido Pedido a ser adicionado
 */
void adicionarPedido(Pedido *pedido);

/**
 * @brief Remove um pedido da heap.
 *
 *
 * Esta função remove um pedido da heap com o ID fornecido.
 *
 * @param heap A heap de onde o pedido será removido
 * @param id O ID do pedido a ser removido
 */
void removerPedido(Heap *heap, int id);

/**
 * @brief Envia um pedido da heap.
 *
 * Esta função remove o pedido com o menor timestamp da heap e o envia.
 *
 * @param heap A heap de onde o pedido será removido
 */
void enviarPedido(Heap *heap);

/**
 * @brief Lista todos os pedidos na tabela hash.
 *
 * Esta função percorre a tabela hash e imprime todos os pedidos nela.
 */
void listarPedidosTabelaHash();

/**
 * @brief Inicializa a heap.
 *
 * Esta função aloca memória para a heap e define todos os elementos
 * como NULL, efetivamente limpando ou inicializando a heap para uso.
 *
 * @param capacidade A capacidade máxima da heap
 */
Heap *inicializarHeap(int capacidade);

/**
 * @brief Gera um identificador único para um pedido.
 *
 * Esta função utiliza a função `rand()` para gerar um identificador 
 * pseudoaleatório para um pedido. O ID gerado será utilizado para
 * identificar de forma única cada pedido no sistema.
 *
 * @return Um número inteiro representando o ID único do pedido.
 */
int gerarId();

/**
 * @brief Cria e inicializa um novo pedido.
 *
 * Esta função aloca memória para um novo pedido e o inicializa com
 * um ID gerado aleatoriamente, a descrição fornecida, e o timestamp 
 * atual (que indica o momento em que o pedido foi criado). O ponteiro
 * para o próximo pedido é inicializado como NULL.
 *
 * @param descricao A string que contém a descrição do pedido.
 * @return Um ponteiro para o novo pedido criado, ou NULL em caso de falha de alocação de memória.
 */
Pedido* criarPedido(const char* descricao);

#endif // PEDIDO_H
