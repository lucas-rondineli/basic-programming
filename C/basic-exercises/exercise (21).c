#include <stdio.h>

int main()
{
    short int n1 = 1, n2 = 0;

    for (int i = 0; i < 8; i++)
    {
        printf("%hd\n", n2);
        n1 += 2 * n2;
        n2 = n1 - n2;
        n1 = n1 - n2;
    }

    getchar();
    return 0;
}