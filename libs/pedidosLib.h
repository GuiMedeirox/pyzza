typedef struct Pedido Pedido;


struct Pedido{
  int idPedido;
  float totalPedido; 
  int status;
  char tag[10];
  char cpf[11];
  char *clienteNome; 
  char *saborPizza; 
  char *tamanhoPizza; 
  float precoPizza; 
};

void menuPedido();
void criarPedido();
void listarPedidos();
// void verPedidos();
