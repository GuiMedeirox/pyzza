typedef struct Funcionario Funcionario;
struct Funcionario{
  char nome[100]; 
  char cpf[12]; 
  char telefone[12]; 
  char funcao[50]; 
  int status;
};

void menuFuncionario();
void criarFuncionario();
void lerFuncionarios();
void buscarFuncionario();
void editarFuncionario();
void deletarFuncionario();