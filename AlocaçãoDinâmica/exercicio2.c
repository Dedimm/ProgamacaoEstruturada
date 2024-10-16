#include<stdio.h>
#include<stdlib.h>
void aloca(float **p,int tam);
void receba(float *p, int tam);
void media(float *p, int tam);
int main()
{
    int cont=0;
    char op;
    float *ponteiro=NULL;
    do{
        aloca(&ponteiro, cont+1);
        printf("\nDeseja continuar acrescentando numero? S/N ");
        scanf(" %c", &op );
        if(op != 'N' && op != 'n')
        cont++;
    } while(op != 'N' && op != 'n');
    receba(ponteiro, cont);
    media(ponteiro, cont);
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
void media(float *p, int tam)
{
    float soma=0, mediaa;
    int i;
    for(i=0;i<tam;i++,p++)
    {
        soma += *p;
    }
    mediaa = soma/tam;
    printf("\nA media dos valores \x82 %.2f", mediaa);
}