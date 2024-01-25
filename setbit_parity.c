#include<stdio.h>
int main()
{
    int n,n1=0;
    printf("enter the number : ");
    scanf("%d", &n);
    while(n)
    {
        n1 += n & 1;
        n >>= 1;
        printf("n1 -> %d\t\n", n1);
         printf("n -> %d\t\n", n);
    }
    printf("number set bits ->%d\n", n1);
    if(n1 & 1)
    {
        printf("number odd");
    }
    else{
    printf("number even");
    }
    return 0;
}