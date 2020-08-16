//2 - Escreva um programa que gere 30 números aleatórios e faça ordenação destes números em ordem inversa (Utilize o método de inserção)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main(){
    int vet[30],i,j,aux;
    srand(time(NULL)); //fazendo ele ser random de verdade
    for(i=0;i<30;i++){ //preenchendo
        vet[i]=rand()%300;
    }
    for(i=1;i<29;i++){
        j=i;
        while (j>=0 && vet[j]<vet[j+1]){ //o maior fica sempre a direita, ordem decrescente
            aux=vet[j];
            vet[j]=vet[j+1];
            vet[j+1]=aux;
            j--;
        }
        
    }
    for(i=0;i<30;i++){ //mostrando resultado
        printf("%d ",vet[i]);
    }
}