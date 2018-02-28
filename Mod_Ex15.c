#include <stdio.h>

typedef struct Pesquiza { 
    int idade,filhos,sexo;
    float salario;
} Pesquiza;

void Cadastro();
void Estatistica();
Pesquiza registro[2];

int main(){
    float mediaSal;
    int maiorId, menorId, counter;

    Cadastro();
    for (int i = 0; i < 2; i++) {
       printf("Idade:\t %d\t Sexo:\t %d\t Salário:\t %.2f\t N.Filhos:\t %d\n",registro[i].idade,registro[i].sexo,registro[i].salario,registro[i].filhos);
    }
    Estatistica(&mediaSal,&menorId,&maiorId,&counter);
    printf("A media Salarial dos registros:\t%.2f",mediaSal);
    printf("\nA menor idade dos registros:\t%d",menorId);
    printf("\nA maior idade dos registros:\t%d",maiorId);
    printf("\n%d Homens possuem filhos e recebem até R$ 2.000,00 de salário.\n",counter); 
}

void Cadastro(){
    char aux;
    int ver = 0;
    for (int i = 0; i < 2; i++) {
        printf("\n---------- CADASTRO DE REGISTRO %d -----------\n",i+1);
        printf("Idade: ");
        scanf("%d",&registro[i].idade);
        printf("\nSexo: [M]/[F]? ");
        do {
            scanf(" %c",&aux);
        if ((aux == 'F') || (aux == 'f')) {
            registro[i].sexo = 0;
            ver = 1;
        } else if ((aux == 'M') || (aux == 'm')) {
            registro[i].sexo = 1;
            ver = 1;
        } else {
            printf("\nValor informado INCORRETO. Tente novamente [M]/[F].\n");
        }
        } while (ver != 1);
        printf("\nSalário: ");
        scanf("%f",&registro[i].salario);
        printf("\nN. de FIlhos: ");
        scanf("%d",&registro[i].filhos);
    }
}

void Estatistica(float *media, int *menor, int *maior, int *count){
    *count = 0;
    for (int i = 0; i < 2; i++) {
        *media += registro[i].salario;
        if (registro[i].sexo = 1) {
            if ((registro[i].salario <= 2000) && (registro[i].filhos >= 1)) {
                ++*count;
            }
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


















