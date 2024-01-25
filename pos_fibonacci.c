#include<stdio.h>
int main()
{
   int n, n1,n2,n3;
   printf("enter a number : ");
   scanf("%d", &n);
   if(n >= 0)
   {
    n1 = 0;
    n2 = 1;
        while(n1 <= n)
        {
            n3 = n1 + n2;
            printf("%d\t", n1);
            n1 = n2;
            n2 = n3;
        }
   }
   else{
    printf("Invalid input");
   }
   
}
