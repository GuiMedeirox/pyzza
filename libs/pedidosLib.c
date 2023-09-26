#include <stdio.h> 
#include "pedidosLib.h"

int menuPedidos(){
  int opcao; 

  printf("1. Cadastrar um novo pedido\n");
  printf("2. Buscar um pedido específico\n");
  printf("3. Ver os pedidos\n");
  printf("4. Editar um pedido\n");
  printf("5. Deletar um pedido\n");
  printf("Opção: \n"); 
  scanf("%d", &opcao);

  switch (opcao){
    case 1: 
    printf("Digita o CPF do cliente:\n "); 
    printf("Digita o sabor da pizza:\n "); 
    break;
    case 2: 
    printf("Digita o id do pedido: \n");
    break;
    case 3:
    //showpedidos(); 
    break;
    case 4: 
    printf("Digita o id do pedido a ser editado: \n");
    break; 
    case 5: 
    printf("Digita o id do pedido a ser deletado: \n");
    break; 
    default: 
    printf("Opção inválida."); 

}


}