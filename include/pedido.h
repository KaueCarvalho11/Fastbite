#ifndef PEDIDO_H
#define PEDIDO_H

#include <stdlib.h>

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
 * um valor de hash para um ID inteiro, garantindo que ele se encaixe no tamanho da tabela hash.
 *
 * @param id O ID inteiro a ser hashado.
 * @return Um valor de hash inteiro sem sinal dentro do intervalo [0, TAMANHO_HASH - 1].
 */
unsigned int hash(int id);

#endif // PEDIDO_H
