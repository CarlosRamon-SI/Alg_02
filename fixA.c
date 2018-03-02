#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TMateria {
    char disciplina[30];
    int qtdeProvas;
    float *notasProvas; 
} TMateria;

typedef struct TAluno {
    char nome[30], RGA[13];
    int disciplinas;
    int codigo;
    TMateria *materias;
} TAluno;

typedef struct TNoh {
    TAluno matricula;
    struct TNoh *proximo;
} TNoh;

typedef struct TLista {
    TNoh *cabeca;
    int tamanho;
} TLista;

void inicializar (TLista *lista);
void toList (TLista *lista, TAluno aluno);

int main(){
    
    int n;
    float media;
    TAluno aluno;
    TLista lista;
    FILE *arquivo;
    inicializar(&lista);
    arquivo = fopen("listaAlunos.dat","r+b");
    do {
        fread(&aluno, sizeof(TAluno), 1, arquivo);
        if (!feof(arquivo))
            toList(&lista,aluno);            
    } while (!feof(arquivo));

    /*    
    for (int i = 0; i < n; i++) {
        media = 0;

        printf("\n***********************************\nNome: %s\nRGA: %s\n", pAluno[i].nome, pAluno[i].RGA);
        
        for (int k = 0; k < pAluno[i].disciplinas; k++) {
            printf("\n.:: %s ::.\n\n", pAluno[i].materias[k].disciplina);
            
            for (int j = 0; j < pAluno[i].disciplinas; j++) {
                printf("| %.2f |", pAluno[i].materias[k].notasProvas[j]);
                media += pAluno[i].materias[k].notasProvas[j];
            }

            media /= pAluno[i].materias[k].qtdeProvas;
            printf("\nMedia: %.2f\n", media);
            
            if (media < 7) {
                printf("Prova Final!\n\n");
            } else {
                printf("Aprovado\n\n");
            }
        }
    }

    //Liberar memória alocada
    for (int i = 0; i < n ; i++) {
        for (int l = 0; l < pAluno[i].disciplinas; l++) {
            free(pAluno[i].materias[l].notasProvas);
        }
        free(pAluno[i].materias);            
    }
    free(pAluno);
    */
}

void inicializar ( TLista *lista ) {
    lista->cabeca = NULL;
    lista->tamanho = 0;
}

void toList (TLista *lista, TAluno aluno) {
    TNoh *anterior, *atual;
    TNoh *noh = malloc(sizeof(TNoh));
    noh->matricula = aluno;
    if (noh != NULL) {
        
        if (lista->cabeca == NULL) {
            
            lista->cabeca = noh;
            noh->proximo = atual;
            lista->tamanho++;

        } else {

            atual = lista->cabeca;
            if (noh->matricula.codigo < atual->matricula.codigo) {
                
                lista->cabeca = noh;
                noh->proximo = atual;
                lista->tamanho++;

            } else {

                while(atual != NULL && (noh->matricula.codigo > atual->matricula.codigo)) {
                    
                    anterior = atual;
                    atual = atual->proximo;

                }

                anterior->proximo = noh;
                noh->proximo = atual;
                lista->tamanho++;

            }
        }
    }
}





