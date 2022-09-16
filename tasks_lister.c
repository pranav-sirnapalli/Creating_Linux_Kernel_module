
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched.h>
#include<linux/sched/signal.h>


MODULE_LICENSE("GPL");
MODULE_AUTHOR("Pranav Kalwad");
MODULE_DESCRIPTION("OS Project");

int tasks_lister_init(void)
{
	struct task_struct *task;

	printk(KERN_INFO "Loading module...\n");

  	for_each_process(task)
  	{
    		printk(KERN_INFO "pid: %d | pname: %s | state: %ld\n", task->pid, task->comm, task->state);
 	}

  	printk(KERN_INFO "Module loaded.\n");
  	return 0;
}

void tasks_lister_exit(void)
{
	printk(KERN_INFO "Module removed.\n");
}

module_init(tasks_lister_init);
module_exit(tasks_lister_exit);
