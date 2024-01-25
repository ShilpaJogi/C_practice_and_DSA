#include <stdio.h>
func(int a, int b);
int main() {
   int a=10, b=3;
   func(a, b);
   return 0;
}
func(int a, int b)
{
   int c;
   c = a + b;
   printf("print c value = %d", c);
   return c;
}