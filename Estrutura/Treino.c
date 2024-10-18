#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct hospede
{
    int quarto;
    char nome[80];
    int acompanhante;
    char categoria;
    int dias;
} hospede;

typedef struct quarto
{
    int num;
    char categoria;
    char status;
}quarto;

void aloca_quarto(quarto **p_quarto, int qtd_quarto);
void aloca_hospede(hospede **p_hospede, int qtd_hospede);

void cadastro_quarto(quarto *p_quarto, char categoria);
void cadastro_hospede(hospede *p_hospede, quarto *p_quarto, int qtd_quarto);

int busca_quarto(quarto *p_quarto, int qtd_quarto, char categoria, char status);
int busca_hospede(hospede *p_hospede, quarto *p_quarto, int qtd_hospede);

void mostra_quarto(quarto *p_quarto, int qtd_quarto);
void mostra_hospede(hospede *p_hospede, int hospede);

void checkout(hospede *p_hospede, quarto *p_quarto, int qtd_hospede, int qtd_quarto);

int main()
{
    quarto *p_quarto = NULL;
    hospede *p_hospede = NULL;
    int qtd_quarto = 0, qtd_hospede = 0, op;
    char categoria;

    for (int i = 0; i < 5; i++)
    {
        if (i < 2)
        {
            categoria = 'F';
        }
        else
        {
            categoria = 'S';
        }
        aloca_quarto(&p_quarto, qtd_quarto + 1);
        cadastro_quarto(p_quarto + qtd_quarto, categoria);
        qtd_quarto++;
    }
    do
    {
        printf("\nCheck-in[1] \nCheck-out[2] \nHospedes[3] \nQuartos[4] \nSair[5] \n");
        scanf("%i", &op);
        fflush(stdin);
        switch (op)
        {
        case 1:
            aloca_hospede(&p_hospede, qtd_hospede + 1);
            cadastro_hospede(p_hospede + qtd_hospede, p_quarto, qtd_quarto);
            qtd_hospede++;
            break;
        case 2:
            checkout(p_hospede, p_quarto, qtd_hospede, qtd_quarto);
            break;
        case 3:
            mostra_hospede(p_hospede, qtd_hospede);
            break;
        case 4:
            mostra_quarto(p_quarto, qtd_quarto);
            break;
        }
    } while (op != 5);
    return 0;
}

void aloca_quarto(quarto **p_quarto, int qtd_quarto)
{
    if ((*p_quarto = (quarto *)realloc(*p_quarto, qtd_quarto * sizeof(quarto))) == NULL)
        exit(1);
}

void aloca_hospede(hospede **p_hospede, int qtd_hospede)
{
    if ((*p_hospede = (hospede *)realloc(*p_hospede, qtd_hospede * sizeof(hospede))) == NULL)
        ;
}

void cadastro_quarto(quarto *p_quarto, char categoria)
{
    static int num = 1;
    p_quarto->num = num++;
    p_quarto->categoria = categoria;
    p_quarto->status = 'L';
}

void cadastro_hospede(hospede *p_hospede, quarto *p_quarto, int qtd_quarto)
{
    int acompanhantes, dias, quarto;
    printf("\nDigite seu nome: ");
    fgets(p_hospede->nome, 80, stdin);
    fflush(stdin);
    do
    {
        printf("Digite a quantidade de acompanhantes (max: 3): ");
        scanf("%i", &acompanhantes);
        if (acompanhantes < 0 || acompanhantes > 3)
            printf("\nQuantidade invalida");

    } while (acompanhantes < 0 || acompanhantes > 3);
    p_hospede->acompanhante = acompanhantes;
    fflush(stdin);
    if (acompanhantes == 0)
    {
        quarto = busca_quarto(p_quarto, qtd_quarto, 'S', 'L');
        p_hospede->categoria = 'S';
        if (quarto < 0)
        {
            quarto = busca_quarto(p_quarto, qtd_quarto, 'F', 'L');
            p_hospede->categoria = 'F';
        }
        (p_quarto + quarto)->status = 'O';
        p_hospede->quarto = (p_quarto + quarto)->num;
    }
    else
    {
        quarto = busca_quarto(p_quarto, qtd_quarto, 'F', 'L');
        p_hospede->categoria = 'F';
        (p_quarto + quarto)->status = 'O';
        p_hospede->quarto = (p_quarto + quarto)->num;
    }
    do
    {
        printf("\nDigite o tempo de estadia: ");
        scanf("%i", &dias);
        if (dias < 0)
        {
            printf("\nQuantidade inválida.");
        }
    } while (dias <= 0);
    p_hospede->dias = dias;
    fflush(stdin);
}

