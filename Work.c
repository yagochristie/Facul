#include <stdio.h>
#include <string.h>

int main() {
    int codigo, regiao;
    char nome[50];
    float peso, precoProduto, precoFrete, precoTotal;

    int dia, mes, hora, minuto;
    int diaEntrega, mesEntrega, anoEntrega;

    printf("===== CADASTRO DA COMPRA =====\n");

    printf("Codigo do produto: ");
    scanf("%d", &codigo);
    getchar(); // limpar buffer

    printf("Nome do produto: ");
    fgets(nome, 50, stdin);
    nome[strcspn(nome, "\n")] = 0; // remove \n

    printf("Peso do produto (Kg): ");
    scanf("%f", &peso);

    printf("Preco do produto (R$): ");
    scanf("%f", &precoProduto);

    printf("\nREGIOES:\n");
    printf("[1] Sul\n[2] Sudeste\n[3] Norte\n[4] Nordeste\n");
    printf("Escolha a regiao de entrega: ");
    scanf("%d", &regiao);

    // Cálculo do frete
    
    switch (regiao) {
        case 1: // Sul
            precoFrete = (peso > 2) ? 50 : 30;
            break;

        case 2: // Sudeste
            precoFrete = (peso > 2) ? 45 : 25;
            break;

        case 3: // Norte
            precoFrete = (peso > 2) ? 55 : 35;
            break;

        case 4: // Nordeste
            precoFrete = (peso > 2) ? 60 : 40;
            break;

        default:
            printf("Regiao invalida!\n");
            return 0;
    }

    // Cálculo preço total
    
    precoTotal = precoProduto + precoFrete;

    // Data e hora da compra

    printf("\nDia da compra (DD MM): ");
    scanf("%d %d", &dia, &mes);
    

    printf("Hora da compra (HH MM): ");
    scanf("%d %d", &hora, &minuto);


   // Data prevista de ENTREGA (sempre dia seguinte)

   diaEntrega = dia + 7;
   mesEntrega = mes;

   // Tratamento simples para mudança de mês
   
    if (diaEntrega > 30) {
     diaEntrega = 1;
     mesEntrega++;

    if (mesEntrega > 12) {
        mesEntrega = 1;
    }
}
    // LIMPAR TELA ANTES DO RESUMO
    system("cls");
    
    // RESUMO DA COMPRA

    printf("      RESUMO FINAL\n");
    printf("=========================\n");
    printf("Codigo do produto: %d\n", codigo);
    printf("Nome do produto: %s\n", nome);
    printf("Peso do produto: %.2f Kg\n", peso);
    printf("Preço do produto: R$ %.2f\n", precoProduto);

    printf("Regiao de entrega: ");
    switch (regiao) {
        case 1: printf("Sul\n"); break;
        case 2: printf("Sudeste\n"); break;
        case 3: printf("Norte\n"); break;
        case 4: printf("Nordeste\n"); break;
    }

    printf("Preço do frete: R$ %.2f\n", precoFrete);
    printf("Preço total da compra: R$ %.2f\n", precoTotal);

    printf("Data da compra: %d/%d \n",
           dia, mes);
           
    printf("hora da compra: %d:%d \n", 
	       hora, minuto);

    printf("Data prevista de entrega: %02d/%02d\n",
           diaEntrega, mesEntrega);

    return 0;
}
