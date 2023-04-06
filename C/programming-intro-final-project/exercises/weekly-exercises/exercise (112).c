/*
Faça um programa para incluir alunos no arquivo criado no
exercício 1. Não podem existir dois alunos com o mesmo número.
*/

#include <stdio.h>
#include <locale.h>
#include <string.h>

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

    int totalStudents;
    printf("Informe a quantidade de alunos a serem incluidos: ");
    scanf("%d", &totalStudents);
    clearBuffer();

    // Encontra a quantidade total de alunos armazenados no arquivo
    fseek(file, 0, SEEK_END);
    int totalInFile = ftell(file) / sizeof(tStudent);
    fseek(file, 0, SEEK_SET);

    // Cria um array guardando os números dos estudantes
    int studentsNumbers[totalInFile + totalStudents];
    for (int i = 0; i < totalInFile; i++)
    {
        fread(&studentsNumbers[i], sizeof(int), 1, file);
        fseek(file, sizeof(tStudent) - sizeof(int), SEEK_CUR);
    }

    // Cria um novo estudante, não permitindo um número repetido, com notas entre 0 e 10, e adiciona no arquivo
    tStudent student;
    for (int i = 0; i < totalStudents; i++)
    {
        // Garante que o número não seja repetido
        int numberExists;
        do
        {
            numberExists = 0;
            printf("\nDigite o número do aluno %d: ", i + 1);
            scanf("%d", &student.number);
            clearBuffer();
            for (int j = 0; j < totalInFile + i; j++)
                if (student.number == studentsNumbers[j])
                {
                    printf("O número escolhido já está sendo utilizado, tente novamente.\n");
                    numberExists = 1;
                    break;
                }
        } while (numberExists);
        // Aceita quaisquer nomes e cursos com até 30 caracteres
        printf("Digite o nome do aluno %d: ", i + 1);
        scanf("%29[^\n]", student.name);
        clearBuffer();
        printf("Digite o curso do aluno %d: ", i + 1);
        scanf("%29[^\n]", student.course);
        clearBuffer();
        // Garante que as notas sejam entre 0 e 10
        do
        {
            printf("Digite a primeira nota do aluno %d: ", i + 1);
            scanf("%f", &student.grade1);
            clearBuffer();
            if (student.grade1 < 0 || student.grade1 > 10)
                printf("Erro. Digite uma nota entre 0 e 10.\n");
        } while (student.grade1 < 0 || student.grade1 > 10);
        do
        {
            printf("Digite a segunda nota do aluno %d: ", i + 1);
            scanf("%f", &student.grade2);
            clearBuffer();
            if (student.grade2 < 0 || student.grade2 > 10)
                printf("Erro. Digite uma nota entre 0 e 10.\n");
        } while (student.grade2 < 0 || student.grade2 > 10);

        // Salva o estudante no arquivo e adiciona o seu número ao array de números para
        // garantir que não haja repetição
        fwrite(&student, sizeof(tStudent), 1, file);
        memmove(&studentsNumbers[totalInFile + i], &student, sizeof(int));
    }
    printf("\nAlunos Inseridos com Sucesso.");

    fclose(file);
    if (getchar() != '\n')
        clearBuffer();
    return 0;
}
