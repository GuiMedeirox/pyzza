#include <stdio.h> 
#include <stdlib.h> 
#include "pizzasLib.h"
#include <string.h> 
#include "checkers.h"

void criarPizza(Pizza* p, const char* filename){ 
  FILE* file = fopen(filename, "ab");
  p = (Pizza*) malloc(sizeof(Pizza));
  printf("--- Cadastro de Pizzas ---\n");
  do{
    printf("Digita o tamanho da Pizza: ");
    scanf("%s", p->tamanho);
    getchar();
    printf("Digita o recheio: ");
    fgets(p->recheio, sizeof(p->recheio), stdin); 
  } while( checkNome(p->recheio) == 0 && checkNome(p->tamanho) == 0);

  fprintf (file, "%s %s", p->tamanho, p->recheio);
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
      Pizza *p;  
      criarPizza(p, "cardapio.dat");
      // free(p);
      break;

    case 2: 
    printf("Digita o sabor da pizza que você quer buscar: \n"); 
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
