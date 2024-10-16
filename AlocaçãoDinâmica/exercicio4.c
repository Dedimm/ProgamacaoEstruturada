#include<stdio.h>
#include<stdlib.h>
void aloca(int **p, int tam);
void leitura(int *p);
void mostra(int *p, int tam);
void menor(int *p, int tam, int **p_impar, int *qm);
int main()
{
	int *ptr=NULL, *p_impar=NULL;
	int cont=0, qm;
	char op;
	do{
		aloca(&ptr, cont+1 );
		leitura(ptr + cont);
		cont++;
		printf("Deseja informar mais numero: <S/N> ");
		scanf(" %c", &op);
	}while(op != 'N' && op != 'n');
	mostra(ptr,cont);
	menor(ptr, cont, &p_impar, &qm);
	printf("\n");
    printf("\nImpares gerados:\n");
	mostra(p_impar, qm);

}
void aloca(int **p, int tam)
{
	if((*p = (int*)realloc(*p, tam * sizeof(int)))==  NULL)
	exit(1);
}
void leitura(int *p)
{
	printf("Endereco %i - Numero = ",p );
	scanf("%i", p);
	fflush(stdin);
}
void mostra(int *p, int tam)
{
	int i;
	for(i=0;i<tam;i++,p++)
	{
	printf("\nEndereco %i - Valor = %i", p,*p);
	}
}
void menor(int *p, int tam, int **p_impar, int *qm)
{
	int i, cont=0, sub=0;
    *qm=0;
	for(i=0, cont=0;i<tam/2;i++,cont++)
	{
		sub=*(p+i+cont+1)-*(p+i+cont);
		if(tam % 2 != 0)
		{
			if(i == tam/2)
			{
				sub = (*p + i + cont -1);
			}
		}
        if(sub % 2 != 0)
        {
		aloca(p_impar, (*qm)+1);
		*(*p_impar + *qm) = sub;
		(*qm)++;
        }
	}
}