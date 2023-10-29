#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "pizzasLib.h"
#include "checkers.h"

void criarPizza(){
  clear();
  FILE* file = fopen("cardapio.dat", "ab");
  Pizza* p = (Pizza*) malloc(sizeof(Pizza));
  printf("--- Cadastro de Pizzas ---\n");
  do{
    printf("Digita o sabor da Pizza: ");
    scanf(" %100[^\n]", p->recheio);
   // fgets(p->descricao, sizeof(p->descricao), stdin);
    printf("Digita os ingredientes da pizza: ");
    scanf(" %150[^\n]", p->descricao);
    // fgets(p->recheio, sizeof(p->recheio), stdin); 
  } while( checkNome(p->recheio) == 0 && checkNome(p->descricao) == 0);

  printf("\nPizza criada com sucesso!");
  printf("\nO sabor escolhido foi: %s", p->recheio);
  printf("\nOs ingredientes do sabor %s sao %s: ", p->recheio, p->descricao); 
  fprintf (file, "%s | %s \n", p->recheio, p->descricao);
  fclose(file);
}

void buscaPizza(){
  FILE* file = fopen("cardapio.dat", "rb");
  Pizza* p = (Pizza*) malloc(sizeof(Pizza));
  char sabor[30];

  if(file == NULL){
    printf("Erro ao abrir o arquivo!");
  } else{
    printf("--- Busca de Pizzas ---\n");
    printf("Digita o sabor de pizza a ser buscado: ");
    scanf("%100[^\n]", sabor );

  
  }



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
      // buscaPizza(); 
    
    break; 
    case 3: 
    //12cardapio()
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
