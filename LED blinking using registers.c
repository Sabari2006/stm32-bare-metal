#include "stm32f4xx.h"

#define GPIODEN    (1U << 3)
#define PIN14      (1U << 14)
#define LED_PIN     PIN14

int main(void)
{

    RCC->AHB1ENR |= GPIODEN;


    GPIOD->MODER  |=  (1U << 28);
    GPIOD->MODER  &= ~(1U << 29);

    while(1)
    {
    	while(1)
    	{
    	    GPIOD->BSRR = LED_PIN;

    	    for (volatile int i = 0; i < 100000; i++);

    	    GPIOD->BSRR = (1U << 29);

    	    for (volatile int i = 0; i < 100000; i++);
    	}
    }
}
