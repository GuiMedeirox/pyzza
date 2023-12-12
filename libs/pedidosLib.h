typedef struct Pedido Pedido;


struct Pedido{
  int idPedido;
  float totalPedido; 
  int status;
  char tag[10];
  char cpf[12];
  char clienteNome[100]; 
  char saborPizza[100]; 
  char tamanhoPizza[2]; 
  float precoPizza; 
};

void menuPedido();
void criarPedido();
void listarPedidos();
void editarPedido();
int verificaIdPedido(int a); 
int obterTotal(int id);
void pagarPedido(int id);
void buscarPedidoPorCliente(const char* cpf);