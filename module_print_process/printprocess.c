#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/fs_struct.h>

int init_module(void)
{
	printk(KERN_ALERT"Hello World %s\n",current->comm);
	return 0;
}

void cleanup_module(void)
{
	printk(KERN_ALERT"Goodbye\n");
}
