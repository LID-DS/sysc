/**
 * @file	sysc.c
 * @author	Dennis Kreussel <dnk0@protonmail.com>
 * @date 	14.06.2019
 * @version	0.1
*/ 

#include <linux/module.h>
#include <linux/fs.h>
#include <linux/kernel.h>

/* Device specific files
 */
#include <linux/genhd.h>
#include <linux/blkdev.h>

MODULE_AUTHOR("Dennis Kreussel <dnk0@protonmail.com>");

static int major_num 		= 0;

static int __init 
sysc_init(void)
{
	major_num = register_blkdev(major_num, "sysc");

	if (major_num < 0)
	{
		printk(KERN_ERR "SYSC: unable to get a major number");
		return -EBUSY;
	}

	return 0;
}

static void __exit
sysc_exit(void)
{
	unregister_blkdev(major_num, "sysc");
}

module_init(sysc_init);
module_exit(sysc_exit);
