//Author : Prateek
//Date : 23 AUG 2017

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define max 20
//array for heap, storage from 1 to sz-1
int heap[max+1];
int sz=1;	//next free location in heap

//insert item in a min heap stored from 1 to sz-1
int insert(int *a,int item)
{
	//if heap is full, return error
	if(sz>max+1) return -1;
	//if heap is empty, add first element
	if(sz==1){a[1]=item; sz++; return 1;}
	
	//else, find appropriate position i for new item
	int i=sz;
	int j=floor(i/2);
	while((i>=1)&&(j!=0)&&(a[j]>item))
	{
		a[i]=a[j]; 
		i=j; 
		j=floor(i/2);
	}
	//place item, incerement sz, return success
	a[i]=item;
	sz++;
	return 1;
}
//heapify the tree stored from 1 to sz-1
int heapify(int *a)
{
	int new=1,temp;
	int j=2*new,item=a[new];
	while(j<sz)
	{
		if((a[j]>a[j+1])&&(a[j+1]!=-1))j++;
		if(item <= a[j]) break;
		temp=floor(j/2);
		a[temp]=a[j]; j=2*j;
	}
	temp=floor(j/2);a[temp]=item;
}
//Delete item from heap, update sz accordingly
int delete(int *a)
{
	if(sz==1) return -1;
	int retval = a[1];
	a[1]=a[sz-1];
	a[--sz]=-1;
	heapify(a);
	return retval;
}

int main()
{
	int i=0;
	while(i<20)
	{
		heap[i]=-1;
		i++;
	}
	
	int n,b;
	printf("\nEnter the number of elements (upto 15) in array: ");
	scanf("%d",&n);
	//creation of min heap
	
	for(i=0;i<n;i++){
		printf("Enter element %d:\t",i+1);
		scanf("%d",&b);
		insert(heap,b);
	}
	
	printf("min heap:\t");
	for(i=1;i<sz;i++)
	{
		printf("%d\t",heap[i]);
	}
	
	
	printf("\nArray in ascending order:");
	
	int ele;
	ele=delete(heap);
	while(ele!=-1)
	{
		printf("%d\t",ele);
		ele=delete(heap);
	}
	
	return 0;
}
