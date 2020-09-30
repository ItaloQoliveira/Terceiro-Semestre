#include <stdlib.h>
#include <stdio.h>

typedef struct NodeItem {
  int info;
  struct NodeItem *prox;
} node;
typedef struct {
  node *top;
} stack;

typedef struct {
  node *head;
  node *tail;
} queue;
void newStack(stack *s);
int isEmptyStack(stack *s);
void push(stack *s, int value);
int pop(stack *s);
int top(stack *s);
void newQueue(queue *f);
void enqueue(queue *f, int value);
int dequeue(queue *f);
int isEmpty(queue *f);
node *newNode(int value);
void showQueue(queue *f);
void reverter(queue *f, stack *s);

void main() {
  queue q;
  stack s;
  int quantidade,valor;

  newQueue(&q);
  newStack(&s);
  printf("\n Insira quantos números serao inseridos na fila");
  scanf("%d",&quantidade);
  for(int i=0;i<quantidade;i++){
      printf("\n Insira um numero na lista: ");
      scanf("%d",&valor);
      enqueue(&q,valor);
  }
  reverter(&q,&s);
}

node *newNode(int value) {
  node *n = (node *)malloc(sizeof(node));
  n->info = value;
  n->prox = NULL;
  return n;
}
void newStack(stack *s){
  s->top = NULL;
}

void newQueue(queue *f){
  f->head = NULL;
}

int isEmpty(queue *f) {
  return f->head == NULL;
}
int isEmptyStack(stack *s) {
    return s->top == NULL;
}
void push(stack *s, int value) {
  node *n = newNode(value);
  n->prox = s->top;
  s->top = n;
}
int pop(stack *s) {
  node *n;
  int aux;
  aux = top(s);
  n = s->top;
  s->top = n->prox;
  free(n);
  return aux;
}
int top(stack *s) {
  if (isEmptyStack(s)) {
    printf("Stack underflow!\n");
    exit(1);
  }
  return s->top->info;
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

void reverter(queue *f, stack *s){
    while(!isEmpty(f)){
        push(s,dequeue(f));
    }
    //agora so printar
    while(!isEmptyStack(s)){
        printf("%d ",pop(s));
    }
}