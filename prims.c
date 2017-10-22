#include<stdio.h>
#include<omp.h>
int a,b,u,v,n,i,j,ne=1,tid;
int visited[10]={0},min=999,mincost=0,cost[10][10];
int main()
{
 printf("\n Enter the number of nodes:");
 scanf("%d",&n);
 printf("\n Enter the adjacency matrix:\n");
 for(i=1;i<=n;i++)
  for(j=1;j<=n;j++)
  {
   scanf("%d",&cost[i][j]);
   if(cost[i][j]==0)
    cost[i][j]=999;
  }
 visited[1]=1;
 printf("\n");
 while(ne<n)
 {
  for(i=1,min=999;i<=n;i++)
   for(j=1;j<=n;j++)
   {
   	#pragma omp parallel sections shared(tid)
   	{
	   #pragma omp section
    if(cost[i][j]<min)
    {
	
     if(visited[i]!=0)
     {
      min=cost[i][j];
      a=u=i;
      b=v=j;
      tid=omp_get_thread_num();	
     }
 }

}

}
     
  if(visited[u]==0 || visited[v]==0)
  { printf("\nThread %d is calculating the  minimum cost",tid);
   printf("\n Edge %d:(%d %d) cost:%d",ne++,a,b,min);
   mincost+=min;
   visited[b]=1;
  }
	
  cost[a][b]=cost[b][a]=999;
printf("\nPATH TRAVELLED FROM %d---->%d",a,b);
 }

 printf("\n Minimun cost of graph is=%d \n",mincost);

//return 1;
}
/*----------------------------OUTPUT-------------------------
admini@proj-16:~$ gcc -fopenmp prims.c
admini@proj-16:~$ ./a.out

 Enter the number of nodes:5

 Enter the adjacency matrix:
0 1 0 6 9
1 0 2 4 5
0 2 0 3 3
6 4 3 0 0 
9 5 3 0 0


Thread 1 is calculating the  minimum cost
 Edge 1:(1 2) cost:1
PATH TRAVELLED FROM 1---->2
Thread 1 is calculating the  minimum cost
 Edge 2:(2 3) cost:2
PATH TRAVELLED FROM 2---->3
Thread 1 is calculating the  minimum cost
 Edge 3:(3 4) cost:3
PATH TRAVELLED FROM 3---->4
Thread 1 is calculating the  minimum cost
 Edge 4:(3 5) cost:3
PATH TRAVELLED FROM 3---->5
 Minimun cost of graph is=9 
admini@proj-16:~$ 
*/

