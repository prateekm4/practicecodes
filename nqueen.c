#include<stdio.h>
#include<string.h>
#include<math.h>

char board[10][10];
int x[10];
int n;


int place(int k , int i)
{
   int j;
   for(j=1 ; j<k ; j++)
   {
      if(x[j] == i || (abs(x[j]-i)) == (abs(j-k)))
        return 0; 
   }
   return 1;
}   
      

void initboard(int n)
{
   int i,j;
     for(i=1;i<=n;i++)     //initialize board
     {
        for(j=1;j<=n;j++)
        {
          board[i][j]='-';
        }   
     }
     for(i=1;i<=n;i++)     //allocate the queens on the board    
     {
        j = x[i];
        board[i][j]='Q';
     }    
}
         
void nqueen(int k , int n)
{
   int i;
   for(i=1 ; i<=n ; i++)
   {
      if(place(k,i))            //check whether kth queen can be placed in ith column
      {
        x[k] = i;
        if(k == n)              //print solution if all queens are placed on the board
        {
           printf("\npossible outcome :: \n");
           initboard(n);
           display(n);       
        }
        
       else
         nqueen(k+1,n);
     }  
  }

}
void display(int n)
{
   int i,j;
   
 for(i=1;i<=n;i++)
   printf("%d\t",x[i]);
   
   printf("\n\n");
    for(i=1;i<=n;i++)      //display board
    {
      for(j=1;j<=n;j++)
      {
         printf("%c ",board[i][j]);    
      }
      printf("\n");
    }                 
}


int main()
{
  n=8;
  nqueen(1,n);
}


