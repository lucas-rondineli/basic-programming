/*
BARBARA GEOVANNA ALVES CAVALCANTE
ELIANE SANTOS SILVA
LUCAS RONDINELI LUCENA FRAGOSO
WESLLEY RHAONNY DE LIMA FREITAS
*/

#include <stdio.h>
#include <locale.h>
#include <string.h>

void limpaBuffer()
{
    scanf("%*[^\n]");
    scanf("%*c");
}

typedef struct
{
    int numFunc;
    int nivel;
    int departamento;
    int proximo;
} tFuncionario;

typedef struct
{
    int codDepto;
    char nomeDepto[30];
    int inicio;
} tDepartamento;

enum tipoDeArquivo
{
    FUNCIONARIOS,
    DEPARTAMENTOS
};

int lerArquivo(void *vetor, int tipo, char arquivo[])
{
    // Abre o arquivo ou o cria caso ele não exista
    FILE *arq = fopen(arquivo, "rb");
    if (arq == NULL)
    {
        arq = fopen(arquivo, "wb");
        if (arq == NULL)
        {
            printf("\tErro criando o arquivo.\n");
            if (getchar() != '\n')
                limpaBuffer();
            return -1;
        }
        fclose(arq);
        return 0;
    }

    // Encontra o total de funcionários ou departamentos no arquivo
    fseek(arq, 0, SEEK_END);
    int totalNoArquivo = ftell(arq) / (tipo == FUNCIONARIOS ? sizeof(tFuncionario) : sizeof(tDepartamento));
    fseek(arq, 0, SEEK_SET);
    // Salva os funcionários ou departamentos no vetor
    fread(vetor, (tipo == FUNCIONARIOS ? sizeof(tFuncionario) : sizeof(tDepartamento)), totalNoArquivo, arq);
    fclose(arq);
    return totalNoArquivo;
}

int salvarArquivo(void *vetor, int tipo, int tamanho, char arquivo[])
{
    // Abre o arquivo para escrita
    FILE *arq = fopen(arquivo, "wb");
    if (arq == NULL)
    {
        printf("\tErro criando o arquivo.\n");
        if (getchar() != '\n')
            limpaBuffer();
        return -1;
    }

    fwrite(vetor, (tipo == FUNCIONARIOS ? sizeof(tFuncionario) : sizeof(tDepartamento)), tamanho, arq);
    fclose(arq);
    return 0;
}

int criarDepartamento(tDepartamento vetorDepartamentos[], int *totalDepartamentos)
{
    // Limite máximo de departamentos
    if (*totalDepartamentos == 5)
    {
        printf("\n\tTotal de departamentos já atingido.\n");
        if (getchar() != '\n')
            limpaBuffer();
        return -1;
    }

    // Criação de um novo departamento e seus atributos
    tDepartamento novoDepartamento;
    novoDepartamento.codDepto = *totalDepartamentos + 1;

    int i;
    do
    {
        printf("\n\tInforme o nome do departamento: ");
        scanf("%29[^\n]", novoDepartamento.nomeDepto);
        limpaBuffer();

        for (i = 0; i < *totalDepartamentos; i++)
            if (!strcmp(novoDepartamento.nomeDepto, vetorDepartamentos[i].nomeDepto))
                break;
        if (i != *totalDepartamentos)
            printf("\tPerdão, essa opção é inválida! Por favor, tente novamente.\n");
    } while (i != *totalDepartamentos);

    // Adiciona o novo departamento e retorna sua posição no vetor
    memcpy(&vetorDepartamentos[(*totalDepartamentos)++], &novoDepartamento, sizeof(tDepartamento));
    return *totalDepartamentos - 1;
}

