#include <stdio.h>

int func(int n)
{
    if (n == 0)
        return 2;
    else
    {
        return func(n - 1) + 4;
    }
}

int main(void)
{
    printf("%d", func(5));
    return 0;
}