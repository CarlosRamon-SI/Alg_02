/**
NOME : CARLOS RAMON MOREIRA LEITE
RGA : 201711316032
*/

#include <stdio.h>

int funcao(int x);

int main(){
    int num;
    printf("Digite um valor para calcular: ");
    scanf("%d",&num);
    num = funcao(num);
    printf("O resultado obtido após cálculo: %d",num);
}

int funcao(int x){
    if (x <= 1) {
        x = 5;
    } else {
        x = 10 * funcao(x-1)+5;
    }
    return x;
}
