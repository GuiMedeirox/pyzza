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
    exit(1);
  } 
  int id; 
  printf("Insere o ID da pizza: \n");
  scanf(" %d", &id);

  do{
      p->idPedido = rand() % 1000000;
    } while(verificaIdPedido(p->idPedido) == 1);
  strcpy(p->saborPizza, encontraPizza(id));
  strcpy(p->tamanhoPizza, obterTamanhoPizza(id));
  p->precoPizza = obterPreco(p->tamanhoPizza);
  if(p->saborPizza==NULL || p->tamanhoPizza==NULL){
    printf("Pizza nao encontrada");
  }
  printf("Pizza adicionada no carrinho com sucesso!"); 
  printf("\nSabor: %s\n", p->saborPizza);
  printf("\nTamanho: %s\n", p->tamanhoPizza);
  printf("\nValor: %f\n", p->precoPizza);
  fwrite(p, sizeof(Pedido), 1, file);

  int opt;
  do{
    printf("Voce quer adicionar mais alguma pizza no carrinho?\n");
    printf("0 - NAO || 1 - sim\n");
    scanf(" %d", &opt);
   	if(opt==1){
      do{
   		  printf("Insere o ID da outra pizza: \n");
        scanf(" %d", &id);
      }while(verificaIDDuplicado(id)==0);
  		strcpy(p->saborPizza, encontraPizza(id));
      strcpy(p->tamanhoPizza, obterTamanhoPizza(id));
      p->precoPizza = obterPreco(p->tamanhoPizza);
    	fwrite(p, sizeof(Pedido), 1, file);
      printf("ID do PEDIDO: %d", p->idPedido);
      printf("Pizza adicionada no carrinho com sucesso!"); 
      printf("\nSabor: %s\n", p->saborPizza);
      printf("\nTamanho: %s\n", p->tamanhoPizza);
      printf("\nValor: %f\n", p->precoPizza);
   	} else if(opt == 0){
      clear();
      printf("Carrinho fechado com sucesso!");
    }

   }while(opt==1);
    fclose(file);
    obterTotal(p->idPedido);
    free(p);
  }

void editarPedido(){
  clear();
  Pedido pedidoEditado;
  FILE* file = fopen("pedidos.dat", "rb+");
  int id; 

  if(file == NULL){
    printf("Erro ao abrir o arquivo!"); 
    exit(1);
  }

  printf("Digita o ID do pedido a ser editado: ");
  scanf(" %i", &id);
  
  while(fread(&pedidoEditado, sizeof(Pedido), 1, file) == 1){
    if(pedidoEditado.idPedido == id){
      printf("Pedido encontrado! \n");
      printf("ID DO PEDIDO: %i \n RESPONSAVEL: %s \n", pedidoEditado.idPedido, pedidoEditado.clienteNome);
      printf("Digite o novo status do pedido (0 - NÃO PAGO || 1 - PAGO)\n");
      scanf("%d", &pedidoEditado.status);
      printf("Pedido editado com sucesso, agora o status é: %i", pedidoEditado.status);
      fseek(file, -sizeof(Pedido), SEEK_CUR);
      fwrite(&pedidoEditado, sizeof(Pedido), 1, file);
    }
  }
  
  fclose(file);
}

void listarPedidos(){
  FILE *file = fopen("pedidos.dat", "rb");
  Pedido *p = (Pedido*) malloc(sizeof(Pedido));  
  int idAnterior;
  if (file == NULL){
    printf("Erro ao abrir o arquivo de clientes!");
    exit(1);
  }
  while( fread(p, sizeof(Pedido), 1, file) ){
      if(idAnterior != p->idPedido){
      printf("\n-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#\n");     
      printf("ID - CLIENTE - TOTAL DO PEDIDO - STATUS - CPF \n");
      printf("%-6d | %-6s | %-6d | %-1d | %-11s \n", p->idPedido, p->clienteNome, obterTotal(p->idPedido), p->status, p->cpf);
      printf("SABOR - TAMANHO - PRECO\n");
      printf("%-6s | %-2s | %-5f\n", p->saborPizza, p->tamanhoPizza, p->precoPizza);  
      } else if(idAnterior == p->idPedido){
        printf("%-6s | %-2s | %-5f\n", p->saborPizza, p->tamanhoPizza, p->precoPizza);
      } 
      idAnterior = p->idPedido;
    }
  free(p);
  fclose(file);
}

