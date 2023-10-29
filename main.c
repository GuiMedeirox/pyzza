#include <stdio.h>
#include <stdlib.h>
#include "libs/clientesLib.h"
#include "libs/pedidosLib.h"
#include "libs/funcionarioLib.h"
#include "libs/pizzasLib.h"
#include "libs/checkers.h"

int main() {
    int op;

    do {
        printf("\n\n----------");
        printf("\nPyzza!\n");
        printf("Escolha uma opção:\n");
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
                clear();
                menuPizzas();
                break; 
            case 2:
                clear();
                menuFuncionario(); 
                break;
            case 3:
                clear();
                menuClientes();
                break;
            case 4:
                clear();
                menuPedidos(); 
                break;
            case 5: 
                clear();
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
