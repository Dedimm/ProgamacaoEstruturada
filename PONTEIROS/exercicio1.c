#include<stdio.h>
void leitura(float *t, int tam);
void maior_temp(float *t, int tam);
float mediaa(float *t, int tam);
void menor(float *t, int tam, float media);
int main(){
float temperatura[31],media;
int dias, pos_inf[31], qtde=0;

printf("\nTemperatura Diarias\n");
printf("Qtde dias: ");
scanf("%i", &dias);
leitura(temperatura,dias);
media=mediaa(temperatura,dias);
printf("\nA media \x82: %f", media);
maior_temp(temperatura,dias);
menor(temperatura, dias, media);
}
void leitura(float *t, int tam)
{
int i;
for(i=0;i<tam;i++)
{
printf("\nTemperatura - %i dia: ", i+1);
scanf("%f", t++);
}
}
float mediaa(float *t, int tam)
{
int i;
float soma, media;
for(i=0;i<tam;i++,t++)
{
soma += *t;
}
media=soma/tam;
return media;
}
void maior_temp(float *t, int tam)
{
int i, dia;
float maior=0;
for(i=0;i<tam;i++, t++)
{
if(*t > maior)
{
maior = *t;
dia = i+1;
}
}
printf("\nA maior temperatura foi: %1.f, no dia %i", maior, dia);
}
void menor(float *t, int tam, float media)
{
int i, dia;
float sabio;
for(i=0;i<tam;i++,t++)
{
if(*t < media)
{
sabio = *t;
dia = i+i;
printf("\nTemperaturas inferiores a media: %1.f, no dia: %i", sabio, dia);
}
}
}