#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VAGAS 3   // Número máximo de vagas por turma
#define MAX_TURMAS 10 // Número máximo de turmas que podem ser criadas

// Estrutura de um aluno
struct aluno
{
    int mat;        // matrícula
    char nome[81];  // nome do aluno
    float notas[3]; // 3 notas
    float media;    // média das notas
};
typedef struct aluno Aluno;

// Estrutura de uma turma
struct turma
{
    char id;                  // identificador da turma (ex: 'A', 'B')
    int vagas;                // número de vagas disponíveis (inicialmente MAX_VAGAS)
    Aluno *alunos[MAX_VAGAS]; // vetor de ponteiros para os alunos matriculados
};
typedef struct turma Turma;

// Vetor global de ponteiros para turmas (cada posição aponta para uma turma criada)
Turma *turmas[MAX_TURMAS];

// Variável que controla quantas turmas já foram criadas
int num_turmas = 0;

// a) Cria uma nova turma com o identificador informado
//    Retorna um ponteiro para a turma criada

Turma *cria_turma(char id)
{
    // Verifica se já existe uma turma com o mesmo id
    for (int i = 0; i < num_turmas; i++)
    {
        if (turmas[i]->id == id)
        {
            printf("Turma %c já existe!\n", id);
            return NULL;
        }
    }
    // Aloca memória para a nova turma
    Turma *nova = (Turma *)malloc(sizeof(Turma));
    if (nova == NULL)
    {
        printf("Erro de alocação de memória!\n");
        return NULL;
    }
    // Inicializa os campos
    nova->id = id;
    nova->vagas = MAX_VAGAS;
    for (int i = 0; i < MAX_VAGAS; i++)
    {
        nova->alunos[i] = NULL; // nenhum aluno matriculado inicialmente
    }
    return nova;
}

// b) Matricula um aluno em uma turma, se houver vaga.
//    Inicializa as notas com zero.

void matricula_aluno(Turma *turma, int mat, char *nome)
{
    if (turma == NULL)
    {
        printf("Turma inválida!\n");
        return;
    }
    if (turma->vagas == 0)
    {
        printf("Não há vagas disponíveis nesta turma!\n");
        return;
    }
    // Procura a primeira posição vazia no vetor de alunos
    int pos = -1;
    for (int i = 0; i < MAX_VAGAS; i++)
    {
        if (turma->alunos[i] == NULL)
        {
            pos = i;
            break;
        }
    }
    if (pos == -1)
    {
        printf("Erro interno: vaga não encontrada!\n");
        return;
    }
    // Aloca memória para o novo aluno
    Aluno *novo = (Aluno *)malloc(sizeof(Aluno));
    if (novo == NULL)
    {
        printf("Erro de alocação de memória!\n");
        return;
    }
    // Preenche os dados
    novo->mat = mat;
    strcpy(novo->nome, nome);
    for (int i = 0; i < 3; i++)
    {
        novo->notas[i] = 0.0f;
    }
    novo->media = 0.0f;
    // Coloca o aluno na turma
    turma->alunos[pos] = novo;
    turma->vagas--;
    printf("Aluno matriculado com sucesso!\n");
}

// c) Lança as notas para todos os alunos de uma turma.
//    Para cada aluno, solicita as 3 notas e calcula a média.

void lanca_notas(Turma *turma)
{
    if (turma == NULL)
    {
        printf("Turma inválida!\n");
        return;
    }
    int total_alunos = MAX_VAGAS - turma->vagas; // número de alunos matriculados
    if (total_alunos == 0)
    {
        printf("Não há alunos matriculados nesta turma!\n");
        return;
    }
    printf("Lançando notas para a turma %c:\n", turma->id);
    for (int i = 0; i < MAX_VAGAS; i++)
    {
        if (turma->alunos[i] != NULL)
        {
            Aluno *a = turma->alunos[i];
            printf("Matrícula: %d\n", a->mat);
            printf("Aluno: %s\n", a->nome);
            // Lê as três notas
            for (int j = 0; j < 3; j++)
            {
                printf("Digite a nota %d: ", j + 1);
                scanf("%f", &a->notas[j]);
            }
            // Calcula a média
            float soma = 0.0f;
            for (int j = 0; j < 3; j++)
            {
                soma += a->notas[j];
            }
            a->media = soma / 3.0f;
        }
    }
    printf("Notas lançadas com sucesso!\n");
}

// d) Imprime os dados de todos os alunos de uma turma.

