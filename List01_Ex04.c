/**
 * NOME : CARLOS RAMON MOREIRA LEITE
 * RGA : 201711316032
 * */

#include <stdio.h>

int fib(int x);

int main(){
    int num;
    printf("\nFIBONACCI\nDigite um valor para calcular: ");
    scanf("%d",&num);
    num = fib(num);
    printf("O resultado obtido foi: %d",num);
}

int fib(int x){
    if (x <= 0) {
        x = 0;
    } else {
        if (x == 1) {
            x = 1;
        } else {
            if (x > 40) {
                printf("\nValor muito alto. Favor tente numero menor.\n");
            } else {
                x = fib(x-1)+fib(x-2);
            }
        }
    }
    return x;
}
