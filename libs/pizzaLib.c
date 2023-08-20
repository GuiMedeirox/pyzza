#include <stdio.h> 
#include "pizzaLib.h"

int menuPizza(){
  int opcao; 
  
  printf("1. Cadastrar um novo sabor de pizza\n");
  printf("2. Buscar um sabor de pizza específico\n");
  printf("3. Ver o cardápio\n");
  printf("4. Editar um sabor de pizza\n");
  printf("5. Deletar um sabor de pizza\n");
  printf("Opção: ");
  scanf("%d", &opcao);

  return opcao; 
}