/* Name:Shylesh S
   Roll No: 47
   Program No. 9
   Program: Heap Sort */

#include<stdio.h>
#include<math.h>

void heapify(int a[],int n,int i){
    int large=i,l=2*i+1,r=2*i+2,t=0;

    if (l<=n && a[large]<a[l]) large=l;
    if (r<=n && a[large]<a[r]) large=r;

    if (large!=i){
        t=a[i];
        a[i]=a[large];
        a[large]=t;
        if (large<=n/2) heapify(a,n,large);
    }
}

void heapsort(int a[],int n){
    int t=0,i;
    for (i=n/2;i>=0;i--) heapify(a,n,i);
    for (i=n;i>0;i--){
            t=a[i];
            a[i]=a[0];
            a[0]=t;
            heapify(a,i-1,0);
    }
}

int main(){
	int a[20],i,size;
	printf("Enter The Size of The array: ");
	scanf("%d",&size);
	printf("Enter Array Elements: \n");
	for(i=0;i<size;i++)
	{
		scanf("%d",&a[i]);
	}
	heapsort(a,size);
	for(i=0;i<size;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}
