//Write a function that takes an array of integers and the size of the array, then calculates the sum and average of the elements in the array and returns the results through pointers.

#include<stdio.h>
#include<stdlib.h>

int average(int size, int *p, float *aver)
{
	int sum = 0;

	for(int i = 0; i < size; i++)
	{
		sum = sum + p[i];
	}
	 
	*aver = (float)sum / size;
	
}

int main()
{
	int n;
	float aver;
	printf("Input the size of array:");
	scanf("%d",&n);
	int *p = (int *) malloc(n*sizeof(int));
	printf("Input elements of array:\n");
	for(int i = 0; i < n; i++)
	{
		printf("Element %d:", i);
		scanf("%d",&p[i]);
	}
	
	average(n, p, &aver);
	printf("The average of array is:%.2f", aver);
	
	free(p);
}
	