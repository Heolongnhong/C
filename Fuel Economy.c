#include<stdio.h>

void Calculating_Fuel_Economy(int *minutes,int *speed,float *gasoline, float *miles_per_gallon);
void Calculating_Distance_Traveled(float *radius,int *revolutions);
void Revised_Fuel_Economy_Calculation(float *radius,int *revolutions,float *gasoline, float *miles_per_gallon);

int main()
{
	int number, minutes, speed;
	float gasoline, miles_per_gallon;
	float radius;
	int revolutions;
	printf("1. Calculating_Fuel_Economy\n2. Calculating_Distance_Traveled\n3. Revised_Fuel_Economy_Calculation\n");
	scanf("%d",&number);
	switch (number)
	{
		
		case 1:
			Calculating_Fuel_Economy(&minutes, &speed, &gasoline, &miles_per_gallon);
			break;
		case 2:
			Calculating_Distance_Traveled(&radius, &revolutions);
			break;
		case 3:
			Revised_Fuel_Economy_Calculation(&radius, &revolutions, &gasoline, &miles_per_gallon);
			break;
		default:
            printf("Error! Finish program.");
            break;
			
	}
	
	return 0;
	
}

void Calculating_Fuel_Economy(int *minutes,int *speed,float *gasoline, float *miles_per_gallon)
{
	
	float hours, distance;
	printf("How many minutes did you drive?\n");
	scanf("%d", minutes);
	printf("What was the average speed of the car during that time?\n");
	scanf("%d", speed);
	printf("How many gallons of gas did your car use?\n");
	scanf("%f", gasoline);
	
	if (*minutes <= 0 || *speed <= 0 || *gasoline <= 0.0)
	{
		printf("Input wrong. Finish program.\n");
	}
	else
	{
		hours = *minutes / 60.0;
		distance = hours * *speed;
		*miles_per_gallon = distance / *gasoline;
	}
	printf("Your car averaged %.2f miles per gallon.\n", *miles_per_gallon);
	
}

void Calculating_Distance_Traveled(float *radius,int *revolutions)
{
	float exchange, traveled, diameter ;
	printf("What is the radius of your tires, in inches?\n");
	scanf("%f", radius);
	printf("How many revolutions did your car's tires make?\n");
	scanf("%d", revolutions);
	
	if (*radius <= 0.0 || *revolutions <= 0)
	{
		printf("Input wrong. Finish program.");
	}
	else
	{
		exchange = *radius / 63360.0;
		diameter = 2 * 3.142 * exchange;
		traveled = diameter * *revolutions;
	}
	printf("Your car traveled %.2f miles.", traveled);
	
}

void Revised_Fuel_Economy_Calculation(float *radius,int *revolutions,float *gasoline, float *miles_per_gallon)
{
	float exchange, traveled, diameter ;
	printf("What is the radius of your tires, in inches?\n");
	scanf("%f", radius);
	printf("How many revolutions did your car's tires make?\n");
	scanf("%d", revolutions);
	printf("How many gallons of gas did your car use?\n");
	scanf("%f", gasoline);
	
	if (*radius <= 0.0 || *revolutions <= 0 || *gasoline <= 0.0)
	{
		printf("Input wrong. Finish program.\n");
	}
	else
	{
		exchange = *radius / 63360.0;
		diameter = 2 * 3.142 * exchange;
		traveled = diameter * *revolutions;
		*miles_per_gallon = traveled / *gasoline;
	}
	printf("Your car averaged %.2f miles per gallon.\n", *miles_per_gallon);
	
}