#include <stdio.h>
#include <stdlib.h>
/*Escreva um programa que receba 3
valores e informe qual deles é o maior
valor*/
void main(){
  int v[3],i,j,maior=0;
  printf("Digite 3 números que lhe direi qual o maior\n");
  scanf("%d %d %d",&v[0],&v[1],&v[2]);
  for ( i = 0; i < 3; i++) {
      if (v[i]>maior){
        maior= v[i];
      }
  }
  printf("%d foi o maior número digitado <3\n",maior );
}
