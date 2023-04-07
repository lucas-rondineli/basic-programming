/*
BARBARA GEOVANNA ALVES CAVALCANTE
ELIANE SANTOS SILVA
LUCAS RONDINELI LUCENA FRAGOSO
WESLLEY RHAONNY DE LIMA FREITAS
*/

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

void limpaBuffer()
{
    scanf("%*[^\n]");
    scanf("%*c");
}

typedef struct
{
    char tipo[4];
    int coluna;
    int linha;
    int maior;
    int **matriz;
} PGM;

int lerArquivo(PGM *arquivoOriginal, char *caminho)
{
    // Caso o arquivo não exista, sai da função
    FILE *arq = fopen(caminho, "r");
    if (arq == NULL)
        return -1;

    // Lê tudo do arquivo, exceto a matriz
    fscanf(arq, "%3[^\n]", arquivoOriginal->tipo);
    char c;
    fscanf(arq, " %c", &c);
    if (c == '#')
        fscanf(arq, "%*[^\n]", &c);
    else
        fseek(arq, 2, SEEK_SET);
    fscanf(arq, "%d %d", &arquivoOriginal->coluna, &arquivoOriginal->linha);
    fscanf(arq, "%d", &arquivoOriginal->maior);

    // Cria um ponteiro para o vetor de "ponteiros que tem a posição inicial das linhas"
    // Resumindo, cria a "linha" da matriz[linha][coluna]
    arquivoOriginal->matriz = malloc(sizeof(int *) * arquivoOriginal->linha);

    // Cria vários ponteiros para "os vetores que possuem os valores das linhas"
    // Resumindo, cria a "coluna" da matriz[linha][coluna]
    for (int i = 0; i < arquivoOriginal->linha; i++)
        arquivoOriginal->matriz[i] = malloc(sizeof(int) * arquivoOriginal->coluna);

    // Lê a matriz para o struct
    for (int i = 0; i < arquivoOriginal->linha; i++)
        for (int j = 0; j < arquivoOriginal->coluna; j++)
            fscanf(arq, "%d", &arquivoOriginal->matriz[i][j]);

    fclose(arq);
    return 0;
}

int salvarArquivo(PGM *arquivoOriginal, char *caminho)
{
    // Caso não consiga criar o arquivo, sai da função
    FILE *arq = fopen(caminho, "w");
    if (arq == NULL)
        return -1;

    // Escreve tudo no arquivo, exceto a matriz
    fprintf(arq, "%s\n", arquivoOriginal->tipo);
    fprintf(arq, "%d %d\n", arquivoOriginal->coluna, arquivoOriginal->linha);
    fprintf(arq, "%d\n", arquivoOriginal->maior);

    // Escreve a matriz no arquivo
    int j;
    for (int i = 0; i < arquivoOriginal->linha; i++)
    {
        for (j = 0; j < arquivoOriginal->coluna - 1; j++)
            fprintf(arq, "%d ", arquivoOriginal->matriz[i][j]);
        fprintf(arq, "%d\n", arquivoOriginal->matriz[i][j]);
        free(arquivoOriginal->matriz[i]);
    }
    free(arquivoOriginal->matriz);

    fclose(arq);
    return 0;
}

void copiarPGM(PGM *destino, PGM *origem)
{
    // Copia tudo, menos a matriz
    memcpy(destino, origem, sizeof(PGM) - sizeof(int **));

    // Cria um ponteiro para o vetor de "ponteiros que tem a posição inicial das linhas"
    // Resumindo, cria a "linha" da matriz[linha][coluna]
    destino->matriz = malloc(sizeof(int *) * destino->linha);

    // Cria vários ponteiros para "os vetores que possuem os valores das linhas"
    // Resumindo, cria a "coluna" da matriz[linha][coluna]
    for (int i = 0; i < destino->linha; i++)
        destino->matriz[i] = malloc(sizeof(int) * destino->coluna);

    // Lê a matriz de um struct para a matriz do outro
    for (int i = 0; i < destino->linha; i++)
        for (int j = 0; j < destino->coluna; j++)
            destino->matriz[i][j] = origem->matriz[i][j];
}

