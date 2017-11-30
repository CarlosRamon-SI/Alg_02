#include <stdio.h>

int main(){
    FILE *dados;
    char nome[20];
    int idade;
    double salario;
    
    dados = fopen("dados.txt","w");
    if (dados == NULL) {
        printf("Erro de abertura do Arquivo\n");
    } else {
        printf("OK!\n");
    

        for (int i = 0; i < 2; i++) {
            
            printf("Digite seu nome: ");
            scanf(" %[^\n]s",nome);
            printf("\nDigite sua idade: ");
            scanf(" %d",&idade);
            printf("\nDigite o seu Salário: ");
            scanf(" %lf",&salario);

            fprintf(dados,"%s %d %.2lf\n",nome,idade,salario);
        }
    fclose(dados);
    }
}
