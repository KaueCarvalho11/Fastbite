<h1 align="center">FastBite</h1>    
Sistema de gerenciamento de pedidos e cardápio para um restaurante. O sistema oferece duas opções de acesso: como cliente ou como loja, permitindo diferentes funcionalidades dependendo do modo de acesso.

##  📖 Índice  
- [Funcionalidades](#funcionalidades)    
- [Estruturas de Dados Utilizadas](#estruturas-de-dados-utilizadas)   
- [Clonar repositório](#clonar-repositorio)  
- [Compilar](#compilar)  
- [Instruções de uso](#instrucoes-de-uso)  
- [Estrutura de Arquivos](#estrutura-de-arquivos) 
- [Colaboradores](#colaboradores) 

<a id="funcionalidades"></a>
## 🔍 Funcionalidades

### Modo Cliente
No modo cliente, os usuários podem:

* **Visualizar cardápio**

Permite que o cliente veja o cardápio disponível.

* **Fazer pedido**

O cliente pode fazer um novo pedido, especificando a descrição do pedido. O pedido é então adicionado à fila de pedidos na ordem em que foi feito.

### Modo Loja
No modo loja, os usuários podem:

* **Enviar pedido**

Envia o pedido com maior prioridade para entrega. A prioridade é determinada pela ordem de criação dos pedidos (primeiro a entrar, primeiro a sair - FIFO).


* **Listar pedidos**

Lista todos os pedidos armazenados na tabela hash, mostrando o ID do pedido e a descrição.


* **Cancelar pedido**

Permite ao administrador cancelar um pedido específico, removendo-o da heap e da tabela hash.

* **Sair**

Sai do modo loja.

<a id="estruturas-de-dados-utilizadas"></a>
##  📊 Estruturas de Dados Utilizadas

### Árvore Binária
Utilizada para armazenar e gerenciar os itens do cardápio, permitindo adições, remoções e alterações eficientes.

### Heap Mínima
Utilizada para gerenciar os pedidos na ordem de prioridade (baseada na ordem de chegada).

### Tabela Hash
Utilizada para armazenar e acessar rapidamente os pedidos usando o ID do pedido como chave.

<a id="clonar-repositorio"></a>
## ♻ Clonar repositório
```Bash 
$ git clone https://github.com/KaueCarvalho11/Fastbite.git
```

<a id="compilar"></a>
## 📦 Compilar
```Bash
$ gcc -c cardapio.c main.c pedido.c
$ gcc -o fastbite.exe cardapio.o main.o pedido.o
```

<a id="instrucoes-de-uso"></a>
## 📝 Instruções de Uso 
1. Executar o programa
```bash
$ ./fastbite.exe
```
2. Navegar através do menu
 - Após a execução, o usuário pode navegar pelas funcionalidades do sistema através do menu:
```bash
--- Menu Cliente ---
1. Ver cardapio
2. Fazer pedido
3. Sair
Escolha uma opcao:
```

<a id="estrutura-de-arquivos"></a>
## 📁 Estrutura de Arquivos

* **src/main.c**

Contém a função principal e os menus de navegação.

* **src/cardapio.c** e **include/cardapio.h**

Implementação e definições para gerenciamento de cardápio usando árvore binária.

* **src/pedido.c** e **include/pedido.h**

 Implementação e definições para gerenciamento de pedidos utilizando heap e tabela hash.

<a id="colaboradores"></a> 
 ## 💻 Colaboradores
- [Franciêr Eduardo](https://github.com/FrancierLuz)
- [Francisco Ádrian](https://github.com/adrianviniciuscs)
- [Juanny Thayssa](https://github.com/Thayssz)
- [Kauê Carvalho](https://github.com/KaueCarvalho11)