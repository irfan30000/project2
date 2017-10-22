/*TITLE:-Implement a Parallel ODD-Even Sort algorithm using GPU or ARM equivalent.
ASSIGNMENT NO:-
BATCH:-T2*/

#include<iostream>
#include<omp.h>
using namespace std;
int i;
void even(int a[50],int n)
{
	int temp,x;
	for(x=0;x<n;x++)
	{
              if(x%2==0)
		{
                   #pragma omp parallel for num_threads(2) shared(a) private(i,temp)
	 	    for(i=1;i<n;i=i+2)
                     
			if(a[i-1] > a[i])
			{
			  temp = a[i];
			  a[i] = a[i-1];
			  a[i-1] = temp;
			}
                       cout<<"\nEVEN SORT:";
                      for(i=0;i<n;i++)
	                 {
		          cout<<"\t"<<a[i];
	                }
          
		     
                 }
                   
              else 
                {
                  #pragma omp parallel for num_threads(2) shared(a) private(i,temp)
                   for(i=1;i<n;i=i+2)
                    
			if(a[i] > a[i+1])
			{
			  temp = a[i];
			  a[i] = a[i+1];
			  a[i+1] = temp;
			}
                      cout<<"\nODD SORT:";
                        for(i=0;i<n;i++)
	                 {
			           cout<<"\t"<<a[i];
						 
         		     }
			
                          cout<<"\n";
                 
                      
	        }
                    
        }
}
int main()
{
	int i=0,n,a[50];
	cout<<"\nEnter how many elements u want:";
	cin>>n;
	cout<<"\nEnter the elements:";
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
        for(i=0;i<n;i++)
         {
            even(a,n);
      	}
	
return 0;
}


/***********************************OUTPUT ON BEAGLE BONE BOARD*************
swl-04@Comp-SWL-04:~$ ssh root@192.168.7.2
Debian GNU/Linux 7

BeagleBoard.org BeagleBone Debian Image 2014-04-23

Support/FAQ: http://elinux.org/Beagleboard:BeagleBoneBlack_Debian
Last login: Wed Apr 23 20:20:23 2014 from comp-swl-04.local
root@beaglebone:~# cd /home
root@beaglebone:/home# ls
GroupB_2quick.c  df	      oe.c	qsort.c      root@192.168.7.2
a.out		 odd_even.c   oe.cpp	qsort.cpp    sortq.c
bb.c		 oddeven.c    oesort.c	quickmp.cpp  stepper.py
dd		 oddeven.cpp  penmp	quicksort.c  test
debian		 odev.c       qs.c	ra.py
root@beaglebone:/home# g++ oe.cpp
root@beaglebone:/home# ./a.out

Enter how many elements u want:8

Enter the elements:12
5
89
3
75
8
45
99

EVEN SORT:	5	12	3	89	8	75	45	99
ODD SORT:	5	3	12	8	89	45	75	99

EVEN SORT:	3	5	8	12	45	89	75	99
ODD SORT:	3	5	8	12	45	75	89	99

EVEN SORT:	3	5	8	12	45	75	89	99
ODD SORT:	3	5	8	12	45	75	89	99

EVEN SORT:	3	5	8	12	45	75	89	99
ODD SORT:	3	5	8	12	45	75	89	99

EVEN SORT:	3	5	8	12	45	75	89	99
ODD SORT:	3	5	8	12	45	75	89	99

EVEN SORT:	3	5	8	12	45	75	89	99
ODD SORT:	3	5	8	12	45	75	89	99

EVEN SORT:	3	5	8	12	45	75	89	99
ODD SORT:	3	5	8	12	45	75	89	99

EVEN SORT:	3	5	8	12	45	75	89	99
ODD SORT:	3	5	8	12	45	75	89	99

EVEN SORT:	3	5	8	12	45	75	89	99
ODD SORT:	3	5	8	12	45	75	89	99

EVEN SORT:	3	5	8	12	45	75	89	99
ODD SORT:	3	5	8	12	45	75	89	99

EVEN SORT:	3	5	8	12	45	75	89	99
ODD SORT:	3	5	8	12	45	75	89	99

EVEN SORT:	3	5	8	12	45	75	89	99
ODD SORT:	3	5	8	12	45	75	89	99

EVEN SORT:	3	5	8	12	45	75	89	99
ODD SORT:	3	5	8	12	45	75	89	99

EVEN SORT:	3	5	8	12	45	75	89	99
ODD SORT:	3	5	8	12	45	75	89	99

EVEN SORT:	3	5	8	12	45	75	89	99
ODD SORT:	3	5	8	12	45	75	89	99

EVEN SORT:	3	5	8	12	45	75	89	99
ODD SORT:	3	5	8	12	45	75	89	99

EVEN SORT:	3	5	8	12	45	75	89	99
ODD SORT:	3	5	8	12	45	75	89	99

EVEN SORT:	3	5	8	12	45	75	89	99
ODD SORT:	3	5	8	12	45	75	89	99

EVEN SORT:	3	5	8	12	45	75	89	99
ODD SORT:	3	5	8	12	45	75	89	99

EVEN SORT:	3	5	8	12	45	75	89	99
ODD SORT:	3	5	8	12	45	75	89	99

EVEN SORT:	3	5	8	12	45	75	89	99
ODD SORT:	3	5	8	12	45	75	89	99

EVEN SORT:	3	5	8	12	45	75	89	99
ODD SORT:	3	5	8	12	45	75	89	99

EVEN SORT:	3	5	8	12	45	75	89	99
ODD SORT:	3	5	8	12	45	75	89	99

EVEN SORT:	3	5	8	12	45	75	89	99
ODD SORT:	3	5	8	12	45	75	89	99

EVEN SORT:	3	5	8	12	45	75	89	99
ODD SORT:	3	5	8	12	45	75	89	99

EVEN SORT:	3	5	8	12	45	75	89	99
ODD SORT:	3	5	8	12	45	75	89	99

EVEN SORT:	3	5	8	12	45	75	89	99
ODD SORT:	3	5	8	12	45	75	89	99

EVEN SORT:	3	5	8	12	45	75	89	99
ODD SORT:	3	5	8	12	45	75	89	99

EVEN SORT:	3	5	8	12	45	75	89	99
ODD SORT:	3	5	8	12	45	75	89	99

EVEN SORT:	3	5	8	12	45	75	89	99
ODD SORT:	3	5	8	12	45	75	89	99

EVEN SORT:	3	5	8	12	45	75	89	99
ODD SORT:	3	5	8	12	45	75	89	99

EVEN SORT:	3	5	8	12	45	75	89	99
ODD SORT:	3	5	8	12	45	75	89	99
root@beaglebone:/home# 

***************************************ON TERMINAL*******************
swl-04@Comp-SWL-04:~$ scp oe.cpp root@192.168.7.2:/home
Debian GNU/Linux 7

BeagleBoard.org BeagleBone Debian Image 2014-04-23

Support/FAQ: http://elinux.org/Beagleboard:BeagleBoneBlack_Debian
oe.cpp                                        100% 1397     1.4KB/s   00:00    
swl-04@Comp-SWL-04:~$ */ 





		
