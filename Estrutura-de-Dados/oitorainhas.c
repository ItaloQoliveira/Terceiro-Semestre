#include <stdlib.h>
#include <stdio.h>

void mostraTab(char tab[20][20], int N);
void zeraTab(char tab[20][20], int N);
int preencheTab(char tab[20][20], int N, int linha);
int validaTab(char tab[20][20], int N, int linha, int pos);
int possibilidades=0;
int main() {
  char tabuleiro[20][20];
  int N = 6;

  zeraTab(tabuleiro, N);
  preencheTab(tabuleiro, N, 0);

  printf("\nResultado:\n\n");
  mostraTab(tabuleiro, N);
  return 0;
}

int preencheTab(char tab[20][20], int N, int linha) {
  int i,j;
  if (linha == N){
    possibilidades++;
    printf("%d \n",possibilidades);
    mostraTab(tab,N); 
     return 1;
  }
  for (i = 0; i < N; i++) {
    tab[linha][i] = 'X';
    if (validaTab(tab, N, linha, i)) {
      if (preencheTab(tab, N, linha + 1)){
          if(i==(N-1)) return 1;
      }
    }
    tab[linha][i] = ' ';
  }

  return 0;
}

int validaTab(char tab[20][20], int N, int linha, int pos){
  int i, j;

  // Verificando se ha peça na coluna
  for (i = 0; i < linha; i++) {
    if (tab[i][pos] == 'X') return 0;
  }

  //Verificando se a peça na diagonal a esquerda
  i = linha - 1;
  j = pos - 1;
  while (i >= 0 && j >= 0) {
    if (tab[i--][j--] == 'X') return 0;
  }

  //Verificando se a peça na diagonal a direita
  i = linha - 1;
  j = pos + 1;
  while (i >= 0 && j < N) {
    if (tab[i--][j++] == 'X') return 0;
  }

  return 1;
}

void mostraTab(char tab[20][20], int N) {
  int i, j;

  printf("-   -");
  for (i = 0; i < N; i++) {
    printf("|%3d|", i+1);
  }
  printf ("\n");
  for (i = 0; i < N; i++) {
    printf("-%3d-", i + 1);
    for(j = 0; j < N; j++) {
         printf("[ %c ]", tab[i][j]);
    }
    printf("-%3d-\n", i + 1);
  }
  printf("-   -");
  for (i = 0; i < N; i++) {
    printf("|%3d|", i+1);
  }
  printf ("\n");
}

void zeraTab(char tab[20][20], int N) {
  int i, j;
  for (i = 0; i < N; i++) {
    for(j = 0; j < N; j++) {
         tab[i][j] = ' ';
    }
  }
}