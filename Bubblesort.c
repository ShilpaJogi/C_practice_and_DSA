#include<stdio.h>
int main()
{
    int i,j;
    int arr[] = {1,2,3,4,5,6};
    for(i = 0; i<6; i++)
    {
        for(j=i+1; j<6; j++)
        {
            if(arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}