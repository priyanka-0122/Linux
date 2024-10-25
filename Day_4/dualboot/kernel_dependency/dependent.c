#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/init.h>

extern int a;
extern char *name;

MODULE_LICENSE("GPL");
MODULE_DESCIPTION("Dependent Module");
MODULE_AUTHOR("Priyanka");
MODULE_VERSION ("1.2");

static int __init dependent_init(void)
{
	pr_info("Welcome to Dependent Module\n"); //if pr_info is used then it is not needed to pass the info, error and warning to the kernel
	pr_info("Value of a = %d\n", a);
	pr_info("Name = %s\n", name);

	return 0;
}

// cleanup/exit function
void __exit independent_exit(void)
{
	pr_info("Bye from Dependent Module\n");
}

module_init(dependent_init);
module_exit(dependent_exit);
