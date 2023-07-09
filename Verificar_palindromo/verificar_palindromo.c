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

int verificarPalindromo(char palavra[])
{
  int contador = 0, limite = 0, salvacont = 0;
  while(palavra[contador] != '\0')
    contador++;
  limite = contador;
  char reverte[limite];
  salvacont = limite;
  limite = 0;

  for(; contador > 0; contador--)
  {
    reverte[contador-1] = palavra[limite];
    limite++;
  }

  for(contador = 0; contador < salvacont; contador++)
  {
    if(palavra[contador] != reverte[contador])
      return 0;
  }
  return 1; 
}

int main(void)
{
  char palavra[200];
  printf("Digite uma string para ver se é um anagrama de um palindromo\n");
  Sget(palavra, 200);
  printf("%s", verificarPalindromo(palavra)? "true" : "false");
}