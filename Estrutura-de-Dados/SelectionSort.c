//Mesmo header do insertionsort.jpg
#include <stdio.h>

void main(){
    int array[]={8,5,9,4,6,2,3},i,j,maiorindex,maiorzin,aux;
    for(i=6;i>0;i--){
        maiorzin=array[i];
        maiorindex=i;
        for(j=0;j<=i;j++){
            if(array[j]>maiorzin){
                maiorzin=array[j]; //MANO, to mto feliz 
                maiorindex=j;//Deu bom. Só precisei de um
            }                // baralho e alguns neuronios
        }                    // Bom trabalho, italo 8:)
        aux=array[maiorindex];
        array[maiorindex]=array[i];
        array[i]=aux;
    }
    for(i=0;i<7;i++){
        printf("%d",array[i]);
    }
}