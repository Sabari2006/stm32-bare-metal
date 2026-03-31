// ================= REGISTER ADDRESSES =================
#define RCC_AHB1ENR   (*(volatile unsigned int*)0x40023830)

#define GPIOD_MODER   (*(volatile unsigned int*)0x40020C00)
#define GPIOD_BSRR    (*(volatile unsigned int*)0x40020C18)

#define GPIOA_MODER   (*(volatile unsigned int*)0x40020000)
#define GPIOA_IDR     (*(volatile unsigned int*)0x40020010)

// ================= BIT DEFINITIONS =================
#define GPIODEN   (1U << 3)
#define GPIOAEN   (1U << 0)

#define PIN14     (1U << 14)
#define PIN0      (1U << 0)

#define LED_PIN   PIN14
#define BTN_PIN   PIN0

// ================= MAIN FUNCTION =================
int main(void)
{
    // 1. Enable clock for GPIOD and GPIOA
    RCC_AHB1ENR |= GPIODEN;
    RCC_AHB1ENR |= GPIOAEN;

    // 2. Configure PD14 as OUTPUT (01)
    GPIOD_MODER |=  (1U << 28);
    GPIOD_MODER &= ~(1U << 29);

    // 3. Configure PA0 as INPUT (00)
    GPIOA_MODER &= ~(1U << 0);
    GPIOA_MODER &= ~(1U << 1);

    // 4. Infinite loop
    while(1)
    {
        // Read button
        if(GPIOA_IDR & BTN_PIN)
        {
            // LED ON
            GPIOD_BSRR = LED_PIN;
        }
        else
        {
            // LED OFF
        	 GPIOD_BSRR = (1U << 30);

        }
    }
}
