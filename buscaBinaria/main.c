#include <stdio.h>
#include <stdlib.h>

int main(){ /** a busca binaria funciona somente com vetores ordenados **/

    int *vetor; /** Variavel para passar um ponteiro para o vetor que sera alocado **/
    int tamanhovetor; /** Variavel para receber o tamanho do vetor que sera alocado **/
    int i; /** Variavel para contar os loops **/
    int valor; /** Variavel com valor temporario da posicao do vetor **/
    int valorbusca; /** Variavel para escolher qual vetor buscar **/
    int controlebusca = 1; /** Variavel para identificar se o elemento foi encontrado **/
    int comeco, meio, fim; /** Variaveis de controle do vetor durante a busca binaria **/


    /** Escreve uma mensagem pedindo o tamanho do vetor **/
    printf("Digite um tamanho para o seu vetor: ");

    /** Recebe o tamanho do vetor **/
    scanf("%d", &tamanhovetor);

    /** Aloca o espaco de memoria do vetor **/
    vetor = (int *) malloc(tamanhovetor * sizeof(int));

    /** Verifica se houve erro na alocacao **/
    if (vetor == NULL)
    {

       /** Exibe a mensagem de erro **/
       printf("Não foi possível realizar a alocação do seu vetor");
       return(1);

    }
    else
    {

        /** Pegar os valores do vetor **/
        for (i = 0; i < tamanhovetor; i++)
        {
            printf("Digite a posicao %d do vetor: ", i);
            scanf("%d", &valor);
            vetor[i] = valor;
        }

        /** Recebe o valor a ser buscado no vetor **/
        printf("Digite o elemento que deseja buscar no seu vetor: ");
        scanf("%d", &valorbusca);

        /** Define o inicio e o fim do vetor **/
        comeco = 0;
        fim = tamanhovetor - 1;

        /** Loop que ira realizar a busca binaria **/
        while (comeco <= fim)
        {

              /** Obtem o meio do vetor **/
              meio = (comeco + fim) / 2;

              /** Verifica se o elemento foi encontrado **/
              if (valorbusca == vetor[meio])
              {
                 controlebusca = 0;
                 break;
              }

              /**
               Se o valor buscado for menor que o meio do vetor,
               entao o fim do vetor sera o meio atual -1
              **/
              else if (valorbusca < vetor[meio])
              {
                 fim = meio - 1;
                 continue;
              }

              /**
               Se o valor buscado for maior que o meio do vetor, entao a busca
               comecara a partir do meio atual atual do vetor
              **/
              else if(valorbusca > vetor[meio])
              {
                 comeco = meio + 1;
                 continue;
              }

              /**
               Caso nada seja encontrado, define o controleBusca = 1
              **/
              else
              {
                 controlebusca = 1;
                 break;
              }

        }

        /**
         Verifica a variavel que indica se o elemento foi encontrado ou nao.
         Se for 0, o elemento foi encontrado, caso contrario, o elemento nao foi
         encontrado. Basta entao exibir as mensagens.
        **/
        if (controlebusca == 0){
           printf("O elemento %d foi encontrado! Posicao: %d - Valor: %d", valorbusca, meio, vetor[meio]);
        } else {
           printf("O elemento %d nao foi encontrado!", valorbusca);
        }

        return (0);

    }

}
