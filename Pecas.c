#include<stdio.h>
#include<stdbool.h>

int peca, direcaoVertical, direcaoHorizontal, lado, casas, indexDirecao = 1, maxCasas = 7;
char* direcaoVerticalChar; 
char* direcaoHorizontalChar;

bool EscolhaErrada(int escolha, int escolhaMax)
{
    return escolha <= 0 || escolha > escolhaMax;
}

void EscolhaDePeca()
{
    do
    {
        printf("escolha a peça!\n");
        printf("1. Torre\n");
        printf("2. Bispo\n");
        printf("3. Rainha\n");
        printf("4. Cavalo\n");
        scanf("%d", &peca);
    }
    while (EscolhaErrada(peca, 4));
    

    switch (peca)
    {
        case 1:
        printf("Você escolheu a Torre\n");
        break;

        case 2:
        printf("Você escolheu o Bispo\n");
        break;
    
        case 3:
        printf("Você escolheu a Rainha\n");
        break;

        case 4:
        printf("Você escolheu o Cavalo\n");
        break;
    }
}

void EscolhaDoLado()
{
    if(peca == 1)
    {
        do
        {
            printf("Para qual lado irá mover\n");
            printf("1. Cima ou Baixo\n");
            printf("2. Direita ou Esquerda\n");
            scanf("%d", &lado);
        } while (EscolhaErrada(lado, 2));
    }
}

void EscolhaVertical()
{
    if(peca != 1 || lado == 1)
    {
        do
        {
            printf("Para onde irá mover verticalmente\n");
            printf("1. Cima\n");
            printf("2. Baixo\n");
            scanf("%d", &direcaoVertical);
        } while (EscolhaErrada(direcaoVertical, 2));
    
        if(direcaoVertical == 1) 
            direcaoVerticalChar = "Cima\n";
        else if(direcaoVertical == 2) 
            direcaoVerticalChar = "Baixo\n";

        printf("Escolheu %s\n", direcaoVerticalChar);
    }
}

void EscolhaHorizontal()
{
    if(peca != 1 || lado == 2)
    {
        do
        {
            printf("Para onde irá mover horizontalmente\n");
            printf("1. Direita\n");
            printf("2. Esquerda\n");
            scanf("%d", &direcaoHorizontal);
        } while (EscolhaErrada(direcaoHorizontal, 2));
    
        if(direcaoHorizontal == 1) 
            direcaoHorizontalChar = "Direita\n";
        else if(direcaoHorizontal == 2) 
            direcaoHorizontalChar = "Esquerda\n";
    }
}

void AndarNumeroDeCasas()
{
    switch (peca)
    {
        //Cavalo
        case 4:

        for(int i = 0; i < 2; i++)
        {
            printf("%s", direcaoVerticalChar);
        }

        printf("%s", direcaoHorizontalChar);
        
        break;
    
        //Peças normais
        default:
        do
        {
            printf("Mova o número de casas que deseja de 1 até 7!\n");
            scanf("%d", &casas);
        } while (EscolhaErrada(casas, maxCasas));

        for(int i = 0; i < casas; i++)
        {
            if(direcaoHorizontal != 0) printf("%s", direcaoHorizontalChar);
            if(direcaoVertical != 0) printf("%s", direcaoVerticalChar);
            printf("\n");
        }
        break;
    }
}

int main()
{
    EscolhaDePeca();
    EscolhaDoLado();
    EscolhaVertical();
    EscolhaHorizontal();
    AndarNumeroDeCasas();
    return 0;
}
