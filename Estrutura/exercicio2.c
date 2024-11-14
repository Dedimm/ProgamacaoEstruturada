#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void aloca(aluno **ptr, int tam);
void leitura(aluno *ptr);
int buscar(aluno *ptr, int tam);
void notas(aluno *ptr);
void mostrar(aluno *ptr);

typedef struct aluno
{
    char nome[80];
    char RA[7];
    float notas[2];
    float media;
} aluno;

int main()
{
    int op, cont = 0, achou;
    aluno *ptr = NULL;
    do
    {
        printf("[1]Cadastro\n[2]Insira nota do aluno\n[3]Alunos\n[4]Fim \nopcao:");
        scanf("%i", &op);
        switch (op)
        {
        case 1:
            aloca(&ptr, cont + 1);
            leitura(ptr + cont);
            cont++;
            break;
        case 2:
            achou = busca(ptr, cont);
            if (achou != -1)
            {
                notas(ptr + achou);
            }
            else{
                printf("\nAluno nao encontrado");
            }
            break;
        case 3:
            achou = busca(ptr, cont);
            mostrar(ptr + achou);
        }
    } while (op != 4);
}

void aloca(aluno **ptr, int tam)
{
    if ((*ptr = (aluno *)realloc(*ptr, tam * sizeof(aluno))) == NULL)
        exit(1);
}

void leitura(aluno *ptr)
{
    printf("\nNome: ");
    gets(ptr->nome);
    fflush(stdin);
    printf("\nRA: ");
    gets(ptr->RA);
    fflush(stdin);
    printf("\n--CADASTRO REALIZADO--");
    system("pause");
}

int buscar(aluno *ptr, int tam)
{
    char aux[7];
    int i;
    printf("\nInsira seu RA: ");
    gets(aux);
    fflush(stdin);
    for (i = 0; i < tam; i++, ptr++)
    {
        if (strcmp(aux, ptr->RA) == 0)
            return i;
    }
    return -1;
}

void notas(aluno *ptr)
{
    float conta;
    printf("\nInsira a nota da primeira prova: ");
    scanf("%f", *(ptr->notas + 0));
    printf("\nInsira a nota da segunda prova: ");
    scanf("%f", *(ptr->notas + 1));
    conta = (*(ptr->notas + 0) + *(ptr->notas + 1)) / 2;
    ptr->media = conta;
}

void mostrar(aluno *ptr)
{
    printf("----------------");
    printf("\nNome: ", ptr->nome);
    printf("\nRA:", ptr->RA);
    printf("\nNota 1: ", *(ptr->notas + 0));
    printf("\nNota 2: ", *(ptr->notas + 1));
    printf("\nMedia: ", ptr->media);
}
