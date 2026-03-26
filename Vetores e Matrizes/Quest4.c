#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 100 // Tamanho máximo para cada nome

int main()
{
    int numPessoas;
    printf("Quantas pessoas deseja armazenar? ");
    scanf("%d", &numPessoas);
    getchar(); // Consumir o '\n' deixado pelo scanf

    // Aloca o vetor de ponteiros para os nomes (strings)
    char **nomes = (char **)malloc(numPessoas * sizeof(char *));
    if (nomes == NULL)
    {
        printf("Erro de alocação para os nomes!\n");
        return 1;
    }

    // Aloca o vetor de idades
    int *idades = (int *)malloc(numPessoas * sizeof(int));
    if (idades == NULL)
    {
        printf("Erro de alocação para as idades!\n");
        free(nomes);
        return 1;
    }

    // Leitura dos dados
    for (int i = 0; i < numPessoas; i++)
    {
        // Aloca espaço para o nome (MAX_NOME caracteres)
        nomes[i] = (char *)malloc(MAX_NOME * sizeof(char));
        if (nomes[i] == NULL)
        {
            printf("Erro de alocação para o nome %d\n", i + 1);
            // Libera o que já foi alocado antes de sair
            for (int j = 0; j < i; j++)
                free(nomes[j]);
            free(nomes);
            free(idades);
            return 1;
        }

        printf("Digite o nome completo da pessoa %d: ", i + 1);
        fgets(nomes[i], MAX_NOME, stdin);
        // Remove o '\n' do final, se presente
        nomes[i][strcspn(nomes[i], "\n")] = '\0';

        printf("Digite a idade de %s: ", nomes[i]);
        scanf("%d", &idades[i]);
        getchar(); // Limpa o buffer para o próximo nome
    }

    // Exibe os nomes e idades
    printf("\nPessoas cadastradas:\n");
    for (int i = 0; i < numPessoas; i++)
    {
        printf("Nome: %s, Idade: %d\n", nomes[i], idades[i]);
    }

    // Libera a memória
    for (int i = 0; i < numPessoas; i++)
    {
        free(nomes[i]); // Libera cada string
    }
    free(nomes);  // Libera o vetor de ponteiros
    free(idades); // Libera o vetor de idades

    return 0;
}