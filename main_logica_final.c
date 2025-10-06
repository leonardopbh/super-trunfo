#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    // Variáveis para a primeira carta
    char estado1[3];
    char codigo1[4];
    char nome1[50];
    unsigned long int populacao1;
    float area1;
    float pib1;
    int pontos_turisticos1;
    float densidade1, pib_per_capita1;

    // Variáveis para a segunda carta
    char estado2[3];
    char codigo2[4];
    char nome2[50];
    unsigned long int populacao2;
    float area2;
    float pib2;
    int pontos_turisticos2;
    float densidade2, pib_per_capita2;

    int primeiro_atributo, segundo_atributo;
    float valor1_attr1 = 0, valor1_attr2 = 0; // Valores da carta 1 para os atributos escolhidos
    float valor2_attr1 = 0, valor2_attr2 = 0; // Valores da carta 2 para os atributos escolhidos
    float soma1, soma2;                       // Soma dos dois atributos para cada carta
    int pontos_carta1 = 0, pontos_carta2 = 0; // Pontos ganhos em cada atributo
    char nomes_atributos[7][30] = {"", "População", "Área", "PIB", "Pontos Turísticos", "Densidade Populacional", "PIB per Capita"};

    // Leitura dos dados da primeira carta
    printf("=== SUPER TRUNFO - NÍVEL FINAL (AVANÇADO) ===\n");
    printf("🎯 Comparação com DOIS atributos + Soma final!\n\n");

    printf("=== CARTA 1 ===\n");
    do {
        printf("Digite o estado (duas letras, ex: SP, RJ): ");
        scanf("%2s", estado1);
        // Converte para maiúsculas
        estado1[0] = toupper(estado1[0]);
        estado1[1] = toupper(estado1[1]);
        
        // Verifica se ambas as letras são válidas (A-Z)
        if (strlen(estado1) != 2 || estado1[0] < 'A' || estado1[0] > 'Z' || 
            estado1[1] < 'A' || estado1[1] > 'Z') {
            printf("❌ Estado inválido! Digite duas letras válidas (ex: SP, RJ, MG).\n");
        } else {
            break; // Estado válido, sai do loop
        }
    } while (1);

    do {
        printf("Digite o código da carta (sem espaços): ");
        scanf("%3s", codigo1); // Limita a 3 caracteres
        
        // Limpa o buffer para verificar se havia mais caracteres
        int c;
        char resto[100] = "";
        int pos = 0;
        while ((c = getchar()) != '\n' && c != EOF && pos < 99) {
            resto[pos++] = c;
        }
        resto[pos] = '\0';
        
        // Verifica se o código é válido
        if (strlen(codigo1) == 0) {
            printf("❌ Código inválido! O código não pode estar vazio.\n");
        } else if (strlen(resto) > 0) {
            // Se sobrou algo no buffer, significa que havia espaços ou mais texto
            printf("❌ Código inválido! O código não pode conter espaços.\n");
            printf("💡 Você digitou: '%s%s'. Use apenas: '%s'\n", codigo1, resto, codigo1);
        } else {
            break; // Código válido, sai do loop
        }
        printf("💡 Digite um código válido (ex: A01, B15, C03).\n");
    } while (1);

    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", nome1);

    do {
        printf("Digite a população: ");
        if (scanf("%lu", &populacao1) != 1 || populacao1 <= 0) {
            printf("❌ População inválida! Digite um número inteiro positivo.\n");
            while (getchar() != '\n'); // Limpa o buffer
            populacao1 = 0;
        }
    } while (populacao1 <= 0);

    do {
        printf("Digite a área (km²): ");
        if (scanf("%f", &area1) != 1 || area1 <= 0) {
            printf("❌ Área inválida! Digite um número positivo.\n");
            while (getchar() != '\n'); // Limpa o buffer
            area1 = 0;
        }
    } while (area1 <= 0);

    do {
        printf("Digite o PIB (bilhões): ");
        if (scanf("%f", &pib1) != 1 || pib1 <= 0) {
            printf("❌ PIB inválido! Digite um número positivo.\n");
            while (getchar() != '\n'); // Limpa o buffer
            pib1 = 0;
        }
    } while (pib1 <= 0);

    do {
        printf("Digite o número de pontos turísticos: ");
        if (scanf("%d", &pontos_turisticos1) != 1 || pontos_turisticos1 < 0) {
            printf("❌ Número de pontos turísticos inválido! Digite um número inteiro não negativo.\n");
            while (getchar() != '\n'); // Limpa o buffer
            pontos_turisticos1 = -1;
        }
    } while (pontos_turisticos1 < 0);

    // Leitura dos dados da segunda carta
    printf("\n=== CARTA 2 ===\n");
    do {
        printf("Digite o estado (duas letras, ex: SP, RJ): ");
        scanf("%2s", estado2);
        // Converte para maiúsculas
        estado2[0] = toupper(estado2[0]);
        estado2[1] = toupper(estado2[1]);
        
        // Verifica se ambas as letras são válidas (A-Z)
        if (strlen(estado2) != 2 || estado2[0] < 'A' || estado2[0] > 'Z' || 
            estado2[1] < 'A' || estado2[1] > 'Z') {
            printf("❌ Estado inválido! Digite duas letras válidas (ex: SP, RJ, MG).\n");
        } else {
            break; // Estado válido, sai do loop
        }
    } while (1);

    do {
        printf("Digite o código da carta (sem espaços): ");
        scanf("%3s", codigo2); // Limita a 3 caracteres
        
        // Limpa o buffer para verificar se havia mais caracteres
        int c;
        char resto[100] = "";
        int pos = 0;
        while ((c = getchar()) != '\n' && c != EOF && pos < 99) {
            resto[pos++] = c;
        }
        resto[pos] = '\0';
        
        // Verifica se o código é válido
        if (strlen(codigo2) == 0) {
            printf("❌ Código inválido! O código não pode estar vazio.\n");
        } else if (strlen(resto) > 0) {
            // Se sobrou algo no buffer, significa que havia espaços ou mais texto
            printf("❌ Código inválido! O código não pode conter espaços.\n");
            printf("💡 Você digitou: '%s%s'. Use apenas: '%s'\n", codigo2, resto, codigo2);
        } else {
            break; // Código válido, sai do loop
        }
        printf("💡 Digite um código válido (ex: A01, B15, C03).\n");
    } while (1);

    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", nome2);

    do {
        printf("Digite a população: ");
        if (scanf("%lu", &populacao2) != 1 || populacao2 <= 0) {
            printf("❌ População inválida! Digite um número inteiro positivo.\n");
            while (getchar() != '\n'); // Limpa o buffer
            populacao2 = 0;
        }
    } while (populacao2 <= 0);

    do {
        printf("Digite a área (km²): ");
        if (scanf("%f", &area2) != 1 || area2 <= 0) {
            printf("❌ Área inválida! Digite um número positivo.\n");
            while (getchar() != '\n'); // Limpa o buffer
            area2 = 0;
        }
    } while (area2 <= 0);

    do {
        printf("Digite o PIB (bilhões): ");
        if (scanf("%f", &pib2) != 1 || pib2 <= 0) {
            printf("❌ PIB inválido! Digite um número positivo.\n");
            while (getchar() != '\n'); // Limpa o buffer
            pib2 = 0;
        }
    } while (pib2 <= 0);

    do {
        printf("Digite o número de pontos turísticos: ");
        if (scanf("%d", &pontos_turisticos2) != 1 || pontos_turisticos2 < 0) {
            printf("❌ Número de pontos turísticos inválido! Digite um número inteiro não negativo.\n");
            while (getchar() != '\n'); // Limpa o buffer
            pontos_turisticos2 = -1;
        }
    } while (pontos_turisticos2 < 0);

    // Cálculos da densidade populacional e PIB per capita
    densidade1 = (float)populacao1 / area1;
    pib_per_capita1 = pib1 / (float)populacao1;

    densidade2 = (float)populacao2 / area2;
    pib_per_capita2 = pib2 / (float)populacao2;

    // Exibição dos dados das cartas
    printf("\n=== DADOS DAS CARTAS ===\n");

    printf("\nCarta 1 - %s (%s):\n", nome1, estado1);
    printf("Código: %s\n", codigo1);
    printf("População: %lu habitantes\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("Pontos Turísticos: %d\n", pontos_turisticos1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade1);
    printf("PIB per Capita: %.2f mil reais\n", pib_per_capita1);

    printf("\nCarta 2 - %s (%s):\n", nome2, estado2);
    printf("Código: %s\n", codigo2);
    printf("População: %lu habitantes\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Pontos Turísticos: %d\n", pontos_turisticos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade2);
    printf("PIB per Capita: %.2f mil reais\n", pib_per_capita2);

    // MENU DINÂMICO PARA ESCOLHA DO PRIMEIRO ATRIBUTO
    printf("\n=== ESCOLHA DOS ATRIBUTOS PARA COMPARAÇÃO ===\n");
    printf("📋 Escolha o PRIMEIRO atributo:\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Pontos Turísticos\n");
    printf("5. Densidade Populacional\n");
    printf("6. PIB per Capita\n");
    do {
        printf("Escolha uma opção (1-6): ");
        if (scanf("%d", &primeiro_atributo) != 1 || primeiro_atributo < 1 || primeiro_atributo > 6) {
            printf("❌ Opção inválida! Digite um número de 1 a 6.\n");
            while (getchar() != '\n'); // Limpa o buffer
            primeiro_atributo = 0;
        }
    } while (primeiro_atributo < 1 || primeiro_atributo > 6);

    // MENU DINÂMICO PARA ESCOLHA DO SEGUNDO ATRIBUTO (excluindo o primeiro)
    printf("\n📋 Escolha o SEGUNDO atributo (diferente do primeiro):\n");

    // Switch para exibir menu dinâmico (sem a opção já escolhida)
    switch (primeiro_atributo)
    {
    case 1: // Se escolheu População, não mostra ela novamente
        printf("2. Área\n3. PIB\n4. Pontos Turísticos\n5. Densidade Populacional\n6. PIB per Capita\n");
        break;
    case 2: // Se escolheu Área
        printf("1. População\n3. PIB\n4. Pontos Turísticos\n5. Densidade Populacional\n6. PIB per Capita\n");
        break;
    case 3: // Se escolheu PIB
        printf("1. População\n2. Área\n4. Pontos Turísticos\n5. Densidade Populacional\n6. PIB per Capita\n");
        break;
    case 4: // Se escolheu Pontos Turísticos
        printf("1. População\n2. Área\n3. PIB\n5. Densidade Populacional\n6. PIB per Capita\n");
        break;
    case 5: // Se escolheu Densidade Populacional
        printf("1. População\n2. Área\n3. PIB\n4. Pontos Turísticos\n6. PIB per Capita\n");
        break;
    case 6: // Se escolheu PIB per Capita
        printf("1. População\n2. Área\n3. PIB\n4. Pontos Turísticos\n5. Densidade Populacional\n");
        break;
    }

    do {
        printf("Escolha uma opção: ");
        if (scanf("%d", &segundo_atributo) != 1) {
            printf("❌ Entrada inválida! Digite um número válido.\n");
            while (getchar() != '\n'); // Limpa o buffer
            segundo_atributo = 0;
            continue;
        }
        
        if (segundo_atributo < 1 || segundo_atributo > 6) {
            printf("❌ Opção inválida! Digite um número de 1 a 6.\n");
            continue;
        }
        
        if (segundo_atributo == primeiro_atributo) {
            printf("❌ Erro: Você não pode escolher o mesmo atributo duas vezes!\n");
            continue;
        }
        
        break; // Sai do loop se todas as validações passaram
    } while (1);

    // FUNÇÃO PARA OBTER VALORES DOS ATRIBUTOS
    // Para o primeiro atributo
    switch (primeiro_atributo)
    {
    case 1:
        valor1_attr1 = (float)populacao1;
        valor2_attr1 = (float)populacao2;
        break;
    case 2:
        valor1_attr1 = area1;
        valor2_attr1 = area2;
        break;
    case 3:
        valor1_attr1 = pib1;
        valor2_attr1 = pib2;
        break;
    case 4:
        valor1_attr1 = (float)pontos_turisticos1;
        valor2_attr1 = (float)pontos_turisticos2;
        break;
    case 5:
        valor1_attr1 = densidade1;
        valor2_attr1 = densidade2;
        break;
    case 6:
        valor1_attr1 = pib_per_capita1;
        valor2_attr1 = pib_per_capita2;
        break;
    }

    // Para o segundo atributo
    switch (segundo_atributo)
    {
    case 1:
        valor1_attr2 = (float)populacao1;
        valor2_attr2 = (float)populacao2;
        break;
    case 2:
        valor1_attr2 = area1;
        valor2_attr2 = area2;
        break;
    case 3:
        valor1_attr2 = pib1;
        valor2_attr2 = pib2;
        break;
    case 4:
        valor1_attr2 = (float)pontos_turisticos1;
        valor2_attr2 = (float)pontos_turisticos2;
        break;
    case 5:
        valor1_attr2 = densidade1;
        valor2_attr2 = densidade2;
        break;
    case 6:
        valor1_attr2 = pib_per_capita1;
        valor2_attr2 = pib_per_capita2;
        break;
    }

    // COMPARAÇÃO DOS ATRIBUTOS INDIVIDUAIS
    printf("\n=== COMPARAÇÃO DETALHADA ===\n");
    printf("🥊 Atributos escolhidos: %s vs %s\n\n",
           nomes_atributos[primeiro_atributo], nomes_atributos[segundo_atributo]);

    // Comparação do primeiro atributo
    printf("🔹 PRIMEIRO ATRIBUTO - %s:\n", nomes_atributos[primeiro_atributo]);
    printf("   Carta 1 (%s): %.2f\n", nome1, valor1_attr1);
    printf("   Carta 2 (%s): %.2f\n", nome2, valor2_attr1);

    // Lógica especial para densidade populacional (menor vence)
    if (primeiro_atributo == 5)
    { // Densidade populacional
        if (valor1_attr1 < valor2_attr1)
        {
            printf("   🏆 Vencedor: Carta 1 (%s) - menor densidade!\n", nome1);
            pontos_carta1++;
        }
        else if (valor2_attr1 < valor1_attr1)
        {
            printf("   🏆 Vencedor: Carta 2 (%s) - menor densidade!\n", nome2);
            pontos_carta2++;
        }
        else
        {
            printf("   🤝 Empate neste atributo!\n");
        }
    }
    else
    { // Para todos os outros atributos (maior vence)
        if (valor1_attr1 > valor2_attr1)
        {
            printf("   🏆 Vencedor: Carta 1 (%s)\n", nome1);
            pontos_carta1++;
        }
        else if (valor2_attr1 > valor1_attr1)
        {
            printf("   🏆 Vencedor: Carta 2 (%s)\n", nome2);
            pontos_carta2++;
        }
        else
        {
            printf("   🤝 Empate neste atributo!\n");
        }
    }

    // Comparação do segundo atributo
    printf("\n🔹 SEGUNDO ATRIBUTO - %s:\n", nomes_atributos[segundo_atributo]);
    printf("   Carta 1 (%s): %.2f\n", nome1, valor1_attr2);
    printf("   Carta 2 (%s): %.2f\n", nome2, valor2_attr2);

    // Lógica especial para densidade populacional (menor vence)
    if (segundo_atributo == 5)
    { // Densidade populacional
        if (valor1_attr2 < valor2_attr2)
        {
            printf("   🏆 Vencedor: Carta 1 (%s) - menor densidade!\n", nome1);
            pontos_carta1++;
        }
        else if (valor2_attr2 < valor1_attr2)
        {
            printf("   🏆 Vencedor: Carta 2 (%s) - menor densidade!\n", nome2);
            pontos_carta2++;
        }
        else
        {
            printf("   🤝 Empate neste atributo!\n");
        }
    }
    else
    { // Para todos os outros atributos (maior vence)
        if (valor1_attr2 > valor2_attr2)
        {
            printf("   🏆 Vencedor: Carta 1 (%s)\n", nome1);
            pontos_carta1++;
        }
        else if (valor2_attr2 > valor1_attr2)
        {
            printf("   🏆 Vencedor: Carta 2 (%s)\n", nome2);
            pontos_carta2++;
        }
        else
        {
            printf("   🤝 Empate neste atributo!\n");
        }
    }

    // CÁLCULO DA SOMA DOS ATRIBUTOS
    soma1 = valor1_attr1 + valor1_attr2;
    soma2 = valor2_attr1 + valor2_attr2;

    printf("\n=== SOMA DOS ATRIBUTOS ===\n");
    printf("📊 Soma Carta 1 (%s): %.2f + %.2f = %.2f\n", nome1, valor1_attr1, valor1_attr2, soma1);
    printf("📊 Soma Carta 2 (%s): %.2f + %.2f = %.2f\n", nome2, valor2_attr1, valor2_attr2, soma2);

    // RESULTADO FINAL USANDO OPERADOR TERNÁRIO
    printf("\n=== RESULTADO FINAL ===\n");
    printf("🎯 Placar individual: Carta 1 (%d pontos) x Carta 2 (%d pontos)\n", pontos_carta1, pontos_carta2);
    printf("🏁 Resultado pela SOMA DOS ATRIBUTOS:\n");

    // Usando operador ternário para determinar o vencedor final
    printf("🏆 VENCEDOR FINAL: ");
    if (soma1 > soma2)
    {
        printf("Carta 1 - %s\n", nome1);
    }
    else if (soma2 > soma1)
    {
        printf("Carta 2 - %s\n", nome2);
    }
    else
    {
        printf("EMPATE!\n");
    }

    // Explicação detalhada do resultado
    if (soma1 > soma2)
    {
        printf("🎉 %s (%s) venceu com soma %.2f > %.2f!\n", nome1, estado1, soma1, soma2);
        printf("💪 Diferença de %.2f pontos na soma final!\n", soma1 - soma2);
    }
    else if (soma2 > soma1)
    {
        printf("🎉 %s (%s) venceu com soma %.2f > %.2f!\n", nome2, estado2, soma2, soma1);
        printf("💪 Diferença de %.2f pontos na soma final!\n", soma2 - soma1);
    }
    else
    {
        printf("🤝 Empate perfeito! Ambas as cartas somaram %.2f pontos!\n", soma1);
        printf("⚔️ As cidades estão perfeitamente equilibradas!\n");
    }

    printf("\n=== RESUMO DA BATALHA ===\n");
    printf("⚔️  %s (%s) vs %s (%s)\n", nome1, estado1, nome2, estado2);
    printf("🎯 Atributos: %s e %s\n", nomes_atributos[primeiro_atributo], nomes_atributos[segundo_atributo]);
    printf("📊 Somas: %.2f vs %.2f\n", soma1, soma2);
    printf("🏆 Vencedor: %s\n",
           (soma1 > soma2) ? nome1 : (soma2 > soma1) ? nome2
                                                     : "EMPATE");

    return 0;
}
