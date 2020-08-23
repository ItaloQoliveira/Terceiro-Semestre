/*1 - Escreva um programa que gere uma lista com 1000 valores aleatórios (com números entre 0 e
10000), ordene os números, e faça uma comparação entre a busca sequencial e a busca binária,
tal que ao final seja exibido a quantidade de testes realizado em cada método.
O valor buscado é informado pelo usuário.*/
#include<stdlib.h>
#include<time.h>
#include <stdio.h>
#define N 1000
int flag=0;
int contBin=0; //Eu nao gosto de usar variável global mas...
int buscaSeq(int array[],int key);
int buscaBin(int array[],int key, int left, int right);
void preenche(int array[]);
void ordena(int array[]);
void main(){
    int vet[N],chave;
    printf("Insira o número entre 0 e 10000 que será buscado: ");
    scanf("%d",&chave); 
    preenche(vet);
    ordena(vet);
    buscaSeq(vet,chave);
    buscaBin(vet,chave,0,N-1);
    if(flag==1){
        printf("\nNa busca binaria foram testados %d valores e o buscado foi encontrado ",contBin);    
    }else{
        printf("\nNa busca binaria foram testados %d valores e o buscado nao foi encontrado ",contBin);
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
int buscaSeq(int array[],int key){
    int i,contCompara=0;
    for(i=0;i<N && array[i]<=key;i++,contCompara++){
        if(key==array[i]){
            printf("\nNa busca sequencial testamos %d valores e o buscado foi encontrado!",i);
            return i;
        }
    }
    printf("\nNa busca sequencial testamos %d valores e o buscado nao foi encontrado!",i);
    return -1;
}
int buscaBin(int array[],int key,int left, int right){
    if(left>right){
        return -1;
    }
    int mid=(left+right)/2;
    contBin++;
    if(array[mid]==key){
        flag=1;
        return mid;
    } else if(array[mid]>key){
        return buscaBin(array,key,left,mid-1);
    } else if(array[mid]<key){
        return buscaBin(array,key,mid+1,right);
    }
}