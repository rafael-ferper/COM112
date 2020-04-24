#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define QTDE 10
#define STR_LEN 30

typedef struct
{
    int codigo;
    char descricao[STR_LEN];
    float preco;
} produto;

produto *cria_vet(int tam)
{

    int i;
    produto *vet = (produto *)calloc(tam, sizeof(produto));

    for (i = 0; i < tam; i++)
    {

        setbuf(stdin, NULL);
        printf("\nDigite os dados do Produto %d:", i + 1);
        printf("\nCodigo: ");
        scanf("%d", &vet[i].codigo);
        setbuf(stdin, NULL);
        printf("Descricao: ");
        scanf("%[^\n]s", vet[i].descricao);
        printf("Preco (R$): ");
        scanf("%f", &vet[i].preco);
    }

    return vet;
}

void print_vet(produto *vet, int tam)
{

    int i;

    for (i = 0; i < tam; i++)
    {
        printf("\nProduto %d: \nCODIGO: %d \nDESCRICAO: %s \nPRECO: %7.2f Reais \n", i + 1, vet[i].codigo, vet[i].descricao, vet[i].preco);
    }
}

void troca(produto *x, produto *y)
{

    produto aux;

    aux = *x;
    *x = *y;
    *y = aux;
}

void ordena_alfabetico(produto *vet, int tam)
{

    int i, j, menor;

    for (i = 0; i < tam - 1; i++)
    {

        menor = i;
        for (j = i + 1; j < tam; j++)
        {
            if (strcmp(vet[j].descricao, vet[menor].descricao) < 0)
            {
                menor = j;
            }
        }

        troca(&vet[menor], &vet[i]);
    }

    printf("\n\nOs produtos ordenados em ordem alfabetica de acordo com a descricao:");
    print_vet(vet, tam);
}

int busca_codigo(produto *vet, int tam, int cod)
{

    int i, cont = 1;
    for (i = 0; i < tam - 1; i++)
    {
        if (cod == vet[i].codigo)
        {
            printf("\nO numero de comparacoes feitas foi: %d", cont);
            return 0;
        }
        else
            cont++;
    }
    return -1;
}

int main()
{

    int tam = QTDE, num;
    int cod;

    produto *vet = cria_vet(tam);
    ordena_alfabetico(vet, tam);

    printf("\n\nInsira o codigo de algum produto para ser buscado: ");
    scanf("%d", &cod);
    num = busca_codigo(vet, tam, cod);
    if (num == -1)
    {
        printf("Nao foi possivel achar o codigo %d", cod);
    }
    return 0;
}
