
#include "user_led.h"
#include "user_uart.h"
#include"user_os_kernal.h"

volatile int task_profile_a,task_profile_b,task_profile_c;
volatile int i=0;
void user_thread_a(void)
{
	while(1)
		{
			task_profile_a++;
			led_on();
			i=0;
			while(i<1000)
			{
				i++;
			}
				printf("led ON thread a running \n\r");

		}

}
void user_thread_b(void)
{
	while(1)
		{
			task_profile_b++;
			led_off();
			i=0;
			while(i<1000)
			{
				i++;
			}
				printf("led OFF task b running  \n\r");
		}

}
void user_thread_c(void)
{
	while(1)
		{
			task_profile_c++;
			led_on();
			i=0;
			while(i<1000)
			{
				i++;
			}
				printf("led ON task c running \n\r");

		}

}

int main()
{
	led_init();
	uart_tx_init();
	/*initialise the kernal*/
	os_kernel_init();
	/*add three threads*/
	os_kernal_add_thread(user_thread_a,user_thread_b,user_thread_c);
	/*set round robin time quanta*/
	os_kernal_lanch(10);//10 ms is set now

	while(1)
	{
		//the code is not supposed to come here
	}
}
