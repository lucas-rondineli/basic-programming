/*
Faça um programa para criar um arquivo ALUNOS.DAT, no qual
cada registro será composto pelos campos: numero, nome,
curso, nota1, nota2.
*/

#include <stdio.h>
#include <locale.h>

void clearBuffer()
{
    scanf("%*[^\n]");
    scanf("%*c");
}

int main(int argc, char **argv)
{
    setlocale(LC_ALL, "portuguese");

    FILE *file;
    file = fopen("ALUNOS.DAT", "wb");
    if (file == NULL)
    {
        printf("Erro.");
        return 1;
    }
    printf("Arquivo Criado com Sucesso.");

    fclose(file);
    if (getchar() != '\n')
        clearBuffer();
    return 0;
}
