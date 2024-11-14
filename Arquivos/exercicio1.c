#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct RPG{
    char nome[20];
    char nome_personagem[20];
    char classe_social[20];
    char sexualidade[20];
    char meme_favorito[20];
    char timefutebol[20];
    char cidade[20];
}rpg;

void aloca(rpg **p, int tam);
void cadastra(rpg *p);
void grava(rpg *p);
int verifica();
void mostrar(rpg *p, int tam);

int main()
{
    rpg *ptr=NULL;
    int qplayer, op;
    aloca(&ptr, 1);
    qplayer=verifica();
    do{
        printf("\n[1]Cadastrar\n[2]Mostrar Jogadores\n[3]Fim\nOpcao: ");
        scanf("%i", &op);
        switch(op){
            case 1:
            cadastra(ptr);
            qplayer++;
            break;
            case 2:
            mostrar(ptr, qplayer);
        }
    }while(op != 3);
    
}

void aloca(rpg **p, int tam)
{
    if ((*p = (rpg*) realloc(*p, tam * sizeof(rpg))) == NULL)
    exit(1);
}

void cadastra(rpg *p)
{
    printf("\nNome: ");
    getchar();
    gets(p->nome);
    printf("\nNome do personagem: ");
    gets(p->nome_personagem);
    printf("\nCidade: ");
    gets(p->cidade);
    printf("\nClasse social: (pobre, mediano, fodao): ");
    gets(p->classe_social);
    printf("\nSexualidade: ");
    gets(p->sexualidade);
    printf("\nMeme favorito: ");
    gets(p->meme_favorito);
    printf("Time futebol: ");
    gets(p->timefutebol);
    grava(p);
}

void grava(rpg *p)
{
    FILE *fptr=NULL;
    if((fptr=fopen("ficha.bin", "ab"))==NULL)
    {
        printf("\nErro ao abrir o arquivo");
    }
    else{
        fwrite(p, sizeof(rpg), 1, fptr);
    }
    fclose(fptr);
}

int verifica()
{
    long int cont=0;
    FILE *fptr=NULL;
    if((fptr=fopen("ficha.bin", "rb"))==NULL)
    {
        return cont;
    }
    else{
        fseek(fptr, 0, 2);
        cont=ftell(fptr)/sizeof(rpg);
        fclose(fptr);
        return cont;
    }
}

void mostrar(rpg *p, int tam)
{
    FILE *fptr=NULL;
    int i;
    if((fptr=fopen("ficha.bin", "rb"))==NULL)
    {
        printf("\nErro ao abrir o arquivo");
    }
    else{
        printf("\n--------------------");
        for(i=0;i<tam;i++)
        {
            fseek(fptr,i*sizeof(rpg), 0);
            fread(p,sizeof(rpg), 1, fptr);
            printf("\nNome: %s", p->nome);
            printf("\nNome personagem: %s", p->nome_personagem);
            printf("\nCidade: %s", p->cidade);
            printf("\nSexualidade: %s", p->sexualidade);
            printf("\nMeme favorito: %s", p->meme_favorito);
            printf("\nTime futebol: %s", p->timefutebol);
            printf("\nClase social: %s ", p->classe_social);
            printf("\n-----------------------------");
        }
    }
}