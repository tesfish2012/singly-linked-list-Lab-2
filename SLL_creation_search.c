#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
struct node
  {
   int data;
   struct node *next;
  }*start;
void create_node(int n);
void insertatBegin(int num);
void insertatEnd(int num);
void insertatMiddle(int num, int pos);
void display();

int main()
{
    int n ;
	int num ,pos;
    printf("enter number of nodes to create a linked list\n");
    scanf("%d",&n);
	create_node(n);
	printf("enter the data at the bigining\n");
    scanf("%d",&num);
   insertatBegin(num);
    printf("enter the position \n");
    scanf("%d",&pos);
    printf(" the data is going to fill\n");
    scanf("%d",&num);
    insertatMiddle(num, pos);
     
    printf("enter the data at the ending\n");
    scanf("%d",&num);
    insertatEnd(num);
    return 0;
}



void create_node(int n){
 struct node *new_node ,*temp = NULL; 
    start= NULL;
    int i =0,num;
    while (i<n)
    {
       new_node = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data at pos %d :" ,i+1);
        scanf("%d", &new_node-> data);
        if (start != NULL){
        	new_node->data;
            temp->next = new_node;
            temp = new_node;
        }
        else {
            start = temp = new_node;
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
    return;
}

void insertatBegin(int num)
{
    struct node *new_node;
    new_node = (struct node*)malloc(sizeof(struct node));
        new_node->data = num; 
        new_node->next =start; 
        start = new_node; 
        display();
}

void insertatEnd(int num)
{
struct node *new_node, *temp;
    new_node = (struct node*)malloc(sizeof(struct node));
    if(new_node == NULL)
    {
        printf(" Memory can not be allocated.");
    }
    else
    {
        new_node->data = num;     
        new_node->next = NULL; 
        temp = start;
        while(temp->next != NULL)
            temp = temp->next;
            temp->next = new_node; 
           
    }
	 display();
}

void insertatMiddle(int num, int pos)
{
    int i;
    struct node *new_node, *temp;
    new_node = (struct node*)malloc(sizeof(struct node));
    if(new_node == NULL)
    {
        printf(" Memory can not be allocated.");
    }
    else
    {
        new_node->data = num; 
        new_node->next = NULL;
        temp = start;
        for(i=2; i<=pos-1; i++)
        {
            temp = temp->next;
            if(temp == NULL)
                break;
        }
        if(temp != NULL)
        {
            new_node->next = temp->next;  
            temp->next = new_node; 
		  
        }
        else
        {
            printf("There is not present like this position\n");
        }
    }
	display();
}
void display(){
	struct node *new_node;
	printf("\n lists of the singlly linked list is\n");
	new_node=start;
    while (new_node != NULL)
    {
        printf("%d=>", new_node->data);
        new_node =new_node -> next;
    }
    printf("NULL\n");
}
