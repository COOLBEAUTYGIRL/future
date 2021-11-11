#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    int A, B;

    scanf("%d %d", &A, &B);

    while (A != 0 && B != 0)
    {
        scanf("%d %d, &A, &B");
        printf("%d\n", A+B);
    }
    return 0;
}