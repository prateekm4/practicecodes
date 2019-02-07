// DAA Assignment 2 - Optimal storage on tapes problem using greedy method
// complexity : O(nlogn) where n is number of programs.
// Author : Prateek

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define max 40

struct program
{
	int label;
	int len;
};
typedef struct program p;


//array for heap, storage from index 1 to sz-1
p heap[max+1];
int sz=1;	//next free location index in heap


//insert item in a min heap stored from 1 to sz-1
int insert(p *a,int no,int item)
{
	//if heap is full, return error
	if(sz>max+1) return -1;
	//if heap is empty, add first element
	if(sz==1)
	{	
		a[1].label=no; 
		a[1].len=item; 
		sz++; 
		return 1;
	}
	

	//else, find appropriate position i for new item, shift elements if necessary
	int i=sz;
	int j=floor(i/2);
	while((i>=1)&&(j!=0)&&(a[j].len>item))
	{
		a[i].label=a[j].label; 
		a[i].len=a[j].len; 
		i=j;
		j=floor(i/2);
	}
	//place item, incerement sz, return success
	a[i].label=no;
	a[i].len=item;
	sz++;
	return 1;
}

//heapify the tree stored from 1 to sz-1
int heapify(p *a)
{
	int j=2,temp;
	
	int item=a[1].label;
	int item2=a[1].len;
	
	
	while(j<sz)
	{
		if((a[j].len>a[j+1].len)&&(a[j+1].label!=-1))j++;//select the smaller child at j
		
		if(item2 <= a[j].len) break;//position found
		temp=floor(j/2);
		a[temp].label=a[j].label; 
		a[temp].len=a[j].len; 
		j=2*j;
	}
	temp=floor(j/2);
	a[temp].label=item;
	a[temp].len=item2;
}

//Delete item from heap, update sz accordingly, return index of structure
int delete(p *a)
{
	if(sz==1) return -1;
	a[1].label=a[sz-1].label;
	a[1].len=a[sz-1].len;
	
	a[--sz].label=-1;
	heapify(a);
	return 1;
}

int main()
{
	int i=0;
	while(i<20)
	{
		heap[i].label=-1;
		i++;
	}
	
	p programs_input[30];
	int output_permutation[30];
	int output_order[30];
	printf("\nEnter the number of Programs (upto 15): ");
	//using first structure (index 0) to store
	scanf("%d",&programs_input[0].label);
	
	//creation of min heap
	for(i=1;i<=programs_input[0].label;i++){
		printf("Enter lenth of program %d:\t",i);
		scanf("%d",&programs_input[i].len);
		programs_input[i].label=i;
		insert(heap,i,programs_input[i].len);
	}
	
	printf("\nmin heap:\n");
	for(i=1;i<sz;i++)
	{
		printf("P%d \t %d\n",heap[i].label,heap[i].len);
	}
	
	//printf("\nArray in ascending order:");
	int ele,l,j=1;

	ele = heap[1].label;
	l = heap[1].len;
	while(ele!=-1)
	{
		//append the program number and its length in array
		output_permutation[j]=ele;
		output_order[j]=l;
		j++;
		
		delete(heap);
		ele = heap[1].label;
		l = heap[1].len;
	}
	
	//print results
	printf("\n\nPermutation for which MRT is minimum: \n");
	for(i=1;i<j;i++)
	{
		printf("P%d\t",output_permutation[i]);
	}
	printf("\nProgram lengths is resultant permutation: \n");
	for(i=1;i<j;i++)
	{
		printf("%d\t",output_order[i]);
	}
	
	int ctr=j-1,k,mrt=0;
	for(i=1;i<j;i++)
	{
		mrt += output_order[i] * ctr;
		ctr--;
	}
	printf("\nResultant MRT: %d\n",mrt);
	
	return 0;
}
