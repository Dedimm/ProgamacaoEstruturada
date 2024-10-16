#include<stdio.h>
int main()
{
    int vetor[5], *ponteiro;
    ponteiro = vetor;
    printf("Preencha o vetor:\n");
    for(int i = 0;i<5;i++,ponteiro++)
    {
        scanf("%i",ponteiro);
    }
    ponteiro = vetor;
    for(int i=0;i<5;i++, ponteiro++)
    {
        printf("\nnum[%i] = %i", i, *ponteiro);
    }
}