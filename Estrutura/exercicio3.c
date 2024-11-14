#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pessoa
{
    char nome[31];
    char fone[21];
} pessoa;

typedef struct data
{
    int dia;
    int mes;
    int ano;
} data;

void aloca(pessoa **ptr, int tam);
void aloca_data(data **ptr, int tam);
void leitura(pessoa *ptr, data *ptr_data, int tam);
int buscar(pessoa *ptr, int tam);
void mostrar_telefone(pessoa *ptr, data *ptr_data);
void mostra_lista(pessoa *ptr, data *ptr_data, int tam);

int main()
{
    data *ptr_data = NULL;
    pessoa *ptr_pessoa = NULL;
    int cont = 0, op, achou;
    do
    {
        printf("[1]Cadastro\n[2]Pessoas\n[3]Lista\nOpcao: ");
        scanf("%i", &op);
        switch (op)
        {
        case 1:
            aloca(&ptr_pessoa, cont + 1);
            aloca_data(&ptr_data, cont + 1);
            leitura(ptr_pessoa + cont, ptr_data + cont, cont);
            cont++;
            break;
        case 2:
            achou = buscar(ptr_pessoa, cont);
            if (achou != -1)
            {
                mostrar_telefone(ptr_pessoa + achou, ptr_data + achou);
            }
            else
            {
                printf("\nEssa pessoa nao esta em nosso sistema");
            }
            break;
        case 3:
            mostra_lista(ptr_pessoa, ptr_data, cont);
        }
    }while(op != 4);
}

void aloca(pessoa **ptr, int tam)
{
    if ((*ptr = (pessoa *)realloc(*ptr, tam * sizeof(pessoa))) == NULL)
        exit(1);
}
void aloca_data(data **ptr, int tam)
{
    if ((*ptr = (data *)realloc(*ptr, tam * sizeof(data))) == NULL)
        exit(1);
}

void leitura(pessoa *ptr, data *ptr_data, int tam)
{
    printf("\nNome: ");
    getchar();
    gets(ptr->nome);
    fflush(stdin);
    printf("\nTelefone: ");
    gets(ptr->fone);
    printf("\nData de nascimento: ");
    printf("\nDia: ");
    scanf("%i", &ptr_data->dia);
    fflush(stdin);
    printf("\nMes: ");
    scanf("%i", &ptr_data->mes);
    fflush(stdin);
    printf("\nAno: ");
    scanf("%i", &ptr_data->ano);
    fflush(stdin);
}

int buscar(pessoa *ptr, int tam)
{
    int i;
    char aux[31];
    printf("\nInsira o nome da pessoa desejada: ");
    getchar();
    gets(aux);
    fflush(stdin);
    for (i = 0; i < tam; i++, ptr++)
    {
        if (strcmp(aux, ptr->nome) == 0)
        return i;
    }
    return -1;
}

void mostrar_telefone(pessoa *ptr, data *ptr_data)
{
    printf("\n----------------");
    printf("\nNome: %s", ptr->nome);
    printf("\nTelefone: %s", ptr->fone);
    printf("\nData de nascimento: %i de %i de %i", ptr_data->dia, ptr_data->mes, ptr_data->ano);
    printf("\n----------------\n");
}

void mostra_lista(pessoa *ptr, data *ptr_data, int tam)
{
    int i;
    for (i = 0; i < tam; i++, ptr++, ptr_data++)
    {
        printf("\n-----------------\n");
        printf("\nNome: %s", ptr->nome);
        printf("\nTelefone: %s", ptr->fone);
        printf("\nData de nascimento: %i de %i de %i\n", ptr_data->dia, ptr_data->mes, ptr_data->ano);
    }
}