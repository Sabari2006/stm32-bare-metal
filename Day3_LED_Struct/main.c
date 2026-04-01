typedef struct
{
    volatile unsigned int MODER;
    volatile unsigned int OTYPER;
    volatile unsigned int OSPEEDR;
    volatile unsigned int PUPDR;
    volatile unsigned int IDR;
    volatile unsigned int ODR;
    volatile unsigned int BSRR;
} GPIO_TypeDef;

#define RCC_AHB1ENR (*(volatile unsigned int*)0x40023830)
#define GPIOD ((GPIO_TypeDef*)0x40020C00)

#define GPIODEN (1U << 3)
#define LED_PIN (1U << 14)

int main(void)
{
    RCC_AHB1ENR |= GPIODEN;

    GPIOD->MODER |=  (1U << 28);
    GPIOD->MODER &= ~(1U << 29);

    while(1)
    {
        GPIOD->BSRR = LED_PIN;

        for (volatile int i = 0; i < 100000; i++);

        GPIOD->BSRR = (LED_PIN << 16);

        for (volatile int i = 0; i < 100000; i++);
    }
}
