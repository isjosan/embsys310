/* This program blinks LED1 in an infinite loop */
#define RCC_BASE 0x40021000 /*RCC (Reset and Clock Control) Register Base Address */
#define RCC_AHB2ENR (RCC_BASE + 0x4C) /* Peripheral Clock Enable Register Address*/
#define GPIOA_BASE 0x48000000 /* GPIOA Base Address */
#define GPIOA_MODER GPIOA_BASE /* GPIOA Port Mode Register Address */
#define GPIOA_ODR (GPIOA_BASE + 0x14) /* GPIOA Port Output Data Register */
#define RCC_AHB2ENR_DATA 0x00000001 /* Reset Value: 0x00000000 */
#define GPIOA_MODER_DATA 0x00000400 /* Reset Value: 0xABFFFFFF */
#define GPIOA_ODR_LED_DATA 0x00000020 /* Reset Value: 0x00000000 */
#define GPIOA_ODR_LED_CLR_DATA 0x00000000
#define BASE_PERIPH_ALIAS  0x42000000 /* Base Address of Peripheral bit-band alias memory region */
#define GPIOA_CLK_ENABL  (BASE_PERIPH_ALIAS + (0x2104C * 32) + (0 * 4)) /* GPIO CLK ENABLE BIT WORD ADDRESS */


const unsigned int DLY = 1000000;

void delay(unsigned int max_count);

void main(void)
{
  *((unsigned int*)GPIOA_CLK_ENABL) = 0x1; /* Enable Clock Gating for GPIOA with GPIO CLK ENABLE BIT WORD ADDRESS */
  //*((unsigned int*)RCC_AHB2ENR) |= RCC_AHB2ENR_DATA; /* Enable Clock Gating for GPIOA */
  *((unsigned int*)GPIOA_MODER) &= GPIOA_MODER_DATA; /* Set PA5 for LED1 for OUTPUT */
  
  while(1)
  {
      *((unsigned int*)GPIOA_ODR) ^= GPIOA_ODR_LED_DATA; /* Use XOR to toggle LED1 (ON)*/
      delay(DLY);
      
      *((unsigned int*)GPIOA_ODR) ^= GPIOA_ODR_LED_DATA; /* Use XOR to toggle LED1 (OFF) */
      delay(DLY);
  }  
}

void delay(unsigned int max_count)
{
    unsigned int count = 0;
    
    for(count = 0; count < max_count ; ++count);
}

