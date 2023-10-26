#include <stdio.h> 
#include <stdlib.h> 
#include "pizzasLib.h"

Pizza* criarPizza(){
  Pizza *p; 
  p = (Pizza*) malloc(sizeof(Pizza));
  
  printf("--- Cadastro de Pacientes ---");
  fgets(p->tamanho, sizeof(p->tamanho), stdin);
  fputs(p->tamanho, stdout);

}

void menuPizzas(){
  int opcao; 
  
  printf("1. Cadastrar um novo sabor de pizza\n");
  printf("2. Buscar um sabor de pizza específico\n");
  printf("3. Ver o cardápio\n");
  printf("4. Editar um sabor de pizza\n");
  printf("5. Deletar um sabor de pizza\n");
  printf("Opção: ");
  scanf("%i", &opcao);
  
  printf("%i %s",opcao, "\n" );

   switch (opcao){
    case 1: 
      printf("Digita o sabor da pizza: \n"); 
      printf("Digita os ingrediente \n");
      criarPizza(); 
      break; 
    case 2: 
    printf("Digita o sabor da pizza que você quer buscar: \n"); 
    break; 
    case 3: 
    //12cardapio()
    break; 
    case 4: 
    printf("Digita o sabor da pizza que você quer editar: \n");
    break; 
    case 5: 
    printf("Digita o sabor da pizza que você quer deletar: \n");
    break; 
    default: 
    printf("Opção inválida."); 

}

}