int admitirFuncionario(tFuncionario vetorFuncionarios[], int *totalFuncionarios, tDepartamento vetorDepartamentos[], int *totalDepartamentos)
{
    // Limite máximo de funcionários
    if (*totalFuncionarios == 20)
    {
        printf("\n\tTotal de funcionários já atingido.\n");
        if (getchar() != '\n')
            limpaBuffer();
        return -1;
    }

    // Cria o novo funcionário
    tFuncionario novoFuncionario;

    // Recebe o número do funcionário garantindo que não seja repetido
    int i;
    do
    {
        printf("\n\tInforme o número do funcionário: ");
        scanf("%d", &novoFuncionario.numFunc);
        limpaBuffer();
        for (i = 0; i < *totalFuncionarios; i++)
            if (novoFuncionario.numFunc == vetorFuncionarios[i].numFunc)
                break;
        if (i != *totalFuncionarios)
            printf("\tPerdão, essa opção é inválida! Por favor, tente novamente.\n");
    } while (i != *totalFuncionarios);

    // Recebe o nível salarial do funcionário
    printf("\n\tInforme o nível salarial do funcionário: ");
    scanf("%d", &novoFuncionario.nivel);
    limpaBuffer();

    // Caso haja departamentos, os mostra para o usuário escolher
    // Caso não, faz o usuário criar um novo departamento
    if (*totalDepartamentos > 0)
    {
        printf("\n\tEscolha um dos seguintes departamentos:\n");
        for (int i = 0; i < *totalDepartamentos; i++)
            printf("\t\t%d - %s\n", i + 1, vetorDepartamentos[i].nomeDepto);
    }
    else
        printf("\n\tNão existem departamentos já registrados.\n");
    printf("\t\t0 - Adicionar um Novo Departamento\n");
    do
    {
        printf("\n\tInforme o número de um dos departamentos ou 0 para criar um novo: ");
        scanf("%d", &novoFuncionario.departamento);
        limpaBuffer();
        if (!novoFuncionario.departamento && *totalDepartamentos == 5)
        {
            printf("\tTotal de departamentos já atingido.\n");
            novoFuncionario.departamento = -1;
        }
        if (novoFuncionario.departamento < 0 || novoFuncionario.departamento > *totalDepartamentos)
            printf("\tPerdão, essa opção é inválida! Por favor, tente novamente.\n");
    } while (novoFuncionario.departamento < 0 || novoFuncionario.departamento > *totalDepartamentos);
    novoFuncionario.departamento--;

    // Cria um departamento, caso necessário, e faz o novo funcionário ser o primeiro e último da lista
    if (novoFuncionario.departamento == -1)
    {
        // Cria o departamento e faz o novo usuário ser seu inicio
        novoFuncionario.departamento = criarDepartamento(vetorDepartamentos, totalDepartamentos);
        vetorDepartamentos[novoFuncionario.departamento].inicio = *totalFuncionarios;
        novoFuncionario.proximo = -1;
    }
    // Caso não crie um novo, atualiza o valor de "próximo" do funcionário que vem antes do criado
    // Ou, atualiza o valor de inicio do departamento, caso o número do novo funcionário seja menor
    // que o do antigo "inicio"
    else
    {
        int funcionarioInicial = vetorDepartamentos[novoFuncionario.departamento].inicio;
        i = funcionarioInicial;
        if (novoFuncionario.numFunc < vetorFuncionarios[i].numFunc)
        {
            novoFuncionario.proximo = funcionarioInicial;
            vetorDepartamentos[novoFuncionario.departamento].inicio = *totalFuncionarios;
        }
        else
        {
            while (1)
            {
                if (vetorFuncionarios[i].proximo == -1)
                    break;
                if (vetorFuncionarios[vetorFuncionarios[i].proximo].numFunc > novoFuncionario.numFunc)
                    break;
                i = vetorFuncionarios[i].proximo;
            }
            novoFuncionario.proximo = vetorFuncionarios[i].proximo;
            vetorFuncionarios[i].proximo = *totalFuncionarios;
        }
    }
    // Adiciona o novo funcionário ao final do vetor e informa ao usuário
    memcpy(&vetorFuncionarios[(*totalFuncionarios)++], &novoFuncionario, sizeof(tFuncionario));
    printf("\n\tFuncionário Admitido com Sucesso.\n");

    printf("\n\t(Pressione Enter para continuar)");
    if (getchar() != '\n')
        limpaBuffer();
    return 0;
}

