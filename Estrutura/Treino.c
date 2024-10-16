#include<stdio.h>
#include<stdlib.h>

typedef struct hotel{
    char nome[80];
    int quarto;
}hotel;

void aloca(hotel **p, int tam);
void leitura(hotel *p);
int main()
{
    hotel *ptr=NULL;
    int op, cont=0;
        printf("Seja bem-vindo, Escolha uma opção: " );
    do{
        printf("\n[1]Check in \n[2]Check Out \n[3]Sair");
        scanf("%i", &op);
        switch(op)
        {
            case 1;
            aloca(&ptr, cont+1);
            leitura(ptr + cont);
            cont++;
            break;
        }
    }
}
void aloca(hotel **p, int tam)
{
    if((*p=(hotel*)realloc(*p,tam*size_of(hotel)))==NULL)
    exit(1);
}
void leitura(hotel *p)
{
    int quarto;
    printf("\nQual seu nome?");
    getchar();
    fgets(p->nome, 80, stdin);
    printf("\nEscolha o tipo de quarto\n [1]Solteiro \n[2]Casal");
    scanf("%i", &quarto);
    if(quarto==1)
    {
        printf("\nTemos quarto de 1 a 10");
        scanf("%i")
    }

}