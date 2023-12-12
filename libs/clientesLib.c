#include "all.h"

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
    scanf(" %12[0-9]", c->cpf);
    while(checkCPF(c->cpf) != 1 ||verificaCPFDuplicado(c->cpf) == 1 ){
      printf("CPF inválido ou já cadastrado no banco de dados, insira novamente: ");
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
  c->status=1;
  
  fwrite(c, sizeof(Cliente), 1, file);
  free(c);
  fclose(file); 
  
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
    if(c->status == 1){
      printf("%s | %s | %s\n", c->nome, c->cpf, c->telefone);
    }
  }
  fclose(file);
}

int buscarCliente(){
  clear();
  char cpf[12];
  FILE* file = fopen("clientes.dat", "rb");
  Cliente* c = (Cliente*) malloc(sizeof(Cliente));
  if(file == NULL){
      printf("Erro ao abrir o arquivo!\n");
      exit(1);
  }

  printf("Digita o CPF do cliente que você quer buscar: ");
  scanf(" %11[^\n]", cpf);

  while(!feof(file)){
    fread(c, sizeof(Cliente), 1, file);
    if( strcmp(c->cpf, cpf) == 0 && c->status==1 ) {
      printf("Cliente: %s", c->nome);
      fclose(file);
      return 1; 
      break;
    }
  }
  free(c);
  return 0; 
}

char *encontraCliente( const char *cpf) {
    Cliente cliente;
    FILE *file = fopen("clientes.dat", "rb"); // Abre o arquivo para leitura

    if (file == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return NULL;
    }

    while (fread(&cliente, sizeof(Cliente), 1, file) == 1) {
        if (strcmp(cliente.cpf, cpf) == 0) {
            // CPF encontrado, aloca memória para o nome
            char *result = (char *)malloc(strlen(cliente.nome) + 1);
            if (result == NULL) {
                printf("Erro ao alocar memória.\n");
                fclose(file);
                return NULL;
            }

            // Copia o nome para o resultado e o retorna
            strcpy(result, cliente.nome);
            fclose(file);
            return result;
        }
    }
    // Se o CPF não for encontrado, retorna NULL
    fclose(file);
    return NULL;
}

