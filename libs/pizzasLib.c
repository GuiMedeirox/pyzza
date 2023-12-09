#include "all.h"

float obterPreco(const char* tamanho);
void criarPizza();


void criarPizza(){
  clear();
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

  do{
      p->idPizza = rand() % 1000000;
    } while(verificaIDDuplicado(p->idPizza) == 1);

    printf("Digita o tamanho da pizza: ");
    scanf(" %2[^\n]", p->tamanho);

    if ( strcmp(p->tamanho, "P") == 0 || strcmp(p->tamanho, "p") == 0 ){
    } else if (strcmp(p->tamanho, "M") == 0 || strcmp(p->tamanho, "m") == 0  ){
    } else if ( strcmp(p->tamanho, "G") == 0 || strcmp(p->tamanho, "g") == 0  ){
    } else if ( strcmp(p->tamanho, "GG") == 0 || strcmp(p->tamanho, "gg") == 0  ){
    } else{
      strcpy(p->tamanho,"00");
    }
    while(strcmp(p->tamanho, "00")==0){
      printf("Insere o tamanho da pizza novamente: ");
      getchar();
      scanf(" %2[^\n]", p->tamanho);

    }

  printf("\nPizza criada com sucesso!");
  printf("\nO sabor escolhido foi: %s", p->sabor);
  printf("\nOs ingredientes do sabor %s sao: %s ", p->sabor, p->ingredientes);
  printf("\nTamanho da pizza: %s", p->tamanho);
  printf("\nID da pizza: %d", p->idPizza);
  p->total = obterPreco(p->tamanho);
  printf("\nPreco da pizza: %f", p->total);
  p->status=1;

  fwrite(p, sizeof(Pizza), 1, file);



  free(p);
  fclose(file); 
}

