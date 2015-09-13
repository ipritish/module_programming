#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

static int hello_data __initdata = 3;

static int __init hello_data_init(void)
{
	printk(KERN_ALERT"Hello World\n");
	return 0;
}

static void __exit hello_data_exit(void)
{
	printk(KERN_ALERT"Goodbye\n");
}

module_init(hello_data_init);
module_exit(hello_data_exit);

MODULE_LICENSE("GPL");

MODULE_AUTHOR("Pritish Jain");

MODULE_SUPPORTED_DEVICE("testdevice");

MODULE_DESCRIPTION("hello data module");
