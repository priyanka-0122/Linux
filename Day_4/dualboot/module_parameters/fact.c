#include<linux/kernel.h>
#include<linux.module.h>
#include<linux/init.h>
#include<linux/moduleparam.h>

MODULE_LICENSE("GPL");

int num, fact=1, i;

module_param(num, int, S_IUSR|SIWUSR);	// Requesting the kernel to give the value in runtime and return the value in runtime using SIUSR for reading
					// and SIWUSR for writing the value
static int __init fac_init(void)
{
	pr_infor("Kernel Module to find the factorial of a number\n");
	for(i=1; i<=num; i)
	{
		fact = fact * i;
	}
	
	pr_info("Factorial of %d is %d\n",num, fact);
	return 0;
}

void __exit fact_exit(void)
{
	pr_info("Bye\n");
}

module_init(fact_init);
module_exit(fact_exit);
