#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int info;
    struct Node *prox;
} node;

typedef struct{
    node *first;
} list;

list *newList(); //criar uma lista
node *addNode(list *l, int value); //cria um node e adiciona na lista
node *addNodeFinal(list *l,int value);//cria um node e adiciona no fim da lista
int length(list *l); //retorna o tamanho da lista
int isEmpty(list *l); //verifica se a lista esta vazia
void impLista(list *l); //imprime lista
void inverteLista(list *l); //inverte, q1
void oddEvenLista(list *l);//separa odd e even q2
void mostraSoma(list *l);//soma os node q4
int menor(list *l);//retorna menor valor q5
void main(){
    list *l;
    l = newList();
    addNode(l,5);
    addNode(l,7);
    addNode(l,3);
    addNode(l,2);
    addNode(l,6);
    printf("O menor número é: %d ",menor(l));

}
list *newList(){
    list *l = (list *)malloc(sizeof(list));
    l->first = NULL;
    return l;
}
node *addNode(list *l, int value){
    node *n = (node *)malloc(sizeof(node));
    n->info = value;
    n->prox = l->first;
    l->first=n;
    return n;
}
node *addNodeFinal(list *l, int value){
    node *n = (node *)malloc(sizeof(node));
    node *aux;
    aux = l->first;
    n->info = value;
    n->prox = NULL;
    for(int i=0 ;i<length(l);i++){
        aux = aux->prox;    
    }
    
    aux->prox = n;
    
    return n;
}
void impLista(list *l){
    node *n;
    n=l->first;
    while(n!=NULL){
        printf("%d ",n->info);
        n=n->prox;
    }
}
int length(list *l){
    int tam = 0;
    node *n = l->first;
    while (n->prox!=NULL){
        n = n->prox;
        tam++;
    }
    return tam;
}
int isEmpty(list *l){
    return l->first == NULL;
}

void inverteLista(list *l){
    list *aux;
    node *n;
    n = l->first;
    aux = newList();
    for(int i=0; i<=length(l);i++){
        addNode(aux,n->info); //ideia para melhora: eventualmente a memoria acabaria, pois não é liberado cada node. para resolver isso seria o seguinte: n->info deveria ser retornado de uma função que daria o free no node lá
        n= n->prox;
    }
    l->first=aux->first; //l->first aponta para a listra recem criada onde as coisas estão inversas
    free(aux);
}
void oddEvenLista(list *l){
    list *aux;
    node *n;
    n = l->first;
    aux = newList();
    for(int i=0;i<=length(l);i++){     //a nota da funcao anterior vale aqui tmb, memoria go brrr
        if(n->info%2==0){
            addNode(aux,n->info);
            //printf("batata"); debug go brrrrrrr 
        }else{
            addNodeFinal(aux,n->info);
            //printf("pao"); debug go brrr
        }
        n = n->prox;
    }
    l->first = aux->first;
    free(aux);
}
void mostraSoma(list *l){
    node *n;
    int soma=0;
    n = l->first;
    for(int i=0;i<=length(l);i++){
        soma += n->info;
        n = n->prox;
    }
    printf(" A soma de todos os nodes é = %d ",soma);
}
int menor(list *l){
    node *n;
    int menor;
    n = l->first;
    menor = n->info;
    for(int i=0;i<=length(l);i++){
        if(n->info<menor){
            menor = n->info;
        }
        n = n->prox;

    }
    return menor;
}