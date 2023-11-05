#include <stdio.h> 
#include "pedidosLib.h"
#include "pizzasLib.h"
#include "clientesLib.h"

struct Pedido{
  int id; 
  // struct Cliente cliente; 
  // struct Pizza pizza;
};

void menuPedidos(){
  int opcao; 

  printf("Caro usuário, a parte do pedido tem como base o conceito de listas aninhadas, conteúdo que será abordado na 3a unidade. Sendo assim, este modulo será desenvolvido durante esse período.  ");
  printf("Volte em breve!");
  // printf("1. Cadastrar um novo pedido\n");
  // printf("2. Buscar um pedido específico\n");
  // printf("3. Ver os pedidos\n");
  // printf("4. Editar um pedido\n");
  // printf("5. Deletar um pedido\n");
  // printf("Opção: \n"); 
  //scanf("%d", &opcao);

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