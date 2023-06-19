#include<stdio.h>
float calculate_area(float radius,float PI);
int perfect_square(int number);
int power(int a, int n);
int main()
{
	int a,n;
	power(a, n);
	
	float radius, PI=3.14159;
	printf("Input radius from the keyboard: ");
	scanf("%f",&radius);
	calculate_area(radius, PI);
	float result = calculate_area(radius, PI);
	if (result == -1.0)
	{
		printf("Invalid.");
	}
	else
	{
		printf("The result is: %.5f\n",result);
	}
	
	int number;
	printf("Input the number from the keyboard: \n");
	scanf("%d",&number);
	perfect_square(number);
	int check = perfect_square(number);
	if (check == 0)
	{
		printf("It is not a perfect square.");
	}
	else
	{
		printf("It is a perfect square.");
	}
	

}

int power(int a, int n) {
    int result = 1;
    for (int i = 0; i < n; i++) {
        result *= a;
    }
    return result;
}

float calculate_area(float radius,float PI)
{
	float area;
	if (radius <= 0)
	{
		return -1.0;
	}
	else
	{
		area = PI * (radius * radius);
		return area;
	}
}

int perfect_square(int number)
{
	if (number <= 0)
	{
		return 0;
	}
	else 
	{
		for(int i = 1; i <= number/2; i++)
		{
			if (number == i*i)
			{
				return 1;
			}
		}
		return 0;
	}
}