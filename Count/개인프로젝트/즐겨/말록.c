#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>
#define _CRT_SECUTE_NO_WARNINGS

int main()
{
    int num1;
    int num2;

    int *numPtr1 = malloc(sizeof(10));
    int *numPtr2 = malloc(sizeof(20));

    scanf("%d %d", &num1, &num2);

    *numPtr1 = num1;
    *numPtr2 = num2;

    printf("%d\n", *numPtr1 + *numPtr2);

    free(numPtr1);
    free(numPtr2);

    return 0;
}