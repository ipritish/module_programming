#include <linux/module.h>
#include <linux/kernel.h>
#include<linux/kthread.h>
#include<linux/sched.h>
#include<linux/init.h>
#include <linux/time.h>   // for using jiffies 
#include <linux/timer.h>

static struct task_struct *my_thread;
int data;

int thread_fn(void *data) {

	unsigned long j0,j1;
	int delay = 60*HZ;

	printk(KERN_INFO "In my thread");
	j0 = jiffies;
	j1 = j0 + delay;

	while (time_before(jiffies, j1))
		        schedule();

	return 0;
}

int thread_init (void) 
{
	   
	//char our_thread[8] = "my_thread";
	printk(KERN_INFO "in init");
	my_thread = kthread_run(&thread_fn,(void *)data,"hello thread");
	/*if(my_thread)
	{
		printk(KERN_INFO "in if");
		wake_up_process(my_thread);
	}*/

	return 0;
}



void thread_cleanup(void) 
{
	int ret;
	ret = kthread_stop(my_thread);
	if(!ret)
		printk(KERN_INFO "Thread stopped");

}
MODULE_LICENSE("GPL");   
module_init(thread_init);
module_exit(thread_cleanup);