int busca_quarto(quarto *p_quarto, int qtd_quarto, char categoria, char status)
{
    for (int i = 0; i < qtd_quarto; i++)
    {
        if ((p_quarto + i)->categoria == categoria)
        {
            if ((p_quarto + i)->status == status)
            {
                return i;
            }
        }
    }
    return -1;
}

void mostra_quarto(quarto *p_quarto, int qtd_quarto)
{
    system("cls");
    for (int i = 0; i < qtd_quarto; i++)
    {
        printf("Quarto - [%i]\n", (p_quarto + i)->num);
        printf("Categoria - %s\n", ((p_quarto + i)->categoria) == 'F' ? "Familiar" : "Solteiro");
        printf("Status: %s\n", ((p_quarto + i)->status) == 'L' ? "Livre" : "Ocupado");
        printf("-------------\n");
    }
}

void mostra_hospede(hospede *p_hospede, int qtd_hospede)
{
    system("cls");
    for (int i = 0; i < qtd_hospede; i++)
    {
        printf("Hospede: %s", (p_hospede + i)->nome);
        printf("Acompanhantes: %i\n", (p_hospede + i)->acompanhante);
        printf("Categoria: %s\n", ((p_hospede + i)->categoria) == 'F' ? "Familiar" : "Solteiro");
        printf("Quarto: %i\n", (p_hospede + i)->quarto);
        printf("Tempo de permanencia: %i dias\n", (p_hospede + i)->dias);
        printf("--------------------\n");
    }
}

int busca_hospede(hospede *p_hospede, quarto *p_quarto, int qtd_hospede)
{
    for (int i = 0; i < qtd_hospede; i++)
    {
        if ((p_hospede + i)->quarto == -1)
        {
            return i;
        }
    }
    return -1;
}

void checkout(hospede *p_hospede, quarto *p_quarto, int qtd_hospede, int qtd_quarto)
{
    int num_quarto, pos_quarto;
    char op;
    do
    {
        printf("\nDigite o numero do quarto que voce deseja: ");
        scanf("%i", &num_quarto);
        fflush(stdin);

        for (int i = 0; i < qtd_quarto; i++)
        {
            if ((p_quarto + i)->num == num_quarto)
            {
                if ((p_quarto + i)->status == 'O')
                {
                    (p_quarto + i)->status == 'L';
                    pos_quarto = num_quarto;
                    break;
                }
            }
            else
            {
                pos_quarto = -1;
            }
        }

        if (pos_quarto < 0)
        {
            printf("O quarto indicado esta livre ou nao existe. \n");
            printf("Deseja tentar novamente (S/N): ");
            scanf("%c", &op);
            fflush(stdin);
        }
        if (op == 'N' || op == 'n')
            break;
    } while (pos_quarto < 0);
    for (int i = 0; i < qtd_hospede; i++)
    {
        if ((p_hospede + i)->quarto == num_quarto)
        {
            printf("Quarto: %i\n", num_quarto);
            printf("Nome: %s", (p_hospede + i)->nome);
            printf("Categoria: %s\n", ((p_hospede + i)->categoria) == 'F' ? "Familiar" : "Solteiro");
            printf("Acompanhantes: %i\n", (p_hospede + i)->acompanhante);
            printf("Dias: %i\n", (p_hospede + i)->dias);
            printf("Total Pago: R$%i\n", ((((p_hospede + i)->categoria) == 'F') ? (((p_hospede + i)->acompanhante + 1) * 45) : 85) * (p_hospede + i)->dias);
        }
    }
}
