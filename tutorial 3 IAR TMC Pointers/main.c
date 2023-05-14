int counter = 123;
int main()
{
  int *p_int;
  p_int = (int *)0x20000002u;
  *p_int = 0x12343237;
   return 0;
}
