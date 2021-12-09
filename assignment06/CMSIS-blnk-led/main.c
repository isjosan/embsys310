// This program blinks LED1 in an infinite loop and uses CMSIS
#include "stm32l475xx.h"
#include "system_stm32l4xx.h"

const unsigned int DLY = 1000000;
    
void delay(unsigned int max_count);
    
int main(void)
{
   RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN; //Enable Clock Gating for GPIOA 
   GPIOA->MODER &= GPIO_MODER_MODE5_0; //Set PA5 for LED1 for OUTPUT 
  
  while(1)
  {
      
      GPIOA->ODR ^= GPIO_ODR_OD5; //Use XOR to toggle LED1
      delay(DLY);
      
  }
    
}

void delay(unsigned int max_count)
{
    unsigned int count = 0;
    
    for(count = 0; count < max_count ; ++count);
}  
