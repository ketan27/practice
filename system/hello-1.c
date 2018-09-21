/*
 * hello-1.c
 * This is for kernel module code. Intention is to learn how kernel module compilation works and 
 * this is doing nothing but just printing hello world.
 */

#include <linux/module.h>
#include <linux/kernel.h>

int init_module(void)
{
    printk(KERN_INFO "Hello, world!! \n");

    return 0;
}

void cleanup_module(void)
{
    printk(KERN_INFO "Goodbye world!!\n");
}
