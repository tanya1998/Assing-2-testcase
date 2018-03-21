#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>

int main()
{
    

    //struct timeval start;
    //gettimeofday(&start,NULL);
    long int pid=fork();
    
    
    if(pid!=0)
    {
        printf("Process 1 %ld\n",getpid());
        printf("Process 2 %ld\n",pid);
        int amma=syscall(323,pid,200);
        //printf("System call sys_rt_nice returned %ld\n",amma);
        printf("Process 1 rt_nice = 0 \n");
        printf("Process 2 rt_nice = 200 \n");
        
    }

    
    if(pid==0)
    {
        //struct timeval stop;
        //clock_t begin =clock();
        long prod=1;
        long i=1;
        for(i=1;i<2000000000;i++)
        {
            prod=prod*i;
            //if(i%1000000==0)    
                //syscall(324,getpid());        
        }
        //gettimeofday(&stop,NULL);
        printf("Process with PID %ld terminated \n",getpid());
        
    }
    else
    {
        //struct timeval stop;
        
        long prod=1;
        long i=1;
        for(i=1;i<1000000000;i++)
        {
            prod=prod*i;
            //printf("%ld\n",getpid());
            //syscall(324,getpid());
            
            
        }
        //gettimeofday(&stop,NULL);
        
        //clock_t end = clock();    
        printf("Process with PID %ld terminated \n",getpid());
        wait(pid);
    }
    return 0;
}
