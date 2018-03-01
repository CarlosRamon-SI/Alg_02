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
    TMateria *materias;
} TAluno;


int main(){
    
    int n;
    float media;
    TAluno *pAluno;
    pAluno = (TAluno *) malloc(n * sizeof(TAluno));
    printf("Digite a qtde de Registros: ");
    scanf("%d",&n);
    
    if (pAluno != NULL) {
        printf("Memória Alocada com Sucesso!\n\n");
        
        for (int i = 0; i < n; i++) {
            
            //Registrando o Aluno:
            printf("\n--== ALUNO %03d ==--\n\n", i+1);
            printf("Digite seu Nome: ");
            scanf(" %[^\n]s",pAluno[i].nome);
            printf("Digite seu RGA: ");
            scanf(" %s",pAluno[i].RGA);
            printf("Digite a qtde de Disciplinas: ");
            scanf("%d",&pAluno[i].disciplinas);

            pAluno[i].materias = (TMateria *) malloc(sizeof(TMateria) * pAluno[i].disciplinas);
            
            //Verifica sucesso da alocação
            if (pAluno[i].materias != NULL) {
                
                for (int k = 0; k < pAluno[i].disciplinas ; k++) {
                    
                    printf("Digite a Disciplina %02d: ", k+1);
                    scanf(" %[^\n]s",pAluno[i].materias[k].disciplina);
                    printf("Digite a qtde de Avaliações: ");
                    scanf("%d",&pAluno[i].materias[k].qtdeProvas);

                    pAluno[i].materias[k].notasProvas = (float *) malloc(pAluno[i].materias[i].qtdeProvas * sizeof(float));

                    //Verifica sucesso da alocação
                    if (pAluno[i].materias[k].notasProvas != NULL) {
                        
                        for (int j = 0; j < pAluno[i].materias[k].qtdeProvas ; j++) {
                            printf("Valor nota %02d: ", j+1);
                            scanf(" %f",&pAluno[i].materias[k].notasProvas[j]);
                        }

                    } else {
                        printf("001 - Falha ao alocar memória\n");
                    }
                }

            } else {
                printf("002 - Falha ao alocar memória\n");
            }
        }

    } else {
        printf("003 - Falha ao alocar memória\n");
    }

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
}
