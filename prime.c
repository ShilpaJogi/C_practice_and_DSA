#include<stdio.h>
int main()
{
    int num;
    int i, j;
    printf("enter the number : ");
    scanf("%d", &num);
    if(num > 1)
    {
         int arr[num];
        if(num > 0)
        {
           
            for(i = 1; i < num; i++)
            {
                arr[i] =i + 1;
            }
            for(i = 1; i < num; i++)
            {
                if(arr[i] != 0)
                {
                    for(j = arr[i] * arr[i]; j <= num; j += arr[i])
                    {
                        arr[j - 1]=0;
                    }
                }
            }
           printf("prime num are -> ");
            for(i=1; i<num; i++)
            {
                if(arr[i] != 0)
                
                {
                printf("%d\t", arr[i]);
                }
            }
        }
         
    }
    return 0;
}