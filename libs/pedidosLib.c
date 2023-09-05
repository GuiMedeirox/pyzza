#include <stdio.h> 
#include "pedidosLib.h"

int menuPedidos(){
  int opcao; 

  printf("1. Cadastrar um novo pedido\n");
  printf("2. Buscar um pedido específico\n");
  printf("3. Ver os pedidos\n");
  printf("4. Editar um pedido\n");
  printf("5. Deletar um pedido\n");
  printf("Opção: "); 
  scanf("%d", &opcao);

  switch (opcao){
    case 1: 
    printf("Digita o CPF do cliente: "); 
    printf("Digita o sabor da pizza: "); 
    default: 
    printf("Opção inválida."); 

}


}