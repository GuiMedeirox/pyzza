typedef struct Pizza Pizza;

struct Pizza{
  char tag[10];
  char sabor[100]; 
  char ingredientes[150]; 
  int status; 
  char tamanho[2]; 
  float total; 
};

float obterPreco(const char* tamanho);
char* obterTamanhoPizza(const char* tag);
void menuPizzas(); 
void criarPizza();
void editarPizza();
void deletarPizza();
void lerCardapio();
int buscarPizza();
void buscarPizzaIngrediente(); 
char* encontraPizza (const char* tag);
int verificaTAGDuplicada(const char* tag);