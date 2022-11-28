#include <stdio.h>
#include <stdlib.h>
 /** Define constante **/
#define MAX 5
 /**Funcao de ordenacao**/
void insertionSort(int *a);

int main(int argc, char** argv)
{
 int i, vetor[MAX];

 /** Lê a constante MAX **/
 for(i = 0; i < MAX; i++)
 {
  printf("Digite um valor: ");
  scanf("%d", &vetor[i]);
 }

 /** Ordena os valores **/
 insertionSort(vetor);

 /** Imprime os valores agora ordenados **/
 printf("Valores ordenados \n");
 for(i = 0; i < MAX; i++)
 {
  printf("%d \n", vetor[i]);
 }
 return 0;
}

// Função de Ordenação por Inserção
void insertionSort(int *a)
{
 int i, j, tmp;

 for(i = 1; i < MAX; i++)
 {
  tmp = a[i];
  for(j = i-1; j >= 0 && tmp < a[j]; j--)
  {
   a[j+1] = a[j];
  }
  a[j+1] = tmp;
 }
}
