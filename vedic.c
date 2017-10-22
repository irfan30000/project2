/*Title:-Vedic Mathematics method to find square of 2-digit number is used in a distributed programming. Use shared memory and distributed(multi-CPU) programming to complete the task
Assignmnet No:-
Batch:-T2
-----------------------------------------------------------------------------------------*/
#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int a,n,N, sum=0,d1[10], d[10],i,j,nj,nj1,t1,t2,t3,tsum=0,k;
	
	printf("enter the n digit number to be squared\n");
	scanf("%d",&N);
	a=N;
	for(i=0;a;i++)//separate out digits 
	{
	 d[i]=a%10;
	 a=a/10;	
	}
	n=i;
      printf("The Number is %d",N);
      printf("\nTotal digits are %d\n",n);

    #pragma omp parallel num_threads(n) private(sum,nj,nj1,t1,t2,t3)
    {
    	#pragma omp for
    	for(j=1;j<=n;j++) //apply the formula for Nn2 = E(j=1ton) 
    	{ 	int id = omp_get_thread_num();
	    	nj=n-j;
		nj1=n-j+1;               
		t1=N%((int) (pow(10,nj)));
		t2=N%((int) (pow(10,nj1)));
		t3= d[nj]*(int) pow(10,nj);
		printf("Thread-%d printing N= %d\t n= %d\t j= %d\t nj= %d \t nj1= %d\t t1= %d\t t2= %d\t t3= %d\n",id,N,n,j,nj,nj1,t1,t2,t3);
		sum=t3*(t1+t2);
		printf("Summation thread-%d is  %d\n",id,sum);
		#pragma omp atomic
		tsum+=sum;

     	}
    }

	printf("the suqare of %d is %d\n",N,tsum);
    return 0;
}

/*---------------------------------OUTPUT--------------------------------------------------
swl-02@swl02-OptiPlex-3020:~$ gcc vedic.c -fopenmp -lm
swl-02@swl02-OptiPlex-3020:~$ ./a.out
enter the n digit number to be squared
12
The Number is 12
Total digits are 2
Thread-0 printing N= 12	 n= 2	 j= 1	 nj= 1 	 nj1= 2	 t1= 2	 t2= 12	 t3= 10
Summation thread-0 is  140
Thread-1 printing N= 12	 n= 2	 j= 2	 nj= 0 	 nj1= 1	 t1= 0	 t2= 2	 t3= 2
Summation thread-1 is  4
the suqare of 12 is 144
swl-02@swl02-OptiPlex-3020:~$ ./a.out
enter the n digit number to be squared
123
The Number is 123
Total digits are 3
Thread-1 printing N= 123	 n= 3	 j= 2	 nj= 1 	 nj1= 2	 t1= 3	 t2= 23 t3= 20
Summation thread-1 is  520
Thread-2 printing N= 123	 n= 3	 j= 3	 nj= 0 	 nj1= 1	 t1= 0	 t2= 3	 t3= 3
Summation thread-2 is  9
Thread-0 printing N= 123	 n= 3	 j= 1	 nj= 2 	 nj1= 3	 t1= 23	 t2= 123 t3= 100
Summation thread-0 is  14600
the suqare of 123 is 15129
swl-02@swl02-OptiPlex-3020:~$ ./a.out
enter the n digit number to be squared
1720
The Number is 1720
Total digits are 4
Thread-2 printing N= 1720	 n= 4	 j= 3	 nj= 1 	 nj1= 2	 t1= 0	 t2= 20 t3= 20
Summation thread-2 is  400
Thread-3 printing N= 1720	 n= 4	 j= 4	 nj= 0 	 nj1= 1	 t1= 0	 t2= 0	 t3= 0
Summation thread-3 is  0
Thread-0 printing N= 1720	 n= 4	 j= 1	 nj= 3 	 nj1= 4	 t1= 720	 t2= 1720	 t3= 1000
Summation thread-0 is  2440000
Thread-1 printing N= 1720	 n= 4	 j= 2	 nj= 2 	 nj1= 3	 t1= 20	 t2= 720 t3= 700
Summation thread-1 is  518000
the suqare of 1720 is 2958400
swl-02@swl02-OptiPlex-3020:~$ 
*/
