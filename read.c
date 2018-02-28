#include <stdio.h>
#include <string.h>

typedef struct TPessoa {
    char nome[30];
    int idade;
    float salario;
} TPessoa;

int main() {
    TPessoa pessoas[4];
    FILE *f = fopen("dados.txt","r");
    char aux;

    while (!feof(f)){
        fscanf(f,"%c",&aux);
        printf("%c",aux);
    }
    fclose(f);
}
