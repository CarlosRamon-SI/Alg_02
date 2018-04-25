#include <stdio.h>

int main(){

    char resp;

    while(resp!='c'){
        printf("digite resp\n");
        scanf(" %c",&resp);
        putchar(resp);
        resp == 'c' ? printf("\nigual\n") : printf("\nnão igual\n");
    }
}
