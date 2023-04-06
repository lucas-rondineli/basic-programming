#include "auxiliares.h"

int lerPerfis(perfil *inicio)
{
    FILE *file;

    // Abre o arquivo
    file = fopen("placar.txt", "r");
    if (file == NULL)
    {
        file = fopen("placar.txt", "w");
        fclose(file);
        return 1;
    }

    // Define o tamanho do arquivo
    fseek(file, 0, SEEK_END);
    int fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Lê os perfis
    perfil *atual = inicio;
    while (ftell(file) < fileSize)
    {
        atual->proximo = malloc(sizeof(perfil));
        atual = atual->proximo;
        fscanf(file, "%s %d %d ", atual->nome, &atual->partidasGanhas, &atual->partidasTotais);
    }
    atual->proximo = NULL;

    // Fecha o arquivo
    fclose(file);
    return 0;
}

int salvarPerfis(perfil *inicio)
{
    FILE *file;

    // Abre o arquivo
    file = fopen("placar.txt", "w");
    if (file == NULL)
    {
        printf("Erro criando o placar.");
        return -1;
    }

    // Ordena os perfis por nome
    ordenaLista(inicio, NOME);

    // Salva os perfis
    perfil *atual = inicio->proximo, *remover;
    while (atual != NULL)
    {
        fprintf(file, "%s %d %d\n", atual->nome, atual->partidasGanhas, atual->partidasTotais);
        remover = atual;
        atual = atual->proximo;
        free(remover);
    }

    // Fecha o arquivo
    fclose(file);
    return 0;
}

int visualizarPlacar(perfil *inicio)
{
    // Sai da função caso o placar esteja vazio
    if (inicio->proximo == NULL)
    {
        printf("\n\tInfelizmente, ainda não existem jogadores cadastrados.\n");
        pausar(0.5);
        printf("\n\t(Pressione ");
        colorir(VERMELHO);
        printf("Enter");
        colorir(NORMAL);
        printf(" para continuar)");

        if (getchar() != '\n')
            limpaBuffer();
        return 1;
    }

    // Ordena os jogadores por número de vitórias
    ordenaLista(inicio, RANK);

    // Mostra o Placar
    printf("\n\t-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    colorir(ROXO);
    printf("\t                                        PLACAR                                         \n");
    colorir(NORMAL);
    printf("\t-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n");
    pausar(0.2);
    printf("\tNo  |              NOME              |  Vitórias   | Partidas Jogadas | Taxa de Vitória\n");

    perfil *atual = inicio->proximo;
    float porcentagemDeVitoria;
    int contador, contadorW;
    // Uma Wide String, com caracteres UniCode, que não tem problema de duplicar quantidade de caracteres da acentuação
    wchar_t nomeW[30];
    for (int i = 0; atual != NULL; i++)
    {
        porcentagemDeVitoria = atual->partidasTotais != 0 ? (float)atual->partidasGanhas / atual->partidasTotais * 100 : 0.0;

        // Passando o nome como Wide String pra nomeW
        mbstowcs(nomeW, atual->nome, 30);
        // Contando os caracteres duplicados
        contador = strlen(atual->nome);
        // Contando o verdadeiro número de caracteres
        contadorW = wcslen(nomeW);

        printf("\t%03d | %-30s", i + 1, atual->nome);
        // Compensando os espaços perdidos com a diferença entre as contagens
        for (int j = contador - contadorW; j > 0; j--)
            printf(" ");
        printf(" |     %03d     |       %03d        |     %6.2f%%\n", atual->partidasGanhas, atual->partidasTotais, porcentagemDeVitoria);
        pausar(0.2);
        atual = atual->proximo;
    }

    printf("\n\t(Pressione ");
    colorir(VERMELHO);
    printf("Enter");
    colorir(NORMAL);
    printf(" para continuar)");

    if (getchar() != '\n')
        limpaBuffer();
    return 0;
}
