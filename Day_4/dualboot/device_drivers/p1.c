#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/init.h>
#include<linux/types.h>
#include<linux/fs.h>
#include<linux/slab.h>		//memory allocation
#include<linux/uaccess.h>	//copy_to_usr, copy_frm_usr
#include<linux/err.h>

#define mem_size 1024

// Global variables
static dev_t dev;

static struct class *dev_class;
static struct cdev etx_cdev;
uint8_t *kernel_buffer;

static int __init etx_driver_init(void);
static void __exit etx_driver_exit(void);
static int etx_open(struct inode *inode, struct file *file);
static int etx_release(struct inode *inode, struct file *file);
static ssize_t etx_read(struct file *filp, char __user *buf, size_t len, loff_t *off);
static ssize_t etx_write(struct file *filp, const char __user *buf, size_t len, loff_t *off);

// File structure operations
static struct file_operations fops = {
	.owner=THIS_MODULE,
	.read=etx_read,
	.write=etx_write,
	.open=etx_open,
	.release=etx_release
};

static int etx_open(struct inode *inode, struct file *file)
{
	pr_info("Device File Opened\n");
	return 0;
}

static etx_release(struct inode *inode, struct file *file)
{
	pr_info("Device File Closed\n");
	return 0;
}

static ssize_t etx_read(struct file *filp, char __user *buf, size_t len, loff_t *off)
{
	if(copy_to_user(buf, kernel_buffer, mem_size))
	{
		pr_info("Data Read: Err!\n");
	}
	pr_info("Data Read: Done!\n");
	return mem_size;
}


