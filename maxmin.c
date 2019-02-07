// DAA Assignment 1
// Author : Prateek
// Program to find maximum and minimum value in an integer array using Divide and conquer
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int a[50];

void maxmin(int i, int j, int *mx, int *mn)
{
	if(i==j)
	{
		*mx=*mn=a[i];
	}
	else if(i==j-1)
	{
		if(a[i] < a[j]) {*mx=a[j]; *mn=a[i];}
		else {*mx=a[i]; *mn=a[j];}	
	}
	else{
		int mx1,mn1;
		int m = floor((i+j)/2);
		maxmin(i,m,mx,mn);
		maxmin(m+1,j,&mx1,&mn1);
		
		if(*mx < mx1) *mx=mx1;
		if(*mn > mn1) *mn=mn1;	
	}
}
int main()
{
	int l=0,h,max,min;
	int n;
	printf("\nEnter the number of elements (upto 50) in array: ");
	scanf("%d",&n);
	h=n-1;
	
	int i;
	for(i=0;i<n;i++){
		printf("Enter element %d:\t",i+1);
		scanf("%d",&a[i]);
	}
	
	maxmin(l,h,&max,&min);

	printf("\nMaximum Element: %d",max);
	printf("\nMinimum Element: %d\n\n",min);
	

	return 0;
	
}

/*
:OUTPUT:

prateekm4@prateekm4-VirtualBox:~$ gcc maxmin.c -lm
prateekm4@prateekm4-VirtualBox:~$ ./a.out

Enter the number of elements (upto 50) in array: 1
Enter element 1:	5

Maximum Element: 5
Minimum Element: 5

prateekm4@prateekm4-VirtualBox:~$ ./a.out

Enter the number of elements (upto 50) in array: 2
Enter element 1:	45
Enter element 2:	6

Maximum Element: 45
Minimum Element: 6

prateekm4@prateekm4-VirtualBox:~$ ./a.out

Enter the number of elements (upto 50) in array: 3
Enter element 1:	85
Enter element 2:	-4
Enter element 3:	78

Maximum Element: 85
Minimum Element: -4

prateekm4@prateekm4-VirtualBox:~$ ./a.out

Enter the number of elements (upto 50) in array: 9 
Enter element 1:	5
Enter element 2:	7
Enter element 3:	-8
Enter element 4:	25
Enter element 5:	16
Enter element 6:	-2 
Enter element 7:	0
Enter element 8:	55
Enter element 9:	3

Maximum Element: 55
Minimum Element: -8

*/


