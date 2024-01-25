#include<stdio.h>
int main()
{
    int num, a, i, j, k;
    printf("enter the num: ");
    scanf("%d", &num);
    for (i = 1; i <= num; i++)
    {
        a = num - i;
        for (j = 1; j <= a; j++)
        {
        // printf("%d", a);
        }
        for (k = 1; k<=i; k++)
        printf("*");
        printf("\n");
    }
}