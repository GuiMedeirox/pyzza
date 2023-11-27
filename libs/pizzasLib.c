#include "all.h"

float obterPreco(const char* tamanho);
void criarPizza();


void criarPizza(){
  clear();
  char tamanhoStr[2];
  FILE* file = fopen("cardapio.dat", "ab");
  Pizza* p = (Pizza*) malloc(sizeof(Pizza));
  printf("--- Cadastro de Pizzas ---\n");
  

    printf("Digita o sabor da Pizza: ");
    scanf(" %100[^\n]", p->sabor);
    getchar();
    while( checkNome(p->sabor) != 1 ){
      printf("Sabor invalido, digite novamente: ");
      scanf(" %100[^\n]", p->sabor);
    }

    printf("Digita os ingredientes da pizza: ");
    scanf(" %150[^\n]", p->ingredientes);
    getchar();
    while( checkNome(p->ingredientes) != 1 ){
      printf("Ingredientes invalidos, digite novamente: ");
      scanf(" %150[^\n]", p->ingredientes);
    }
    printf("(Digita a TAG + tamanho da pizza, exemplo: Frango Catupiry, tamanho G -> FCTPG)\n");
    printf("Digita a tag da pizza: ");
    scanf(" %10[^\n]", p->tag);
    
    while( checkNome(p->tag) != 1 || verificaTAGDuplicada(p->tag) == 1){
      printf("TAG invalida ou ja esta em uso, digita novamente: ");
      scanf(" %10[^\n]", p->tag);
    }

    printf("Digita o tamanho da pizza: ");
    scanf(" %2[^\n]", p->tamanho);

    while( p->tamanho == NULL ){
      printf("Tamanho invalido, insira novamente: ");
      scanf(" %2[^\n]", p->tamanho);
    }



  printf("\nPizza criada com sucesso!");
  printf("\nO sabor escolhido foi: %s", p->sabor);
  printf("\nOs ingredientes do sabor %s sao: %s ", p->sabor, p->ingredientes);
  printf("\nTamanho da pizza: %s", p->tamanho);
  printf("\nTag da pizza: %s", p->tag);
  p->total = obterPreco(p->tamanho);
  printf("\nPreco da pizza: %f", p->total);
  p->status=1;

  fwrite(p, sizeof(Pizza), 1, file);
  free(p);
  fclose(file); 
}

