typedef struct Pizza Pizza;

struct Pizza{
  char tag[10];
  char sabor[100]; 
  char ingredientes[150]; 
  int status; 
};

void menuPizzas(); 
void criarPizza();
void editarPizza();
void deletarPizza();
void lerCardapio();
void buscarPizza();