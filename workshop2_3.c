#include<stdio.h>
int main()
{
	int height;
	printf("Input the height of the pyramid from the keyboard: ");
	scanf("%d",&height);
	if (height <= 0)
	{
		printf("Wrong input. Finish program.");
	}
	else
	{
		for(int i = 1; i <= height; ++i)
		{
			for(int j = 1; j <= i; ++j)
			{
				printf("%d ",j);
			}
			printf("\n");
		}
	}	
}