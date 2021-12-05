// This program blinks LED1 in an infinite loop and uses SysTick Handler to decrement delay duration in milliseconds
#include "stm32l475xx.h"
#include "system_stm32l4xx.h"
#include "delay.h"
#include <stdint.h>

#define SYS_CLOCK_HZ 4000000u   // Default clock after startup
                                // Section 3.11 in STM32L475 datasheet DS10969
#define DLY_MILLISEC 1000u

uint32_t delayInMilliseconds = 0;

void SysTick_Initialize(void);

void main(void)
{
   RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN; //Enable Clock Gating for GPIOA 
   GPIOA->MODER &= GPIO_MODER_MODE5_0; //Set PA5 for LED1 for OUTPUT 
   
   SysTick_Initialize();
   
  while(1)
  {
      
      GPIOA->ODR ^= GPIO_ODR_OD5; //Use XOR to toggle LED1
      delayInMilliseconds = DLY_MILLISEC;
      delay(delayInMilliseconds);
      
  }
}

void SysTick_Initialize(void)
{
    SysTick->LOAD = (SYS_CLOCK_HZ / 1000) - 1;       // 0xE000E014 - Counts down to 0.
    SysTick->VAL = 0x0;                              // 0xE000E018 - Clears initial value
    SysTick->CTRL = 0x7;                             // 0xE000E010 - Enable interrupts
}

void SysTick_Handler(void)
{
    --delayInMilliseconds;
}



