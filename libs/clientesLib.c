#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#include <ctype.h> 
#include "clientesLib.h"
#include "checkers.h"

void criarCliente(){
  clear();
  FILE* file = fopen("clientes.dat", "ab");
  Cliente* c = (Cliente*) malloc(sizeof(Cliente));
  printf("--- Cadastro de Clientes ---\n");
  
    printf("Digita o nome do cliente: ");
    scanf(" %100[^\n]", c->nome);
    while(checkNome(c->nome) != 1){
      printf("Nome inválido, insira novamente: ");
      scanf(" %100[^\n]", c->nome);
    }
    getchar();
   
    printf("Digita o CPF do cliente: ");
    scanf(" %15[0-9]", c->cpf);
    while(checkCPF(c->cpf) != 1){
      printf("CPF inválido, insira novamente: ");
      scanf(" %12[0-9]", c->cpf);
    }
    printf("Digita o telefone do cliente: ");
    scanf(" %15[0-9]", c->telefone);
    while(checkTelefone(c->telefone) != 1){
      printf("Número de telefone inválido!"); 
      printf("Digita novamente o número do cliente: ");
      scanf("%12[0-9]", c->telefone);
    }

  printf("\nCliente criado com sucesso!");
  printf("\nO nome do cliente é: %s", c->nome);
  //fprintf (file, "%s | %s \n", p->sabor, p->ingredientes);
  fwrite(c, sizeof(Cliente), 1, file);
  free(c);
  fclose(file); 
  // fgets(p->recheio, sizeof(p->recheio), stdin); 
  }


void exibirClientes(){
  FILE *file = fopen("clientes.dat", "rb");
  Cliente *c = (Cliente*) malloc(sizeof(Cliente));  
  
  if (file == NULL){
    printf("Erro ao abrir o arquivo de clientes!");
    exit(1);
  }
  printf("NOME | CPF | TELEFONE\n");
  while( fread(c, sizeof(Cliente), 1, file) ){
    printf("%s | %s | %s\n", c->nome, c->cpf, c->telefone);
  }
  fclose(file);
}

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
      criarCliente();
      break; 
    
    case 2: 
      printf("Digita o CPF do cliente a ser buscado:\n ");
      break; 
    
    case 3: 
      exibirClientes();
      break; 
    
    case 4 :
      printf("Digita o CPF do cliente a ser editado: \n");
      break; 
    
    case 5: 
      printf("Digita o CPF do cliente a ser deletado: \n");
      break; 
    
    default: 
      printf("Opção inválida."); 
  }

}
