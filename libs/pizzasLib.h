typedef struct Pizza Pizza;

struct Pizza{
  // char tag[10];
  int idPizza; 
  char sabor[100]; 
  char ingredientes[150]; 
  int status; 
  char tamanho[2]; 
  float total; 
  Pizza* proxima; 
};

float obterPreco(const char* tamanho);
char* obterTamanhoPizza(int id);
void menuPizzas(); 
void criarPizza();
void editarPizza();
// void deletarPizza();
void lerCardapio();
int buscarPizza();
void buscarPizzaIngrediente(); 
char* encontraPizza (int id);
int verificaIDDuplicado(int id);
void exibirPizzaOrdemAlfabetica();