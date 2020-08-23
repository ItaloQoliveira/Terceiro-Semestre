//Utilizando o programa cartas.c, modifique-o para que as cartas sejam novamente ordenadas considerando o valor dos números e depois dos naipes (utilize o método bolha)
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct {
   int num;   // 1 - Ás, 2 ... 10, 11 = Valete, 12 = Dama, 13 = Rei
   int naipe; // O = Ouros, 1 = Espadas, 2 = Copas, 3 = Paus
} carta;

void preenche(carta baralho[52]);
void imprime(carta baralho[52]);
void embaralha(carta baralho[52], int cartas);
void troca(carta *a, carta *b);
void ordena(carta baralho[52]);
int buscaBin(carta baralho[],int naipe,int numero, int left, int right);
int main() {
  carta baralho[52];
  int naipe,num;

  preenche(baralho);
  imprime(baralho);
  embaralha(baralho, 100);
  ordena(baralho);
  imprime(baralho);
  printf("\nQual o naipe da carta que será buscada?");
  scanf("%d",&naipe);
  printf("\nQual o numero da carta que será buscada?");
  scanf("%d",&num);
  buscaBin(baralho,naipe,num,0,51);
}
int buscaBin(carta baralho[],int naipe,int numero, int left, int right){
    if(left>right){
        return -1;
    }
    int mid=(left+right)/2;
    if(baralho[mid].naipe==naipe){
        if(baralho[mid].num==numero){
            printf("A carta desejada se encontra na posição %d",mid);
            return mid;
        } else if(baralho[mid].num>numero){
            buscaBin(baralho,naipe,numero,left,mid-1);
        }else{
            buscaBin(baralho,naipe,numero,mid+1,right);
        }
    } else if(baralho[mid].naipe>naipe){
        buscaBin(baralho,naipe,numero,left,mid-1);
    } else if(baralho[mid].naipe<naipe){
        buscaBin(baralho,naipe,numero,mid+1,right);
    }
}
void ordena(carta baralho[52]){
    int i,j;
    for(i=0;i<52;i++){
       j=i;
       while(j>=0){
           if(baralho[j].naipe>baralho[j+1].naipe){
               troca(&baralho[j],&baralho[j+1]);
           }else if (baralho[j].naipe==baralho[j+1].naipe){
               if(baralho[j].num>baralho[j+1].num){
                   troca(&baralho[j],&baralho[j+1]);
               }
           }
        j--;
           
       }
    }
}

void troca(carta *a, carta *b) {
    carta aux;
    aux.num = a->num;
    aux.naipe = a->naipe;

    a->num = b->num;
    a->naipe = b->naipe;

    b->num = aux.num;
    b->naipe = aux.naipe;
}

void preenche(carta baralho[52]) {
  int i, j, k = 0;

  for (i = 1; i<14; i++) {
    for (j = 0; j<4; j++) {
      baralho[k].num = i;
      baralho[k].naipe = j;
      k++;
    }
  }
}

void imprime(carta baralho[52]) {
  int i;
  char letras[] = {'J', 'Q', 'K'};
  char *nipes[] = {"<>"," #", "S2", " &"};

  printf("\nSequencia de cartas: \n");
  for (i=0; i<52; i++) {
    if (baralho[i].num == 1) {
      printf("[ A%s ] ", nipes[baralho[i].naipe]);
    } else if (baralho[i].num > 10) {
      printf("[%2c%s ] ", letras[baralho[i].num - 11], nipes[baralho[i].naipe]);
    } else {
      printf("[%2d%s ] ", baralho[i].num, nipes[baralho[i].naipe]);
    }
    if (i % 10 == 9) printf("\n");
  }
  printf("\n\nLegenda: <> ouro, # espadas, S2 = copas, & paus\n");
}

void embaralha(carta baralho[52], int cartas) {
  int i, j;
  srand(time(NULL));
  while(cartas > 0) {
    troca(&baralho[rand() % 52], &baralho[rand() % 52]);
    cartas--;
  }
}