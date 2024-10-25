#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/init.h>
#include<linux/fs.h>
#include<linux/kdev_t.h>
#include<linux/version.h>
#include<linux/types.h>

#define MINOR_COUNT	1
#define FIRST_MINOR	0


static dev_t dev; // in the variable dev the minor number whcih is allocated by the terminal is saved

MODULE_LICENSE("GPL");

static int __init blkfig_init(void)
{
	pr_info("My First Character Device Driver\n");

	int ret = alloc_chrdev_region(&dev,FIRST_MINOR,MINOR_COUNT,"blk");
	// this steps is wrote to allocated a major number to the device "blk"
	if (ret < 0)
	{
		pr_err("Failed to allocate Major Number\n");
		return ret;
	}
	pr_info("Major Number: blk: %d\n", MAJOR(dev));

	return 0;
}

void __exit blkfig_exit(void)
{
	pr_info("Bye from First Device Driver\n");

	unregister_chrdev_region(dev,MINOR_COUNT);
}

module_init(blkfig_init);
module_exit(blkfig_exit);
