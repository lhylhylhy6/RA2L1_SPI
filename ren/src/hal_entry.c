/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author        Notes
 * 2021-10-10     Sherman       first version
 */
#include <rtthread.h>
#include "hal_data.h"
#include <rtdevice.h>

#define LED1_PIN    "P502" /* Onboard LED pins */
#define USER_INPUT  "P104"//"P004"

rt_uint32_t led_blu;
void touch_button_callback(uint64_t status)
{
    if (status)
    {
        rt_pin_write(led_blu, PIN_HIGH);
    }
    else
    {
        rt_pin_write(led_blu, PIN_LOW);
    }
}

struct rt_spi_device *my_spi;
void spi_test(void *parameter)
{
    my_spi = (struct rt_spi_device *)malloc(sizeof(struct rt_spi_device));
	
	if(!my_spi)
		rt_kprintf("error\n");
    rt_spi_bus_attach_device(my_spi,"spi01","spi0",(int *)0x01);
	
    my_spi = (struct rt_spi_device *)rt_device_find("spi01");

	struct rt_spi_configuration cfg;
    cfg.data_width = 8;
    cfg.mode = RT_SPI_MASTER | RT_SPI_MODE_0 | RT_SPI_MSB;
    cfg.max_hz = 20 * 1000 *1000;
	
    rt_spi_configure(my_spi,&cfg);
	
    rt_spi_send(my_spi,"abcde\n",7);
}

void hal_entry(void)
{
    rt_kprintf("\nHello RT-Thread!\n");

    led_blu = rt_pin_get("P501");
    rt_uint32_t led1_pin = rt_pin_get(LED1_PIN);
	spi_test(NULL);
    while (1)
    {
		rt_spi_send(my_spi,"abcde\n",7);
        rt_pin_write(led1_pin, PIN_HIGH);
        rt_thread_mdelay(500);
        rt_pin_write(led1_pin, PIN_LOW);
        rt_thread_mdelay(500);
    }
}

void irq_callback_test(void *args)
{
   // rt_kprintf("\n IRQ03 triggered \n");
}

int icu_sample(void)
{
    /* init */
    rt_uint32_t pin = rt_pin_get(USER_INPUT);
    rt_kprintf("\n pin number : 0x%04X \n", pin);
    rt_err_t err = rt_pin_attach_irq(pin, PIN_IRQ_MODE_RISING, irq_callback_test, RT_NULL);
    if (RT_EOK != err)
    {
        rt_kprintf("\n attach irq failed. \n");
    }
    err = rt_pin_irq_enable(pin, PIN_IRQ_ENABLE);
    if (RT_EOK != err)
    {
        rt_kprintf("\n enable irq failed. \n");
    }
	return RT_EOK;
}
// MSH_CMD_EXPORT(icu_sample, icu sample);
INIT_APP_EXPORT(icu_sample);
