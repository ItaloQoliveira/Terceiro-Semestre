/*Considrando que uma lista estática esteja ordenada de modo decrescente faça os ajustes para 
que a busca binária seja realizada corretamente.*/
#include <stdio.h>
int buscaBin(int array[],int key, int left, int right);
void main(){
    int vet[]={15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};// vetor qualquer decrescente
    buscaBin(vet,13,0,14);

}
int buscaBin(int array[],int key,int left, int right){
    if(left>right){
        return -1;
    }
    int mid=(left+right)/2;
    if(array[mid]==key){
        printf("Valor encontrado na posiçao %d",mid);   
        return mid;
    } else if(array[mid]<key){
        buscaBin(array,key,left,mid-1); //já que a ordem é decrescente, é só inverter os sinais de maor e menor :)
    } else if(array[mid]>key){
        buscaBin(array,key,mid+1,right);
    }
}