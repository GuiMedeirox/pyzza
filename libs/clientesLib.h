typedef struct Cliente Cliente; 
struct Cliente{ 
  char nome[100]; 
  char cpf[12]; 
  char telefone[11]; 
};
void menuClientes();
void criarCliente();
void exibirClientes();
void buscarCliente();
void editarCliente();
void deletarCliente();
