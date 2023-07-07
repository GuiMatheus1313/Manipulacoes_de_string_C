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

#define tamanho 200
int main()
{
    int tam_atual = 0;
    char frase_original[tamanho];
    char frase_revertida[tamanho];
    
    printf("Digita uma frase de até 199 caracteres para reverte-la\n");
    Sget(frase_original, tamanho);
    
    tam_atual = strlen(frase_original);

    printf("A frase revertida esta abaixo\n");
    for(int i = tam_atual-1; 0 < i; i--)
        printf("%s", frase_original[i]);
    return 0;
}