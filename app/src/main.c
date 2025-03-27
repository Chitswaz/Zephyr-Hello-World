#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>

void main(void)
{
    printk("Hello World from Zephyr!\n");
    while (1) {
        k_msleep(1000);
        printk("Running...\n");
    }
}