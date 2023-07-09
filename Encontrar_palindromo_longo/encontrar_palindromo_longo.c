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

int PalindromoVF(char palavra[], int i, int j)
{
    for(; i < j; i++, j--)
        if (palavra[i] != palavra[j])
            return 0;
    return 1;
}

void PalindromoLongo(char palavra[])
{
  int contador_palindromo = 0, limite = 1, salvacont = 0, i = 0, j = 0;
  salvacont = strlen(palavra);
  //limite = contador;
  //salvacont = limite;
  //limite = 0;


  while(i < salvacont)
  {
    for(j = i; j < salvacont; j++)
        if(PalindromoVF(palavra, i, j) && (j - i + 1) > limite)
        {
            contador_palindromo = i;
            limite = j-i + 1;
        }
    i++;
  }

  for(i = contador_palindromo; i < contador_palindromo + limite; i ++)
    printf("%c", palavra[i]);
}

int main()
{
    char palavra[200];
    printf("Digite uma string para ver se é um anagrama de um palindromo\n");
    Sget(palavra, 200);
    PalindromoLongo(palavra);
}