int removerDepartamento(tFuncionario vetorFuncionarios[], int *totalFuncionarios, tDepartamento vetorDepartamentos[], int *totalDepartamentos)
{
    // Caso não haja departamentos, sai da função
    if (*totalDepartamentos == 0)
        return 1;

    // Testa se um departamento deve ser removido, caso não, sai da função
    int i;
    for (i = 0; i < *totalDepartamentos; i++)
        if (vetorDepartamentos[i].inicio == -1)
            break;
    if (i == *totalDepartamentos)
        return 1;

    // Corrige os "departamentos" dos funcionários e os "codDeptos" dos departamentos
    int numeroDepartamento = i;
    for (int i = 0; i < *totalFuncionarios; i++)
        if (vetorFuncionarios[i].departamento > numeroDepartamento)
            vetorFuncionarios[i].departamento--;

    for (int i = 0; i < *totalDepartamentos; i++)
        if (vetorDepartamentos[i].codDepto - 1 > numeroDepartamento)
            vetorDepartamentos[i].codDepto--;

    // Sobreescreve o departamento antigo no vetor utilizando os departamentos posteriores
    memcpy(&vetorDepartamentos[numeroDepartamento], &vetorDepartamentos[numeroDepartamento + 1], sizeof(tDepartamento) * (--(*totalDepartamentos) - numeroDepartamento));
    return 0;
}

int demitirFuncionario(tFuncionario vetorFuncionarios[], int *totalFuncionarios, tDepartamento vetorDepartamentos[], int *totalDepartamentos)
{
    // Caso não haja funcionários, sai da função
    if (*totalFuncionarios == 0)
    {
        printf("\n\tNão há funcionários para serem demitidos.\n");
        printf("\n\t(Pressione Enter para continuar)");
        if (getchar() != '\n')
            limpaBuffer();
        return -1;
    }

    // Recebe o número do funcionário a ser removido
    int numeroFuncionario, numeroDepartamento, i;
    do
    {
        printf("\n\tInforme o número do funcionário: ");
        scanf("%d", &numeroFuncionario);
        limpaBuffer();
        for (i = 0; i < *totalFuncionarios; i++)
            if (numeroFuncionario == vetorFuncionarios[i].numFunc)
                break;
        if (i == *totalFuncionarios)
            printf("\tPerdão, essa opção é inválida! Por favor, tente novamente.\n");
    } while (i == *totalFuncionarios);
    numeroFuncionario = i;

    // Recebe o nome do departamento do funcionário a ser removido
    do
    {
        printf("\n\tInforme o número do departamento da qual será retirado o funcionário: ");
        scanf("%d", &numeroDepartamento);
        limpaBuffer();
        numeroDepartamento--;
        if (numeroDepartamento != vetorFuncionarios[numeroFuncionario].departamento)
            printf("\tPerdão, esse não é o departamento do funcionário escolhido. Por favor, tente novamente.\n");
    } while (numeroDepartamento != vetorFuncionarios[numeroFuncionario].departamento);

    // Corrige o "proximo" do funcionário anterior ao removido
    // Ou, caso ele fosse o primeiro, corrige o "inicio" do departamento
    i = vetorDepartamentos[numeroDepartamento].inicio;
    if (i == numeroFuncionario)
        vetorDepartamentos[numeroDepartamento].inicio = vetorFuncionarios[numeroFuncionario].proximo;
    else
    {
        while (1)
        {
            if (vetorFuncionarios[i].proximo == numeroFuncionario)
                break;
            i = vetorFuncionarios[i].proximo;
        }
        vetorFuncionarios[i].proximo = vetorFuncionarios[numeroFuncionario].proximo;
    }

    // Corrige os índices dos "proximos" dos funcionários e os "inicios" dos departamentos
    for (int i = 0; i < *totalDepartamentos; i++)
        if (vetorDepartamentos[i].inicio > numeroFuncionario)
            vetorDepartamentos[i].inicio--;
    for (int i = 0; i < *totalFuncionarios; i++)
        if (vetorFuncionarios[i].proximo > numeroFuncionario)
            vetorFuncionarios[i].proximo--;

    // Sobreescreve o funcionario antigo no vetor utilizando os funcionários posteriores
    memcpy(&vetorFuncionarios[numeroFuncionario], &vetorFuncionarios[numeroFuncionario + 1], sizeof(tFuncionario) * (--(*totalFuncionarios) - numeroFuncionario));

    // Remove os departamentos que ficaram vazios, informa o fim da função ao usuário
    printf("\n\tFuncionário Demitido com Sucesso.\n");
    if (vetorDepartamentos[numeroDepartamento].inicio == -1)
        printf("\tE também, foi desfeito o departamento \"%s\", pois ficou sem funcionários.\n", vetorDepartamentos[numeroDepartamento].nomeDepto);
    removerDepartamento(vetorFuncionarios, totalFuncionarios, vetorDepartamentos, totalDepartamentos);

    printf("\n\t(Pressione Enter para continuar)");
    if (getchar() != '\n')
        limpaBuffer();
    return 0;
}

