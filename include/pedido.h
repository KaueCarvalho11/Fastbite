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

/**
 * @brief Insere um pedido na heap.
 *
 * Esta função insere um pedido na heap, mantendo a propriedade de heap.
 *
 * @param heap A heap onde o pedido será inserido
 * @param pedido O pedido a ser inserido
 */
void inserirPedidoHeap(Heap *heap, Pedido *pedido);


/**
 * @brief Remove o pedido com o menor timestamp da heap.
 *
 * Esta função remove o pedido com o menor timestamp da heap e o retorna.
 *
 * @param heap A heap de onde o pedido será removido
 * @return O pedido com o menor timestamp
 */
void trocarPedidos(Pedido **a, Pedido **b);

/**
 * @brief Remove o pedido com o menor timestamp da heap.
 *
 * Esta função remove o pedido com o menor timestamp da heap e o retorna.
 *
 * @param heap A heap de onde o pedido será removido
 * @return O pedido com o menor timestamp
 */
void minimizarHeap(Heap *heap, int i);

/**
 * @brief Remove o pedido com o menor timestamp da heap.
 *
 * Esta função remove o pedido com o menor timestamp da heap e o retorna.
 *
 * @param heap A heap de onde o pedido será removido
 * @return O pedido com o menor timestamp
 */
Pedido* extrairMinimo(Heap *heap);

/**
 * @brief Cria um novo pedido.
 *
 * Esta função cria um novo pedido e o adiciona na heap de pedidos.
 *
 * @param heap A heap pra onde o pedido vai ser adicionado.
 */
void fazerPedido(Heap *heap);

/**
 * @brief Envia o pedido com o menor timestamp para entrega.
 *
 * Esta função extrai o pedido com o menor timestamp da heap (que representa
 * o pedido mais antigo ou com maior prioridade). Se houver um pedido disponível,
 * ele é enviado para entrega e removido da heap. A função então libera a memória
 * alocada para o pedido. Caso não haja pedidos, uma mensagem informando que não
 * há pedidos disponíveis é exibida.
 *
 * @param heap A heap de onde o pedido será extraído e enviado.
 */
void enviarPedido(Heap *heap);

/**
 * @brief Imprime todos os pedidos na heap.
 *
 * Esta função imprime todos os pedidos na heap.
 *
 * @param heap A heap a ser impressa
 */
void imprimirPedidos(Heap *heap);

#endif // PEDIDO_H
