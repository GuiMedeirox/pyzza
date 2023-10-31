#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <ctype.h> 
#include "pizzasLib.h"
#include "checkers.h"

void criarPizza(){
  clear();
  FILE* file = fopen("cardapio.dat", "ab");
  Pizza* p = (Pizza*) malloc(sizeof(Pizza));
  printf("--- Cadastro de Pizzas ---\n");
  do{
    printf("Digita o sabor da Pizza: ");
    scanf(" %100[^\n]", p->sabor);
    getchar();
   // fgets(p->descricao, sizeof(p->descricao), stdin);
    printf("Digita os ingredientes da pizza: ");
    scanf(" %150[^\n]", p->ingredientes);
    // fgets(p->recheio, sizeof(p->recheio), stdin); 
  } while( checkNome(p->sabor) == 0 && checkNome(p->ingredientes) == 0);

  printf("\nPizza criada com sucesso!");
  printf("\nO sabor escolhido foi: %s", p->sabor);
  printf("\nOs ingredientes do sabor %s sao: %s ", p->sabor, p->ingredientes); 
  //fprintf (file, "%s | %s \n", p->sabor, p->ingredientes);
  fwrite(p, sizeof(Pizza), 1, file);
  free(p);
  fclose(file); 
}

void lerCardapio(){
  clear();
  FILE* file = fopen("cardapio.dat", "rb");
  if(file == NULL){
      printf("Erro ao abrir o arquivo!\n");
      exit(1);
    }
  Pizza* p = (Pizza*) malloc(sizeof(Pizza));
  

  while(fread(p, sizeof(Pizza), 1, file)){
    printf("Sabor: %s || Ingredientes: %s\n", p->sabor, p->ingredientes);
  }
  fclose(file);
}

void buscarPizza(){ 
  clear();
  char sabor[100];
  FILE* file = fopen("cardapio.dat", "rb");
  Pizza* p = (Pizza*) malloc(sizeof(Pizza));
  if(file == NULL){
      printf("Erro ao abrir o arquivo!\n");
      exit(1);
  }

  printf("Digita o sabor que você quer buscar: ");
  scanf(" %100[^\n]", sabor);
  while(fread(p, sizeof(Pizza), 1, file)){
    printf("%s %s", p->sabor, sabor);
    if(strcmp(p->sabor, sabor ) == 0){
      printf("%s", p->sabor);
    }
  }
  fclose(file);
  free(p);
}

void menuPizzas(){
  int opcao; 

  printf("1. Cadastrar um novo sabor de pizza\n");
  printf("2. Buscar um sabor de pizza específico\n");
  printf("3. Ver o cardápio\n");
  printf("4. Editar um sabor de pizza\n");
  printf("5. Deletar um sabor de pizza\n");
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
    printf("Digita o sabor da pizza que você quer editar: \n");
    break; 
    case 5: 
    printf("Digita o sabor da pizza que você quer deletar: \n");
    break; 
    default: 
    printf("Opção inválida."); 

}

}
