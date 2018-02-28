#include <stdio.h>
#include <string.h>

int main(){
    char nome[30];
    int idade,i = 0;
    float salario;
    FILE *f = fopen("dados.txt","a");
    if (f == NULL ) {
        printf("Erro no arquivo!\n");
    } else {
        printf("Digite seu nome: ");
        scanf(" %[^\n]s",nome);
        while(nome[i] != '\0'){
            i++;
        }
        printf("valor de i %d\n",i);
        fprintf(f,"%s ",nome);
        printf("Digite sua idade: ");
        scanf("%d",&idade);
        if(i>=8){
            fprintf(f,"\t%02d",idade);
        } else {
            fprintf(f,"\t\t%02d",idade);
        }
        printf("Digite seu salário: ");
        scanf("%f",&salario);
        fprintf(f,"\t%08.2f\n",salario);
        fclose(f);
    }
}
