#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 
#include <ctype.h> 
#include "funcionarioLib.h"
#include "checkers.h"

void criarFuncionario(){
  clear();
  FILE* file = fopen("funcionarios.dat", "ab");
  Funcionario* f = (Funcionario*) malloc(sizeof(Funcionario));
  printf("--- Cadastro de Funcionários ---");
  
  do{
    printf("\nDigita o nome do funcionário: ");
    scanf(" %100[^\n]", f->nome);

    printf("Digita o CPF do funcionário: ");
    scanf(" %11[0-9]", f->cpf);
    getchar();
    
    printf("Digita o telefone do funcionário: ");
    scanf(" %11[0-9]", f->telefone); 
    getchar();

    printf("Digita a função do funcionário: ");
    scanf(" %50[^\n]", f->funcao);
    getchar();
  } while(checkTelefone(f->telefone) == 0 && checkNome(f->funcao) == 0 && checkCPF(f->cpf) == 0 && checkNome(f->nome) == 0 );
  
  printf("\nFuncionario cadastrado com sucesso!\n");
  printf("\nO nome escolhido foi: %s", f->nome);
  printf("\nTelefone: %s", f->telefone);
  printf("\nO CPF eh %s e o cargo: %s ", f->cpf, f->funcao); 
  fwrite(f, sizeof(Funcionario), 1, file);
  free(f);
  fclose(file); 
  }



void lerFuncionarios(){
  
  FILE *file = fopen("funcionarios.dat", "rb");
  Funcionario *f = (Funcionario*) malloc(sizeof(Funcionario));  
  if (file == NULL){
    printf("Erro ao abrir o arquivo de clientes!");
    exit(1);
  }

  while( fread(f, sizeof(Funcionario), 1, file) ){
    printf("%s | %s | %s | %s", f->nome, f->cpf, f->telefone, f->funcao);
  }
  fclose(file);
}
void buscarFuncionario(){
  clear();
  Funcionario *f = (Funcionario*) malloc(sizeof(Funcionario));
  FILE* file = fopen("funcionarios.dat", "rb");
  char cpf[12];

  if(file == NULL){
    printf("Erro ao abrir o arquivo!"); 
    exit(1);
  }

  printf("Digita o CPF do funcionário a ser buscado: ");
  scanf(" %12[^\n]", cpf);
  
  while(!feof(file)){
    fread(f, sizeof(Funcionario), 1, file);
    if( strcmp(f->cpf, cpf) == 0 ) {
      printf("O funcionario eh: %s", f->nome);
      fclose(file);
      break;
    }
  }
  free(f);
}
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
      criarFuncionario();
      break;
    case 2: 
      buscarFuncionario();
      break;
    case 3: 
      lerFuncionarios();
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
