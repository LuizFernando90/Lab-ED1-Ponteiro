#include <stdio.h>
#include <string.h>

#define MAX_NOME 100

typedef struct
{
    char nome[MAX_NOME];
    char documento[20]; // CPF, RG, etc.
    int idade;
} Pessoa;

// a) Preencher pessoa
void preencher_pessoa(Pessoa *p)
{
    printf("Digite o nome: ");
    fgets(p->nome, MAX_NOME, stdin);
    p->nome[strcspn(p->nome, "\n")] = '\0';

    printf("Digite o número do documento: ");
    fgets(p->documento, 20, stdin);
    p->documento[strcspn(p->documento, "\n")] = '\0';

    printf("Digite a idade: ");
    scanf("%d", &p->idade);
    getchar(); // limpa o buffer
}

// b) Imprimir pessoa
void imprimir_pessoa(Pessoa *p)
{
    printf("\n--- Dados da Pessoa ---\n");
    printf("Nome: %s\n", p->nome);
    printf("Documento: %s\n", p->documento);
    printf("Idade: %d anos\n", p->idade);
}

// c) Atualizar idade
void atualizar_idade(Pessoa *p, int nova_idade)
{
    p->idade = nova_idade;
    printf("Idade atualizada com sucesso!\n");
}

// d) Encontrar mais velha e mais nova em um vetor
void mais_velha_mais_nova(Pessoa vetor[], int n)
{
    if (n == 0)
    {
        printf("Nenhuma pessoa cadastrada.\n");
        return;
    }

    int idx_velha = 0, idx_nova = 0;
    for (int i = 1; i < n; i++)
    {
        if (vetor[i].idade > vetor[idx_velha].idade)
            idx_velha = i;
        if (vetor[i].idade < vetor[idx_nova].idade)
            idx_nova = i;
    }

    printf("\n--- Pessoa mais velha ---\n");
    printf("Nome: %s\n", vetor[idx_velha].nome);
    printf("Idade: %d anos\n", vetor[idx_velha].idade);

    printf("\n--- Pessoa mais nova ---\n");
    printf("Nome: %s\n", vetor[idx_nova].nome);
    printf("Idade: %d anos\n", vetor[idx_nova].idade);
}

int main()
{
    int n;
    printf("Quantas pessoas deseja cadastrar? ");
    scanf("%d", &n);
    getchar(); // limpa o buffer

    Pessoa pessoas[n];

    // Preenchimento
    for (int i = 0; i < n; i++)
    {
        printf("\n--- Cadastro da pessoa %d ---\n", i + 1);
        preencher_pessoa(&pessoas[i]);
    }

    // Impressão de todos
    for (int i = 0; i < n; i++)
    {
        imprimir_pessoa(&pessoas[i]);
    }

    // Atualizar idade de uma pessoa (pelo nome)
    char nome_busca[MAX_NOME];
    printf("\nDigite o nome da pessoa para alterar idade: ");
    fgets(nome_busca, MAX_NOME, stdin);
    nome_busca[strcspn(nome_busca, "\n")] = '\0';

    int nova_idade;
    for (int i = 0; i < n; i++)
    {
        if (strcmp(pessoas[i].nome, nome_busca) == 0)
        {
            printf("Nova idade: ");
            scanf("%d", &nova_idade);
            atualizar_idade(&pessoas[i], nova_idade);
            break;
        }
    }

    // Encontrar mais velha e mais nova
    mais_velha_mais_nova(pessoas, n);

    return 0;
}