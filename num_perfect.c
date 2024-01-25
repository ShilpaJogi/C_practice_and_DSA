#include<stdio.h>
int main()
{
    int num,i,sum=0;
    printf("enter the number : ");
    scanf("%d", &num);
    if(num < 0)
    {
        printf("inavlid,positive number only");
    }
    else
    {
        for(i = 1; i < num; i++)
        {
            if(num % i == 0)
            sum = sum + i;
        }
        if(sum == num)
        {
            printf("entered num is perfect");
        }
        else
        {
            printf("enter num is not perfect");
        }
    return 0;
    }
}