void funcao1(PGM *arquivoOriginal, char *caminho)
{
    // Copia o struct com as informações do arquivo original para um novo struct que será modificado
    PGM arquivoClareado;
    copiarPGM(&arquivoClareado, arquivoOriginal);

    // Percorre cada elemento da matriz dessa struct aumentando o valor de cada elemento em 30
    // Limitando esse aumento à 255
    for (int i = 0; i < arquivoClareado.linha; i++)
        for (int j = 0; j < arquivoClareado.coluna; j++)
            if (arquivoClareado.matriz[i][j] + 30 < 255)
                arquivoClareado.matriz[i][j] += 30;
            else
                arquivoClareado.matriz[i][j] = 255;
    // Aumenta o valor do maior elemento em 30, ou no máximo até 255
    arquivoClareado.maior = arquivoClareado.maior + 30 < 255 ? arquivoClareado.maior + 30 : 255;

    // Salva o struct recém modificado em um novo arquivo
    salvarArquivo(&arquivoClareado, caminho);
}

void funcao2(PGM *arquivoOriginal, char *caminho)
{
    // Cria um novo struct para ser modificado além de outros parâmetros para a função
    PGM arquivoZoom;
    int i, j, linImpar = 0, colImpar = 0;

    // Verifica se o número de linhas é ímpar e adiciona mais uma linha caso sim
    // Além disso, uma variável armazena "1" para facilitar a reversão disso futuramente, sem prejudicar as demais funções
    if (arquivoOriginal->linha % 2 == 1)
    {
        arquivoOriginal->linha++;
        linImpar = 1;
    }

    // Repete o processo com o número de colunas, adicionando mais uma se for ímpar
    // Mais uma vez, foi armazenado "1" em uma variável para facilitar a reversão
    if (arquivoOriginal->coluna % 2 == 1)
    {
        arquivoOriginal->coluna++;
        colImpar = 1;
    }

    // Copia o struct com as informações do arquivo original para um novo struct que será modificado
    copiarPGM(&arquivoZoom, arquivoOriginal);

    // Verifica se o número de linhas é ímpar através da variável que foi atribuída para verificação anteriormente
    // Se a condição for verdadeira, a coluna adicionada receberá os valores da última coluna da matriz original
    // Por fim, há decrementação do número de linhas que foi armazenado no arquivo da imagem (retorna ao tamanho original)
    if (linImpar)
    {
        for (int i = 0; i < arquivoZoom.coluna; i++)
            arquivoZoom.matriz[arquivoZoom.linha - 1][i] = arquivoZoom.matriz[arquivoZoom.linha - 2][i];
        arquivoOriginal->linha--;
    }

    // Repete o processo na verificação das colunas
    if (colImpar)
    {
        for (int i = 0; i < arquivoZoom.linha; i++)
            arquivoZoom.matriz[i][arquivoZoom.coluna - 1] = arquivoZoom.matriz[i][arquivoZoom.coluna - 2];
        arquivoOriginal->coluna--;
    }

    // Caso os números de linhas e colunas sejam ímpares, depois de passar pelos processos anteriores restará um último elemento vazio
    // Para evita que isso aconteça, será repetido o valor do último elemento da linha/coluna
    if (linImpar && colImpar)
        arquivoZoom.matriz[arquivoZoom.linha - 1][arquivoZoom.coluna - 1] = arquivoZoom.matriz[arquivoZoom.linha - 2][arquivoZoom.coluna - 2];

    // Percorre a matriz e calcula a média entre os 4 vizinhos
    for (i = 0; i < arquivoZoom.linha; i += 2)
        for (j = 0; j < arquivoZoom.coluna; j += 2)
            arquivoZoom.matriz[i / 2][j / 2] = (arquivoZoom.matriz[i][j] + arquivoZoom.matriz[i][j + 1] + arquivoZoom.matriz[i + 1][j] + arquivoZoom.matriz[i + 1][j + 1]) / 4;

    // Reduz o valor da matriz ao meio, determinando uma matriz 4x menor que a anterior — tendo, consequentemente, o fim do processo de Zoom
    arquivoZoom.linha = arquivoZoom.linha / 2;
    arquivoZoom.coluna = arquivoZoom.coluna / 2;

    // Salva o struct recém modificado em um novo arquivo
    salvarArquivo(&arquivoZoom, caminho);
}

