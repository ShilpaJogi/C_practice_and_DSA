#include<stdio.h>
int main()
{
    int num, N,M;
    printf("enter the num :");
    scanf("%d", &num);
    printf("enter the num to set :");
    scanf("%d", &N);
    printf("enter the num to clear:");
    scanf("%d", &M);
    if(num >> N & 1)
    {
        num = num & (~(1 << M));
        printf("num is %d", num);
    }
    else
    {
        printf("num is %d", num);
    }
return 0;
}