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

void RemoveCaractereDuplo(char frase[])
{
    char repete = ' ';
    int limite_frase = strlen(frase);
    for (int i = 0; i < limite_frase; i++)
    {
        int repete = 0;
        for(int j = 0; j < i; j++)
        {
            if(frase[i] == frase[j] && frase[i] != ' ')
            {
                repete = 1;
                break;
            }
        }
        if(repete == 0)
            printf("%c", frase[i]);
    }
}


int main()
{
  char frase[200];
  printf("Digite uma string para ver se é um anagrama de um palindromo\n");
  Sget(frase, 200);
  RemoveCaractereDuplo(frase);
}