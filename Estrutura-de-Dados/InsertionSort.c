/*Vou utilizar deste arquivo para aprender insertion sort e 
o selection sort. Sei bem a teoria, mas nunca implementei
GL italo do futuro <3*/
#include <stdio.h>

void main(){
    int array[]={39,77,55,28,69,46,94},c, j,i;
    for(i=0;i<7;i++){
        j=i;
        while (j>=0 && (array[j]>array[j+1])){
            c=array[j];
            array[j]=array[j+1];
            array[j+1]=c;
            j--; //Tô bem feliz, deu bom! <3 :) 
        }
        
    }
    for(i=0;i<7;i++){
        printf("%d",array[i]);
    }
}
