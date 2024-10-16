#include<stdio.h>
#include<stdlib.h>
void aloca(int **p, int tam);
void leitura(int *p)
int main()
{
    int *ptr=NULL, cont=0;
    char op;
    do{
        aloca(&ptr, cont + 1);
        leitura(ptr + cont);
        cont++;
        printf("Espaco alocado, Deseja alocar mais espaço? <S/N>: ");
        scanf(" %c", &op);
    } while (op != 'n' && op != 'N')
    {
        
    }
    
}