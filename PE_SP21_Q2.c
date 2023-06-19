#include<stdio.h>
int factorial(int number);
int main()
{
	int number;
	printf("Input the number from the keyboard: ");
	scanf("%d",&number);
	int check = factorial(number);
	if(check == 0)
	{
		printf("Input wrong.");
	}
	else
	{
		printf("The result of (%d + 1)! is: %d",number,check);
	}
}
int factorial(int number)
{
	int n = number + 1;
	if(n <= 0)
	{
		return 0;
	}
	else
	{
		for(int i = 1; i <= number; i++)
	{
		n = n * i;
	}
		return n;
	}
}