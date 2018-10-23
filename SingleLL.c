#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *next;
};


void push(struct Node** head_ref, int new_data)
{
	struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
	new_node->data=new_data;
	new_node->next=(*head_ref);
	(*head_ref)=new_node;
}


void append(struct Node** head_ref, int new_data)
{
	struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
	struct Node* last=*head_ref;
	new_node->data=new_data;
	new_node->next=NULL;
	if(*head_ref==NULL)
		*head_ref=new_node;
		return;
	while(last->next!=NULL)
	{
		last=last->next;
	}
	last->next=new_node;
	return;
}

void deletenode(struct Node **head_ref, int pos)
{
	if(*head_ref==NULL)
		return;
	struct Node* temp=*head_ref;
	if(pos==0)
	{
		*head_ref=temp->next;
		free(temp);
		return;
	}
	for(int i=0;temp!=NULL && i<pos-1;i++)
		temp=temp->next;
	if(temp==NULL || temp->next==NULL)
		return;
	struct Node *next=temp->next->next;
	free(temp->next);
	temp->next=next;
}




void printlist(struct Node* node)
{
	while(node!=NULL)
	{
		printf("%d \t",node->data);
		node=node->next;
	}
}

void search(struct Node **head_ref, int key)
{	
	int pos;
	struct Node* temp=*head_ref;
	while(temp!=NULL && temp->data!=key)
		{
			
			temp=temp->next;
		}
	for(int i=0;temp!=NULL && i<pos-1;i++)
		temp=temp->next;
	
	if(temp!=NULL&& temp->data==key)
	{
		printf("\nElement Found at %d",pos);
	}
}

void main()
{	
	int value,key,del;
	struct Node* head=NULL;

	printf("Enter a value to be pushed: ");
	scanf("%d",&value);
	append(&head,value);
	printf("Enter a value to be pushed: ");
	scanf("%d",&value);
	push(&head,value);

	printf("Enter a value to be pushed: ");
	scanf("%d",&value);
	push(&head,value);
	printf("Enter a value to be pushed: ");
	scanf("%d",&value);
	push(&head,value);
	
	printf("The list is now ");
	printlist(head);

	printf("\nEnter the position to be deleted: ");
	scanf("%d", &del);
	
	deletenode(&head,del);
	
	
	
	printf("\nAfter Deletion the list is ");
	printlist(head);
	
	printf("\nEnter a value to be searched: ");
	scanf("%d",&key);
	search(&head,key);
}


