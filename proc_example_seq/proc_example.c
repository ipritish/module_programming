#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>

#define procfs_name "helloworld"

/**
 * This structure hold information about the /proc file
 *
 */
struct proc_dir_entry *hello_proc;

static int hello_show(struct seq_file *m, void *v)
{
    seq_printf(m, "%s\n", "Hello World!");
    return 0;
}

static int hello_open(struct inode *inode, struct file *file)
{
    return single_open(file, hello_show, NULL);
}

static const struct file_operations proc_file_fops = {
	.owner = THIS_MODULE,
	.open  = hello_open,
	.read       = seq_read,
    .llseek     = seq_lseek,
    .release    = single_release,
};

int init_module()
{
	hello_proc = proc_create(procfs_name,0,NULL,&proc_file_fops);
	
	if (hello_proc == NULL) {
		//remove_proc_entry(procfs_name, &proc_root);
		printk(KERN_ALERT "Error: Could not initialize /proc/%s\n",procfs_name);
		return -ENOMEM;
	}

	printk(KERN_INFO "/proc/%s created\n", procfs_name);	
	return 0;	/* everything is ok */
}

void cleanup_module()
{
	remove_proc_entry(procfs_name, NULL);
	printk(KERN_INFO "/proc/%s removed\n", procfs_name);
}
