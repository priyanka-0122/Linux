#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>

MODULE_LICENCE("GPU");			//Mandatory when writing a kernel program and other's can be skippked as well
MODULE_AUTHOR("Priyanka");
MODULE_DESCRIPTION("Simple Kernel Module");
MODULE_VERSION("1.0");

// start function
static int __init hello_world_init(void)
{
	printk(KERN_INFO "Welcome to Kernel\n");

	return 0;
}

// cleanup function
void __exit hello_world_exit(void)
{
	printk(KERN_INFO "Bye\n");
}

module_init(hello_world_init);
module_exit(hello_world_exit);
