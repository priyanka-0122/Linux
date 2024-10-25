#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/init.h>

MODULE_LICENSE("GPL");
MODULE_DESCIPTION("Independent Module");
MODULE_AUTHOR("Priyanka");
MODULE_VERSION ("1.2");

int a = 10;
char *name = "pavan";

EXPORT_SYMBOL(a);	//Macro used to make the above global variables to be available to other kernel modules
EXPORT_SYMBOL(name);

static int __init independent_init(void)
{
	pr_info("Welcome to Independent Module\n"); //if pr_info is used then it is not needed to pass the info, error and warning to the kernel
	pr_info("Value of a = %d\n", a);
	pr_info("Name = %s\n", name);

	return 0;
}

// cleanup/exit function
void __exit independent_exit(void)
{
	pr_info("Bye from independent Module\n");
}

module_init(independent_init);
module_exit(independent_exit);
