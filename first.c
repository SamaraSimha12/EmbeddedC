#include "stm32f4xx.h"  // Include the header for your specific microcontroller

// Delay function (simple for demonstration)
void delay(int count) {
    while (count--) {
        for (int i = 0; i < 1000; i++) {
            // Just waste time
        }
    }
}

int main(void) {
    // Enable the GPIOC clock (assuming the LED is connected to pin 13)
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;

    // Set GPIOC pin 13 as output (LED)
    GPIOC->MODER |= (1 << (13 * 2));  // Set pin 13 as output (02 in MODER register)

    while (1) {
        // Toggle the LED on PC13
        GPIOC->ODR ^= (1 << 13);  // Toggle the output data register

        // Wait for some time (delay)
        delay(500);
    }
}
