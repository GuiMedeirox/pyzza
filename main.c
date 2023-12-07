#include "libs/all.h"

int main() {
    int op;

    do {
        printf("\n----------");
        printf("\nPyzza!\n");
        printf("\n----------\n");
        printf("Escolha uma opção:\n");
        printf("1. Pizzas\n");
        printf("2. Clientes\n");
        printf("3. Pedidos\n");
        printf("4. Sobre o projeto\n");
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
                menuClientes();
                break;
            case 3:
                clear();
                menuPedido(); 
                break;
            case 4:
                clear();
                printf("Projeto feito e utilizado na disciplina de programação, o intuito é simples: suprir todas (ou quase) as funcionalidades que um sistema de uma pizzaria pode ter.\n"); 
                printf("Um agradecimento especial a:\n Eduardo dc:(eduardoferro);\n Tesch dc:(ptesch) \n Gabriel Canuto ");
                printf("dev: Guilherme\n");
                printf("GitHub: @GuiMedeirox\n"); 
                break;
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
