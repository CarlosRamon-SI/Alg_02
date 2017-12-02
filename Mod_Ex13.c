/**
 * NOME : CARLOS RAMON MOREIRA LEITE
 * RGA : 201711316032
 * */

#include <stdio.h>

int CalculaTensao(int resis, int corre);

int main(){
    int resistencia[10], corrente[10],tensao[10];
    for (int i = 0; i < 9; i++) {
       printf("\nDigite os valores Resistência e Corrente para calcular sua Tensão:\n");
       scanf("%d %d",&resistencia[i],&corrente[i]);
       tensao[i] = CalculaTensao(resistencia[i],corrente[i]); 
    }
    for (int i = 0; i < 9; i++) {
        printf("Tensão de %d & %d é: %d.\n",resistencia[i],corrente[i],tensao[i]);
    }
}

int CalculaTensao(int resis, int corre){
    int x = resis;
    for (int i = 1; i < corre; i++) {
       x *= resis;
    }
    return x;
}
