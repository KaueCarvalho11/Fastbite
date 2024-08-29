# Fastbite
Sistema de gerenciamento de pedidos e cardápio para um restaurante. O sistema oferece duas opções de acesso: como cliente ou como loja, permitindo diferentes funcionalidades dependendo do modo de acesso.

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




