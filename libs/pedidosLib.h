typedef struct Pedido Pedido;


struct Pedido{
  int idPedido;
  // Pizza *p;
  float total; 
  int status;
  char tag[10];
  char cpf[11];
};

void menuPedido();
void criarPedido();
// void verPedidos();
