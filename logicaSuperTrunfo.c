#include <stdio.h>

// Estrutura para armazenar os dados das cartas
typedef struct {
    char estado[50];
    char codigo[10];
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
} Carta;

// Função para calcular densidade populacional e PIB per capita
void calcularAtributos(Carta *c) {
    c->densidade_populacional = c->populacao / c->area;
    c->pib_per_capita = c->pib / c->populacao;
}

// Função para exibir os dados das cartas
void exibirCarta(Carta c) {
    printf("\nCarta: %s (%s)\n", c.nome, c.estado);
    printf("População: %d\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: %.2f bilhões de reais\n", c.pib);
    printf("Pontos Turísticos: %d\n", c.pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", c.densidade_populacional);
    printf("PIB per Capita: %.2f reais\n", c.pib_per_capita);
}

// Função para exibir o menu de atributos
int escolherAtributo(char *mensagem) {
    int opcao;
    printf("%s\n", mensagem);
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Populacional\n");
    printf("6 - PIB per Capita\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);
    return opcao;
}

// Função para obter o valor do atributo
float obterValorAtributo(Carta c, int atributo) {
    switch (atributo) {
        case 1: return c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return c.pontos_turisticos;
        case 5: return c.densidade_populacional;
        case 6: return c.pib_per_capita;
        default: return 0;
    }
}

// Função para determinar o vencedor com base no atributo
int compararAtributo(float valor1, float valor2, int atributo) {
    return (atributo == 5) ? (valor1 < valor2) : (valor1 > valor2);
}

int main() {
    Carta carta1 = {"SP", "A01", "São Paulo", 12325000, 1521.11, 699.28, 50, 0, 0};
    Carta carta2 = {"RJ", "B02", "Rio de Janeiro", 6748000, 1200.25, 300.50, 30, 0, 0};

    // Calcular atributos
    calcularAtributos(&carta1);
    calcularAtributos(&carta2);

    // Exibir cartas
    exibirCarta(carta1);
    exibirCarta(carta2);

    // Escolher dois atributos diferentes
    int atributo1 = escolherAtributo("Escolha o primeiro atributo para comparação:");
    int atributo2;
    do {
        atributo2 = escolherAtributo("Escolha o segundo atributo para comparação (diferente do primeiro):");
        if (atributo2 == atributo1) {
            printf("\nErro: O segundo atributo deve ser diferente do primeiro.\n");
        }
    } while (atributo2 == atributo1);

    // Obter valores
    float valor1_c1 = obterValorAtributo(carta1, atributo1);
    float valor1_c2 = obterValorAtributo(carta2, atributo1);
    float valor2_c1 = obterValorAtributo(carta1, atributo2);
    float valor2_c2 = obterValorAtributo(carta2, atributo2);

    // Comparação
    int resultado1 = compararAtributo(valor1_c1, valor1_c2, atributo1);
    int resultado2 = compararAtributo(valor2_c1, valor2_c2, atributo2);

    // Soma dos atributos
    float soma1 = valor1_c1 + valor2_c1;
    float soma2 = valor1_c2 + valor2_c2;

    printf("\nComparação de Cartas:\n");
    printf("Atributo 1: %s\n", (atributo1 == 5) ? "Densidade Populacional" : "Outro Atributo");
    printf("%s: %.2f vs %s: %.2f -> %s venceu!\n", carta1.nome, valor1_c1, carta2.nome, valor1_c2, resultado1 ? carta1.nome : carta2.nome);
    printf("Atributo 2: %s\n", (atributo2 == 5) ? "Densidade Populacional" : "Outro Atributo");
    printf("%s: %.2f vs %s: %.2f -> %s venceu!\n", carta1.nome, valor2_c1, carta2.nome, valor2_c2, resultado2 ? carta1.nome : carta2.nome);

    // Determinar vencedor final
    if (soma1 > soma2) {
        printf("\nVencedor final: %s!\n", carta1.nome);
    } else if (soma1 < soma2) {
        printf("\nVencedor final: %s!\n", carta2.nome);
    } else {
        printf("\nResultado final: Empate!\n");
    }

    return 0;
}