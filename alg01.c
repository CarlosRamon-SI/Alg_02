#include <stdio.h>

int SomaIntervalo(int x,int y){
    int soma= 0;
    for (int i = x+1; i < y; i++) {
        soma += i;
    }
    return soma;
}
    

int total = 0;

int main(){
    int num[2], aux;
    
    for (int i = 1; i < 3; i++) {
        printf("Digite um valor qualquer.\n");
        scanf(" %d",&num[i]);
    }

    if (num[1]>num[2]){
        aux=num[1];
        num[1]=num[2];
        num[2]=aux;
    }
    
    total = SomaIntervalo(num[1],num[2]);
    printf("O total da soma no intervalo entre %d e %d = %d .",num[1],num[2],total);
}
