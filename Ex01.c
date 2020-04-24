#include <stdlib.h>
#include <stdio.h>

void bubblesort_decrescente(int *v, int n)
{
    int i, continua, aux, fim = n;
    do
    {
        continua = 0;
        for (i = 0; i < fim - 1; i++)
        {
            if (v[i] < v[i + 1])
            {
                aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
                continua = i;
            }
        }
        fim--;
    } while (continua != 0);
}

main()
{

    int i, v[10];

    printf("Digite 10 numeros para serem ordenados na ordem decrescente:\n");
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &v[i]);
    }

    bubblesort_decrescente(v, 10);
    printf("Ordem Decrescente: \n");
    for (i = 0; i < 10; i++)
    {
        printf("%d ", v[i]);
    }
}
