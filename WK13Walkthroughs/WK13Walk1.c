/*-------------------------------------------------
// Walkthrough Practice Question-1
-------------------------------------------------*/

#include<stdio.h>

float getNumber(int num)
{
    int x = 4;
    float f = 0.2f;

    return (num * x) + f;
}

int main(void)
{
    int i, count = 5;

    for (i = 0; i < count; i++) {
        printf("%d: %.1f\n", i + 1, getNumber(i));
    }

    return 0;
}