void imprime_alunos(Turma *turma)
{
    if (turma == NULL)
    {
        printf("Turma inválida!\n");
        return;
    }
    int total_alunos = MAX_VAGAS - turma->vagas;
    if (total_alunos == 0)
    {
        printf("Não há alunos matriculados nesta turma!\n");
        return;
    }
    printf("Lista de alunos da turma %c:\n", turma->id);
    for (int i = 0; i < MAX_VAGAS; i++)
    {
        if (turma->alunos[i] != NULL)
        {
            Aluno *a = turma->alunos[i];
            printf("Matrícula: %d\n", a->mat);
            printf("Nome: %s\n", a->nome);
            printf("Média: %.1f\n", a->media);
            printf("-------------------\n");
        }
    }
}

// e) Imprime todas as turmas criadas (id e vagas disponíveis).
//    n é o número de turmas existentes.

void imprime_turmas(Turma **turmas, int n)
{
    if (n == 0)
    {
        printf("Nenhuma turma criada ainda!\n");
        return;
    }
    printf("Listando turmas...\n");
    for (int i = 0; i < n; i++)
    {
        printf("Turma %c - %d vagas disponíveis\n", turmas[i]->id, turmas[i]->vagas);
    }
}

// f) Procura uma turma pelo identificador id.
//    Retorna o ponteiro para a turma ou NULL se não encontrada.

Turma *procura_turma(Turma **turmas, int n, char id)
{
    for (int i = 0; i < n; i++)
    {
        if (turmas[i]->id == id)
        {
            return turmas[i];
        }
    }
    return NULL;
}

// Função auxiliar: libera toda a memória alocada antes de sair

void libera_memoria()
{
    for (int i = 0; i < num_turmas; i++)
    {
        if (turmas[i] != NULL)
        {
            // Libera os alunos da turma
            for (int j = 0; j < MAX_VAGAS; j++)
            {
                if (turmas[i]->alunos[j] != NULL)
                {
                    free(turmas[i]->alunos[j]);
                }
            }
            // Libera a turma
            free(turmas[i]);
        }
    }
}

// Função principal: exibe o menu e gerencia as opções

int main()
{
    int opcao;
    char id;
    int mat;
    char nome[81];
    Turma *turma;

    printf("Bem-vindo ao Programa de Gerenciamento de Turmas!\n");
    printf("Este programa gerencia as turmas ofertadas, fornecendo as funcionalidades de matricula, lançamento de notas e listagem de alunos.\n");
    printf("Autor: Ada Lovelace\n");
    printf("Versao: 1.0\n\n");

    do
    {
        printf("\nMENU:\n");
        printf("1 - Criar turma\n");
        printf("2 - Listar turmas\n");
        printf("3 - Matricular aluno\n");
        printf("4 - Lancar notas\n");
        printf("5 - Listar alunos\n");
        printf("6 - Sair\n");
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);
        getchar(); // limpa o '\n' deixado pelo scanf

        switch (opcao)
        {
        case 1: // Criar turma
            if (num_turmas >= MAX_TURMAS)
            {
                printf("Limite máximo de turmas atingido!\n");
                break;
            }
            printf("Criando nova turma...\n");
            printf("Digite um id: ");
            scanf("%c", &id);
            getchar(); // limpa '\n'
            turma = cria_turma(id);
            if (turma != NULL)
            {
                turmas[num_turmas] = turma;
                num_turmas++;
                printf("Turma %c criada com sucesso!\n", id);
            }
            break;

        case 2: // Listar turmas
            imprime_turmas(turmas, num_turmas);
            break;

        case 3: // Matricular aluno
            printf("Matriculando aluno...\n");
            printf("Digite o id da turma: ");
            scanf("%c", &id);
            getchar();
            turma = procura_turma(turmas, num_turmas, id);
            if (turma == NULL)
            {
                printf("Turma inexistente!\n");
                break;
            }
            printf("Digite a matricula: ");
            scanf("%d", &mat);
            getchar();
            printf("Digite o nome: ");
            fgets(nome, 81, stdin);
            // remove o '\n' do final
            nome[strcspn(nome, "\n")] = '\0';
            matricula_aluno(turma, mat, nome);
            break;

        case 4: // Lançar notas
            printf("Lancando notas...\n");
            printf("Digite o id da turma: ");
            scanf("%c", &id);
            getchar();
            turma = procura_turma(turmas, num_turmas, id);
            if (turma == NULL)
            {
                printf("Turma inexistente!\n");
                break;
            }
            lanca_notas(turma);
            break;

        case 5: // Listar alunos de uma turma
            printf("Listando alunos...\n");
            printf("Digite o id da turma: ");
            scanf("%c", &id);
            getchar();
            turma = procura_turma(turmas, num_turmas, id);
            if (turma == NULL)
            {
                printf("Turma inexistente!\n");
                break;
            }
            imprime_alunos(turma);
            break;

        case 6: // Sair
            printf("Obrigado por usar este programa!\n");
            libera_memoria();
            break;

        default:
            printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 6);

    return 0;
}