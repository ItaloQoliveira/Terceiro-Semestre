#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

void troca(int *x, int *y);
void quicksort(int vet[], int left, int right);
int partition(int vet[], int left, int right);
int partition1(int vet[], int left, int right);
void fill(int vet[]);
void imprime(int vet[]);
int contadorlugarcerto=0,contadordivisao;
int main() {
  int vet[N];

  fill(vet);
  imprime(vet);
  quicksort(vet, 0, N-1);
  imprime(vet);
  printf("Vezes em que o pivo estava no lugar certo: %d\n",contadorlugarcerto);
  printf("Vezes em que o pivo dividiu em partes iguais: %d\n",contadordivisao);
}


void troca(int *x, int *y) {
  int aux;
  aux = *x;
  *x = *y;
  *y = aux;
}

void fill(int vet[]) {
  int i;
  srand(time(NULL));
  for (i=0; i<N; i++) {
    vet[i] = rand() % 100;
  }
}

void imprime(int vet[]) {
  int i;
  for (i=0; i<N; i++) {
    printf("[%d]", vet[i]);
  }
  printf("\n");
}

void quicksort(int vet[], int left, int right) {
  //https://www.hackerearth.com/pt-br/practice/algorithms/sorting/quick-sort/visualize/
  int pivot;
  if (left >= right) {
    return;
  }
  pivot = partition(vet, left, right);
  int esquerda=pivot-left-1;
  int direita=right-pivot+1;
  if(direita-esquerda==0||direita-esquerda==1||direita-esquerda==-1){
    contadordivisao+=1;
  }

  quicksort(vet, left, pivot-1);
  quicksort(vet, pivot+1, right);
}

int partition(int vet[], int left, int right) {
  int i, j, pivo;

  pivo = vet[left];
  i = left + 1;
  for (j = i; j <= right; j++) {
    if (vet[j] < pivo) {
      troca(&vet[j], &vet[i]);
      i++;
    }
  }
  if(left==i-1){
    contadorlugarcerto+=1;
    //printf("%d=%d\n",left,i-1); //verificar se estava realmente na posição certa!
  }
  troca(&vet[left], &vet[i - 1]);
  return i - 1;
}

int partition1(int vet[], int left, int right) {
  int i = left, j = right-1;
  troca(&vet[left + ((right - left)/2)], &vet[right]);
  while(i <= j) {
    while (vet[i] <= vet[right] && i < right) {
      i++;
    }
    while (vet[j] > vet[right] && j >= left) {
      j--;
    }
    if (i < j) {
      troca(&vet[i], &vet[j]);
    }
  }
  troca(&vet[i], &vet[right]);
  return i;
}