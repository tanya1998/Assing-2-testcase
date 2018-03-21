#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/sched.h>
#include<linux/syscalls.h>
#include<asm/errno.h>
asmlinkage long sys_rtnice(int pid, long rtnice)
{
	
	unsigned long long int rtval = (unsigned long long int)rtnice * 1000000000;
	if(pid<0)
		return ESRCH ;     // No such process PID-3
	struct task_struct *task;
	char str[45];
	struct sched_entity *sched;
	int found =0;
	for_each_process(task)
	{
		sched = &(task->se);

	if(((long)task_pid_nr(task))==pid)
		
	{sched->rtnice = rtval
	 found =1;
	}
	else
	return ESRCH;
	}	        
	return 0; //ran correctly
}
