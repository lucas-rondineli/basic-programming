/*
Faça um programa para alterar o curso dos alunos do arquivo
criado no Exercício 1.
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
    if (totalInFile < 1)
    {
        printf("Não há estudantes para terem seus cursos editados.");
        fclose(file);
        if (getchar() != '\n')
            clearBuffer();
        return 1;
    }

    // Cria um array guardando os números dos estudantes
    fseek(file, 0, SEEK_SET);
    int studentsNumbers[totalInFile];
    for (int i = 0; i < totalInFile; i++)
    {
        fread(&studentsNumbers[i], sizeof(int), 1, file);
        fseek(file, sizeof(tStudent) - sizeof(int), SEEK_CUR);
    }
    fseek(file, 0, SEEK_SET);

    // Mostra os alunos na tela
    printf("No  | Nome                          | Curso                         | Nota 1 | Nota 2\n");
    tStudent student;
    for (int i = 0; i < totalInFile; i++)
    {
        fread(&student, sizeof(tStudent), 1, file);
        printf("%-03d | %-30s| %-30s|%7.2f |%7.2f\n", student.number, student.name, student.course, student.grade1, student.grade2);
    }

    // Escolhe o aluno e o seu novo curso
    int optStudent;
    int i;
    do
    {
        printf("\nEscolha um aluno pelo número: ");
        scanf("%d", &optStudent);
        clearBuffer();
        i = 0;
        for (i; i < totalInFile; i++)
            if (optStudent == studentsNumbers[i])
                break;
        if (i == totalInFile)
            printf("Erro. Índice inválido, tente novamente.\n");
    } while (i == totalInFile);
    char course[30];
    printf("Digite o novo curso do aluno: ");
    scanf("%29[^\n]", course);

    // Faz o "i" se tornar o "índice" do aluno que terá o curso mudado
    for (i = 0; 1; i++)
        if (optStudent == studentsNumbers[i])
            break;
    // Vai até a posição do aluno e salva o aluno que terá o curso mudado
    fseek(file, sizeof(tStudent) * i, SEEK_SET);
    fread(&student, sizeof(tStudent), 1, file);
    fseek(file, - (int)sizeof(tStudent), SEEK_CUR);
    // Altera o curso do aluno que foi lido
    strcpy(student.course, course);

    // Adiciona o aluno modificado no arquivo
    fwrite(&student, sizeof(tStudent), 1, file);
    printf("Curso Alterado com Sucesso.");

    fclose(file);
    if (getchar() != '\n')
        clearBuffer();
    return 0;
}
