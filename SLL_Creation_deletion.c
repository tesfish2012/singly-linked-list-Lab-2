#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
struct node
  {
   int data;
   struct node *next;
  }*start;
void DeletatFirst();
void deleeteatAnyPosission(int pos);
void deleteLastNode();
void create_node(int n);
void display();

int main()
{
     int n ;
    printf("enter number of nodes to create a linked list\n");
    scanf("%d",&n);
	create_node(n);
	int num ,number,numberend,pos;
	printf("enter the any any number to deleete  the first node\n");
	scanf("%d",&number);
     DeletatFirst();
    printf("enter the position to delete the node \n");
    scanf("%d",&pos);
   deleeteatAnyPosission( pos);
     
    printf("enter any number to delete at the end\n");
    scanf("%d",&numberend);
    deleteLastNode();
    return 0;
}



void create_node(int n){
	typedef struct node new_node;
    new_node *head,  *temp = NULL; 
    start= NULL;
    int i =0;
    while (i<n)
    {
        head  = (new_node *)malloc(sizeof(new_node));
        printf("Enter the data %d : ",i+1);
        scanf("%d", &head-> data);
        if (start != NULL){
            temp->next = head;
            temp = head;
        }
        else {
            start = temp = head;
        }
       i++;
    }    
	temp->next= NULL;
    temp = start;  
	printf("\n lists of the singlly linked list is\n");
    while (temp != NULL)
    {
        printf("%d=>", temp->data);
        temp = temp -> next;
    }
    printf("NULL\n"); 
}


void display(){
	struct node *new_node;
	printf("\n lists of the singlly linked list is\n");
	new_node=start;
    while (new_node!= NULL)
    {
        printf("%d=>", new_node->data);
        new_node =new_node -> next;
    }
    printf("NULL\n");
}



void DeletatFirst()
{
    struct node *node_to_delete;
    if(start == NULL)
    {
        printf(" there is no node to delete");
    }
    else
    {
        node_to_delete = start;
        start = start->next;
        printf("\nthe data at start is going to delete %d\n", node_to_delete->data);
        free(node_to_delete);  
        display();
    }
}

void deleeteatAnyPosission(int pos)
{
    int i;
    struct node *node_to_delete, *temp;
 
    if(start == NULL)
    {
        printf(" There are no nodes in the List");
    }
    else
    {
        node_to_delete = start;
        temp = start;
 
        for(i=2; i<=pos; i++)
        {
            temp = node_to_delete;
            node_to_delete = node_to_delete->next;
 
            if(node_to_delete == NULL)
                break;
        }
        if(node_to_delete != NULL)
        {
            if(node_to_delete == start)
                start = start->next;
 
            temp->next = node_to_delete->next;
            node_to_delete->next = NULL;
            free(node_to_delete);
            display();
        }
        else
        {
            printf(" Deletion can not be possible from that position\n");
        }
    }
}

void deleteLastNode()
{
    struct node *node_to_delete, *temp;
    if(start == NULL)
    {
        printf(" There is no element  to delete");
    }
    else
    {
        node_to_delete = start;
        temp = start;
        while(node_to_delete->next != NULL)
        {
            temp = node_to_delete;
            node_to_delete = node_to_delete->next;
        }
        if(node_to_delete == start)
        {
            start = NULL;
        }
        else
        { 
      temp->next = NULL;
        }
        free(node_to_delete);
        display();
    }
	}
