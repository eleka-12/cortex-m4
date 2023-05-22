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
void setupPORTF(){
    SYSCTL_RCGCGPIO_R = 0x20u;  /* Enabling PORTF register*/
    GPIO_PORTF_DIR_R = 0x0Eu;   /* Setting direction Register to output*/
    GPIO_PORTF_DEN_R = 0x0Eu;   /* Enabling the digital enable Register */
}

void setLEDColor(int duration , int value){
    GPIO_PORTF_DATA_R |= value;
    delay(duration);
}

void clearLEDColor(int duration , int value){
    GPIO_PORTF_DATA_R &= ~value;
    delay(duration);
}

int main()
{    
  setLEDColor(1000000,GREEN_LED);
  setupPORTF(); //setting up PORT F register to RGB LED
  while(1){
    setLEDColor(1000000 , GREEN_LED); // setting BLUE LED on by setting data to 0x0100
    clearLEDColor(1000000 , GREEN_LED); 
  }
}