#include "lm4f120h5qr.h"

void delay(int val)
{      
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
    GPIO_PORTF_DATA_R = value;
    delay(duration);
}
int main()
{
  setupPORTF(); //setting up PORT F register to RGB LED
  while(1){
    setLEDColor(2000000 , 0x02); // setting RED LED on by setting data to 0x0010
    setLEDColor(1000000 , 0x00); // setting all color LED to 0x0000 
    setLEDColor(4000000 , 0x04); // setting BLUE LED on by setting data to 0x0100
    setLEDColor(1000000 , 0x00); 
    setLEDColor(6000000 , 0x08); // setting GREEN LED on by setting data to 0x1000
    setLEDColor(1000000 , 0x00);        
  }
}