#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct show{
    char cantor[30];
    int registro;
    int ingressos;
    float valor;
}show;

typedef struct pessoa{
    char cpf[20];
    int reg;
    char nome[30];
    int qtde;
}pessoa;

int main()
{
    show *pshow=NULL;
    pessoa *ptr=NULL;
    int op, i;
    for(i=;i<5;i++)
    {
        cadastroShow(&pshow + (i+1));
    }
}