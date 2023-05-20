  void delay(int val){
      int start = 0;
      while(start < val){
        ++start;
      }
    }

int main()
{
  *((unsigned int *) 0x400FE608U) = 0x20u;
  *((unsigned int *) 0x40025400U) = 0x0Eu;
  *((unsigned int *) 0x4002551CU) = 0x0Eu;
  while(1){
    delay(1000000);
    *((unsigned int *) 0x400253FCU) = 0x02u;
    delay(1000000);
    *((unsigned int *) 0x400253FCU) = 0x00u;
    delay(1000000);
    *((unsigned int *) 0x400253FCU) = 0x04u;
    delay(1000000);
    *((unsigned int *) 0x400253FCU) = 0x00u;
    delay(1000000);
    *((unsigned int *) 0x400253FCU) = 0x08u;
    delay(1000000);
    *((unsigned int *) 0x400253FCU) = 0x00u;
  }
}