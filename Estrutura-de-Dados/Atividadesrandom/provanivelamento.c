#include <stdio.h>
#include <string.h>
char notaFinal(float n1, float n2, float n3);
int primo(int x);
int menorQueMedia(int nums[], int N);
void percentualDespesas(float gastos[]);
void removeVazio(char texto[]);
void main() {
    char nota[]="outro teste para garantir e evitar falhas";
    removeVazio(nota);
    printf("%s",nota);
}
char notaFinal(float n1, float n2, float n3){
    float media;
    media= ((n1*2) + (n2*3) + (n3*5))/10;
    if (media>8.5){
        return 'A';
    } else if (media > 7){
        return 'B';
    } else if (media>6){
        return 'C';
    }else {
        return 'D';
    }
}   
int primo(int x){
    int i,contador=0;
    for(i=1;i<x;i++){
        if(x%i==0){
            contador++;
        }
    }
    if(contador==1){
        return 1;
    }else{
        return 0;
    }
}
int menorQueMedia(int nums[], int N){  
    int i,abaixocontador=0;           
    float media,soma=0;
    for(i=0;i<N;i++){
        soma+=nums[i];
    }
    media = soma/N;
    for (i=0;i<N;i++){
        if(nums[i]<media){
            abaixocontador++;
        }
    }
    return abaixocontador;
}
void percentualDespesas(float gastos[]){
    float somatotal;
    int i;
    for(i=0;i<10;i++){
        somatotal+= gastos[i];
    }
    for(i=0;i<10;i++){
        printf("O gasto total da despesa %d foi de: %.2f porcento \n ",i, (gastos[i]/somatotal)*100 );
    }
}
void removeVazio(char texto[]){
    int i,j,k;
    char proibido =' ';
    for(i=0;i<strlen(texto);i++){
        if(texto[i]==proibido){
            for (j=i;j<strlen(texto);j++){
                texto[j]= texto[j+1];
            }
        }
    }

}