#include <stdio.h>
#include <stdlib.h>
int main() {
	
	int x=25, *ptr=&x;
	printf("*ptr at %p\n", *ptr);
	printf("*ptr++ at %p\n", *ptr++);	
	
	printf("*ptr at %p\n", *ptr);
	printf("*__*++ptr at %p\n", *++ptr);
	
	printf("*ptr at %p\n", *ptr);	
	// printf("*___++*ptr at %p\n", ++(*ptr));
	
	printf("*ptr at %p\n", *ptr);	
	printf("*____(*ptr)++ at %p\n", (*ptr)++);	
	printf("*ptr at %p\n", *ptr);
	return 0;
	
}