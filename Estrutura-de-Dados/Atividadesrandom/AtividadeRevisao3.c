/*Escreva um programa que receba um
valor do usuário e determine se o
mesmo é um número primo*/
#include <stdio.h>
#include <stdlib.h>
void main(){
  int i,cont=0,valor;
  printf("Digita o valor aí sagrada dama:"); //as palavras ofensivas são uma brincadeira interna, eu juro
  scanf("%d", &valor);
  for  (i = 1; i < valor; i++) {
      if (valor % i ==0) {
        cont++;
      }
  }
  if(cont==1){
    printf(" é um numero primo, bela moça!\n");
  } else{
    printf(" não é um numero primo\n");
  }
}
