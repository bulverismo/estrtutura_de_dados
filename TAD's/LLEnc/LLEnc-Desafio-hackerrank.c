#include <stdlib.h>
#include <stdio.h>	
typedef struct Node
{
    int data;
    struct Node* next;
}Node;

Node* insert(Node *head,int data)
{
    Node *aux;
    aux=head;
    
    // Prepara o novo dado
    Node *novo=(Node*)malloc(sizeof(Node));
    (*novo).data=data;
    (*novo).next=NULL; 
    
    // Se não for o primeiros a inserir encontra a posição
    if (aux)
    {   
        // Caminha enquanto tem um prox não nulo
        // quando encontrar um registro de que o proximo é nulo
        // então para de caminhar e então insere no lugar do nulo
        while (aux->next)
            aux=aux->next;
            
        aux->next=novo;
    } else 
        // Quando for inserir o primeiro registro entra neste caso
        // e modifica diretamente a cabeça da lista
        head=novo;
    
    return head;
        
}

void display(Node *head)
{
	Node *start=head;
	while(start)
	{
		printf("%d ",start->data);
		start=start->next;
	}
}
int main()
{
	int T,data;
    scanf("%d",&T);
    Node *head=NULL;	
    while(T-->0){
        scanf("%d",&data);
        head=insert(head,data);
    }
  display(head);
		
}

