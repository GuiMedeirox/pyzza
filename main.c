#include <stdio.h>
#include <stdlib.h>
#include "libs/clientesLib.h"
#include "libs/pedidosLib.h"
#include "libs/funcionarioLib.h"
#include "libs/pizzasLib.h"

int main() {
    int op;

    do {
        
        printf("\nEscolha uma opção:\n");
        printf("1. Pizzas\n");
        printf("2. Funcionários\n");
        printf("3. Clientes\n");
        printf("4. Pedidos\n");
        printf("5. Sobre o projeto\n");
        printf("0. Sair\n");
        printf("Opção: ");
	    scanf("%d", &op);  
        
        switch (op) {
            case 1:
                system("cls||clear");
                menuPizzas();
                break; 
            case 2:
                system("cls||clear");
                op =  menuFuncionario(); 
                break;
            case 3:
                system("cls||clear");
                menuClientes();
                break;
            case 4:
                system("cls||clear");
                op =  menuPedidos(); 
                break;
            case 5: 
                system("cls||clear");
                printf("Projeto feito e utilizado na disciplina de programação, o intuito é simples: suprir todas (ou quase) as funcionalidades que um sistema de uma pizzaria pode ter.\n"); 
                printf("dev: Guilherme\n");
                printf("GitHub: @GuiMedeirox\n"); 
            case 0:
                printf("Saindo...\n");
                break;
            
            default:
                printf("Opção inválida2!\n");
                break;
        }
    } while (op != 0);

    return 0;
}
