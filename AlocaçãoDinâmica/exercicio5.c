#include<stdio.h>
#include<stdlib.h>
void alocar(int **p, int tam);
void leitura(int *p, int tam);
void mostrarinverso(int *p, int tam);
int main()
{
    int *ptr=NULL, cont;
    printf("\nQuantos numero deseja usar? ");
    scanf("%i", &cont);
    fflush(stdin);
    alocar(&ptr, cont);
    leitura(ptr, cont);
    mostrarinverso(ptr, cont);
}
void alocar(int **p, int tam)
{
    if((*p=(int*)realloc(*p, tam * sizeof(int)))==NULL)
    exit(1);
}
void leitura(int *p, int tam)
{
    int i;
    for(i=0;i<tam;i++,p++)
    {
        printf("\nEndereco: %i Numero: ", p);
        scanf("%i", p);
        fflush(stdin);
    }
}
void mostrarinverso(int *p, int tam)
{
    int i;
    p+=tam-1;
    for(i=tam-1;i>=0;i--,p--)
    {
        printf("\n%i", *p);
    }
}