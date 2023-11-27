#include "all.h"

void criarPedido();
void menuPedido();

void criarPedido(){
  Pedido *p = (Pedido*) malloc(sizeof(Pedido));
  printf("Insere o CPF do responsavel pelo pedido: ");
  scanf(" %11[^\n]", p->cpf );
  char *clienteNome = encontraCliente(p->cpf);
  if(clienteNome != NULL){
    printf("%s", clienteNome);
  } else{
    printf("Cliente nao encontrado");
  }

  printf("Insere a TAG da pizza: ");
  scanf(" %10[^\n]", p->tag);
  char *saborPizza = encontraPizza(p->tag);
  

  
  if(saborPizza!=NULL){
    printf("%s", saborPizza);
  } else {
    printf("Pizza nao encontrada");
  }
  free(p);
}

void menuPedido(){
  int opt; 
  printf("1. Fazer pedido\n");
  printf("2. Ver pedidos\n");
  printf("3. Buscar pedidos\n");
  printf("4. Buscar pedido específico\n");
  printf("5. Deletar pedido");
  printf("Digita qual opcao voce quer: ");
  scanf("%d", &opt);

  switch(opt){
    case 1: 
      criarPedido();
      break;
    case 2: 
      break; 
    case 3: 
      break;
    case 4: 
      break;
    case 5: 
      break;

  }
};