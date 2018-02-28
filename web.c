#include <stdio.h>
#define TAM 50

typedef struct {
    int codigo;
    char nome[TAM];
    int ativo;
}Cliente;

void cabecalho(char *titulo) {
    system("clear"); //para GNU/Linux.
    //system("Cls"); //para Windows.
    printf("\n\n--==[%s]==--\n\n", titulo);
    }

