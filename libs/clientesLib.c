#include <stdio.h>
#include "clientesLib.h"



void menuClientes(){
  int opcao; 

  printf("1. Cadastrar um novo cliente\n");
  printf("2. Buscar um cliente específico\n");
  printf("3. Ver os clientes\n");
  printf("4. Editar um cliente\n");
  printf("5. Deletar um cliente\n");
  printf("Opção: "); 
  scanf("%d", &opcao);

  switch (opcao){
    case 1: 
      printf("Digita o nome do cliente: \n"); 
      printf("Digita o CPF do cliente: \n"); 
      printf("Digita o telefone do cliente: \n"); 
      break; 
    
    case 2: 
      printf("Digita o CPF do cliente a ser buscado:\n ");
      break; 
    
    case 3: 
    //showclientes();
    break; 
    
    case 4 :
      printf("Digita o CPF do cliente a ser editado: \n");
      break; 
    
    case 5: 
      printf("Digita o CPF do cliente a ser deletado: \n");
      break; 
    
    // default: 
    // printf("Opção inválida."); 
  }

}
