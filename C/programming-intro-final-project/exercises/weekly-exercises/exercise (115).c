/*
Faça um programa para excluir os alunos do arquivo criado no
Exercício 1.
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
    FILE *temp;

    // Abre o arquivo que terá um elemento apagado e cria um novo
    // O novo terá o arquivo editado
    file = fopen("ALUNOS.DAT", "rb+");
    temp = fopen("temp.tmp", "w");
    if (file == NULL || temp == NULL)
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
        printf("Não há estudantes para serem removidos.");
        fclose(file);
        if (getchar() != '\n')
            clearBuffer();
        return 1;
    }

    // Caso haja mais de 1 estudante a ser excluido, pergunta ao usuário qual será
    if (totalInFile > 1)
    {
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

        // Escolhe o aluno que será excluido
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
        fseek(file, 0, SEEK_SET);

        // Faz o "i" se tornar o "índice" do aluno que será excluido
        for (i = 0; 1; i++)
            if (optStudent == studentsNumbers[i])
                break;
        totalInFile--;
        // Define o primeiro bit onde está as informações do aluno que será excluido
        int excludeStart = sizeof(tStudent) * (i);
        // Cria uma "string" de bits que armazenará as informações de um arquivo
        // para que elas possam ser passadas ao outro
        // O tamanho da "string" depende de qual "metade" do arquivo é maior,
        // a que vem antes do trecho apagado, ou a que vem depois
        char temporaryInfoHolder[(sizeof(tStudent) * (totalInFile) - excludeStart) > excludeStart ? (sizeof(tStudent) * (totalInFile) - excludeStart) : excludeStart];

        // Copia os dados de todos os estudantes que vem antes do apagado para a "string"
        fread(temporaryInfoHolder, sizeof(tStudent), i, file);
        // Copia a "string" para o arquivo temporário
        fwrite(temporaryInfoHolder, sizeof(tStudent), i, temp);
        // Pula o estudante que será apagado
        fseek(file, sizeof(tStudent), SEEK_CUR);
        // Copia os dados de todos os estudantes que vem depois do apagado para a "string"
        fread(temporaryInfoHolder, sizeof(tStudent), totalInFile - i, file);
        // Copia a "string" para o arquivo temporário
        fwrite(temporaryInfoHolder, sizeof(tStudent), totalInFile - i, temp);
    }

    printf("Aluno Excluido com Sucesso.");

    fclose(file);
    fclose(temp);
    // Apaga o arquivo original e renomeia o temporário com o nome do original
    remove("ALUNOS.DAT");
    rename("temp.tmp", "ALUNOS.DAT");
    if (getchar() != '\n')
        clearBuffer();
    return 0;
}
