#include <stdio.h>
#include "clientesLib.h"



int menuClientes(){
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
    printf("Digita o nome do cliente: "); 
    printf("Digita o CPF do cliente: "); 
    printf("Digita o telefone do cliente: "); 
    default: 
    printf("Opção inválida."); 

}
}
