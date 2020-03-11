#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Q 5
void bubble(int array[]); //nota do criador: torto=decrescente
void bubbletorto(int array[]);
void selection(int array[]);
void selectiontorto(int array[]);
void insertion(int array[]);
void insertiontorto(int array[]);
void troca(int *a,int *b);
void preencher(int array[]);

void main(){
    int vetor[Q],i;
    preencher(vetor);
    selectiontorto(vetor);
    for(i=0;i<Q;i++){
        printf("%d ",vetor[i]);
    }
}
void preencher(int array[]){
    int i;
    srand(time(NULL));
    for(i=0;i<Q;i++){
        array[i]=rand() %101;        
    }
}
void troca(int *a,int *b){
    int aux;
    aux=*a;
    *a=*b;
    *b=aux;
}
void bubble(int array[]){
    int i,j;
     
    for(i=0;i<Q;i++){
        for(j=0;j<Q-1-i;j++){
            if(array[j]>array[j+1]){
                troca(&array[j],&array[j+1]);
            }
        }
    }
}
void bubbletorto(int array[]){
    int i,j;
    for(i=0;i<Q;i++){
        for(j=0;j<Q-1-i;j++){
            if(array[j]<array[j+1]){
                troca(&array[j],&array[j+1]);
            }
        }
    }
}
void selection(int array[]){
    int i,menor,j;
    for(i=0;i<Q;i++){
        menor=i;
        for(j=i;j<Q;j++){
            if(array[menor]>array[j]){
                menor=j;
            }
        }
        troca(&array[i],&array[menor]);
    }
}
void selectiontorto(int array[]){
    int i,maior,j;
    for(i=0;i<Q;i++){
        maior=i;
        for(j=i+1;j<Q;j++){
            if (array[maior]<array[j]){
                maior=j;
            }
        }
        troca(&array[maior],&array[i]);
    }
}

void insertion(int array[]){
    int i,j;
    for(i=1;i<Q;i++){
        j=i;
        while(j>0 && array[j]<array[j-1]){
            troca(&array[j],&array[j-1]);
            j--;
        }
    }
}
void insertiontorto(int array[]){
    int i,j;
    for(i=1;i<Q;i++){
        j=i;
        while(j>0 && array[j]>array[j-1]){
            troca(&array[j],&array[j-1]);
            j--;

        }
    }
}
