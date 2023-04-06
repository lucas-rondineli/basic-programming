#include <stdio.h>
#include <locale.h>

typedef struct
{
    char name[30];
    int points;
} team;

void clearBuffer()
{
    scanf("%*[^\n]");
    scanf("%*c");
}

int main()
{
    setlocale(LC_ALL, "portuguese");

    team teams[10];
    int bestTeam = 0, biggestP = 0;
    for (int i = 0; i < 10; i++)
    {
        printf("\nDigite o nome da equipe %d: ", i + 1);
        
        scanf("%29[^\n]", teams[i].name);

        printf("Quantos pontos a equipe %s fez? ", teams[i].name);
        scanf("%d", &teams[i].points);
        clearBuffer();
        
        if (teams[i].points > biggestP)
        {
            bestTeam = i;
            biggestP = teams[i].points;
        }
    }

    printf("A melhor equipe foi %s com %d pontos.", teams[bestTeam].name, teams[bestTeam].points);

    clearBuffer();
    getchar();
    return 0;
}
