
typedef struct Cliente Cliente;

struct Cliente{ 
  char nome[100]; 
  char cpf[12]; 
  char telefone[12]; 
  int status; 
  Cliente *proximo; 
};

void menuClientes();
void criarCliente();
void exibirClientes();
int buscarCliente();
void editarCliente();
void deletarCliente();
int verificaCPFDuplicado( char* cpf);
char *encontraCliente(char* cpf);
Cliente retornaCliente(const char* cpf);
void exibirClientesAlfabetica();