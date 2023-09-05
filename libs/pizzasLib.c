#include <stdio.h> 
#include "pizzasLib.h"

int menuPizzas(){
  int opcao; 
  
  printf("1. Cadastrar um novo sabor de pizza\n");
  printf("2. Buscar um sabor de pizza específico\n");
  printf("3. Ver o cardápio\n");
  printf("4. Editar um sabor de pizza\n");
  printf("5. Deletar um sabor de pizza\n");
  printf("Opção: ");
  scanf("%d", &opcao);

   switch (opcao){
    case 1: 
    printf("Digita o sabor da pizza: "); 
    printf("Digita os ingrediente ");
    default: 
    printf("Opção inválida."); 

}

}
