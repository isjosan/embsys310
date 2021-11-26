/* This program blinks my first name 'IQBAL' in Morse Code on LED1 */
#define RCC_BASE 0x40021000 /*RCC (Reset and Clock Control) Register Base Address */
#define RCC_AHB2ENR (RCC_BASE + 0x4C) /* Peripheral Clock Enable Register Address*/
#define GPIOA_BASE 0x48000000 /* GPIOA Base Address */
#define GPIOA_MODER GPIOA_BASE /* GPIOA Port Mode Register Address */
#define GPIOA_ODR (GPIOA_BASE + 0x14) /* GPIOA Port Output Data Register */
#define RCC_AHB2ENR_DATA 0x00000001 /* Reset Value: 0x00000000 */
#define GPIOA_MODER_DATA 0xFFFFF7FF /* Reset Value: 0xABFFFFFF */
#define GPIOA_ODR_LED_DATA 0x00000020 /* Reset Value: 0x00000000 */
#define GPIOA_ODR_LED_CLR_DATA 0x00000000

const unsigned int UNIT_DLY = 500000;

void delay(unsigned int max_count);
void dotnspace(void);
void dashnspace(void);

int main(void)
{
  *((unsigned int*)RCC_AHB2ENR) |= RCC_AHB2ENR_DATA; /* Enable Clock Gating for GPIOA */
  *((unsigned int*)GPIOA_MODER) &= GPIOA_MODER_DATA; /* Set PA5 for LED1 for OUTPUT */

/* The following while loop encodes my first name 'IQBAL' in Morse Code, as per the International Morse Code standard. 
   Characters to be transmitted in Morse Code: IQBAL   
   Each dot is a UNIT_DLY with LED1 ON;
   Each dash is  3 * UNIT_DLY with LED1 ON;
   Each space is a UNIT_DLY with LED1 OFF;
   Space between parts of the same letter is a UNIT_DLY with LED1 OFF.
   Space between letters is 3 * UNIT_DLY with LED1 OFF;
   Space between words is 7 * UNIT_DLY with LED1 OFF;
   
   Morse Code Encoding is shown below in parenthesis for reference:
    I(dot space dot space) Q(space space dash space dash space dot space dash space) \
    B(space space dash space dot space dot space dot space) A(space space dot space dash space) \
    L(space space dot space dash space dot space dot space) (space space space space space space) 
*/
  while(1)
  {
      *((unsigned int*)GPIOA_ODR) ^= GPIOA_ODR_LED_CLR_DATA; /* Ensure LED1 is OFF */
      /* Transmit 'I' and space*/
      dotnspace();
      dotnspace();
      /* Transmit 2 more spaces, 'Q' and space*/
      delay(2 * UNIT_DLY);
      dashnspace();
      dashnspace();
      dotnspace();
      dashnspace();
      /* Transmit 2 more spaces,'B' and space */
      delay(2 * UNIT_DLY);
      dashnspace();
      dotnspace();
      dotnspace();
      dotnspace();
      /* Transmit 2 motre spaces,'A' and space*/
      delay(2 * UNIT_DLY);
      dotnspace();
      dashnspace();
      /* Transmit 2 more spaces, 'L' and space */
      delay(2 * UNIT_DLY);
      dotnspace();
      dashnspace();
      dotnspace();
      dotnspace();
      /* Transmit 6 more spaces to compensate for total of 7 spaces between words */ 
      delay(6 * UNIT_DLY);
  }
}

void delay(unsigned int max_count)
{
    unsigned int count = 0;
    
    for(count = 0; count < max_count ; ++count);
}

void dotnspace(void)
{
    *((unsigned int*)GPIOA_ODR) ^= GPIOA_ODR_LED_DATA; /* Begin Transmit 'dot' - Toggle to Turn LED1 ON */
    delay(UNIT_DLY);                                   /* length of a dot is one unit */
    *((unsigned int*)GPIOA_ODR) ^= GPIOA_ODR_LED_DATA; /* End Transmit 'dot' - Toggle to Turn LED1 OFF */
    delay(UNIT_DLY);                                   /* Space between this element and the next */
}

void dashnspace(void)
{
    *((unsigned int*)GPIOA_ODR) ^= GPIOA_ODR_LED_DATA; /* Begin Transmit 'dasht' - Toggle to Turn LED1 ON */
    delay(3 * UNIT_DLY);                               /* length of a dash is 3 units */
    *((unsigned int*)GPIOA_ODR) ^= GPIOA_ODR_LED_DATA; /* End Transmit 'dash' - Toggle to Turn LED1 OFF */
    delay(UNIT_DLY);                                   /* Space between this element and the next */
}        