int verificaCPFDuplicado(const char* cpf) {
    FILE* file = fopen("clientes.dat", "rb");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        exit(1); 
    }

    Cliente cliente;

    while (fread(&cliente, sizeof(Cliente), 1, file) == 1) {
        if (strcmp(cliente.cpf, cpf) == 0) {            
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
}

void buscarClienteFiltrado(){
  clear();
  char nome[100];
  FILE* file = fopen("clientes.dat", "rb");
  Cliente* c = (Cliente*) malloc(sizeof(Cliente));
  if(file == NULL){
      printf("Erro ao abrir o arquivo!\n");
      exit(1);
  }

  printf("Digita o nome do cliente que você quer buscar: ");
  scanf(" %100[^\n]", nome);
  while(!feof(file)){
    fread(c, sizeof(Cliente), 1, file);
    if( strstr(c->nome, nome) != NULL && c->status==1 ) {
      printf("%s \n", c->nome);
      printf(">-<>-<>-<>-<>-<>-<>-<>-<\n");
    }
  }

  fclose(file);
  free(c);    

}

void editarCliente(){
  clear();
  Cliente clienteEditado;
  FILE* file = fopen("clientes.dat", "rb+");
  char cpf[12];
  int opt;

  if(file == NULL){
    printf("Erro ao abrir o arquivo de clientes.");
    exit(1);
  }
  
  printf("Digita o CPF do funcionário a ser editado: ");
  scanf(" %11[^\n]", cpf);

  while(fread(&clienteEditado, sizeof(Cliente), 1, file) == 1){
    if(strcmp(clienteEditado.cpf, cpf) == 0 && clienteEditado.status ==1 ){
      printf("Cliente encontrado! \n");
      printf("Digita qual campo você vai querer editar: \n");
      printf("1. nome\n");
      printf("2. telefone\n");
      scanf("%i", &opt);
      getchar();
      if (opt == 1){
      
        printf("Digita o novo nome p/ Cliente: ");
        scanf(" %100[^\n]", clienteEditado.nome);
        getchar();
        while(checkNome(clienteEditado.nome) != 1){
          printf("Nome inválido, digita novamente: ");
          scanf("%100[^\n]", clienteEditado.nome);      
        }
        printf("Nome editado com sucesso, novo nome: %s ", clienteEditado.nome);
      }
      else if(opt == 2){
      
        printf("Digita o novo telefone p/ Cliente: ");
        scanf(" %11[^\n]", clienteEditado.telefone);
        getchar();
        while(checkTelefone(clienteEditado.telefone) != 1){
          printf("Telefone inválido, digita novamente: ");
          scanf("%11[^\n]", clienteEditado.telefone);
        }
      
        printf("Telefone editado com sucesso, novo numero: %s ", clienteEditado.telefone);
      } else{
        printf("Opção inválida.");
      }

      fseek(file, -sizeof(Cliente), SEEK_CUR);
      fwrite(&clienteEditado, sizeof(Cliente), 1, file);
    }
  }
}

void deletarCliente(){
  clear();
  Cliente c; 
  FILE* file=fopen("clientes.dat","rb+");
  char cpf[12];

  printf("Digita o CPF do cliente a ser deletado: "); 
  scanf("%s", cpf);

  if(file == NULL){
    printf("Erro ao abrir o arquivo");
    exit(1);
  }

  while(fread(&c, sizeof(Cliente),1, file) == 1){
    if (strcmp(c.cpf, cpf) == 0){
      printf("Deletando o cliente %s, de cpf %s e telefone %s.", c.nome, c.cpf, c.telefone);
      c.status = 0; 
      
      fseek(file, -sizeof(Cliente), SEEK_CUR);
      fwrite(&c, sizeof(Cliente), 1, file);
      fclose(file);
      break;
    } 
  }
}

void exibirClientesAlfabetica(void) {
    system("clear||cls");
    FILE* file;
    Cliente* novoCliente;  
    Cliente* listaCliente;  

    file = fopen("clientes.dat", "rb");  
    if (file == NULL) {
        printf("Erro ao abrir o arquivo\n");
        exit(1); 
    }

    printf("\n-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#\n");  
    printf("Clientes em ordem alfabetica: \n");

    listaCliente = NULL;  
    novoCliente = (Cliente*)malloc(sizeof(Cliente)); 
    if (novoCliente == NULL) {   
        printf("Erro de alocacao de memoria\n");
        exit(1); 
    }

    while (fread(novoCliente, sizeof(Cliente), 1, file) == 1) {  
        novoCliente->proximo = NULL;  

        if ((listaCliente == NULL) || (strcmp(novoCliente->nome, listaCliente->nome) < 0)) {  
            novoCliente->proximo = listaCliente; 
            listaCliente = novoCliente;  
        } else {  
            Cliente* clienteAnterior = listaCliente;  
            Cliente* clienteAtual = listaCliente->proximo;   
            while ((clienteAtual != NULL) && strcmp(clienteAtual->nome, novoCliente->nome) < 0) {  
                clienteAnterior = clienteAtual; 
                clienteAtual = clienteAtual->proximo;
            }
            clienteAnterior->proximo = novoCliente;  
            novoCliente->proximo = clienteAtual;  
        }

        novoCliente = (Cliente*)malloc(sizeof(Cliente));
        if (novoCliente == NULL) {
            printf("Erro de alocacao de memoria\n");
            exit(1);
        }
    }

    fclose(file);  

    novoCliente = listaCliente;  
    while (novoCliente != NULL) {  
        printf("%s\n", novoCliente->nome);
        novoCliente = novoCliente->proximo;   
    }

    novoCliente = listaCliente;  
    while (listaCliente != NULL) {
        listaCliente = listaCliente->proximo;  
        free(novoCliente); 
        novoCliente = listaCliente; 
    }
    printf("\n");
}

void menuClientes(){
  int opcao; 
  printf("1. Cadastrar um novo cliente\n");
  printf("2. Buscar um cliente específico\n");
  printf("3. Buscar cliente(s) com um nome específico \n");
  printf("4. Ver os clientes em ordem alfabetica\n");
  printf("5. Ver os clientes\n");
  printf("6. Editar um cliente\n");
  printf("7. Deletar um cliente\n");
  printf("Opção: "); 
  scanf("%d", &opcao);

  switch (opcao){
    case 1: 
      criarCliente();
      break; 
    
    case 2: 
      buscarCliente();
      break; 
    
    case 3: 
      buscarClienteFiltrado();
      break;
      
    case 4:
      exibirClientesAlfabetica();
      break; 
    
    case 5 :
      exibirClientes();
      break; 
    
    case 6: 
      editarCliente();
      break; 
    case 7:
      deletarCliente();
      break;
    default: 
      printf("Opção inválida."); 
  }

}
