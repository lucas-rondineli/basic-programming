#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");

    int i, tot = 0, sum = 0;

    for (i = 14; i <= 73; i += 2) 
    {
        sum += i;
        tot++;
    }
    
    printf("%.2f", (float) sum / tot);

    getchar();
    return 0;
}