#include <stdio.h>
#include <stdlib.h>
int fatorial(int num);
void main(){
    int x;
    printf("Digite x, te mostrarei (x!)\n ");
    scanf("%d",&x);
    printf("(%d!)=%d",x,fatorial(x));
}
int fatorial(int num){
    if ((num-1)>0){ // Se o número é maior ou igual a 2, ele vai entrar na multiplicação.
        num*=fatorial(num-1); //o número é multiplicado com ele mesmo -1 repetidas vezes até que se alcance o valor de 1.
    }
    return num;
}

/* O problema escolhido por mim foi fatorial. O fatorial de um determinado número inteiro N, expresso N!
É calculado multiplicando todos os números anteriores maiores que 1. 
Por exemplo, caso N seja 4, devemos fazer 4x3x2.*/

