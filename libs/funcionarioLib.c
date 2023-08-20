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

  return opcao;
}