//Write a function that takes two integers as input and swaps their values using pointers.

#include<stdio.h>

int swap(int *p1, int *p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

int main()
{
	int a, b;
	printf("Input the first number from the keyboard:");
	scanf("%d", &a);
	printf("Input the second number from the keyboard:");
	scanf("%d", &b);
	swap(&a,&b);
	printf("After swap number\n");
	printf("The first number is: %d\nThe second number is: %d",a,b);
}