#include <stdio.h> 
#include "funcionarioLib.h"

struct Funcionario{
  char* nome; 
  char* cpf; 
  char* telefone; 
  char* funcao; 
};

void menuFuncionario(){
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
    printf("Digita o nome do funcionário: \n"); 
    printf("Digita o CPF do funcionário: \n"); 
    printf("Digita o telefone do funcionário: \n"); 
    printf("Digita a função do funcionário: \n");
    break;
    case 2: 
    printf("Digita o CPF do funcionário: \n");
    break;
    case 3: 
    //showfuncionarios(); 
    break;
    case 4: 
    printf("Digita o CPF do funcionário a ser editado: \n");
    break;
    case 5: 
    printf("Digita o CPF do funcionário a sser deletado: \n");
    break;
    default: 
    printf("Opção inválida."); 
  }
}