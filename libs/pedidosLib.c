#include "all.h"

void criarPedido();
void menuPedido();

void criarPedido(){
  Pedido *p = (Pedido*) malloc(sizeof(Pedido));
  FILE* file = fopen("pedidos.dat", "ab");
  if(file == NULL){
    printf("Erro ao abrir o arquivo. ");
    exit(1);
  }
  do{
    printf("Insere o CPF do responsavel pelo pedido: ");
    scanf(" %12[0-9]", p->cpf );
  } while(checkCPF(p->cpf) != 1);
  
  strcpy(p->clienteNome, encontraCliente(p->cpf));
  if(p->clienteNome == NULL){
    printf("Cliente nao encontrado");
  } 

  printf("Insere a TAG da pizza: ");
  scanf(" %10[^\n]", p->tag);
  
  do{
      p->idPedido = rand() % 1000000;
    } while(verificaIdPedido(p->idPedido) == 1);
  
  strcpy(p->saborPizza, encontraPizza(p->tag));
  strcpy(p->tamanhoPizza, obterTamanhoPizza(p->tag));
  p->precoPizza = obterPreco(p->tamanhoPizza);
  if(p->saborPizza==NULL || p->tamanhoPizza==NULL){
    printf("Pizza nao encontrada");
  }
  fwrite(p, sizeof(Pedido), 1, file);
  printf("%s", p->cpf);
  free(p);
  fclose(file);
}

void listarPedidos(){
  FILE *file = fopen("pedidos.dat", "rb");
  Pedido *p = (Pedido*) malloc(sizeof(Pedido));  
  
  if (file == NULL){
    printf("Erro ao abrir o arquivo de clientes!");
    exit(1);
  }
  while( fread(p, sizeof(Pedido), 1, file) ){
      printf("-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#\n");     
      printf("ID    -      TOTAL DO PEDIDO - STATUS - TAG - CPF \n");
      printf("%-6d | %-6f | %-1d | %-10s | %-11s \n", p->idPedido, p->totalPedido, p->status, p->tag, p->cpf);
      printf("CLIENTE - SABOR - TAMANHO - PRECO\n");
      printf("%-25s | %-25s | %-2s | %-5f", p->clienteNome, p->saborPizza, p->tamanhoPizza, p->precoPizza);  
  }
  free(p);
  fclose(file);
}

int verificaIdPedido(int a){
  FILE *file = fopen("pedidos.dat", "rb");
  Pedido *p = (Pedido*) malloc(sizeof(Pedido));  
  
  int flag; 
  if (file == NULL){
    printf("Erro ao abrir o arquivo de clientes!");
    exit(1);
  }
  while( fread(p, sizeof(Pedido), 1, file) ){
    if(a == p->idPedido){
      flag = 1;
    }
  }
  fclose(file);
  free(p);
  return flag; 
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
      listarPedidos();
      break; 
    case 3: 
      break;
    case 4: 
      break;
    case 5: 
      break;

  }
};