int mudarDepartamento(tFuncionario vetorFuncionarios[], int *totalFuncionarios, tDepartamento vetorDepartamentos[], int *totalDepartamentos)
{
    // Caso não hajam funcionários, ou tenha menos de 2 departamentos, sai da função
    if (*totalFuncionarios == 0)
    {
        printf("\n\tNão é possível mudar departamentos no momento. Admita um funcionário.\n");
        printf("\n\t(Pressione Enter para continuar)");
        if (getchar() != '\n')
            limpaBuffer();
        return -1;
    }
    if (*totalDepartamentos < 2)
    {
        printf("\n\tNão é possível mudar departamentos no momento. São necessários pelo menos 2 departamentos.\n");
        printf("\n\t(Pressione Enter para continuar)");
        if (getchar() != '\n')
            limpaBuffer();
        return -1;
    }

    // Recebe o número do funcionário, do departamento antigo e novo
    int i, numeroFuncionario, numeroDepartamentoAntigo, numeroDepartamentoNovo;
    do
    {
        printf("\n\tInforme o número do funcionário: ");
        scanf("%d", &numeroFuncionario);
        limpaBuffer();
        for (i = 0; i < *totalFuncionarios; i++)
            if (numeroFuncionario == vetorFuncionarios[i].numFunc)
                break;
        if (i == *totalFuncionarios)
            printf("\tPerdão, essa opção é inválida! Por favor, tente novamente.\n");
    } while (i == *totalFuncionarios);
    numeroFuncionario = i;

    // Recebe o nome do departamento antigo do funcionário
    do
    {
        printf("\n\tInforme o número do departamento da qual será retirado o funcionário: ");
        scanf("%d", &numeroDepartamentoAntigo);
        limpaBuffer();
        numeroDepartamentoAntigo--;
        if (numeroDepartamentoAntigo != vetorFuncionarios[numeroFuncionario].departamento)
            printf("\tPerdão, esse não é o departamento do funcionário escolhido. Por favor, tente novamente.\n");
    } while (numeroDepartamentoAntigo != vetorFuncionarios[numeroFuncionario].departamento);

    // Mostra os departamentos, recebe o departamento novo do funcionário e modifica o "departamento" do funcionário
    printf("\n\tEscolha um dos seguintes departamentos:\n");
    for (int i = 0; i < numeroDepartamentoAntigo; i++)
        printf("\t\t%d - %s\n", i + 1, vetorDepartamentos[i].nomeDepto);
    for (int i = numeroDepartamentoAntigo + 1; i < *totalDepartamentos; i++)
        printf("\t\t%d - %s\n", i, vetorDepartamentos[i].nomeDepto);
    do
    {
        printf("\n\tInforme o número de um dos departamentos: ");
        scanf("%d", &numeroDepartamentoNovo);
        limpaBuffer();
        numeroDepartamentoNovo--;
        if (numeroDepartamentoNovo == numeroDepartamentoAntigo || numeroDepartamentoNovo < 0 || numeroDepartamentoNovo >= *totalDepartamentos)
            printf("\tPerdão, essa opção é inválida! Por favor, tente novamente.\n");
    } while (numeroDepartamentoNovo == numeroDepartamentoAntigo || numeroDepartamentoNovo < 0 || numeroDepartamentoNovo >= *totalDepartamentos);
    vetorFuncionarios[numeroFuncionario].departamento = numeroDepartamentoNovo;

    // Corrige o "proximo" do funcionário anterior do departamento antigo
    // Ou, caso ele fosse o primeiro, corrige o "inicio" do departamento antigo
    // Se o funcionário for o único no departamento, o departamento é removido
    i = vetorDepartamentos[numeroDepartamentoAntigo].inicio;
    if (i == numeroFuncionario)
    {
        vetorDepartamentos[numeroDepartamentoAntigo].inicio = vetorFuncionarios[numeroFuncionario].proximo;
        if (vetorDepartamentos[numeroDepartamentoAntigo].inicio == -1)
            printf("\n\tCom essa mudança, foi desfeito o departamento \"%s\", pois ficou sem funcionários.\n", vetorDepartamentos[numeroDepartamentoAntigo].nomeDepto);
        removerDepartamento(vetorFuncionarios, totalFuncionarios, vetorDepartamentos, totalDepartamentos);
    }
    else
    {
        while (1)
        {
            if (vetorFuncionarios[i].proximo == numeroFuncionario)
                break;
            i = vetorFuncionarios[i].proximo;
        }
        vetorFuncionarios[i].proximo = vetorFuncionarios[numeroFuncionario].proximo;
    }

    // Modifica os "proximos" dos funcionários
    // Caso necessário, modifica o "inicio" do departamento novo
    int funcionarioInicial = vetorDepartamentos[numeroDepartamentoNovo].inicio;
    i = funcionarioInicial;
    if (vetorFuncionarios[numeroFuncionario].numFunc < vetorFuncionarios[i].numFunc)
    {
        vetorFuncionarios[numeroFuncionario].proximo = funcionarioInicial;
        vetorDepartamentos[numeroDepartamentoNovo].inicio = numeroFuncionario;
    }
    else
    {
        while (1)
        {
            if (vetorFuncionarios[i].proximo == -1)
                break;
            if (vetorFuncionarios[vetorFuncionarios[i].proximo].numFunc > vetorFuncionarios[numeroFuncionario].numFunc)
                break;
            i = vetorFuncionarios[i].proximo;
        }
        vetorFuncionarios[numeroFuncionario].proximo = vetorFuncionarios[i].proximo;
        vetorFuncionarios[i].proximo = numeroFuncionario;
    }

    // Informa ao usuário o fim da função
    printf("\n\tFuncionário Transferido com Sucesso.\n");
    printf("\n\t(Pressione Enter para continuar)");
    if (getchar() != '\n')
        limpaBuffer();
    return 0;
}

