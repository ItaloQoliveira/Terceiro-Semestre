/*1 - Escreva um programa que gere uma lista com 1000 valores aleatórios (com números entre 0 e
10000), ordene os números, e faça uma comparação entre a busca sequencial e a busca binária,
tal que ao final seja exibido a quantidade de testes realizado em cada método.
O valor buscado é informado pelo usuário.*/
#include<stdlib.h>
#include<time.h>
#include <stdio.h>
#define N 100
void imprime(int array[]);
void preenche(int array[]);
void ordena(int array[]);
int buscaQuaseIndex(int array[],int key);
void main(){
    int vet[N],chave;
    preenche(vet);
    ordena(vet);
    imprime(vet);
    printf("Insira o número que será buscado: ");
    scanf("%d",&chave); 
    buscaQuaseIndex(vet,chave);
    
      
}
int buscaQuaseIndex(int array[],int key){
    int i,j;
    for(i=0;i<N;i+=10){
        if(array[i]>key){
            for(j=i;array[j]>=key;j--){
                if(array[j]==key){
                    printf("Valor presente no vetor");
                    return j;
                }
            }
        }
    }
    printf("Valor não presente no vetor");
    return -1;
}
void imprime(int array[]){
    int i;
    for(i=0;i<N;i++){
        printf("%d ",array[i]);
    }
}
void ordena(int array[]){
    int i,j,aux;
    for(i=0;i<N;i++){
        j=i;
        while((j>=0) && (array[j]>array[j+1]) ){
            aux=array[j];
            array[j]=array[j+1];
            array[j+1]=aux;
            j--;
        } 
    }
}
void preenche(int array[]){
    int i;
    srand(time(NULL));
    for(i=0;i<N;i++){
        array[i]=rand() %10001;
    }
}
