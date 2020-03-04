/*Escreva um programa que receba o
ano de nascimento do usuário e
calcule e informe a sua idade no ano
de 2025
*/
#include <stdlib.h>
#include <stdio.h>
void main() {
    char nome[50];
    int nascimento;
    printf("Qual seu nome, belo senhor??\n" );
    scanf("%s",nome);
    printf("Qual o ano do seu nascimento, caro senhor?\n");
    scanf("%d",&nascimento);
    printf("A idade de %s em 2025 é %d\n",nome,(2025-nascimento));
}
