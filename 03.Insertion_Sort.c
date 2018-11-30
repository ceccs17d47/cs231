/* Name:Shylesh S
   Roll No: 47
   Program No. 3
   Program: Insertion Sort */

#include<stdio.h>
void main()
{
	int i,j,a[100],temp,size;
	printf("Enter The size : ");
	scanf("%d",&size);
	printf("Enter The Elements : ");
	for(i=0;i<size;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=1;i<size;i++)
	{
		temp=a[i];
		j=i-1;
		while(a[j]>temp && j>=0)
		{
			a[j+1]=a[j];
			--j;
		}
		a[j+1]=temp;
	}
	printf("Sorted Array : ");
	for(i=0;i<size;i++)
	{
		printf("%d\t",a[i]);
	}
}
