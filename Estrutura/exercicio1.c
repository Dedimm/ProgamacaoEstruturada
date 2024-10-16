#include<stdio.h>
#include<stdlib.h>

typedef struct banco{
    int conta;
    char nome[80];
    float valor;
}banco;

void aloca(banco **p, int tam);
void leitura(banco *p);
int* movimento(banco *p, int tam);
void acao(banco *p, int op);

int main()
{
    banco *ptr=NULL;
    int cont=0, op, achou;
    do{
        printf("\nEscolha uma opcao:\n[1]Cadastro \n[2]Deposito \n[3]Retirada \n[4]Fim\n");
        scanf(" %i", &op);
        switch (op)
        {
        case 1: 
            aloca(&ptr, cont+1);
            leitura(ptr + cont);
            cont++;
            break;
            case 2:
            case 3: achou = movimento(ptr, cont);
            if(achou != -1)
            {
                acao(ptr + achou, op);
            }
            else
            {
                printf("\nConta nao cadastrada\n");
            }
        }
    }while(op != 4);
}
void aloca(banco **p, int tam)
{
    if((*p=(banco*)realloc(*p,tam*sizeof(banco)))==NULL)
    exit(1);
}
void leitura(banco *p)
{
    static int n=1000;
    printf("Digite seu nome: ");
    getchar();
    fgets(p->nome, 80, stdin);
    p->conta=n;
    p->valor = 0;
    printf("\nConta cadastrada: %i", p->conta);
    n += 100;
}
int* movimento(banco *p, int tam)
{
    int aux, i;
    printf("\nDigite sua conta:");
    scanf("%i", &aux);
    for(i=0;i<tam;i++,p++)
    {
        if(aux==p->conta)
        {
            return i;
        }
    }
        return -1;
}
void acao(banco *p,int op)
{
    int i;
    float dep, ret;
    printf("\nBem vindo: %s", p->nome);
    if(op==2)
    {
        printf("\nInsira a quantia do deposito: ");
        scanf("%f", &dep);
        p->valor+=dep;
        printf("Saldo final: %.2f", p->valor);
    }
    else if(op==3)
    {
        printf("\nInsira o valor da retirada: ");
        scanf("%f", &ret);
        if(ret<=p->valor)
        {
        p->valor-=ret;
        printf("valor final: %2.f", p->valor);
        }
        else
        printf("Saldo insuficiente");
    }
}