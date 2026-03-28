#include <stdio.h>
#include <string.h>

#define MAX_NOME 100
#define MAX_CARGO 50

typedef struct
{
    char nome[MAX_NOME];
    float salario;
    int identificador;
    char cargo[MAX_CARGO];
} Funcionario;

// a) Preencher funcionário
void preencher_funcionario(Funcionario *f)
{
    printf("Digite o nome: ");
    fgets(f->nome, MAX_NOME, stdin);
    f->nome[strcspn(f->nome, "\n")] = '\0';

    printf("Digite o salário: ");
    scanf("%f", &f->salario);
    getchar();

    printf("Digite o identificador: ");
    scanf("%d", &f->identificador);
    getchar();

    printf("Digite o cargo: ");
    fgets(f->cargo, MAX_CARGO, stdin);
    f->cargo[strcspn(f->cargo, "\n")] = '\0';
}

// b) Imprimir funcionário
void imprimir_funcionario(Funcionario *f)
{
    printf("\n--- Dados do Funcionário ---\n");
    printf("Identificador: %d\n", f->identificador);
    printf("Nome: %s\n", f->nome);
    printf("Cargo: %s\n", f->cargo);
    printf("Salário: R$ %.2f\n", f->salario);
}

// c) Alterar salário
void alterar_salario(Funcionario *f, float novo_salario)
{
    f->salario = novo_salario;
    printf("Salário atualizado com sucesso!\n");
}

// d) Encontrar maior e menor salário em um vetor
void maior_menor_salario(Funcionario vetor[], int n)
{
    if (n == 0)
    {
        printf("Nenhum funcionário cadastrado.\n");
        return;
    }

    int idx_maior = 0, idx_menor = 0;
    for (int i = 1; i < n; i++)
    {
        if (vetor[i].salario > vetor[idx_maior].salario)
            idx_maior = i;
        if (vetor[i].salario < vetor[idx_menor].salario)
            idx_menor = i;
    }

    printf("\n--- Funcionário com MAIOR salário ---\n");
    printf("Cargo: %s\n", vetor[idx_maior].cargo);
    printf("Salário: R$ %.2f\n", vetor[idx_maior].salario);

    printf("\n--- Funcionário com MENOR salário ---\n");
    printf("Cargo: %s\n", vetor[idx_menor].cargo);
    printf("Salário: R$ %.2f\n", vetor[idx_menor].salario);
}

int main()
{
    int n;
    printf("Quantos funcionários deseja cadastrar? ");
    scanf("%d", &n);
    getchar();

    Funcionario funcionarios[n];

    // Cadastro
    for (int i = 0; i < n; i++)
    {
        printf("\n--- Cadastro do funcionário %d ---\n", i + 1);
        preencher_funcionario(&funcionarios[i]);
    }

    // Listar todos
    for (int i = 0; i < n; i++)
    {
        imprimir_funcionario(&funcionarios[i]);
    }

    // Alterar salário de um funcionário (por identificador)
    int id_busca;
    float novo_salario;
    printf("\nDigite o identificador do funcionário para alterar salário: ");
    scanf("%d", &id_busca);
    for (int i = 0; i < n; i++)
    {
        if (funcionarios[i].identificador == id_busca)
        {
            printf("Novo salário: ");
            scanf("%f", &novo_salario);
            alterar_salario(&funcionarios[i], novo_salario);
            break;
        }
    }

    // Encontrar maior e menor salário
    maior_menor_salario(funcionarios, n);

    return 0;
}