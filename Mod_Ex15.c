#include <stdio.h>

typedef struct Pesquiza { 
    int idade,filhos;
    char sexo[8];
    float salario;
} Pesquiza;

void Cadastro();
void Estatistica();
Pesquiza registro[2];

int main(){
    
    float mediaSal;
    int maiorId, menorId, count;

    Cadastro();
    for (int i = 0; i < 2; i++) {
       printf("Idade:\t %d\t Sexo:\t %s\t Salário:\t %.2f\t N.Filhos:\t %d\n",registro[i].idade,registro[i].sexo,registro[i].salario,registro[i].filhos); 
    Estatistica(&mediaSal,&menorId,&maiorId,&count);
    printf("A media Salarial dos registros:\t%.2f",mediaSal);
    printf("\nA menor idade dos registros:\t%d",menorId);
    printf("\nA maior idade dos registros:\t%d",maiorId);
    printf("\n%d Homens possuem filhos e recebem até R$ 2.000,00 de salário.",count); 
    }
}

void Cadastro(){
    for (int i = 0; i < 2; i++) {
        printf("\n---------- CADASTRO DE REGISTRO %d -----------\n",i+1);
        printf("Idade: ");
        scanf("%d",&registro[i].idade);
        printf("\nSexo: [M]/[F]? ");
        scanf(" %[^\n]s",registro[i].sexo);
        printf("\nSalário: ");
        scanf("%f",&registro[i].salario);
        printf("\nN. de FIlhos: ");
        scanf("%d",&registro[i].filhos);
    }
}

void Estatistica(float *media, int *menor, int *maior, int *count){
    for (int i = 0; i < 2; i++) {
        *media += registro[i].salario;
        if (registro[i].salario <= 2000) && (registro[i].) {
            $
        }
    }
    *media /= 2;
    *menor = registro[1].idade;
    *maior = registro[1].idade;
    for (int i = 0; i < 2; i++) {
        if (*menor > registro[i].idade) {
            *menor = registro[i].idade;
        }
        if (*maior < registro[i].idade) {
            *maior = registro[i].idade;
        }
    }
}


















