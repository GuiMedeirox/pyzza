#include <stdio.h> 
#include "funcionarioLib.h"

int menuFuncionario(){
  int opcao; 

  printf("1. Cadastrar um novo funcionário\n");
  printf("2. Buscar um funcionário específico\n");
  printf("3. Ver os funcionários\n");
  printf("4. Editar um funcionário\n");
  printf("5. Deletar um funcionário\n");
  printf("Opção: "); 
  scanf("%d", &opcao);

  switch (opcao){
    case 1: 
    printf("Digita o nome do funcionário: "); 
    printf("Digita o CPF do funcionário: "); 
    printf("Digita o telefone do funcionário: "); 
    printf("Digita a função do funcionário: ");
    default: 
    printf("Opção inválida."); 
}
}