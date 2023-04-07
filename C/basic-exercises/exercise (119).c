/*
Faça um programa para consultar o número, nome e a média
de todos os alunos cadastrados no arquivo do Exercício 1.
*/

#include <stdio.h>
#include <string.h>
#include <locale.h>

void clearBuffer()
{
    scanf("%*[^\n]");
    scanf("%*c");
}

typedef struct
{
    int number;
    char name[30];
    char course[30];
    float grade1;
    float grade2;
} tStudent;

int main(int argc, char **argv)
{
    setlocale(LC_ALL, "portuguese");

    FILE *file;
    file = fopen("ALUNOS.DAT", "rb+");
    if (file == NULL)
    {
        printf("Erro abrindo o arquivo.");
        if (getchar() != '\n')
            clearBuffer();
        return 1;
    }

    // Encontra a quantidade total de alunos armazenados no arquivo
    // Caso não haja nenhum, sai do programa
    fseek(file, 0, SEEK_END);
    int totalInFile = ftell(file) / sizeof(tStudent);
    fseek(file, 0, SEEK_SET);
    if (totalInFile < 1)
    {
        printf("Não há estudantes para serem listados.");
        fclose(file);
        if (getchar() != '\n')
            clearBuffer();
        return 1;
    }

    // Mostra os alunos na tela
    printf("No  | Nome                          | Curso                         | Média\n");
    tStudent student;
    for (int i = 0; i < totalInFile; i++)
    {
        fread(&student, sizeof(tStudent), 1, file);
        printf("%-03d | %-30s| %-30s|%7.2f\n", student.number, student.name, student.course, (student.grade1 + student.grade2) / 2);
    }

    fclose(file);
    if (getchar() != '\n')
        clearBuffer();
    return 0;
}
