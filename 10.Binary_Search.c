/* Name:Shylesh S
   Roll No: 47
   Program No. 10
   Program: Binary Search */

#include<stdio.h>
void main()
{
	int i,j,a[100],temp,size,key,first,mid,last;
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
	first=0;
	last=size-1;
	mid=(first+last)/2;

	printf("Enter The element to be searched : ");
	scanf("%d",&key);

	while(first<=last)
	{
		if(a[mid]<key)
		{
			first=mid+1;
		}
		else if(a[mid]==key)
		{
			printf("%d found \n",key);
			break;
		}
		else
			last=mid-1;
		mid=(first+last)/2;
	}
	if (first>last)
		printf("Not Found!\n");
}

