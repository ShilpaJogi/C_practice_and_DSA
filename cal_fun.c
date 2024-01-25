#include<stdio.h>
#define bitset(num, n)  ((num) |= (1<<n))
int main()
{
  int a=10;
  a=a++;
  a=a++ * a--;
printf("a = %d\n", a);
printf("a = %d\n", a++ * a++);
  
}