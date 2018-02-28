#include <stdio.h>
#include <string.h>
#define TAM 3

typedef struct TCadastro {
    char nome[30];
    int idade,codigo;
}TCadastro;

typedef struct Cadastro {
    char nome[30];
    int idade, codigo;
} Cadastro;

int main() {
    int i = 0;
    FILE *file;
    char resp;
    TCadastro registro;
    Cadastro reg;

    //gravar dados
    file = fopen("dados.bin","wb+");
    if (file == NULL) {
        printf("Erro ao abrir arquivo.\n");
    } else {
        do {
            printf("Arquivo aberto com sucesso!\n");
            registro.codigo = 1;
            printf("Digite o nome: ");
            scanf(" %s", registro.nome);
            printf("Digite a idade: ");
            scanf("%d", &registro.idade);
            fwrite(&registro, sizeof(registro), 1, file);
            printf("Deseja continuar ? [S/N]");
            scanf(" %c", &resp);
            i++;
        } while (resp == 's' || resp == 'S');
    }
    fclose(file);

    file = fopen("dados.bin","rb");
    if (file == NULL) {
        printf("Erro ao abrir arquivo.\n");
    } else {
    //ler dados
    rewind(file);
    while(!feof(file)) {
        fread(&reg, sizeof(Cadastro), 1, file);
        if (!feof(file)) {
            if (reg.codigo == 1) {
                printf("%s\t%d\n", reg.nome, reg.idade);
            }
        }
    }
    }
    fclose(file);
}
