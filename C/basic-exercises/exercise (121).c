/*
Faça um programa para consultar o numero, nome e o curso de
todos os alunos cadastrados no Exercício 1 e que estejam
reprovados (media < 5).
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

    // Teste se existe algum aluno que cumpra o requisito de média menor que 5
    // Caso não haja nenhum, sai do programa
    tStudent student;
    int i = 0;
    for (i; i < totalInFile; i++)
    {
        fread(&student, sizeof(tStudent), 1, file);
        if ((student.grade1 + student.grade2) / 2 < 5)
            break;
    }
    if (i == totalInFile)
    {
        printf("Não há estudantes para serem listados.");
        fclose(file);
        if (getchar() != '\n')
            clearBuffer();
        return 1;
    }
    fseek(file, 0, SEEK_SET);

    // Mostra os alunos na tela
    printf("No  | Nome                          | Curso                         | Média\n");
    for (i; i < totalInFile; i++)
    {
        fread(&student, sizeof(tStudent), 1, file);
        if ((student.grade1 + student.grade2) / 2 < 5)
            printf("%-03d | %-30s| %-30s|%7.2f\n", student.number, student.name, student.course, (student.grade1 + student.grade2) / 2);
    }

    fclose(file);
    if (getchar() != '\n')
        clearBuffer();
    return 0;
}
