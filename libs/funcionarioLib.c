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

    scanf(" %50[^\n]", f->funcao);
    getchar();
  } while(checkTelefone(f->telefone) == 0 && checkNome(f->funcao) == 0 && checkCPF(f->cpf) == 0 && checkNome(f->nome) == 0 );
  
  f->status=1;

  printf("\nFuncionario cadastrado com sucesso!\n");
  printf("\nO nome escolhido foi: %s", f->nome);
  printf("\nTelefone: %s", f->telefone);
  printf("\nO CPF eh %s e o funcao: %s ", f->cpf, f->funcao); 
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
    if(f->status == 1){
    printf("%s | %s | %s | %s | %i", f->nome, f->cpf, f->telefone, f->funcao, f->status);
    }
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
  scanf(" %11[^\n]", cpf);
  
  while(!feof(file)){
    fread(f, sizeof(Funcionario), 1, file);
    if( strcmp(f->cpf, cpf) == 0 ) {
      if(f->status == 1){
        printf("O funcionario eh: %s", f->nome);
      }
      fclose(file);
      break;
    }
  }
  free(f);
}

void editarFuncionario(){
  clear();
  Funcionario funcionarioEditado;
  FILE* file = fopen("funcionarios.dat", "rb+");
  char cpf[12];
  int opt;

  if(file == NULL){
    printf("Erro ao abrir o arquivo!"); 
    exit(1);
  }

  printf("Digita o CPF do funcionário a ser editado: ");
  scanf(" %12[^\n]", cpf);
  
  while(fread(&funcionarioEditado, sizeof(Funcionario), 1, file) == 1){
    if(strcmp(funcionarioEditado.cpf, cpf) == 0){
      printf("Funcionario encontrado! \n");
      printf("Digita qual campo você vai querer editar: \n");
      printf("1. nome\n");
      printf("2. funcao\n");
      printf("3. telefone\n");
      scanf("%i", &opt);
     
      if(opt == 1){
        printf("Digita a correcao do nome: ");
        scanf(" %100[^\n]", funcionarioEditado.nome);
        while(checkNome(funcionarioEditado.nome) != 1){
          printf("Nome inválido, digite novamente: ");
          scanf(" %100[^\n]", funcionarioEditado.nome);
        }
      } else if(opt == 2){
        printf("Digita o novo cargo do funcionario: ");
        scanf(" %50[^\n]", funcionarioEditado.funcao);
        while(checkNome(funcionarioEditado.funcao) != 1){
          printf("Funcao inválida, digite novamente: ");
          scanf(" %50[^\n]", funcionarioEditado.funcao);
        }
      }else if(opt == 3){
        printf("Digita o novo telefone do funcionario: ");
        scanf("%11[^\n]", funcionarioEditado.telefone);
        while(checkTelefone(funcionarioEditado.telefone)!= 1){
          printf("Numero invalido, digite novamente: ");
          scanf(" %11[^\n]", funcionarioEditado.telefone);
        }
      }
      fseek(file, -sizeof(Funcionario), SEEK_CUR);
      fwrite(&funcionarioEditado, sizeof(Funcionario), 1, file);
    }
  }
  
  fclose(file);

}

void deletarFuncionario(){
  clear();
  Funcionario f; 
  FILE* file=fopen("funcionarios.dat","rb+");
  char cpf[12];

  printf("Digita o CPF do funcionario a ser deletado: "); 
  scanf("%s", cpf);

  if(file == NULL){
    printf("Erro ao abrir o arquivo");
    exit(1);
  }

  while(fread(&f, sizeof(Funcionario),1, file) == 1){
    if (strcmp(f.cpf, cpf) == 0){
      printf("Deletando o funcionario %s, de cpf %s e funcao %s.", f.nome, f.cpf, f.funcao);
      f.status = 0; 
      long a = 1L;
      fseek(file, -sizeof(Funcionario), SEEK_CUR);
      fwrite(&f, sizeof(Funcionario), 1, file);
      fclose(file);
      break;
    } 
  }
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
      editarFuncionario();
      break;
    case 5: 
      deletarFuncionario();
      break;
    default: 
    printf("Opção inválida."); 
  }
}