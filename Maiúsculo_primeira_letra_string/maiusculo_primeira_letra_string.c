#include <stdio.h>
#include <string.h>

char minuscula[26] = 
  {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
  char maiusculo[26] = 
  {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

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

int encontraMinuscula(int i, char palavra[])
{
  for(int j = 0; j < 26; j++)
    {
       if(palavra[i] == minuscula[j])
         return j;
    }
}

void Maiusculo_frase(char palavra[])
{
  int contador = 0, limite = 0, salvacont = 0, index_letra = 0;
  contador = strlen(palavra);
  limite = contador;
  salvacont = limite;
  

  for(int i = 0; i < 26; i++)
  {
    if(palavra[0] == minuscula[i])
    {
      printf("%c", maiusculo[i]);
      break;
    }
  }

  //for(int i = 1; i < 26; i++)
  int frase_limite = 1;
  while (frase_limite < 200)
  {
    for(int i = 1; i < 26; i++, frase_limite++)
    {
      index_letra = encontraMinuscula(frase_limite+2, palavra);
      if((palavra[frase_limite] == '.' || palavra[frase_limite] == '?') && palavra[frase_limite+1] == ' ' && palavra[frase_limite+2] ==   minuscula[index_letra])
      {
        palavra[frase_limite+2] = maiusculo[index_letra];
        printf("%c %c", palavra[frase_limite], palavra[frase_limite+2]);
        frase_limite += 2;
      }
      else
        printf("%c", palavra[frase_limite]);
    }
    if (palavra[frase_limite] != '\0')
      ;
    else
      break;
  }
}

int main()
{
  char frase[200];
  printf("Digite uma string para ver se é um anagrama de um palindromo\n");
  Sget(frase, 200);
  Maiusculo_frase(frase);
}