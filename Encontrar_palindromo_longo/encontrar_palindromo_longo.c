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

//Função que retorna se até aquela parte é palindromo ou não
int PalindromoVF(char palavra[], int i, int j)
{
    for(; i < j; i++, j--)
        if (palavra[i] != palavra[j])
            return 0;
    return 1;
}

void PalindromoLongo(char palavra[])
{
  //Variáveis para controle de loop
  int contador_palindromo = 0, limite = 1, salvacont = 0, i = 0, j = 0;
  salvacont = strlen(palavra);

  //Loop em que inicia a transição da string
  while(i < salvacont)
  {
    //Loop para percorrer e substituir os palindromos mais longos encontrados, com inicio e fim
    for(j = i; j < salvacont; j++)
        if(PalindromoVF(palavra, i, j) && (j - i + 1) > limite)
        {
            contador_palindromo = i;
            limite = j-i + 1;
        }
    i++;
  }
  
  //Loop na qual retorna o palindromo mais longo da string ao usuário
  for(i = contador_palindromo; i < contador_palindromo + limite; i ++)
    printf("%c", palavra[i]);
}

int main()
{
    char palavra[200];
    printf("Digite uma string para encontrar o maior palindromo\n");
    //Função que adapta o fgets()
    Sget(palavra, 200);
    //Inicia o procedimento do processo
    PalindromoLongo(palavra);
}