#include <stdio.h>
#include <string.h>
//Variáveis globais com o alfabeto completo
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
  //Variáveis para controle de loops 
  int contador = 0, limite = 0, salvacont = 0, index_letra = 0;
  contador = strlen(palavra);
  limite = contador;
  salvacont = limite;
  
  //Loop para a primeira letra da string
  for(int i = 0; i < 26; i++)
  {
    //Condição se ela é minuscula 
    if(palavra[0] == minuscula[i])
    {
      printf("%c", maiusculo[i]);
      break;
    }
  }

  int frase_limite = 1;

  //Loop feito para proceder a cada 26 letras na string
  while (frase_limite < 200)
  {
    //Loop para inicio da verificação do resto 
    for(int i = 1; i < 26; i++, frase_limite++)
    {
      //Executado a função para encontrar a minuscula da posição
      index_letra = encontraMinuscula(frase_limite+2, palavra);

      //Condição para verificar os itens necessários para transformar de minusculo para maiusculo 
      if((palavra[frase_limite] == '.' || palavra[frase_limite] == '?') && palavra[frase_limite+1] == ' ' && palavra[frase_limite+2] ==   minuscula[index_letra])
      {
        //Substitui a letra minuscula -> maiuscula 
        palavra[frase_limite+2] = maiusculo[index_letra];

        //Mostra no display a string adaptada
        printf("%c %c", palavra[frase_limite], palavra[frase_limite+2]);
        frase_limite += 2;
      }
      //Mostra a letra fora da condição
      else
        printf("%c", palavra[frase_limite]);
    }
    //Termina o loop quando a string for vazia na posição selecionada 
    if (palavra[frase_limite] != '\0')
      ;
    else
      break;
  }
}

int main()
{
  char frase[200];
  printf("Digite uma string para adaptar as letras minusculas para maiusculas\n");
  //Função que adapta o fgets()
  Sget(frase, 200);
  //Procedimento para iniciar o processo
  Maiusculo_frase(frase);
}