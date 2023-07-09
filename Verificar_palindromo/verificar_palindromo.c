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
  //Criação das variações de controle de loop
  int contador = 0, limite = 0, salvacont = 0;

  //Loop na qual encontra o tamanho da string do vetor
  while(palavra[contador] != '\0')
    contador++;

  //Armazenar o tamanho da string
  limite = contador;

  //Vetor para armazenar a string reversa
  char reverte[limite];

  salvacont = limite;
  limite = 0;

  //Loop utilizado para formar a string reversa
  for(; contador > 0; contador--)
  {
    reverte[contador-1] = palavra[limite];
    limite++;
  }

  //Loop para mover ambas as strings
  for(contador = 0; contador < salvacont; contador++)
  {
    //Condição para atestar se é ou não palindromo
    if(palavra[contador] != reverte[contador])
      return 0;
  }
  //Caso passar o loop, será palindromo
  return 1; 
}

int main(void)
{
  char palavra[200];
  printf("Digite uma string para ver se é um anagrama de um palindromo\n");
  //Função que adapta o fgets()
  Sget(palavra, 200);

  //Reproduzirá no display do usuário true ou false de acordo com o valor retornado
  printf("%s", verificarPalindromo(palavra)? "true" : "false");
}