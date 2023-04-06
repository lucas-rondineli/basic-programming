#include <stdio.h>

int main()
{
    short unsigned int tot = 0;
    for (int i = 0; i < 98; i += 2)
    {
        printf("%d + ", i);
        tot += i;
    }
    tot += 98;
    printf("98 = %hu", tot);

    getchar();
    return 0;
}