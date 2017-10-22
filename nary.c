/*Title : Implement n-ary search algorithm using OPENMP.
Assignmnet no:-
Batch:-T2
-------------------------------------------------------------*/
# include <stdio.h>
# include <omp.h>
int a[25],s,test;
int global_size,global_x,n;
void nary_search(int size,int x)
{
    if(size<=n)
    {
       test=0;
       #pragma omp parallel num_threads(n)
	{
	     int tid=omp_get_thread_num();
	     if(a[x+tid]==s)
	     {
		printf("\nNumber is found:%d\n",x+tid);
		test=1;
	     }
        }

       if(test==0)
	{
	   printf("\nNumber is not found\n");
	}
     }
     
     else
     {
        test=0;
     	 #pragma omp parallel num_threads(n)
	{
	     int tid=omp_get_thread_num();
	      if(s>=a[tid*size/n+x] && s<=a[tid*size/n+size/n-1+x])
              {	
		 printf("Thread %d is executing:",tid);
                  printf("It may be here %d.......%d\n",a[tid*size/n+x],a[(tid+1)*size/n-1+x]);
                   global_size=size/n;
		   global_x=tid*global_size+x;
		   test=1;
	      }
	}

    if(test==1)
	{
             nary_search(global_size,global_x);
	}        
	else
	     printf("\n not found");
     }
} 



int main()
{

   int i,size=25,x=0;

  for(i=0;i<=size;i++)
  
    a[i]=i;
    printf("\nEnter the number which you want search......");
    scanf("%d",&s);
    printf("\nEnter the no. of thread which you want......");
    scanf("%d",&n);

   nary_search(size,x);
return 0;
}

/*----------------------------Output--------------------------
swl02-OptiPlex-3020:~$ gcc nary.c -fopenmp
swl-02@swl02-OptiPlex-3020:~$ ./a.out

Enter the number which you want search......10

Enter the no. of thread which you want......4
Thread 1 is executing:It may be here 6.......11
Thread 3 is executing:It may be here 10.......11

Number is found:10
swl-02@swl02-OptiPlex-3020:~$ ./a.out

Enter the number which you want search......26

Enter the no. of thread which you want......4

 not foundswl-02@swl02-OptiPlex-3020:~$ 


*/














