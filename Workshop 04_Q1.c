#include<stdio.h>

float factorial(float n)
{
    float factor = 1.0;
    for(float i = 1.0; i <= n; i++)
    {
        factor = factor * i;
    }
    return factor;
}

float power(float x, float n)
{
    float pow = 1.0;
    for(float i = 1.0; i <= n; i++)
    {
        pow = pow * x;
    }
    return pow;
}

float myExp(float x, float n)
{
    float result = 0.0;
    for(float i = 1.0; i <= n; i++)
    {
        result = result + power(x, i) / factorial(i);
    }
    return result;
}

int main()
{
    float x, n;
    printf("Input x from the keyboard:");
    scanf("%f", &x);
    printf("Input n from the keyboard:");
    scanf("%f", &n);
    float S = myExp(x, n);
    printf("The result S = %f", S);
    return 0;
}
