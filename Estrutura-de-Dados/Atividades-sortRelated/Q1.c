/*Escreva um programa que receba uma frase, remova os espaços e ordene os caracteres (Utilize o método seleção direta)*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>
void removeEspaco(char texto[]);
void main(){
    int i,j,maior,maiorindex;
    char frase[]="The  quIck    bRown fox juMps   ovEr  the  lazy  dog",aux;//frase demonstrativa
    removeEspaco(frase);//manda pra função que remove espaço(incluindo duplos :) )
    //puts(frase);// linha de teste da funcao removeEspaco
    for(i=0;i<strlen(frase);i++){ //transformar tudo em minuscula, senao maiuscula sempre vem antes pois, tabela ascii
        frase[i]=tolower(frase[i]);
    }
    for(i=(strlen(frase)-1);i>0;i--){ 
        maior = frase[i]; //seta o maior, pois no selection eu primeiro descubro o maior e troco 1x apenas
        maiorindex=i; //pego o index do maior, preciso dele
        for(j=0;j<=i;j++){
            if(frase[j]>maior){ //indentifico o maior e salvo o index dele
                maior=frase[j];
                maiorindex=j;
            }
        }
        aux=frase[maiorindex]; //agora faz a troca
        frase[maiorindex]=frase[i];
        frase[i]=aux;
        
    }
    puts(frase);
}


void removeEspaco(char texto[]){
    int i,j,k,duplo =0;
    char proibido =' ';
    for(i=0;i<strlen(texto);i++){
        if(texto[i]==proibido){
            for (j=i;j<strlen(texto);j++){
                texto[j]= texto[j+1];
                if(texto[j]==texto[j+1]){
                    duplo+=1;                  
                }
            }
        }
        if (duplo>0){ 
            i--;
            duplo--;
        }
    }
}
