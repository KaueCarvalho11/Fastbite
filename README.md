# Fastbite
Sistema de gerenciamento de pedidos e cardápio para um restaurante. O sistema oferece duas opções de acesso: como cliente ou como loja, permitindo diferentes funcionalidades dependendo do modo de acesso.

## Funcionalidades

### Modo cliente
No modo cliente, os usuários podem:

#### <p align="center">Visualizar cardápio</p>
Permite que o cliente veja o cardápio disponível.

#### <p align="center">Fazer pedido</p>
O cliente pode fazer um novo pedido, especificando a descrição do pedido. O pedido é então adicionado à fila de pedidos na ordem em que foi feito.

### Modo loja
No modo loja, os usuários podem:

#### <p align="center">Enviar pedido</p>
Envia o pedido com maior prioridade para entrega. A prioridade é determinada pela ordem de criação dos pedidos (primeiro a entrar, primeiro a sair - FIFO).

#### <p align="center">Listar pedidos</p>
Lista todos os pedidos armazenados na tabela hash, mostrando o ID do pedido e a descrição.


#### <p align="center">Cancelar pedido</p>
Permite ao administrador cancelar um pedido específico, removendo-o da heap e da tabela hash.




