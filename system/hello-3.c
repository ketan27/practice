#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/moduleparam.h>
#include <linux/stat.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Ketan Pant");

static short int myshort = 0;
static int myint = 0;
static long int mylong = 0;
static char* mystring = "empty";
static int myintArray[2] = {0, 0};
static int arr_argc = 0;

module_param(myshort, short, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
MODULE_PARM_DESC(myshort, "A short int");
module_param(myint, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
MODULE_PARM_DESC(myint, "An integer");
module_param(mylong, long, S_IRUSR);
MODULE_PARM_DESC(mylong, "A long integer");
module_param(mystring, charp, S_IRUSR);
MODULE_PARM_DESC(mystring, "A string type");
module_param_array(myintArray, int, &arr_argc, 0000);
MODULE_PARM_DESC(myintArray, "An integer type array");

static int __init hello_3_init(void)
{
    int i;
    printk(KERN_INFO "Hello world (3)\n");
    printk(KERN_INFO "myshort: %hd\n", myshort);
    printk(KERN_INFO "myint: %d\n", myint);
    printk(KERN_INFO "mylong: %ld\n", mylong);
    printk(KERN_INFO "mystring: %s\n", mystring);

    for (i = 0; i < (sizeof myintArray / sizeof(int)); ++i) {
        printk(KERN_INFO "myintArray[%d]: %d\n", i, myintArray[i]);
    }

    printk(KERN_INFO "Got %d args for array \n", arr_argc);

    return 0;
}

static void __exit hello_3_exit(void)
{
    printk(KERN_INFO "Goodbye world (3)\n");
}

module_init(hello_3_init);
module_exit(hello_3_exit);
