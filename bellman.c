#include<stdio.h>
#define max 99999

struct term
{
   int source_index;
   int dest_index;
   int weight;
};
typedef struct term edge;

struct graph
{
   int V;           //no. of vertices
   int E;           //no. of edges
   edge list[25];   //edge information
};

typedef struct graph graph1;
graph1 g;
int distance[25];     //stores min distances from source
int path[25];         //used to print the path

void initialize()
{
  int i;
  for(i=1;i<=25;i++)
  {
     g.list[i].source_index = 0;
     g.list[i].dest_index = 0;
     g.list[i].weight = 0;
     
     distance[i] = 0;
     path[i] = 0;
  }  
  g.V = 0;
  g.E = 0;
}          

void getgraph()
{
   int i;
   
   printf("\nENTER NO. OF VERTICES : ");
   scanf("%d",&g.V);
   
   printf("\nENTER NO. OF EDGES : ");
   scanf("%d",&g.E);
   
   printf("\n");
   
   printf("\nENTER THE SOURCE->DEST AND WEIGHT : \n");
   for(i=1;i<=g.E;i++)
   {
      printf("\n-> ");
      scanf("%d",&g.list[i].source_index);
      printf(" ");
      scanf("%d",&g.list[i].dest_index);
      printf(" ");
      scanf("%d",&g.list[i].weight);
   }
}

void bellmanford()
{
   int i,j,u,v,w;
   int flag;
   
   for(i=1;i<=g.V;i++)
   {
      distance[i] = max;        //make distance infinity
      path[i] = -1;             //initial path for all is -1
   }
   
   distance[1] = 0;   //source vertex is 1
   
   for(i=1 ;i <= g.V-1; i++)
   {
      flag = 0;
      
      for(j=1;j<=g.E;j++)           //relax each edge
      {
         u = g.list[j].source_index;
         v = g.list[j].dest_index;
         w = g.list[j].weight;
         
         if(distance[u]+w < distance[v])
         {
            distance[v] = distance[u] + w;
            path[v] = u;
            flag++;
         }
      }
      
      if(flag==0)
         break;
   }

   for(i=1;i<=g.E;i++)
   {
      u = g.list[j].source_index;
      v = g.list[j].dest_index;
      w = g.list[j].weight;
         
      if(distance[u]+w < distance[v])
      {
        printf("\nNEGATIVE CYCLE EXISTS..\n");
        return;
      }
   }
   
   for(i=1;i<=g.V;i++)
   {
      printf("%d ",distance[i]);  
   }
  
}

int main()
{
   initialize();
   getgraph();
   bellmanford();
   
   int i,v=2,j=1,k;
   int array[20];
   
   printf("\n");
   while(v<=g.V)//vertex by vertex get it done
   {  
      i = v;
      
      for(k=1;k<=20;k++)
        array[k]=0;
      
      j=1;
      while(1)
      {
        array[j] = path[i];
        i = path[i];
        
        if(array[j]==1)
          break;
        
        j++;
      }
    
      for(k=j;k>0;k--)
        printf("-> %d ",array[k]);
    
      printf("-> %d ",v);  
      printf("\n"); 
     
      v++;
      
   }
   return 0;  
}

/*

OUTPUT ::

student@student-OptiPlex-7010:~$ gcc nehadaa3.c
student@student-OptiPlex-7010:~$ ./a.out

ENTER NO. OF VERTICES : 7

ENTER NO. OF EDGES : 10


ENTER THE SOURCE->DEST AND WEIGHT : 

-> 1 2 6
  
-> 1 3 5
  
-> 1 4 5
  
-> 2 5 -1
  
-> 3 2 -2
  
-> 3 5 1
  
-> 4 3 -2
  
-> 4 6 -1
  
-> 5 7 3
  
-> 6 7 3
  0 1 3 5 0 4 3 
-> 1 -> 4 -> 3 -> 2 
-> 1 -> 4 -> 3 
-> 1 -> 4 
-> 1 -> 4 -> 3 -> 2 -> 5 
-> 1 -> 4 -> 6 
-> 1 -> 4 -> 3 -> 2 -> 5 -> 7 
student@student-OptiPlex-7010:~$ 

*/
