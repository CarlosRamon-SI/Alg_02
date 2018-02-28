#include <stdio.h>

int main(){
    FILE *f;
    char nome[30];
    int idade;
    float salario;
    f = fopen("dados.txt","w");
    if (f == NULL) {
        printf("Falha ao abrir arquivo.");
    } else {
        for (int i = 0; i < 4; i++) {
            printf("Nome: ");
            scanf(" %[^\n]s",nome);
            printf("Idade: ");
            scanf("%d",&idade);
            printf("Salário: ");
            scanf("%f",&salario);
            fprintf(f,"%s %d %.2f\n",nome,idade,salario);
        }
    }
    fclose(f);
}
