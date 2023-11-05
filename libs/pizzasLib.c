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

    printf("Digita a tag da pizza: ");
    scanf(" %10[^\n]", p->tag);

    
    while( checkNome(p->tag) != 1){
      printf("TAG Invalida, digita novamente: ");
      scanf(" %10[^\n]", p->tag);
    }
   
  printf("\nPizza criada com sucesso!");
  printf("\nO sabor escolhido foi: %s", p->sabor);
  printf("\nOs ingredientes do sabor %s sao: %s ", p->sabor, p->ingredientes);
  printf("\nTag da pizza: %s", p->tag);
  p->status=1;

  fwrite(p, sizeof(Pizza), 1, file);
  free(p);
  fclose(file); 
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
      printf("Sabor: %s || Ingredientes: %s || tag: %s\n", p->sabor, p->ingredientes, p->tag);
    }
  }
  fclose(file);
}

void buscarPizza(){ 
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
      break;
    }
  }
  free(p);
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
      printf("Pizza editada! \n");
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
      editarPizza();
      break; 
    case 5: 
      deletarPizza();
      break; 
    default: 
    printf("Opção inválida."); 

}

}
