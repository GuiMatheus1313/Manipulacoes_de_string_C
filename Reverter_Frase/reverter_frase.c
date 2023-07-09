#include <stdio.h>
#include <string.h>

//Função feita para remover o 'ENTER' inserido pela função fgets
int Sget(char *vetor, int TAM)
{
    fflush(stdin);
    if(fgets(vetor, TAM, stdin))
    {
        int i;
        for(i=0; vetor[i] != '\n' && vetor[i]; i++)
            ;
        vetor[i] = '\0';
    }
}

void ReverteFrase(char frase[], int tamanho)
{
    int i = 0, j = 0;

    for(i = tamanho-1; i >= 0; i--)
    {
        if(frase[i] == ' ')
        {
            for(j = i+1; j < tamanho && frase[j] != ' '; j++)
                printf("%c", frase[j]);
        }
    }
}

#define tamanho 200
int main()
{
    int tam_atual = 0;
    char frase_original[tamanho];
    char frase_revertida[tamanho];
    
    printf("Digita uma frase de até 199 caracteres para reverte-la\n");
    Sget(frase_original, tamanho);
    
    tam_atual = strlen(frase_original);
    ReverteFrase(frase_original, tamanho);
}