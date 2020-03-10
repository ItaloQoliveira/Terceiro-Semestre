//Esse aqui é bobolha
#include <stdio.h>

void main(){
    int array[]={3,6,4,8,9,7,5,2},i,j,aux;

    for(i=0;i<7;i++){
        for(j=i;j<7;j++){
            if(array[i]>array[j]){
                aux=array[i];
                array[i]=array[j];
                array[j]=aux;
            }
        }
    }
    for(i=0;i<7;i++){
        printf("%d",array[i]);
    }
}