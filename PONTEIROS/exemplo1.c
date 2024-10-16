#include<stdio.h>
int main()
{
    int numero, *pont;
    pont = &numero;
    printf("\nInsira um numero: ");
    scanf("%i", &numero);
    printf("\nForma direta: %i", numero);
    printf("\nForma indireta: %i", *pont);
    printf("\nEndereco da variavel - diretamente: %i", &numero);
    printf("\nEndereco da variavel - indiretamente: %i", pont);
}