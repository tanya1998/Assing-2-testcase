#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>

int main()
{
    char * rtstr[67];
    char * rtstr2[67];
    char * ent[34];
    long rtnice1 =0;
    long rtnice2 =0;
    printf("rtnice of parent/process1:");
    gets(rtstr);
    gets(ent);
    printf("rtnice of child/process2:");
    gets(rtstr2);

    rtnice1 = atoi(rtstr);
    rtnice2 = atoi(rtstr2);
    

    long int pid=fork();
    
    
    if(pid!=0)
    {
        printf("1st Process PID =  %ld\n",getpid());
        printf("2nd Process PID =  %ld\n",pid);
        printf("Process 1 rt_nice = 100\n");
        printf("Process 2 rt_nice = 200 \n");
	syscall(323,pid,rtnice2);//Child
	syscall(323,getpid(),rtnice1);//Parent
        
    }

    
    if(pid==0)
    {
        //struct timeval stop;
        clock_t begin = clock();
        long sum=0;
        long i = 0;
	long total =0;
        for(i=1;i<1000000000;i++)
        {
            if(i%2==0)
		total++;
            	      
        }
        //gettimeofday(&stop,NULL);
        printf("Process with PID %ld terminated \n",getpid());
        clock_t end = clock();
	printf("Time:-%f\n",((double)begin-(double)end)/CLOCKS_PER_SEC);
    }
    else
    {
        //struct timeval stop;
	
        clock_t begin = clock();
        long sum=0;
        long i = 0;
	long total =0;
        for(i=1;i<5000000000;i++)
        {
            if(i%2==0)
		total++;
            	      
        }
        //gettimeofday(&stop,NULL);
        printf("Process with PID %ld terminated \n",getpid());
        clock_t end = clock();
	printf("Time:-%f\n",((double)begin-(double)end)/CLOCKS_PER_SEC);        
        wait(pid);
    }
    return 0;
}
