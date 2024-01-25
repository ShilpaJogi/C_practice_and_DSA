#include <stdio.h>
int print_bits(int num, int n);  //function prototype
int print_bits(int num, int n)
{
    for ( int i = n - 1; i >= 0; i--)    //running the loop
    {
	if ((num >> i) & 1)    //condition to print n bits
	    printf(" 1 ");
	else
	    printf(" 0 ");
    }
}
int main()
{
    int num, n;   //variable declaration

    printf("Enter the number: ");  //read the number from user
    scanf("%d", &num); 
    printf("Enter the number of bits: ");    //read the number of bits from user
    scanf("%d", &n);

    printf("Binary form of %d: ", num);   //print the binary form 
    print_bits(num, n);   //function callling
}
