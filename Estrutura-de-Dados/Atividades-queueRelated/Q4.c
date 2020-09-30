#include <stdlib.h>
#include <stdio.h>

typedef struct NodeItem {
  int info;
  struct NodeItem *prox;
} node;

typedef struct {
  node *head;
  node *tail;
} queue;

void newQueue(queue *f);
void enqueue(queue *f, int value);
int dequeue(queue *f);
int isEmpty(queue *f);
node *newNode(int value);
void showQueue(queue *f);

int main() {
  queue q;
  int quantidade,valor,flag=1,a,b;
  newQueue(&q);
  printf("\n Insira quantos números serao inseridos na fila");
  scanf("%d",&quantidade);
  for(int i=0;i<quantidade;i++){
      printf("\n Insira um numero na lista: ");
      scanf("%d",&valor); // a entrada em ordem decrescente foi o que considerei para ser crescente.
      enqueue(&q,valor);
  }

  while(!isEmpty(&q)){
      a=dequeue(&q);
      printf("%d",a);
      if(isEmpty(&q)){
          break;
      }
      b=dequeue(&q);
      printf("%d",b);
      if (a<b){
          printf("Não é ordem crescente"); //a entrada tem que ser do maior para o menor, aí ela fica crescente
          flag=0;
      }
  }
  if(flag!=0){
      printf("A fila estava em ordem crescente");

  }
}

node *newNode(int value) {
  node *n = (node *)malloc(sizeof(node));
  n->info = value;
  n->prox = NULL;
  return n;
}

void newQueue(queue *f){
  f->head = NULL;
}

int isEmpty(queue *f) {
  return f->head == NULL;
}

void enqueue(queue *f, int value) {
  node *n = newNode(value);
  if (isEmpty(f)) {
    f->head = f->tail = n;
  } else {
    f->tail->prox = n;
    f->tail = n;
  }
}

int dequeue(queue *f) {
  node *n;
  int aux;

  if (isEmpty(f)) {
    printf("Queue underflow!\n");
    exit(1);
  }

  aux = f->head->info;
  n = f->head;
  f->head = n->prox;
  free(n);
  return aux;
}

void showQueue(queue *f) {
  node *n = f->head;
  printf("Fila:\n");
  while(n != NULL) {
    printf("[%d]", n->info);
    n = n->prox;
  }
  printf("\n");
}