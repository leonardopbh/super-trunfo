#include <stdio.h>

// recursao pra torre
void moverTorre(int n)
{
    if (n == 0)
        return;

    printf("Direita\n");
    moverTorre(n - 1);
}

// recursao do bispo
void moverBispo(int n)
{
    if (n == 0)
        return;

    printf("Cima\n");
    printf("Direita\n");
    moverBispo(n - 1);
}

// rainha recursiva
void moverRainha(int n)
{
    if (n == 0)
        return;
    printf("Esquerda\n");
    moverRainha(n - 1);
}

int main()
{
    int casasTorre = 5;
    int casasBispo = 5;
    int casasRainha = 8;

    // torre
    printf("Torre:\n");
    moverTorre(casasTorre);
    printf("\n");

    // bispo recursivo
    printf("Bispo (recursivo):\n");
    moverBispo(casasBispo);
    printf("\n");

    // bispo com loops aninhados
    printf("Bispo (loops aninhados):\n");
    for (int i = 0; i < casasBispo; i++)
    {
        printf("Cima\n");
        for (int j = 0; j < 1; j++)
        {
            printf("Direita\n");
        }
    }
    printf("\n");

    // rainha
    printf("Rainha:\n");
    moverRainha(casasRainha);
    printf("\n");

    // cavalo em L - 2 pra cima, 1 pra direita
    printf("Cavalo:\n");
    int cont = 0;
    int cima = 0;
    int dir = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 1; j++)
        {
            if (cima < 2)
            {
                printf("Cima\n");
                cima++;
                cont++;
                break;
            }
            else if (dir < 1)
            {
                printf("Direita\n");
                dir++;
                cont++;
                break;
            }
            else
            {
                continue;
            }
        }

        if (cont >= 3)
        {
            break;
        }
    }

    return 0;
}
