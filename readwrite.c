
/*
TITLE : Implement Reader-Writer problem using OPENMP
ASSIGNMENT NO: 
BATCH NO:T1
------------------------------------------------------------------*/
#include<stdio.h>
#include <time.h>
#include <unistd.h>
#include <omp.h>

int var=10;

int main()
{
 int i=0,NumberofReaderThread=0,NumberofWriterThread;

omp_lock_t writelock,xlock;
omp_init_lock(&writelock);
omp_init_lock(&xlock);

int readCount=0;

int tid=0;
#pragma omp parallel sections shared(readCount) private(i)
{
 #pragma omp section
 {
    i=0;
    printf("\nReader %d is trying to enter into the Database for reading the data",i);

    omp_set_lock(&xlock);
    readCount++;
    if(readCount==1)
    {
      omp_set_lock(&writelock);
    }
    omp_unset_lock(&xlock);

    printf("\nReader %d is reading the database var = %d",i, var); 
    printf("\nReader %d is leaving the database",i);  
   
    omp_set_lock(&xlock);
    readCount--;
    if(readCount==0)
    {
      omp_unset_lock(&writelock);
    }
    omp_unset_lock(&xlock);
 }

#pragma omp section 
{
    i=0;
    printf("\nWriter %d is trying to enter into database for modifying the data",i);
    omp_set_lock(&writelock);
    var++;
    printf("\nWriter %d is writting into the database var = %d",i, var); 

    printf("\nWriter %d is leaving the database",i); 
    omp_unset_lock(&writelock);
}

 #pragma omp section
 {
    i=1;
    printf("\nReader %d is trying to enter into the Database for reading the data",i);

    omp_set_lock(&xlock);
    readCount++;
    if(readCount==1)
    {
      omp_set_lock(&writelock);
    }
    omp_unset_lock(&xlock);

   printf("\nReader %d is reading the database var = %d",i, var); 
    printf("\nReader %d is leaving the database",i);  
   
    omp_set_lock(&xlock);
    readCount--;
    if(readCount==0)
    {
      omp_unset_lock(&writelock);
    }
    omp_unset_lock(&xlock);
 }

#pragma omp section
{
    i=1;
    printf("\nWriter %d is trying to enter into database for modifying the data",i);
    omp_set_lock(&writelock);
var++;
    printf("\nWriter %d is writting into the database var = %d",i, var); 
    printf("\nWriter %d is leaving the database",i); 
    omp_unset_lock(&writelock);
}

#pragma omp section
 {
    i=2;
    printf("\nReader %d is trying to enter into the Database for reading the data",i);

    omp_set_lock(&xlock);
    readCount++;
    if(readCount==1)
    {
      omp_set_lock(&writelock);
    }
    omp_unset_lock(&xlock);

    printf("\nReader %d is reading the database var = %d",i, var); 
    printf("\nReader %d is leaving the database",i);  
   
    omp_set_lock(&xlock);
    readCount--;
    if(readCount==0)
    {
      omp_unset_lock(&writelock);
    }
    omp_unset_lock(&xlock);
 }

#pragma omp section
 {
    i=1;
    printf("\nWriter %d is trying to enter into database for modifying the data",i);
    omp_set_lock(&writelock);
var++;
    printf("\nWriter %d is writting into the database var = %d",i, var); 
    printf("\nWriter %d is leaving the database",i); 
    omp_unset_lock(&writelock);
 }


}
	sleep(5);
  omp_destroy_lock(&writelock); 
  omp_destroy_lock(&xlock); 
 return 0;
}

/*----------------------------OUTPUT------------------------------
admin1@admin1:~$ gcc readwrite.c -fopenmp
admin1@admin1:~$ ./a.out

Reader 0 is trying to enter into the Database for reading the data
Reader 0 is reading the database var = 10
Reader 0 is leaving the database
Reader 2 is trying to enter into the Database for reading the data
Reader 2 is reading the database var = 10
Reader 2 is leaving the database
Writer 1 is trying to enter into database for modifying the data
Writer 1 is writting into the database var = 11
Writer 1 is leaving the database
Writer 0 is trying to enter into database for modifying the data
Writer 0 is writting into the database var = 12
Writer 0 is leaving the database
Writer 1 is trying to enter into database for modifying the data
Writer 1 is writting into the database var = 13
Writer 1 is leaving the database
Reader 1 is trying to enter into the Database for reading the data
Reader 1 is reading the database var = 13
Reader 1 is leaving the databaseadmin1@admin1:~$ 

*/
