<h1 align="center">FastBite</h1>    
Sistema de gerenciamento de pedidos e cardápio para um restaurante. O sistema oferece duas opções de acesso: como cliente ou como loja, permitindo diferentes funcionalidades dependendo do modo de acesso.

##  📖 Índice  
- [Funcionalidades](#🔍-funcionalidades)    
- [Estruturas de Dados Utilizadas](#📊-estruturas-de-dados-utilizadas)   
- [Clonar repositório](#♻-clonar-repositório)  
- [Compilar](#📦-compilar)  
- [Instruções de uso](#📝-instruções-de-uso)  
- [Estrutura de Arquivos](#📁-estrutura-de-arquivos) 
- [Colaboradores](#💻-colaboradores) 

## 🔍 Funcionalidades

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

##  📊 Estruturas de Dados Utilizadas

### Árvore Binária
Utilizada para armazenar e gerenciar os itens do cardápio, permitindo adições, remoções e alterações eficientes.

### Heap Mínima
Utilizada para gerenciar os pedidos na ordem de prioridade (baseada na ordem de chegada).

### Tabela Hash
Utilizada para armazenar e acessar rapidamente os pedidos usando o ID do pedido como chave.

## ♻ Clonar repositório
```Bash 
$ git clone
https://github.com/KaueCarvalho11/Fastbite.git
```

## 📦 Compilar
```Bash
```

## 📝 Instruções de Uso

## 📁 Estrutura de Arquivos

* **src/main.c**

Contém a função principal e os menus de navegação.

* **src/cardapio.c** e **include/cardapio.h**

Implementação e definições para gerenciamento de cardápio usando árvore binária.

* **src/pedido.c** e **include/pedido.h**

 Implementação e definições para gerenciamento de pedidos utilizando heap e tabela hash.


 ## 💻 Colaboradores
- [Franciêr Eduardo](https://github.com/FrancierLuz)
- [Francisco Ádrian](https://github.com/adrianviniciuscs)
- [Juanny Thayssa](https://github.com/Thayssz)
- [Kauê Carvalho](https://github.com/KaueCarvalho11)