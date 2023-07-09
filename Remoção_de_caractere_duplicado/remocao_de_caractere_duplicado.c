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
    //Adquire o tamanho total da string em int
    int limite_frase = strlen(frase);
    
    //Loop que irá servir como uma passagem da string escrita, indo de 1 em 1
    for (int i = 0; i < limite_frase; i++)
    {
        //Variável usada para verificação de valores V ou F
        int repete = 0;
        //Loop que irá percorrer toda a string para encontrar se há caractere repete até a posição do loop anterior
        for(int j = 0; j < i; j++)
        {
            //Condição para confirmar se há caractere repetido, sendo o j a passagem de toda string
            if(frase[i] == frase[j] && frase[i] != ' ')
            {
                repete = 1;
                break;
            }
        }
        //Quando não tiver retornado um valor V, irá reproduzir o caractere não multiplicado
        if(repete == 0)
            printf("%c", frase[i]);
    }
}


int main()
{
  char frase[200];
  //Mostrará para o usuário um display de mensagem e permitirá o input de string
  printf("Digite uma string de até 199 caracteres para remover os caracteres multiplicados\n");
  //Função que adapta o fgets()
  Sget(frase, 200);

  //Função que inicia o processo de remoção
  RemoveCaractereDuplo(frase);
}