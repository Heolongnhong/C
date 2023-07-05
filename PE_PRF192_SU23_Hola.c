#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 1000

int question1(int number1, int number2);
int question2(int number);
char* question3(char* character);
int* question4(int* array);
int question5(int* array, int size);
char** question6(char character[][100]);
char* question7(char* s);

int main()
{
    int choice;

    while (1)
    {
        printf("    === MENU ===\n");
        printf("1. Compare two integer numbers\n");
        printf("2. Sum of even numbers from 0 to n\n");
        printf("3. Sort characters following alphabetical order\n");
        printf("4. Use selection sort to sort elements of an array\n");
        printf("5. Check if an array is symmetric\n");
        printf("6. Sort person names\n");
        printf("7. Print middle 5 characters of a string\n");
        printf("8. Quit program\n");
        printf("====================================\n");
        printf("Please input your choice from the keyboard: ");
        scanf("%d", &choice);
        getchar(); // Consume the newline character after reading the choice
        switch (choice)
        {
            case 1:
            {
                int number1, number2;
                printf("Input the first number from the keyboard: ");
                scanf("%d", &number1);
                printf("Input the second number from the keyboard: ");
                scanf("%d", &number2);
                int result = question1(number1, number2);
                if (result == 1)
                {
                    printf("Number 1 is greater than number 2.\n");
                }
                else if (result == 0)
                {
                    printf("Number 1 is equal to number 2.\n");
                }
                else
                {
                    printf("Number 1 is less than number 2.\n");
                }
                printf("\n");
                break;
            }
            case 2:
            {
                int number;
                printf("Input a non-negative number from the keyboard: ");
                scanf("%d", &number);
                int result = question2(number);
                if (result == 0)
                {
                    printf("Input is invalid.\n");
                }
                else
                {
                    printf("The sum of even numbers in the range from 0 to %d is: %d\n", number, result);
                }
                printf("\n");
                break;
            }
            case 3:
            {
                char character[5];
                printf("Input 4 characters from the keyboard: \n");
                for (int i = 0; i < 4; i++)
                {
                    scanf(" %c", &character[i]);
                }
                char* result = question3(character);
                for (int i = 0; i < 4; i++)
                {
                    printf("%c ", result[i]);
                }
                printf("\n");
                free(result); // Free the dynamically allocated memory
                break;
            }
            case 4:
            {
                int array[7];
                printf("Input 7 integer numbers from the keyboard: \n");
                for (int i = 0; i < 7; i++)
                {
                    scanf("%d", &array[i]);
                }
                question4(array);
                printf("The array after sorting: \n");
                for (int i = 0; i < 7; i++)
                {
                    printf("%d ", array[i]);
                }
                printf("\n");
                break;
            }
            case 5:
            {
                int size;
                printf("Please input the size of the array to check symmetry: ");
                scanf("%d", &size);
                int* array = (int*)calloc(size, sizeof(int));
                for (int i = 0; i < size; i++)
                {
                    printf("Element %d:", i);
                    scanf("%d", &array[i]);
                }
                int result = question5(array, size);
                if (result == 1)
                {
                    printf("This is a symmetric array.\n");
                }
                else
                {
                    printf("This is not a symmetric array.\n");
                }
                free(array);
                printf("\n");
                break;
            }
            case 6:
            {
                char character[5][100];
                printf("Input 5 person names from the keyboard:\n");
                getchar(); // Consume the newline character before fgets
                for (int i = 0; i < 5; i++)
                {
                    fgets(character[i], sizeof(character[i]), stdin);
                }
                char** result = question6(character);
                printf("Sorted array of names: ");
                for (int i = 0; i < 5; i++)
                {
                    printf("%s ", result[i]);
                }
                printf("\n");
                for (int i = 0; i < 5; i++)
                {
                    free(result[i]);
                }
                free(result);
                break;
            }
            case 7:
            {
                char s[MAXN];
                printf("Input the string: ");
                fgets(s, sizeof(s), stdin);
                s[strcspn(s, "\n")] = '\0';
                char* result = question7(s);
                printf("Result substring: %s\n", result);
                free(result);
                break;
            }
            case 8:{
				printf("Exting program. Have a good day.");
                return 0;
			}	
            default :{
            	printf("Input invalid. Please input your choice again.\n");
			}
        }
    }

    return 0;
}

int question1(int number1, int number2)
{
    if (number1 > number2)
    {
        return 1;
    }
    else if (number1 == number2)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

int question2(int number)
{
    int sum = 0;
    if (number < 0)
    {
        return sum;
    }
    else
    {
        for (int i = 0; i <= number; i++)
        {
            if (i % 2 == 0)
            {
                sum += i;
            }
        }
        return sum;
    }
}

char* question3(char* character)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (character[i] < character[j])
            {
                char temp = character[i];
                character[i] = character[j];
                character[j] = temp;
            }
        }
    }
    return character;
}

int* question4(int* array)
{
    int min, index_min;
    for (int i = 0; i < 7; i++)
    {
        min = array[i];
        index_min = i;
        for (int j = i + 1; j < 7; j++)
        {
            if (array[j] < min)
            {
                min = array[j];
                index_min = j;
            }
        }
        int temp = array[i];
        array[i] = array[index_min];
        array[index_min] = temp;
    }
    return array;
}

int question5(int* array, int size)
{
    for (int i = 0; i < size / 2; i++)
    {
        if (array[i] != array[size - i - 1])
        {
            return 0;
        }
    }
    return 1;
}

char** question6(char character[][100])
{
    char** sortedArray = malloc(5 * sizeof(char*));
    for (int i = 0; i < 5; i++)
    {
        sortedArray[i] = malloc(100 * sizeof(char));
        strcpy(sortedArray[i], character[i]);
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            if (strcmp(sortedArray[i], sortedArray[j]) > 0)
            {
                char temp[100];
                strcpy(temp, sortedArray[i]);
                strcpy(sortedArray[i], sortedArray[j]);
                strcpy(sortedArray[j], temp);
            }
        }
    }
    return sortedArray;
}

char* question7(char* s)
{
    int n = strlen(s);
    char* result = malloc(6 * sizeof(char));

    for (int i = n / 2 - 2; i <= n / 2 + 2; i++)
    {
        result[i - (n / 2 - 2)] = s[i];
    }
    result[5] = '\0';

    return result;
}
