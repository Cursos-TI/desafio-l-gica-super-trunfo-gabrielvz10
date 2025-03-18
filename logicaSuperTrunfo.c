#include <stdio.h>

int main() {
    // Declaração das variáveis para armazenar as informações das cartas
    char estado1, estado2;
    char codigo1[4], codigo2[4];
    char nome1[50], nome2[50];
    unsigned long int populacao1, populacao2;
    float area1, area2, pib1, pib2;
    int pontosTuristicos1, pontosTuristicos2;
    
    // Entrada de dados para a Carta 1
    printf("Digite o estado da Carta 1 (A-H): ");
    scanf(" %c", &estado1);
    printf("Digite o código da Carta 1: ");
    scanf(" %s", codigo1);
    printf("Digite o nome da cidade da Carta 1: ");
    scanf(" %[^"]s", nome1);
    printf("Digite a população da Carta 1: ");
    scanf(" %lu", &populacao1);
    printf("Digite a área da Carta 1 (km²): ");
    scanf(" %f", &area1);
    printf("Digite o PIB da Carta 1 (bilhões de reais): ");
    scanf(" %f", &pib1);
    printf("Digite o número de pontos turísticos da Carta 1: ");
    scanf(" %d", &pontosTuristicos1);
    
    // Entrada de dados para a Carta 2
    printf("\nDigite o estado da Carta 2 (A-H): ");
    scanf(" %c", &estado2);
    printf("Digite o código da Carta 2: ");
    scanf(" %s", codigo2);
    printf("Digite o nome da cidade da Carta 2: ");
    scanf(" %[^"]s", nome2);
    printf("Digite a população da Carta 2: ");
    scanf(" %lu", &populacao2);
    printf("Digite a área da Carta 2 (km²): ");
    scanf(" %f", &area2);
    printf("Digite o PIB da Carta 2 (bilhões de reais): ");
    scanf(" %f", &pib2);
    printf("Digite o número de pontos turísticos da Carta 2: ");
    scanf(" %d", &pontosTuristicos2);
    
    // Cálculo da Densidade Populacional e PIB per capita
    float densidade1 = populacao1 / area1;
    float densidade2 = populacao2 / area2;
    float pibPerCapita1 = pib1 / populacao1;
    float pibPerCapita2 = pib2 / populacao2;
    
    // Exibição das informações das cartas
    printf("\nCarta 1:\n");
    printf("Estado: %c\nCódigo: %s\nNome: %s\nPopulação: %lu\nÁrea: %.2f km²\nPIB: %.2f bilhões\nPontos Turísticos: %d\nDensidade Populacional: %.2f hab/km²\nPIB per Capita: %.2f reais\n", 
           estado1, codigo1, nome1, populacao1, area1, pib1, pontosTuristicos1, densidade1, pibPerCapita1);
    
    printf("\nCarta 2:\n");
    printf("Estado: %c\nCódigo: %s\nNome: %s\nPopulação: %lu\nÁrea: %.2f km²\nPIB: %.2f bilhões\nPontos Turísticos: %d\nDensidade Populacional: %.2f hab/km²\nPIB per Capita: %.2f reais\n", 
           estado2, codigo2, nome2, populacao2, area2, pib2, pontosTuristicos2, densidade2, pibPerCapita2);
    
    // Comparação baseada em um atributo específico (por exemplo, PIB)
    printf("\nComparação de cartas (Atributo: PIB):\n");
    printf("Carta 1 - %s: %.2f bilhões\n", nome1, pib1);
    printf("Carta 2 - %s: %.2f bilhões\n", nome2, pib2);
    
    if (pib1 > pib2) {
        printf("Resultado: Carta 1 (%s) venceu!\n", nome1);
    } else if (pib2 > pib1) {
        printf("Resultado: Carta 2 (%s) venceu!\n", nome2);
    } else {
        printf("Resultado: Empate!\n");
    }
    
    return 0;
}
