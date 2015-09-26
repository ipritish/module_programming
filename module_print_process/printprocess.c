#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/fs_struct.h>

int init_module(void)
{
	printk(KERN_ALERT"Hello World %c\n",current->comm[0]);
	return 0;
}

void cleanup_module(void)
{
	printk(KERN_ALERT"Goodbye\n");
}
