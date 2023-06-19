#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n, min, index_min;
	printf("Input the size of array: ");
	scanf("%d", &n);
	
	int *p = (int*) malloc(n*sizeof(int));
	
	printf("Input %d elements for the array: \n", n);
	for(int i = 0; i < n; i++)
	{
		printf("Input %d elements: ", i);
		scanf("%d", &p[i]);
	}
	
	for(int i = 0; i < n; i++)
	{
		min = p[i];
		index_min = i;
		for(int j = i + 1; j < n; j++)
		{
			if(min > p[j])
			{
				min = p[j];
				index_min = j;
			}
		}
		int temp = p[i];
		p[i] = p[index_min];
		p[index_min] = temp;
	}
	
	printf("The array after use selection sort: \n");
	for(int i = 0; i < n; i++)
	{
		printf("%d ", p[i]);
	}
	
	free(p);
}
