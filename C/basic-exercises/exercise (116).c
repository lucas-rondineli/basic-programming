/*
Faça um programa para alterar as notas dos alunos do arquivo
criado no exercício 1.
*/

#include <stdio.h>
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
        printf("Não há estudantes para terem suas notas editadas.");
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

    // Escolhe o aluno, qual de suas notas será mudada e a nota nova
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
    int optGrade;
    do
    {
        printf("\nDigite 1 ou 2, para mudar a primeira ou a segunda nota: ");
        scanf("%d", &optGrade);
        clearBuffer();
        if (optGrade != 1 && optGrade != 2)
            printf("Erro. Índice inválido, tente novamente.\n");
    } while (optGrade != 1 && optGrade != 2);
    float newGrade;
    do
    {
        printf("Digite a nova nota do aluno: ");
        scanf("%f", &newGrade);
        clearBuffer();
        if (newGrade < 0 || newGrade > 10)
            printf("Erro. Digite uma nota entre 0 e 10.\n");
    } while (newGrade < 0 || newGrade > 10);

    // Faz o "i" se tornar o "índice" do aluno que terá a nota mudada
    for (i = 0; 1; i++)
        if (optStudent == studentsNumbers[i])
            break;
    // Vai até a posição do aluno e salva o aluno que terá a nota mudada
    fseek(file, sizeof(tStudent) * i, SEEK_SET);
    fread(&student, sizeof(tStudent), 1, file);
    fseek(file, -(int)sizeof(tStudent), SEEK_CUR);
    // Altera a nota do aluno que foi lido
    if (optGrade == 1)
        student.grade1 = newGrade;
    else
        student.grade2 = newGrade;

    // Adiciona o aluno modificado no arquivo
    fwrite(&student, sizeof(tStudent), 1, file);
    printf("Nota Alterada com Sucesso.");

    fclose(file);
    if (getchar() != '\n')
        clearBuffer();
    return 0;
}
