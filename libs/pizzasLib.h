typedef struct Pizza Pizza;

struct Pizza{
  char tamanho[3]; 
  char recheio[100]; 
};

void menuPizzas(); 
Pizza* criarPizza();