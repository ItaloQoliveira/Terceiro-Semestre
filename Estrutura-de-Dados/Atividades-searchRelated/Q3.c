/*Implemente o método de busca sequencial em vetor ordenado que remove o elemento do vetor 
todas as vezes em que o valor é encontrado. Com isso, a quantidade de valores armazenado no 
vetor é dinâmica.*/
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#define N 25
void ordena(int array[]);
void imprime(int array[],int tamanho);
void main(){
    int *vetor,i,tam=N,j,remove,aux;
    vetor=(int *)malloc(tam*sizeof(int));
    srand(time(NULL));
    for(i=0;i<tam;i++){
        vetor[i]=rand() % 50;
    }
    ordena(vetor);
    imprime(vetor,tam);
    printf("\nValor a ser removido: ");
    scanf("%d",&remove);
    for(i=0;i<tam;i++){
        if(vetor[i]==remove){
            for(j=i;j<tam-1;j++){
                if(vetor[j]==vetor[j+1]){ //Resolver o problema de quando o valor esta repetido
                    i=0; 
                }
                aux=vetor[j];
                vetor[j]=vetor[j+1];
                vetor[j+1]=aux;
            }
            tam--;
        }
    }
    vetor=(int *)realloc(vetor,tam*sizeof(int)); //aloca novamente removendo os espaços que tinham o numero a ser removido
    imprime(vetor,tam);
}
void imprime(int array[],int tamanho){
    int i;
    for(i=0;i<tamanho;i++){
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