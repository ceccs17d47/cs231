/* Name:Shylesh S
   Roll No: 47
   Program No. 15
   Program: Polynomial Representation */

#include<stdio.h>
#include<malloc.h>
#include<conio.h>
struct link{
       int coeff;
       int pow;
       struct link *next;
       };
struct link *poly1=NULL,*poly2=NULL,*poly=NULL;
void create(struct link *node)
{
 char ch;
 do
 {
  printf("\n enter coeff:");
  scanf("%d",&node->coeff);
  printf("\n enter power:");
  scanf("%d",&node->pow);
  node->next=(struct link*)malloc(sizeof(struct link));
  node=node->next;
  node->next=NULL;
  printf("\n continue(y/n):");
  ch=getch();
 }
 while(ch=='y' || ch=='Y');
}
void show(struct link *node)
{
 while(node->next!=NULL)
 {
  printf("%dx^%d",node->coeff,node->pow);
  node=node->next;
  if(node->next!=NULL)
   printf("+");
 }
}

int main()
{
      char ch;
      do{
      poly1=(struct link *)malloc(sizeof(struct link));
      
      printf("\n Enter The First Polynomial:");
      create(poly1);

      printf("\nPolynomial is:");
      show(poly1);
      }
      while(ch=='y' || ch=='Y');
}
