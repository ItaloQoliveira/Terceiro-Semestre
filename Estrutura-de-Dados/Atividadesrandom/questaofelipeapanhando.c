/*Preencher vetor numerico aleatoriamente
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void preenche(int vetor[]);
void main(){
  int vet[10],i;

  preenche(vet);

  for(i=0;i<10;i++){
    printf("%d ",vet[i]);
  }
}
void preenche(int vetor[]){
  int i;
  for(i=0;i<10;i++){
    vetor[i]= rand() % 100;
  }
}