int verificaTAGDuplicada(const char* tag) {
    FILE* file = fopen("cardapio.dat", "rb");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return 0; 
    }

    Pizza pizza;

    while (fread(&pizza, sizeof(Pizza), 1, file) == 1) {
        if (strcmp(pizza.tag, tag) == 0) {            
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
}

char* encontraPizza (const char* tag){
    Pizza p;
    FILE *file = fopen("cardapio.dat", "rb"); // Abre o arquivo para leitura

    if (file == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return NULL;
    }

    while (fread(&p, sizeof(Pizza), 1, file) == 1) {
        if (strcmp(p.tag, tag) == 0) {
    
            char *result = (char *)malloc(strlen(p.sabor) + 1);
            if (result == NULL) {
                printf("Erro ao alocar memória.\n");
                fclose(file);
                return NULL;
            }

    
            strcpy(result, p.sabor);
            fclose(file);
            return result;
        }
    }
    
    fclose(file);
    return NULL;
}


void lerCardapio(){
  clear();
  FILE* file = fopen("cardapio.dat", "rb");
  Pizza* p = (Pizza*) malloc(sizeof(Pizza));
  if(file == NULL){
      printf("Erro ao abrir o arquivo!\n");
      exit(1);
    }
  while(fread(p, sizeof(Pizza), 1, file)){
    if(p->status == 1){
      printf("Sabor: %s\n", p->sabor);
      printf("Ingredientes: %s\n", p->ingredientes);
      printf("TAG: %s\n", p->tag);
      printf("Preco: %f\n", p->total);
      printf(">-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<\n");
    }
  }
  fclose(file);
}

int buscarPizza(){ 
  clear();
  char tag[10];
  FILE* file = fopen("cardapio.dat", "rb");
  Pizza* p = (Pizza*) malloc(sizeof(Pizza));
  if(file == NULL){
      printf("Erro ao abrir o arquivo!\n");
      exit(1);
  }

  printf("Digita a TAG da pizza que você quer buscar: ");
  scanf(" %10[^\n]", tag);

  while(!feof(file)){
    fread(p, sizeof(Pizza), 1, file);
    if( strcmp(p->tag, tag) == 0 && p->status==1) {
      printf("%s", p->sabor);
      fclose(file);
      return 0; 
      break;
    }
  }
  free(p);
  return 1; 
}

void buscarPizzaIngrediente(){
  clear();
  char ingredientes[150];
  FILE* file = fopen("cardapio.dat", "rb");
  Pizza* p = (Pizza*) malloc(sizeof(Pizza));
  if(file == NULL){
      printf("Erro ao abrir o arquivo!\n");
      exit(1);
  }

  printf("Digita, pelo menos, um dos ingredientes que você quer buscar: ");
  scanf(" %150[^\n]", ingredientes);
  while(!feof(file)){
    fread(p, sizeof(Pizza), 1, file);
    if( strstr(p->ingredientes, ingredientes) != NULL && p->status==1 ) {
      printf("%s \n", p->ingredientes);
    }
    if(feof(file)){
        fclose(file);
        free(p);
        break;
    }
  }
}

void editarPizza(){
  clear();
  Pizza pizzaEditada;
  FILE* file = fopen("cardapio.dat", "rb+");
  char tag[10];
  int opt;

  if(file == NULL){
    printf("Erro ao abrir o arquivo!"); 
    exit(1);
  }

  printf("Digita a TAG da pizza a ser editado: ");
  scanf(" %10[^\n]", tag);


  while(fread(&pizzaEditada, sizeof(Pizza), 1, file) == 1){
    if(strcmp(pizzaEditada.tag, tag) == 0){
      printf("Digita qual campo você vai querer editar: \n");
      printf("1. nome\n");
      printf("2. ingredientes\n");
      scanf("%i", &opt);
     
      if(opt == 1){
        printf("Digita a correcao do sabor: ");
        scanf(" %100[^\n]", pizzaEditada.sabor);
        while(checkNome(pizzaEditada.sabor) != 1){
          printf("Sabor inválido, digite novamente: ");
          scanf(" %100[^\n]", pizzaEditada.sabor);
        }
      } else if(opt == 2){
        printf("Digita a nova lista de ingredientes: ");
        scanf(" %150[^\n]", pizzaEditada.ingredientes);
        while(checkNome(pizzaEditada.ingredientes) != 1){
          printf("Lista de ingredientes inválida, digite novamente: ");
          scanf(" %150[^\n]", pizzaEditada.ingredientes);
        }
      }
      printf("Pizza editada! \n");
      fseek(file, -sizeof(Pizza), SEEK_CUR);
      fwrite(&pizzaEditada, sizeof(Pizza), 1, file);
    }
  }
  
  fclose(file);

}

void deletarPizza(){
  clear();
  Pizza p;
  FILE* file = fopen("cardapio.dat", "rb+");
  char tag[10];
  int opt;

  if(file == NULL){
    printf("Erro ao abrir o arquivo!"); 
    exit(1);
  }

  printf("Digita a TAG da pizza a ser editado: ");
  scanf(" %10[^\n]", tag);
  
  while(fread(&p, sizeof(Pizza), 1, file) == 1){
    if(strcmp(p.tag, tag) == 0 && p.status == 1){
      printf("Deletando o sabor de pizza: %s", p.sabor);
      p.status = 0;
      fseek(file, -sizeof(Pizza), SEEK_CUR);
      fwrite(&p, sizeof(Pizza), 1, file);
    }
  }
  fclose(file);
}

float obterPreco(const char* tamanho) {

  if ( strcmp(tamanho, "P") == 0 ){
    return 20.0;
  } else if ( strcmp(tamanho, "M") == 0 ){
    return 25.0;
  } else if ( strcmp(tamanho, "G") == 0 ){
    return 30.0;
  } else if ( strcmp(tamanho, "GG") == 0 ){
    return 35.0;
  } else{
    return 0.0;
  }

}

void menuPizzas(){
  int opcao; 

  printf("1. Cadastrar um novo sabor de pizza\n");
  printf("2. Buscar um sabor de pizza específico\n");
  printf("3. Ver o cardápio\n");
  printf("4. Buscar uma pizza por um ingrediente \n");
  printf("5. Editar um sabor de pizza\n");
  printf("6. Deletar um sabor de pizza\n");
  printf("Opção: ");
  scanf("%i", &opcao);  

  switch (opcao){
    case 1: 
      criarPizza();
      break;

    case 2: 
      buscarPizza();
      break; 
    
    case 3: 
      lerCardapio();
      break; 
   
    case 4: 
      buscarPizzaIngrediente();
      break;

    case 5: 
      editarPizza();
      break; 
    case 6: 
      deletarPizza();
      break; 
    default: 
    printf("Opção inválida."); 

  }

}