/*

OUTPUT ::

student@student-OptiPlex-7010:~$ gcc nqueen_neha.c
student@student-OptiPlex-7010:~$ ./a.out

- Q - - - - - - 
- - - Q - - - - 
- - - - - Q - - 
- - - - - - - Q 
- - Q - - - - - 
Q - - - - - - - 
- - - - - - Q - 

possible outcome :: 
5	2	4	7	3	8	6	1	

- - - - Q - - - 
- Q - - - - - - 
- - - Q - - - - 
- - - - - - Q - 
- - Q - - - - - 
- - - - - - - Q 
- - - - - Q - - 
Q - - - - - - - 

possible outcome :: 
5	2	6	1	7	4	8	3	

- - - - Q - - - 
- Q - - - - - - 
- - - - - Q - - 
Q - - - - - - - 
- - - - - - Q - 
- - - Q - - - - 
- - - - - - - Q 
- - Q - - - - - 

possible outcome :: 
5	2	8	1	4	7	3	6	

- - - - Q - - - 
- Q - - - - - - 
- - - - - - - Q 
Q - - - - - - - 
- - - Q - - - - 
- - - - - - Q - 
- - Q - - - - - 
- - - - - Q - - 

possible outcome :: 
5	3	1	6	8	2	4	7	

- - - - Q - - - 
- - Q - - - - - 
Q - - - - - - - 
- - - - - Q - - 
- - - - - - - Q 
- Q - - - - - - 
- - - Q - - - - 
- - - - - - Q - 

possible outcome :: 
5	3	1	7	2	8	6	4	

- - - - Q - - - 
- - Q - - - - - 
Q - - - - - - - 
- - - - - - Q - 
- Q - - - - - - 
- - - - - - - Q 
- - - - - Q - - 
- - - Q - - - - 

possible outcome :: 
5	3	8	4	7	1	6	2	

- - - - Q - - - 
- - Q - - - - - 
- - - - - - - Q 
- - - Q - - - - 
- - - - - - Q - 
Q - - - - - - - 
- - - - - Q - - 
- Q - - - - - - 

possible outcome :: 
5	7	1	3	8	6	4	2	

- - - - Q - - - 
- - - - - - Q - 
Q - - - - - - - 
- - Q - - - - - 
- - - - - - - Q 
- - - - - Q - - 
- - - Q - - - - 
- Q - - - - - - 

possible outcome :: 
5	7	1	4	2	8	6	3	

- - - - Q - - - 
- - - - - - Q - 
Q - - - - - - - 
- - - Q - - - - 
- Q - - - - - - 
- - - - - - - Q 
- - - - - Q - - 
- - Q - - - - - 

possible outcome :: 
5	7	2	4	8	1	3	6	

- - - - Q - - - 
- - - - - - Q - 
- Q - - - - - - 
- - - Q - - - - 
- - - - - - - Q 
Q - - - - - - - 
- - Q - - - - - 
- - - - - Q - - 

possible outcome :: 
5	7	2	6	3	1	4	8	

- - - - Q - - - 
- - - - - - Q - 
- Q - - - - - - 
- - - - - Q - - 
- - Q - - - - - 
Q - - - - - - - 
- - - Q - - - - 
- - - - - - - Q 

possible outcome :: 
5	7	2	6	3	1	8	4	

- - - - Q - - - 
- - - - - - Q - 
- Q - - - - - - 
- - - - - Q - - 
- - Q - - - - - 
Q - - - - - - - 
- - - - - - - Q 
- - - Q - - - - 

possible outcome :: 
5	7	4	1	3	8	6	2	

- - - - Q - - - 
- - - - - - Q - 
- - - Q - - - - 
Q - - - - - - - 
- - Q - - - - - 
- - - - - - - Q 
- - - - - Q - - 
- Q - - - - - - 

possible outcome :: 
5	8	4	1	3	6	2	7	

- - - - Q - - - 
- - - - - - - Q 
- - - Q - - - - 
Q - - - - - - - 
- - Q - - - - - 
- - - - - Q - - 
- Q - - - - - - 
- - - - - - Q - 

possible outcome :: 
5	8	4	1	7	2	6	3	

- - - - Q - - - 
- - - - - - - Q 
- - - Q - - - - 
Q - - - - - - - 
- - - - - - Q - 
- Q - - - - - - 
- - - - - Q - - 
- - Q - - - - - 

possible outcome :: 
6	1	5	2	8	3	7	4	

- - - - - Q - - 
Q - - - - - - - 
- - - - Q - - - 
- Q - - - - - - 
- - - - - - - Q 
- - Q - - - - - 
- - - - - - Q - 
- - - Q - - - - 

possible outcome :: 
6	2	7	1	3	5	8	4	

- - - - - Q - - 
- Q - - - - - - 
- - - - - - Q - 
Q - - - - - - - 
- - Q - - - - - 
- - - - Q - - - 
- - - - - - - Q 
- - - Q - - - - 

possible outcome :: 
6	2	7	1	4	8	5	3	

- - - - - Q - - 
- Q - - - - - - 
- - - - - - Q - 
Q - - - - - - - 
- - - Q - - - - 
- - - - - - - Q 
- - - - Q - - - 
- - Q - - - - - 

possible outcome :: 
6	3	1	7	5	8	2	4	

- - - - - Q - - 
- - Q - - - - - 
Q - - - - - - - 
- - - - - - Q - 
- - - - Q - - - 
- - - - - - - Q 
- Q - - - - - - 
- - - Q - - - - 

possible outcome :: 
6	3	1	8	4	2	7	5	

- - - - - Q - - 
- - Q - - - - - 
Q - - - - - - - 
- - - - - - - Q 
- - - Q - - - - 
- Q - - - - - - 
- - - - - - Q - 
- - - - Q - - - 

possible outcome :: 
6	3	1	8	5	2	4	7	

- - - - - Q - - 
- - Q - - - - - 
Q - - - - - - - 
- - - - - - - Q 
- - - - Q - - - 
- Q - - - - - - 
- - - Q - - - - 
- - - - - - Q - 

possible outcome :: 
6	3	5	7	1	4	2	8	

- - - - - Q - - 
- - Q - - - - - 
- - - - Q - - - 
- - - - - - Q - 
Q - - - - - - - 
- - - Q - - - - 
- Q - - - - - - 
- - - - - - - Q 

possible outcome :: 
6	3	5	8	1	4	2	7	

- - - - - Q - - 
- - Q - - - - - 
- - - - Q - - - 
- - - - - - - Q 
Q - - - - - - - 
- - - Q - - - - 
- Q - - - - - - 
- - - - - - Q - 

possible outcome :: 
6	3	7	2	4	8	1	5	

- - - - - Q - - 
- - Q - - - - - 
- - - - - - Q - 
- Q - - - - - - 
- - - Q - - - - 
- - - - - - - Q 
Q - - - - - - - 
- - - - Q - - - 

possible outcome :: 
6	3	7	2	8	5	1	4	

- - - - - Q - - 
- - Q - - - - - 
- - - - - - Q - 
- Q - - - - - - 
- - - - - - - Q 
- - - - Q - - - 
Q - - - - - - - 
- - - Q - - - - 

possible outcome :: 
6	3	7	4	1	8	2	5	

- - - - - Q - - 
- - Q - - - - - 
- - - - - - Q - 
- - - Q - - - - 
Q - - - - - - - 
- - - - - - - Q 
- Q - - - - - - 
- - - - Q - - - 

possible outcome :: 
6	4	1	5	8	2	7	3	

- - - - - Q - - 
- - - Q - - - - 
Q - - - - - - - 
- - - - Q - - - 
- - - - - - - Q 
- Q - - - - - - 
- - - - - - Q - 
- - Q - - - - - 

possible outcome :: 
6	4	2	8	5	7	1	3	

- - - - - Q - - 
- - - Q - - - - 
- Q - - - - - - 
- - - - - - - Q 
- - - - Q - - - 
- - - - - - Q - 
Q - - - - - - - 
- - Q - - - - - 

possible outcome :: 
6	4	7	1	3	5	2	8	

- - - - - Q - - 
- - - Q - - - - 
- - - - - - Q - 
Q - - - - - - - 
- - Q - - - - - 
- - - - Q - - - 
- Q - - - - - - 
- - - - - - - Q 

possible outcome :: 
6	4	7	1	8	2	5	3	

- - - - - Q - - 
- - - Q - - - - 
- - - - - - Q - 
Q - - - - - - - 
- - - - - - - Q 
- Q - - - - - - 
- - - - Q - - - 
- - Q - - - - - 

possible outcome :: 
6	8	2	4	1	7	5	3	

- - - - - Q - - 
- - - - - - - Q 
- Q - - - - - - 
- - - Q - - - - 
Q - - - - - - - 
- - - - - - Q - 
- - - - Q - - - 
- - Q - - - - - 

possible outcome :: 
7	1	3	8	6	4	2	5	

- - - - - - Q - 
Q - - - - - - - 
- - Q - - - - - 
- - - - - - - Q 
- - - - - Q - - 
- - - Q - - - - 
- Q - - - - - - 
- - - - Q - - - 

possible outcome :: 
7	2	4	1	8	5	3	6	

- - - - - - Q - 
- Q - - - - - - 
- - - Q - - - - 
Q - - - - - - - 
- - - - - - - Q 
- - - - Q - - - 
- - Q - - - - - 
- - - - - Q - - 

possible outcome :: 
7	2	6	3	1	4	8	5	

- - - - - - Q - 
- Q - - - - - - 
- - - - - Q - - 
- - Q - - - - - 
Q - - - - - - - 
- - - Q - - - - 
- - - - - - - Q 
- - - - Q - - - 

possible outcome :: 
7	3	1	6	8	5	2	4	

- - - - - - Q - 
- - Q - - - - - 
Q - - - - - - - 
- - - - - Q - - 
- - - - - - - Q 
- - - - Q - - - 
- Q - - - - - - 
- - - Q - - - - 

possible outcome :: 
7	3	8	2	5	1	6	4	

- - - - - - Q - 
- - Q - - - - - 
- - - - - - - Q 
- Q - - - - - - 
- - - - Q - - - 
Q - - - - - - - 
- - - - - Q - - 
- - - Q - - - - 

possible outcome :: 
7	4	2	5	8	1	3	6	

- - - - - - Q - 
- - - Q - - - - 
- Q - - - - - - 
- - - - Q - - - 
- - - - - - - Q 
Q - - - - - - - 
- - Q - - - - - 
- - - - - Q - - 

possible outcome :: 
7	4	2	8	6	1	3	5	

- - - - - - Q - 
- - - Q - - - - 
- Q - - - - - - 
- - - - - - - Q 
- - - - - Q - - 
Q - - - - - - - 
- - Q - - - - - 
- - - - Q - - - 

possible outcome :: 
7	5	3	1	6	8	2	4	

- - - - - - Q - 
- - - - Q - - - 
- - Q - - - - - 
Q - - - - - - - 
- - - - - Q - - 
- - - - - - - Q 
- Q - - - - - - 
- - - Q - - - - 

possible outcome :: 
8	2	4	1	7	5	3	6	

- - - - - - - Q 
- Q - - - - - - 
- - - Q - - - - 
Q - - - - - - - 
- - - - - - Q - 
- - - - Q - - - 
- - Q - - - - - 
- - - - - Q - - 

possible outcome :: 
8	2	5	3	1	7	4	6	

- - - - - - - Q 
- Q - - - - - - 
- - - - Q - - - 
- - Q - - - - - 
Q - - - - - - - 
- - - - - - Q - 
- - - Q - - - - 
- - - - - Q - - 

possible outcome :: 
8	3	1	6	2	5	7	4	

- - - - - - - Q 
- - Q - - - - - 
Q - - - - - - - 
- - - - - Q - - 
- Q - - - - - - 
- - - - Q - - - 
- - - - - - Q - 
- - - Q - - - - 

possible outcome :: 
8	4	1	3	6	2	7	5	

- - - - - - - Q 
- - - Q - - - - 
Q - - - - - - - 
- - Q - - - - - 
- - - - - Q - - 
- Q - - - - - - 
- - - - - - Q - 
- - - - Q - - - 
student@student-OptiPlex-7010:~$

*/
