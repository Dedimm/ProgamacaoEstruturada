#include<stdio.h>
#include<stdlib.h>
void aloca(float **p, int tam);
void receba(float *p, int tam);
void multiplica(float *p, int tam);
int main()
{
    float *ponteiro=NULL;
    aloca(&ponteiro,6);
    receba(ponteiro, 6);
    multiplica(ponteiro, 6);
}
void aloca(float **p, int tam)
{
    if((*p=(float*)realloc(*p,tam*sizeof(float)))==NULL)
    exit(1);
}
void receba(float *p, int tam)
{
    int i;
    for(i=0;i<tam;i++,p++)
    {
        printf("\nEndereco: %u - Valor = ", p);
        scanf("%f", p);
    }
}
void multiplica(float *p, int tam)
{
    int i;
    for(i=0;i<tam;i++,p++)
    {
        *p *= 5;
        printf("\nEndereco: %u - Valor: %.2f", p,*p);
    }
}