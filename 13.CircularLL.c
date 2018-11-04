#include<stdio.h>
#include<string.h>
#include<stdlib.h>


struct node{
int data;

struct node *next;
};


struct node *head=NULL;

void insertFirst()
{
    struct node *p,*temp;
    p=(struct node *)malloc(sizeof(struct node));
    printf("Enter the a value to be inserted at the beginning:\t");
    scanf("%d",&p->data);
    
    p->next=NULL;
    if(head==NULL){
        head=p;
        p->next=p;
    }
    else{
        temp=head;
        while(temp->next!=head)
            temp=temp->next;
        p->next=head;
        head=p;
        temp->next=head;
    }
}

void insertLast()
{
    struct node *p,*temp;
    p=(struct node *)malloc(sizeof(struct node));
    printf("Enter the value to be inserted at the end:\t");
    scanf("%d",&p->data);
    p->next=NULL;
    if(head==NULL){
        head=p;
        p->next=p;
    }
    else{
        temp=head;
        while(temp->next!=head)
            temp=temp->next;
        temp->next=p;
        p->next=head;
    }
}


void insertInbetween()
{
    struct node *temp,*p;
    int n;
    if(head==NULL){
        printf("The list is empty\n");
        
    }
    
    printf("Enter the number after which you want to insert the node:\t");
    scanf("%d",&n);
    p=(struct node *)malloc(sizeof(struct node));
    printf("Enter the number:\t");
    scanf("%d",&p->data);
    p->next=NULL;
    temp=head;
    if(temp->next == temp && temp->data==n)
    {
        p->next=temp->next;
        temp->next=p;
        
    }
    if(temp->data==n)
    {
        p->next=temp->next;
        temp->next=p;
       
    }
    temp=temp->next;
    while(temp!=head && temp->data!=n)
        temp=temp->next;
    if(temp==head)
        printf("There is no such element exist\n");
    else{
        p->next=temp->next;
        temp->next=p;
    }
}

void deleteLast()
{
    struct node *temp,*t;
    temp=head;
    if(head==NULL)
        printf("\nList is empty\n");
    else if(head->next==head)
    {
        free(head);
        head=NULL;
    }
    else{
        while(temp->next!=head)
        {
            t=temp;
            temp=temp->next;
        }
        free(t->next);
        t->next=head;
    }
}


void deleteFirst()
{
    struct node *temp,*t;
    t=head;
    temp=head;
    if(head==NULL)
        printf("\nThe list is empty\n");
    else if(head->next==head)
    {
        free(head);
        head=NULL;
    }
    else{
        while(temp->next!=head)
            temp=temp->next;
        head=head->next;
        temp->next=head;
        free(t);
    }
}

void deleteInbetween()
{
    struct node *temp,*t;
    int n;
    if(head==NULL){
        printf("The list is empty\n");
    }
    
    printf("Enter the  number which you want to delete:\t");
    scanf("%d",&n);
    temp=head;
    if(temp->next == temp && temp->data==n)
    {
        free(temp);
        head=NULL;
          
    }
    if(temp->data==n)
    {
        t=head;
        while(t->next!=head)
            t=t->next;
        head=head->next;
        t->next=head;
        free(temp);
       
    }
    t=temp;
    temp=temp->next;
    while(temp!=head && temp->data!=n)
    {
        t=temp;
        temp=temp->next;
    }

    if(temp==head)
        printf("There is no such element exist\n");
    else{
        t->next=temp->next;
        free(temp);
    }
}

void search()
{
    struct node *temp;
    int num;
    temp=head;
    printf("Enter the number:\t");
    scanf("%d",&num);
    printf("\n");
    while(temp->next!=head && temp->data!=num)
    {
        temp=temp->next;
    }
    if(temp->data==num)
    {
        printf("Element Present! \n");  
    }
    else
    {
	printf("No such element exist\n");
    }
}



void display()
{
    struct node *temp;
    temp=head;
    if(head==NULL)
        printf("\nThe list is empty\n");
    else{
        printf("The List is \n");
        while(temp->next!=head)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("%d ",temp->data);
    }
}

void main()
{
    int choice;
    while(1)
    {
        printf("\n==============================\n");
        printf("CIRCULAR LINEAR LINKED LIST\n");
        display();
        printf("\n");
        printf("==============================\n");
        printf("1.INSERT AT BEGINNING\n2.INSERT AT END\n3.INSERT IN BETWEEN\n4.DELETE AT BEGINNING\n5.DELETE AT END\n");
        printf("6.DELETE IN BETWEEN\n7.SEARCH \n8.DISPLAY\n0.EXIT\n");
        printf("==============================\n");
        printf("Choose any one of the above:\t");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: insertFirst();
                    break;
            case 2: insertLast();
                    break;
            case 4: deleteFirst();
                    break;
            case 5: deleteLast();
                    break;
            case 8: display();
                    break;
            case 7: search();
                    break;
            case 3: insertInbetween();
                    break;
            case 6: deleteInbetween();
                    break;
            default: printf("Invalid choice\n");
                    break;
            case 0: exit(0);

        }
    }
}
