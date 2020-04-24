#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define QTDE 10
#define STR_LEN 30

typedef struct
{
    char nome[STR_LEN];
    float salario;
} funcionario;

funcionario *cria_vet(int tam)
{

    int i;
    funcionario *vet = (funcionario *)calloc(tam, sizeof(funcionario));

    for (i = 0; i < tam; i++)
    {

        setbuf(stdin, NULL);
        printf("\nDigite os dados do funcionario %d:\nNome: ", i + 1);
        scanf("%[^\n]s", vet[i].nome);
        printf("Salario (R$): ");
        scanf("%f", &vet[i].salario);
    }

    return vet;
}

void print_vet(funcionario *vet, int tam)
{

    int i;

    printf("\nSALARIO  NOME\n");

    for (i = 0; i < tam; i++)
    {
        printf("%7.2f  %s\n", vet[i].salario, vet[i].nome);
    }
}

void troca(funcionario *x, funcionario *y)
{

    funcionario aux;

    aux = *x;
    *x = *y;
    *y = aux;
}

void ordena_salario_decrescente(funcionario *vet, int tam)
{

    int i, j, maior;

    for (i = 0; i < tam - 1; i++)
    {

        maior = i;
        for (j = i + 1; j < tam; j++)
        {
            if (vet[j].salario > vet[maior].salario)
            {
                maior = j;
            }
        }

        troca(&vet[maior], &vet[i]);
    }
}

void ordena_nome_alfabetico(funcionario *vet, int tam)
{

    int i, j, menor;

    for (i = 0; i < tam - 1; i++)
    {

        menor = i;
        for (j = i + 1; j < tam; j++)
        {
            if (strcmp(vet[j].nome, vet[menor].nome) < 0)
            {
                menor = j;
            }
        }

        troca(&vet[menor], &vet[i]);
    }
}

int main()
{

    int tam = QTDE;

    funcionario *vet = cria_vet(tam);

    ordena_salario_decrescente(vet, tam);
    print_vet(vet, tam);

    ordena_nome_alfabetico(vet, tam);
    print_vet(vet, tam);

    return 0;
}
