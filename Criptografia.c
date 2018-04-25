#include <stdio.h>

char menu();
void crip();
void decrip();
void chave(char *k);

int main(){
    FILE *arquivo;
    char nomeArquivo[100], key;
    int resp;
    
    resp = menu();

    switch (resp) {
        case 0:
            crip();
            
            break;
        case 1:
            decrip();
            
            break;
        default:
            printf("\nFinalizando!\n");
    }
}

char menu(){
    char opcao;
    printf("Selecione:\n\n");
    printf("[C] - Criptografia;\n");
    printf("[D] - Decriptografia;\n\n");
    scanf("%c",&opcao);
    if(opcao == 'C' || opcao == 'c'){
        return 0;
    } else if(opcao == 'd' || opcao == 'D'){
        return 1;
    } else {
        return 2;
    }
}

void crip(){
    printf("Opção de Criptografar selecionada\n");

}

void decrip(){
    printf("Opção de Decriptografar selecionada\n");

}

void chave(char *k){
    printf("\nDigite uma chave para realização do processo.\nA Chave deve conter 8 ou 16 caracteres.\n");
    scanf(" %s",k);

}
