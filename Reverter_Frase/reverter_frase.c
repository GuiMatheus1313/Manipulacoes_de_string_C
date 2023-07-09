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
    //Variáveis de controle para loops
    int i = 0, j = 0, k = 0;

    //Loop para percorrer de trás para frente
    for(i = tamanho-1; i >= 0; i--)
    {
        //Condição para formular a inversão após cada espaço
        if(frase[i] == ' ')
        {
            //Após o espaço, adaptará as letras para reverte-las 
            for(j = i+1; j < tamanho && frase[j] != ' '; j++)
                printf("%c", frase[j]);
            printf(" ");
        }
        
    }

    //Loop especificado para a última palavra/letra
    for(;frase[k] != ' ' && k < tamanho; k++)
      printf("%c", frase[k]);
}

#define tamanho 200
int main()
{
    int tam_atual = 0;
    char frase_original[tamanho];
    
    printf("Digita uma string de até 199 caracteres para reverte-la\n");

    //Função que adapta o fgets()
    Sget(frase_original, tamanho);
    
    //Adquire o tamanho atual da string e inicia o procedimento de reverter a frase
    tam_atual = strlen(frase_original);
    ReverteFrase(frase_original, tam_atual);
}