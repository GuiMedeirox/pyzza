#include <stdio.h>
#include <stdlib.h>



int main() {
    int opcao;

    do {
        printf("\nEscolha uma opção:\n");
        printf("1. Pizzas\n");
        printf("2. Funcionários\n");
        printf("3. Clientes\n");
        printf("4. Pedidos\n");
        printf("5. Sobre o projeto\n");
        printf("0. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                
                break;
            case 2:
                
                break;
            case 3:
                
                break;
            case 4:
                
                break;
            case 5: 
                printf("Projeto feito e utilizado na disciplina de programação, o intuito é simples: suprir todas (ou quase) as funcionalidades que um sistema de uma pizzaria pode ter.\n"); 
                printf("dev: Guilherme\n");
                printf("GitHub: @GuiMedeirox\n"); 
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}