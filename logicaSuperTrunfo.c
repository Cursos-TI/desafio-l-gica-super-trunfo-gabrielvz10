#include <stdio.h>

int main() {
    // Declaração das variáveis para as duas cartas
    char estado1, estado2;
    char codigo1[4], codigo2[4];
    char nome1[50], nome2[50];
    int populacao1, populacao2, pontos1, pontos2;
    float area1, area2, pib1, pib2;
    float densidade1, densidade2, pib_per_capita1, pib_per_capita2;
    int opcao;
    
    // Entrada dos dados da primeira carta
    printf("Digite a letra do estado da primeira cidade (A-H): ");
    scanf(" %c", &estado1);
    printf("Digite o código da primeira cidade: ");
    scanf(" %s", codigo1);
    printf("Digite o nome da primeira cidade: ");
    scanf(" %[^"]s", nome1);
    printf("Digite a população da primeira cidade: ");
    scanf(" %d", &populacao1);
    printf("Digite a área da primeira cidade (em km²): ");
    scanf(" %f", &area1);
    printf("Digite o PIB da primeira cidade (em bilhões de reais): ");
    scanf(" %f", &pib1);
    printf("Digite o número de pontos turísticos da primeira cidade: ");
    scanf(" %d", &pontos1);
    
    // Entrada dos dados da segunda carta
    printf("\nDigite a letra do estado da segunda cidade (A-H): ");
    scanf(" %c", &estado2);
    printf("Digite o código da segunda cidade: ");
    scanf(" %s", codigo2);
    printf("Digite o nome da segunda cidade: ");
    scanf(" %[^"]s", nome2);
    printf("Digite a população da segunda cidade: ");
    scanf(" %d", &populacao2);
    printf("Digite a área da segunda cidade (em km²): ");
    scanf(" %f", &area2);
    printf("Digite o PIB da segunda cidade (em bilhões de reais): ");
    scanf(" %f", &pib2);
    printf("Digite o número de pontos turísticos da segunda cidade: ");
    scanf(" %d", &pontos2);
    
    // Cálculo da densidade populacional e PIB per capita
    densidade1 = populacao1 / area1;
    densidade2 = populacao2 / area2;
    pib_per_capita1 = pib1 / populacao1;
    pib_per_capita2 = pib2 / populacao2;
    
    // Menu interativo para escolher a comparação
    printf("\nEscolha o atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Número de pontos turísticos\n");
    printf("5 - Densidade populacional\n");
    printf("6 - PIB per capita\n");
    printf("Digite sua opção: ");
    scanf(" %d", &opcao);
    
    printf("\nComparação de cartas:\n");
    printf("%s (Estado %c) vs. %s (Estado %c)\n", nome1, estado1, nome2, estado2);
    
    switch (opcao) {
        case 1: // População
            printf("Atributo: População\n");
            printf("%s: %d habitantes\n", nome1, populacao1);
            printf("%s: %d habitantes\n", nome2, populacao2);
            if (populacao1 > populacao2) printf("%s venceu!\n", nome1);
            else if (populacao2 > populacao1) printf("%s venceu!\n", nome2);
            else printf("Empate!\n");
            break;
        case 2: // Área
            printf("Atributo: Área\n");
            printf("%s: %.2f km²\n", nome1, area1);
            printf("%s: %.2f km²\n", nome2, area2);
            if (area1 > area2) printf("%s venceu!\n", nome1);
            else if (area2 > area1) printf("%s venceu!\n", nome2);
            else printf("Empate!\n");
            break;
        case 3: // PIB
            printf("Atributo: PIB\n");
            printf("%s: %.2f bilhões de reais\n", nome1, pib1);
            printf("%s: %.2f bilhões de reais\n", nome2, pib2);
            if (pib1 > pib2) printf("%s venceu!\n", nome1);
            else if (pib2 > pib1) printf("%s venceu!\n", nome2);
            else printf("Empate!\n");
            break;
        case 4: // Pontos turísticos
            printf("Atributo: Número de Pontos Turísticos\n");
            printf("%s: %d\n", nome1, pontos1);
            printf("%s: %d\n", nome2, pontos2);
            if (pontos1 > pontos2) printf("%s venceu!\n", nome1);
            else if (pontos2 > pontos1) printf("%s venceu!\n", nome2);
            else printf("Empate!\n");
            break;
        case 5: // Densidade populacional (menor vence)
            printf("Atributo: Densidade Populacional\n");
            printf("%s: %.2f hab/km²\n", nome1, densidade1);
            printf("%s: %.2f hab/km²\n", nome2, densidade2);
            if (densidade1 < densidade2) printf("%s venceu!\n", nome1);
            else if (densidade2 < densidade1) printf("%s venceu!\n", nome2);
            else printf("Empate!\n");
            break;
        case 6: // PIB per capita
            printf("Atributo: PIB per Capita\n");
            printf("%s: %.2f reais\n", nome1, pib_per_capita1);
            printf("%s: %.2f reais\n", nome2, pib_per_capita2);
            if (pib_per_capita1 > pib_per_capita2) printf("%s venceu!\n", nome1);
            else if (pib_per_capita2 > pib_per_capita1) printf("%s venceu!\n", nome2);
            else printf("Empate!\n");
            break;
        default:
            printf("Opção inválida!\n");
    }
    
    return 0;
}