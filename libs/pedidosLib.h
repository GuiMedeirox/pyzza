typedef struct Pedido Pedido;


struct Pedido{
  int idPedido;
  // Pizza *p;
  float total; 
  char tag[10];
  char cpf[11];
  int status;
};

void menuPedido();
void criarPedido();
// void verPedidos();
