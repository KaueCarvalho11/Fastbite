# Fastbite
Sistema de gerenciamento de pedidos e cardápio para um restaurante. O sistema oferece duas opções de acesso: como cliente ou como loja, permitindo diferentes funcionalidades dependendo do modo de acesso.

## Índice  
- [Funcionalidades](#funcionalidades)  
- [Modo cliente](#modo-cliente)  
- [Modo loja](#modo-loja)  
- [Estruturas de Dados Utilizadas](#estruturas-de-dados-utilizadas)  
- [Árvore Binária](#árvore-binária)  
- [Heap Mínima](#heap-mínima)  
- [Tabela Hash](#tabela-hash)  
- [Compilação](#compilação)  
- [Instruções de Uso](#instruções-de-uso)  
- [Estrutura de Arquivos](#estrutura-de-arquivos)  


## Funcionalidades

### Modo cliente
No modo cliente, os usuários podem:

* **Visualizar cardápio**

Permite que o cliente veja o cardápio disponível.

* **Fazer pedido**

O cliente pode fazer um novo pedido, especificando a descrição do pedido. O pedido é então adicionado à fila de pedidos na ordem em que foi feito.

### Modo loja
No modo loja, os usuários podem:

* **Enviar pedido**

Envia o pedido com maior prioridade para entrega. A prioridade é determinada pela ordem de criação dos pedidos (primeiro a entrar, primeiro a sair - FIFO).


* **Listar pedidos**

Lista todos os pedidos armazenados na tabela hash, mostrando o ID do pedido e a descrição.


* **Cancelar pedido**

Permite ao administrador cancelar um pedido específico, removendo-o da heap e da tabela hash.

* **Sair**

Sai do modo loja.

## Estruturas de Dados Utilizadas

### Árvore Binária
Utilizada para armazenar e gerenciar os itens do cardápio, permitindo adições, remoções e alterações eficientes.

### Heap Mínima
Utilizada para gerenciar os pedidos na ordem de prioridade (baseada na ordem de chegada).

### Tabela Hash
Utilizada para armazenar e acessar rapidamente os pedidos usando o ID do pedido como chave.

## Compilação

## Instruções de Uso

## Estrutura de Arquivos

* **src/main.c**

Contém a função principal e os menus de navegação.

* **src/cardapio.c** e **include/cardapio.h**

Implementação e definições para gerenciamento de cardápio usando árvore binária.

* **src/pedido.c** e **include/pedido.h**

 Implementação e definições para gerenciamento de pedidos utilizando heap e tabela hash.