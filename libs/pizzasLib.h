typedef struct Pizza Pizza;

struct Pizza{
  char tag[10];
  char sabor[100]; 
  char ingredientes[150]; 
  int status; 
};

enum Tamanho{
  P = 20, 
  M = 30,
  G = 40,
  GG= 50
};

void menuPizzas(); 
void criarPizza();
void editarPizza();
void deletarPizza();
void lerCardapio();
void buscarPizza();
void buscarPizzaIngrediente();
int verificaTAGDuplicada(const char* tag);