int consultarDepartamento(tFuncionario vetorFuncionarios[], int *totalFuncionarios, tDepartamento vetorDepartamentos[], int *totalDepartamentos)
{
    // Caso não haja departamentos, sai da função
    if (*totalDepartamentos == 0)
    {
        printf("\n\tNão há departamentos para serem consultados.\n");
        printf("\n\t(Pressione Enter para continuar)");
        if (getchar() != '\n')
            limpaBuffer();
        return 1;
    }

    // Recebe o nome do departamento escolhido
    int i, j;
    char nomeDepartamento[30];
    printf("\n\tInforme o nome do departamento que deseja consultar:  ");
    scanf("%29[^\n]", nomeDepartamento);
    limpaBuffer();

    // Encontra os funcionários do departamento escolhido e mostra suas informações
    for (i = 0; i < *totalFuncionarios; i++)
    {
        if (!strcmp(nomeDepartamento, vetorDepartamentos[vetorFuncionarios[i].departamento].nomeDepto))
        {
            printf("\tnumFunc      nivel        departamento\n");
            for (int j = 0; j < *totalFuncionarios; j++)
            {
                if (vetorDepartamentos[vetorFuncionarios[i].departamento].codDepto == vetorFuncionarios[j].departamento + 1)
                    printf("\t%-13d%-13d%-20d\n", vetorFuncionarios[j].numFunc, vetorFuncionarios[j].nivel, vetorFuncionarios[j].departamento + 1);
            }
            break;
        }
    }

    // Caso o departamento escolhido não exista, informa ao usuário
    if (i == *totalFuncionarios)
        printf("\n\tPerdão, essa opção é inválida!\n");

    printf("\n\t(Pressione Enter para continuar)");
    if (getchar() != '\n')
        limpaBuffer();
    return 0;
}

int consultarFuncionario(tFuncionario vetorFuncionarios[], int *totalFuncionarios, tDepartamento vetorDepartamentos[], int *totalDepartamentos)
{
    // Caso não haja funcionários, sai da função
    if (*totalFuncionarios == 0)
    {
        printf("\n\tNão há funcionários para serem consultados.\n");
        printf("\n\t(Pressione Enter para continuar)");
        if (getchar() != '\n')
            limpaBuffer();
        return 1;
    }

    // Recebe o número o funcionário escolhido
    int numeroFunc, i;
    printf("\n\tInforme o número do funcionário que deseja consultar:  ");
    scanf("%d", &numeroFunc);
    limpaBuffer();

    // Encontra o funcionário e mostra suas informações
    for (i = 0; i < *totalFuncionarios; i++)
        if (vetorFuncionarios[i].numFunc == numeroFunc)
        {
            printf("\n\tO nível desse funcionário é: %d\n", vetorFuncionarios[i].nivel);
            printf("\tO código do departamento desse funcionário é: %d\n", vetorFuncionarios[i].departamento + 1);
            printf("\tO nome do departamento desse funcionário é: %s\n", vetorDepartamentos[vetorFuncionarios[i].departamento].nomeDepto);
            break;
        }

    // Caso o funcionário escolhido não exista, informa ao usuário
    if (i == *totalFuncionarios)
        printf("\n\tPerdão, essa opção é inválida!\n");

    printf("\n\t(Pressione Enter para continuar)");
    if (getchar() != '\n')
        limpaBuffer();
    return 0;
}

