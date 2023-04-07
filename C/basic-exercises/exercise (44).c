#include <stdio.h>
#include <locale.h>

void tempo(int s)
{
    int h, m;
    char *time, time_value[10];
    
    h = s / 3600;
    s %= 3600;
    m = s / 60;
    s %= 60;

    printf("O tempo em horas minutos e segundos é: %02d:%02d:%02d\n", h, m, s);
}


int main()
{
    setlocale(LC_ALL, "portuguese");

    int t;
    printf("Digite um tempo em segundos: ");
    scanf("%d", &t);
    
    tempo(t);

    while (getchar() != '\n')
        ;
    getchar();
    return 0;
}