void funcao3(PGM *arquivoOriginal, char *caminho)
{
    // Copia o struct com as informações do arquivo original para um novo struct que será modificado
    PGM arquivoBinarizado;
    copiarPGM(&arquivoBinarizado, arquivoOriginal);

    // Faz com que todos os elementos da matriz desse novo struct se tornem 0 ou igual ao maior valor da struct
    // Caso o elemento seja menor que a metade do maior valor, ele se torna 0, caso não, se torna igual o maior
    for (int i = 0; i < arquivoBinarizado.linha; i++)
        for (int j = 0; j < arquivoBinarizado.coluna; j++)
            if (arquivoBinarizado.matriz[i][j] <= ((arquivoBinarizado.maior) / 2))
                arquivoBinarizado.matriz[i][j] = 0;
            else
                arquivoBinarizado.matriz[i][j] = (arquivoBinarizado.maior);

    // Salva o struct recém modificado em um novo arquivo
    salvarArquivo(&arquivoBinarizado, caminho);
}

void funcao4(PGM *arquivoOriginal, char *caminho)
{
    // Cria um novo struct que será como o struct com as informações do arquivo original, porém rotacionado
    PGM arquivoRotacionado;

    // Copia tudo, menos a matriz
    memcpy(&arquivoRotacionado, arquivoOriginal, sizeof(PGM) - sizeof(int **));
    // Inverte o número de linhas com o número de colunas
    arquivoRotacionado.linha = arquivoOriginal->coluna;
    arquivoRotacionado.coluna = arquivoOriginal->linha;
    // Cria o espaço para as "linhas" do struct novo
    arquivoRotacionado.matriz = malloc(sizeof(int *) * arquivoRotacionado.linha);
    // Cria o espaço para as "colunas" do struct novo
    for (int i = 0; i < arquivoRotacionado.linha; i++)
        arquivoRotacionado.matriz[i] = malloc(sizeof(int) * arquivoRotacionado.coluna);

    // Percorre a matriz do struct antigo, indo da esquerda para a direita (primeiro), de cima a baixo (segundo)
    // copiando esses valores para o novo struct
    // A matriz do novo struct é percorrida seguindo o sentido
    // de cima a baixo (primeiro), depois da direita para a esquerda (segundo)

    // (O primeiro é percorrido como lemos uma folha de papel)
    // (O segundo é percorrido como lemos essa mesma folha caso virássemos ela 90° para a direita)
    for (int i = 0; i < arquivoOriginal->linha; i++)
        for (int j = 0; j < arquivoOriginal->coluna; j++)
            arquivoRotacionado.matriz[j][arquivoRotacionado.coluna - 1 - i] = arquivoOriginal->matriz[i][j];

    // Salva o struct recém modificado em um novo arquivo
    salvarArquivo(&arquivoRotacionado, caminho);
}

int main(int argc, char **argv)
{
    setlocale(LC_ALL, "portuguese");

    // Verifica se o programa recebeu um arquivo para ser modificado
    if (argc == 2)
    {
        // Cria uma struct para onde os dados do arquivo serão copiados
        PGM arquivoOriginal;
        lerArquivo(&arquivoOriginal, argv[1]);

        // Cria os caminhos para serem usados nas funções
        int tamanhoDoCaminho = strlen(argv[1]) + 2;
        char caminhoFuncao1[tamanhoDoCaminho];
        char caminhoFuncao2[tamanhoDoCaminho];
        char caminhoFuncao3[tamanhoDoCaminho];
        char caminhoFuncao4[tamanhoDoCaminho];
        strcpy(caminhoFuncao1, argv[1]);
        strcpy(&caminhoFuncao1[tamanhoDoCaminho - 6], "1.pgm");
        strcpy(caminhoFuncao2, caminhoFuncao1);
        strcpy(caminhoFuncao3, caminhoFuncao1);
        strcpy(caminhoFuncao4, caminhoFuncao1);
        caminhoFuncao2[tamanhoDoCaminho - 6] = '2';
        caminhoFuncao3[tamanhoDoCaminho - 6] = '3';
        caminhoFuncao4[tamanhoDoCaminho - 6] = '4';

        // Função que clareia a imagem
        funcao1(&arquivoOriginal, caminhoFuncao1);
        // Função que dá zoom
        funcao2(&arquivoOriginal, caminhoFuncao2);
        // Função que binariza a imagem
        funcao3(&arquivoOriginal, caminhoFuncao3);
        // Função que rotaciona a imagem
        funcao4(&arquivoOriginal, caminhoFuncao4);

        printf("Arquivos Criados com Sucesso.\n");
    }
    else
        printf("Digite o nome do arquivo na chamada.");

    if (getchar() != '\n')
        limpaBuffer();
    return 0;
}
