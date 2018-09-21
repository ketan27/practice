/*
 * hello-2.c - The second kernel module that doens't have init_module and
 * cleanup_module. Instead we'll use macros module_init and module_exit
 */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

static int __init hello_2_init(void)
{
    printk(KERN_INFO "Hello world, 2\n");

    return 0;
}

static void __exit hello_2_exit(void)
{
    printk(KERN_INFO "Goodbye world, 2\n");
}

module_init(hello_2_init);
module_exit(hello_2_exit);

