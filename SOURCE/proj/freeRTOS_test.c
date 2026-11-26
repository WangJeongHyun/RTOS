#include "stm32f10x.h"
#include "FreeRTOS.h"
#include "task.h"

#include <stdio.h>
#include "stm32f10x.h"
#include "uart.h"
#include "led.h"
#include "key.h"
#include "fnd.h"
#include "cds.h"
#include "exti.h"

unsigned int gTickCount;

void TaskA(void *pvParameters)
{
	while(1)
	{
		if (key_is_pressed(KEY_LEFT))
		{
			printf("LEFT KEY PESSED \r\n");
		}
		else if (key_is_pressed(KEY_CENTER))
		{
			printf("CENTER KEY PESSED \r\n");
		}
		else if (key_is_pressed(KEY_RIGHT))
		{
			printf("RIGHT KEY PESSED \r\n");
		}
vTaskDelay(10);
	}
}
void TaskB(void *pvParameters)
{ 
	
	while(1)
	{
			static uint32_t n = 0;
			led_off_all();
			led_on(LED_0 + n);
			n = (n + 1) % 8;
	vTaskDelay(100);
	}
}

void TaskC(void *pvParameters)
{
	while(1)
	{
		uint32_t tick;
		uint32_t a0, a1, a2, a3;
		
		tick = xTaskGetTickCount();
		a3 = (tick / 10) % 10;
		a2 = (tick / 100) % 10;
		a1 = (tick / 1000) % 10;
		a0 = (tick / 10000) % 10;
		
		fnd_display_number(0, a0);
		vTaskDelay(5);
		
		fnd_display_number(1, a1);
		vTaskDelay(5);
		
		fnd_display_number(2, a2);
		vTaskDelay(5);

		fnd_display_number(3, a3);
		vTaskDelay(5);
	}
}

/*
void TaskD(void *pvParameters)
{

	while(1)
	{
		printf("CDS Value : %d \r\n", cds_get_value());
		vTaskDelay(200);
	}
}
*/
void TaskD(void *pvParameters)
{

	while(1)
	{
			printf("abcdef \r\n");	
			vTaskDelay(1);
	}
}
void TaskE(void *pvParameters)
{

	while(1)
	{
			printf("12345 \r\n");	
			vTaskDelay(1);
	}
}

void TaskE(void *pvParameters)
{

	while(1)
	{
		gTickCount = gTickCount +1 ;
		if(( gTickCount %1000000) ==0)
		{
			printf("%d \r\n", gTickCount /1000000);	
		}
		//vTaskDelay(1);
	}
}


void freeRTOS_test(void)
{
	xTaskCreate(TaskA,"TaskA",configMINIMAL_STACK_SIZE,NULL,tskIDLE_PRIORITY,NULL );
	xTaskCreate(TaskB,"TaskB",configMINIMAL_STACK_SIZE,NULL,tskIDLE_PRIORITY,NULL )