int verificaIDDuplicado(int id) {
    FILE* file = fopen("cardapio.dat", "rb");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return 0; 
    }

    Pizza pizza;

    while (fread(&pizza, sizeof(Pizza), 1, file) == 1) {
        if (pizza.idPizza == id) {            
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
}

char* encontraPizza (int id){
    Pizza p;
    FILE *file = fopen("cardapio.dat", "rb"); // Abre o arquivo para leitura

    if (file == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return NULL;
    }

    while (fread(&p, sizeof(Pizza), 1, file) == 1) {
        if ( id == p.idPizza) {
    
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
      printf("ID: %d \n", p->idPizza);
      printf("Tamanho %s \n", p->tamanho);
      printf("Preco: %f\n", p->total);
      printf(">-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<\n");
    }
  }
  fclose(file);
}

int buscarPizza(){ 
  clear();
  int id; 
  FILE* file = fopen("cardapio.dat", "rb");
  Pizza* p = (Pizza*) malloc(sizeof(Pizza));
  if(file == NULL){
      printf("Erro ao abrir o arquivo!\n");
      exit(1);
  }

  printf("Digita o ID da pizza que você quer buscar: ");
  scanf(" %d", &id);

  while(!feof(file)){
    fread(p, sizeof(Pizza), 1, file);
    if( id == p->idPizza && p->status==1) {
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
  int id; 
  int opt;

  if(file == NULL){
    printf("Erro ao abrir o arquivo!"); 
    exit(1);
  }

  printf("Digita o ID da pizza a ser editado: ");
  scanf(" %d", &id);


  while(fread(&pizzaEditada, sizeof(Pizza), 1, file) == 1){
    if(pizzaEditada.idPizza == id){
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
  int id; 

  if(file == NULL){
    printf("Erro ao abrir o arquivo!"); 
    exit(1);
  }

  printf("Digita a ID da pizza a ser editado: ");
  scanf(" %d", &id);
  
  while(fread(&p, sizeof(Pizza), 1, file) == 1){
    if(p.idPizza==id && p.status == 1){
      printf("Deletando o sabor de pizza: %s", p.sabor);
      p.status = 0;
      fseek(file, -sizeof(Pizza), SEEK_CUR);
      fwrite(&p, sizeof(Pizza), 1, file);
    }
  }
  fclose(file);
}

char* obterTamanhoPizza(int id){
  Pizza p; 
  FILE* file = fopen("cardapio.dat", "rb");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return NULL;
    }

    while (fread(&p, sizeof(Pizza), 1, file) == 1) {
        if (id == p.idPizza) {
    
            char *result = (char *)malloc(strlen(p.tamanho) + 1);
            if (result == NULL) {
                printf("Erro ao alocar memória.\n");
                fclose(file);
                return NULL;
            }

    
            strcpy(result, p.tamanho);
            fclose(file);
            return result;
        }
    }
    
    fclose(file);
    return NULL;
}

float obterPreco(const char* tamanho) {

  if ( strcmp(tamanho, "P") == 0 || strcmp(tamanho, "p") == 0 ){
    return 20.0;
  } else if (strcmp(tamanho, "M") == 0 || strcmp(tamanho, "m") == 0  ){
    return 25.0;
  } else if ( strcmp(tamanho, "G") == 0 || strcmp(tamanho, "g") == 0  ){
    return 30.0;
  } else if ( strcmp(tamanho, "GG") == 0 || strcmp(tamanho, "gg") == 0  ){
    return 35.0;
  } else{
    return 0.0;
  }

}

void exibirPizzaOrdemAlfabetica(){
    system("clear||cls");
    FILE* file;
    Pizza* novaPizza;  
    Pizza* listaPizza;  

    file = fopen("cardapio.dat", "rb");  
    if (file == NULL) {
        printf("Erro ao abrir o arquivo\n");
        exit(1); 
    }

    printf("\n-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#\n");  
    printf("Pizzas em ordem alfabetica: \n");

    listaPizza = NULL;  
    novaPizza = (Pizza*)malloc(sizeof(Pizza)); 
    if (novaPizza == NULL) {   
        printf("Erro de alocacao de memoria\n");
        exit(1); 
    }

    while (fread(novaPizza, sizeof(Pizza), 1, file) == 1) {  
        novaPizza->proxima = NULL;  

        if ((listaPizza == NULL) || (strcmp(novaPizza->sabor, listaPizza->sabor) < 0)) {  
            novaPizza->proxima = listaPizza; 
            listaPizza = novaPizza;  
        } else {  
            Pizza* pizzaAnterior = listaPizza;  
            Pizza* pizzaAtual = listaPizza->proxima;   
            while ((pizzaAtual != NULL) && strcmp(pizzaAtual->sabor, novaPizza->sabor) < 0) {  
                pizzaAnterior = pizzaAtual; 
                pizzaAtual = pizzaAtual->proxima;
            }
            pizzaAnterior->proxima = novaPizza;  
            novaPizza->proxima = pizzaAtual;  
        }

        novaPizza = (Pizza*)malloc(sizeof(Pizza));
        if (novaPizza == NULL) {
            printf("Erro de alocacao de memoria\n");
            exit(1);
        }
    }

    fclose(file);  

    novaPizza = listaPizza;  
    while (novaPizza != NULL) {  
        printf("%s\n", novaPizza->sabor);
        novaPizza = novaPizza->proxima;   
    }

    novaPizza = listaPizza;  
    while (listaPizza != NULL) {
        listaPizza = listaPizza->proxima;  
        free(novaPizza); 
        novaPizza = listaPizza; 
    }
    printf("\n");
}

void menuPizzas(){
  int opcao; 

  printf("1. Cadastrar um novo sabor de pizza\n");
  printf("2. Buscar um sabor de pizza específico\n");
  printf("3. Ver o cardápio\n");
  printf("4. Exibir cardapio em ordem alfabetica\n");
  printf("5. Buscar uma pizza por um ingrediente \n");
  printf("6. Editar um sabor de pizza\n");
  // printf("7. Deletar um sabor de pizza\n");
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
      exibirPizzaOrdemAlfabetica();
      break;

    case 5: 
      buscarPizzaIngrediente();
      break; 
    case 6: 
      editarPizza();
      break;
    // case 7:
    //   deletarPizza();
    //   break; 
    default: 
    printf("Opção inválida."); 

  }

}
