#include <stdio.h>

typedef struct TCadastro {
    char nome[30];
    float salario;
} TCadastro;

FILE * abrirArquivo(char T[20], char M);
void fecharArquivo(FILE *arquivo);
void inserir(TCadastro *novo, FILE *arquivo);
void exibir(FILE *arquivo);

int main(){
    FILE *FP;
    char title[20],menu;

    TCadastro registro;

    printf("Digite o nome do arquivo: ");
    scanf(" %s",title);
    printf("--== [MENU] ==--\n\n");
    printf("[L] - Ler arquivo.\n");
    printf("[E] - Escrever arquivo.\n");
    printf("[A] - Ler e Escrever arquivo.\n");

    scanf(" %c",&menu);
    do {
        if (menu >= 97) 
            menu -= 32;
    } while (menu != 'L' && modo != 'E' && modo != 'A');
    switch (menu) {
        case :
            
            break;
        default:
            
    }

    if(abrirArquivo(title,modo) == NULL) {
        printf("Falha ao abrir arquivo!\n");
    } else {
        FP = abrirArquivo(title,modo);
        printf("Arquivo Aberto com Sucesso!\n\n");
    }
    inserir(&registro,FP);
    if(fclose(FP) != 0) {
        printf("Falha ao fechar arquivo!\n");
    } else {
        exibir(FP);
    }
}

FILE * abrirArquivo(char T[20], char M) {
    switch (M) {
        case 'L':
            return fopen(T,"r");            
            break;
        case 'E':
            return fopen(T,"w");
            break;
        case 'A':
            return fopen(T,"a");
            break;
    }
}

void fecharArquivo(FILE *arquivo) {

}

void inserir(TCadastro *novo, FILE *arquivo){
    printf("Entre com seu Nome: ");
    scanf(" %s",novo->nome);
    printf("Entre com seu Salário: ");
    scanf("%f",&novo->salario);

    fprintf(arquivo,"%s %.2f \n",novo->nome,novo->salario);
}

void exibir(FILE *arquivo) {

}
