#include <stdlib.h>
#include <stdio.h>

typedef struct NodeItem {
  int info;
  char nome[100];
  struct NodeItem *prox;
} node;

typedef struct {
  node *head;
  node *tail;
} queue;

void newQueue(queue *f);
void enqueue(queue *f, int value,char nome[]);
int dequeue(queue *f);
int isEmpty(queue *f);
node *newNode(int value);
void showQueue(queue *f);

void main() {
  queue q;
    int op=1,senhaatual=1;
	char name[100];
  newQueue(&q);
	while(op==1){
		printf("\n1, gerar senha, 2 chamar próximo e qualquer outro numero para encerrar sistema\n");
		scanf("%d",&op);
		fflush(stdin);
		switch (op){
		case 1:
			printf("\nInsira apenas primeiro nome: ");
			scanf(" %[^\n]%*c", name); 
			
			
			enqueue(&q,senhaatual++,name);
			op=1;
			break;
		
		case 2:
			printf("Chamando senha %d, dirija-se ao atendimento",dequeue(&q));
			op=1;
			break;

		default:
			op=0;
			break;
		}

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

void enqueue(queue *f, int value,char nome[]) {
  node *n = newNode(value);
  if (isEmpty(f)) {
	f->head = f->tail = n;
  } else {
	f->tail->prox = n;
	f->tail = n;
  }
  printf("Senha %d, adicionada a fila,",value);
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