void pagarPedido(int id){
  clear();
  Pedido pedidoEditado;
  FILE* file = fopen("pedidos.dat", "rb+");

  if(file == NULL){
    printf("Erro ao abrir o arquivo!"); 
    exit(1);
  }
  
  while(fread(&pedidoEditado, sizeof(Pedido), 1, file) == 1){
    if(pedidoEditado.idPedido == id){
      pedidoEditado.status=1;
      fseek(file, -sizeof(Pedido), SEEK_CUR);
      fwrite(&pedidoEditado, sizeof(Pedido), 1, file);
    }
  }
  printf("Pedido %i pago com sucesso!", id);
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

int obterTotal(int id){
  FILE *file = fopen("pedidos.dat", "rb+");
  Pedido p; 
  
  int total=0; 
  if (file == NULL){
    printf("Erro ao abrir o arquivo de clientes!");
    exit(1);
  }
  while( fread(&p, sizeof(Pedido), 1, file) ){
    if(id == p.idPedido){
      total += p.precoPizza;
    }
  }
  fclose(file);
  return total;
  
}

void buscaPedido(){
  clear();
  int id; 
  FILE* file = fopen("pedidos.dat", "rb");
  Pedido* p = (Pedido*) malloc(sizeof(Pedido));
  if(file == NULL){
      printf("Erro ao abrir o arquivo!\n");
      exit(1);
  }
  do{
    printf("Digita o ID do pedido que você quer buscar: ");
    scanf(" %d", &id);
  }while(verificaIdPedido(id) != 1);

  printf("-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#");
  printf("\nPEDIDO %d\n", id);
  while(!feof(file)){
    fread(p, sizeof(Pedido), 1, file);
    if( id == p->idPedido ) {
      printf("-> %s\n", p->saborPizza);
    }
  }
  printf("-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#");
  fclose(file);
  free(p);
}

void buscarPedidoPorCliente(const char* cpf){
    Pedido pedido;
    FILE *file = fopen("pedidos.dat", "rb"); // Abre o arquivo para leitura

    if (file == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        exit(1);
    }
    clear();
    int idAnterior;
    printf("Pedidos atrelados ao CPF %s\n ", cpf);
    printf("Titular dos pedidos: %s\n", encontraCliente(cpf));
    while (fread(&pedido, sizeof(Pedido), 1, file) == 1) {
        if (strcmp(pedido.cpf, cpf) == 0) {
            if(idAnterior != pedido.idPedido){
              printf("ID: %d\n", pedido.idPedido);
            }
        }
        idAnterior = pedido.idPedido;
    }
    fclose(file);
}

void menuPedido(){
  int opt; 
  char cpf[12];
  int id; 
  printf("1. Fazer pedido\n");
  printf("2. Ver pedidos\n");
  printf("3. Buscar pedidos\n");
  printf("4. Buscar pedido específico\n");
  printf("5. Pagar pedido\n");
  printf("6. Listar pedidos de um cliente\n");
  printf("Digita qual opcao voce quer: \n");
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
      buscaPedido();
      break;
    case 5:
      printf("Digita o ID do pedido a ser pago: ");
      scanf(" %i", &id);
      pagarPedido(id);
      break;
    case 6:
      printf("Digita o CPF do cliente para buscar os pedidos: ");
      scanf(" %12[0-9]", cpf);
      buscarPedidoPorCliente(cpf);
  }
};
