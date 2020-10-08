#include <stdio.h>
#include <stdlib.h>

typedef struct NodeItem{
    int info;
    struct NodeItem *prox;
    struct NodeItem *ant;
}node;

typedef struct{
    node *first;
    node *last;

}list;



list *newList();
int isEmpty(list *l);
node *newNode(int value);
node *addNodeIni(list *l, int value);
node *addNodeFim(list *l, int value);
void delNode(list *l, int value);
node *findNode(list *l, int value);
void showList (list * l);
int length(list *l);
void mostrarContraria(list *l); //mostra em ordem contraria a lista 
void *addEvenOdd(list *l,int value); //add pares no inicio e impares no final
void *addOrdenado(list *l, int value); //add os elementos de forma ordenada;
void *removeMaior(list *l); //remove maior elemento da lista
void main(){
    list *lista;
    lista = newList();
    addEvenOdd(lista,4);
    addEvenOdd(lista,8);
    addEvenOdd(lista,26);
    addEvenOdd(lista,45);
    addEvenOdd(lista,25);
    showList(lista);
    removeMaior(lista);
    showList(lista);

}
list *newList(){
    list *l = (list *)malloc(sizeof(list));
    l->first = NULL;
    l->last = NULL;
    return l;
}
int isEmpty(list *l){
    return l->first == NULL;
}
node *newNode(int value){
    node *n = (node *)malloc(sizeof(node));
    n->info = value;
    n->ant = NULL;
    n->prox = NULL;
    return n;   

}
node *addNodeIni(list *l, int value){
    node *n = newNode(value);
    if(isEmpty(l)){
        l->first = n;
        l->last = n;
    }else{
        n->prox = l->first;
        l->first->ant = n;
        l->first = n;
    }
    return n;
}
node *addNodeFim(list *l, int value){
    node *n = newNode(value);
    if(isEmpty(l)){
        l->first = n;
        l->last = n;
    } else{
        n->ant = l->last;
        l->last->prox = n;
        l->last = n;
    }
    return n;
}
node *findNode(list *l, int value){
    node *n;
    n = l->first;
    while(n != NULL && n->info != value){
        n = n->prox;
    }
    return n;

}
void delNode(list *l, int value) {
    node *n, *ant, *prox;
    n = findNode(l, value);
    if (n != NULL) {
        ant = n->ant;
        prox = n->prox;
        if (n == l->first) {
            l->first = prox;
        }
        if (n == l->last) {
            l->last = ant;
        }
        if (ant != NULL){
            ant->prox = prox;
        }
        if (prox != NULL) {
            prox->ant = ant;
        }
        free(n);
    }
}
void showList (list * l){
  node *n;
  if (isEmpty (l)){
      printf ("Lista vazia\n");
    }
  else{
      printf ("Lista possui %d elemento(s): \n", length (l));
      n = l->first;
      while (n != NULL){
	  if (n->ant != NULL && n->prox != NULL)
	    printf ("-> %d [Ant: %d, Prox: %d]\n", n->info, n->ant->info,n->prox->info);
	  else if (n->ant != NULL)
	    printf ("-> %d [Ant: %d, Prox: NULL]\n", n->info, n->ant->info);
	  else if (n->prox != NULL)
	    printf ("-> %d [Ant: NULL, Prox: %d]\n", n->info, n->prox->info);
	  else
	    printf ("-> %d [Ant: NULL, Prox: NULL]\n", n->info);
	  n = n->prox;
	}
      printf ("\n");
    }
}
int length(list *l) {
    int t=0;
    node *n = l->first;
    while(n != NULL) {
        n = n->prox;
        t++;
    }
    return t;
}

void mostrarContraria(list *l){
    node *n;
    n = l->last;
    while(n!= NULL){
        printf(" %d ",n->info);
        n = n->ant;
    }
}
void *addEvenOdd(list *l,int value){
    if(value%2==0){
        addNodeIni(l,value);
    }else{
        addNodeFim(l,value);
    }

}
void *addOrdenado(list *l, int value){
    node *n = newNode(value);
    node *aux;
    if(l->first!= NULL){
        aux = l->first;
        while(aux!=NULL || aux->prox!=NULL ){
            if(aux->prox->info>n->info){
                aux->prox->ant = n;
                n->ant = aux;
                n->prox = aux->prox;
                aux->prox = n;
                
            }
            aux = aux->prox;
        }

    }else{
        l->first = n;
        l->last = n;
    }
}
void *removeMaior(list *l){
    int maior;
    node *n;
    n = l->first;
    maior = n->info;
    for(int i=0;i<length(l);i++){
        if(n->info>maior){
            maior = n->info;
        }
        n=n->prox;
    }
    delNode(l,maior);
}