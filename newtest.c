#include<stdio.h>
#include<time.h>
#include<unistd.h>
#include<linux/kernel.h>
#include<sys/syscall.h>
int main()

{       syscall(323,(long)getpid(),200); 
	clock_t begin = clock();
        long sum=0;
        long i = 0;
	long total =0;
        for(i=1;i<2000000000;i++)
        {
            if(i%2==0)
		total++;
            	      
        }
        //gettimeofday(&stop,NULL);
        printf("Process with PID %ld terminated \n",getpid());
        clock_t end = clock();
	printf("Time:-%f\n",((double)begin-(double)end)/CLOCKS_PER_SEC);
	return 0;
}
