#include "lm4f120h5qr.h"

#define RED_LED (1U << 1)
#define BLUE_LED (1U << 2)
#define GREEN_LED (1U << 3)

void delay(int val){      
    /* defined a function called delay and used while loop to count by increment method*/
      int start = 0;
      while(start < val){
        ++start;
      } 
}

int main()
{   
    SYSCTL_RCGCGPIO_R = (1U<<5);  /* Enabling PORTF register*/
    GPIO_PORTF_DIR_R = (RED_LED | BLUE_LED | GREEN_LED);   /* Setting direction Register to output*/
    GPIO_PORTF_DEN_R = (RED_LED | BLUE_LED | GREEN_LED);   /* Enabling the digital enable Register */
    while(1){
    GPIO_PORTF_DATA_R |= BLUE_LED;
    delay(1000000);
    GPIO_PORTF_DATA_R &= ~BLUE_LED;
    delay(1000000);
    GPIO_PORTF_DATA_R |= GREEN_LED;
    delay(1000000);
    }
}