int main()
{
    setlocale(LC_ALL, "portuguese");
    tFuncionario vetorFuncionarios[20];
    tDepartamento vetorDepartamentos[5];

    int totalFuncionarios = lerArquivo(vetorFuncionarios, FUNCIONARIOS, "funcionarios.dat");
    int totalDepartamentos = lerArquivo(vetorDepartamentos, DEPARTAMENTOS, "departamentos.dat");

    int menu;
    while (1)
    {
        printf("\n\t-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("\t                            Empresa XYZ                            \n");
        printf("\t-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");

        if (totalFuncionarios == 0)
            printf("\tSem funcionários no momento.\n");
        else
        {
            printf("\tlinha        numFunc      nivel        departamento        proximo\n");
            for (int i = 0; i < totalFuncionarios; i++)
                printf("\t%-13d%-13d%-13d%-20d%d\n", i, vetorFuncionarios[i].numFunc, vetorFuncionarios[i].nivel, vetorFuncionarios[i].departamento + 1, vetorFuncionarios[i].proximo);
        }
        if (totalDepartamentos == 0)
            printf("\tSem departamentos no momento.\n");
        else
        {
            printf("\n\tcodDepto     nomeDepto                     inicio\n");
            for (int i = 0; i < totalDepartamentos; i++)
                printf("\t%-13d%-30s%d\n", vetorDepartamentos[i].codDepto, vetorDepartamentos[i].nomeDepto, vetorDepartamentos[i].inicio);
        }

        printf("\n\t(Pressione Enter para continuar)");
        if (getchar() != '\n')
            limpaBuffer();

        printf("\n\tSeja Bem-Vindo! Escolha uma opção para começar:\n");
        printf("\t\t1 - Admitir um Novo Funcionário.\n");
        printf("\t\t2 - Demitir um Funcionário.\n");
        printf("\t\t3 - Mudar um Funcionário de Departamento.\n");
        printf("\t\t4 - Consultar Funcionários de um Departamento.\n");
        printf("\t\t5 - Consultar Individual de um Funcionário.\n");
        printf("\t\t0 - Finalizar Programa e Salvar.\n");

        do
        {
            printf("\n\tQual opção você deseja? ");
            scanf("%d", &menu);
            limpaBuffer();
            if (menu != 1 && menu != 2 && menu != 3 && menu != 4 && menu != 5 && menu != 0)
                printf("\tPerdão, essa opção é inválida! Por favor, tente novamente.\n");
        } while (menu != 1 && menu != 2 && menu != 3 && menu != 4 && menu != 5 && menu != 0);

        if (menu == 0)
            break;
        switch (menu)
        {
        case 1:
            admitirFuncionario(vetorFuncionarios, &totalFuncionarios, vetorDepartamentos, &totalDepartamentos);
            break;
        case 2:
            demitirFuncionario(vetorFuncionarios, &totalFuncionarios, vetorDepartamentos, &totalDepartamentos);
            break;
        case 3:
            mudarDepartamento(vetorFuncionarios, &totalFuncionarios, vetorDepartamentos, &totalDepartamentos);
            break;
        case 4:
            consultarDepartamento(vetorFuncionarios, &totalFuncionarios, vetorDepartamentos, &totalDepartamentos);
            break;
        case 5:
            consultarFuncionario(vetorFuncionarios, &totalFuncionarios, vetorDepartamentos, &totalDepartamentos);
        }
    }

    salvarArquivo(vetorFuncionarios, FUNCIONARIOS, totalFuncionarios, "funcionarios.dat");
    salvarArquivo(vetorDepartamentos, DEPARTAMENTOS, totalDepartamentos, "departamentos.dat");
    printf("\n\n\tArquivos Salvos com Sucesso.\n");
    if (getchar() != '\n')
        limpaBuffer();
    return 0;
}
