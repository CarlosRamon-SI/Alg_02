#include <stdio.h>

void ProcuraValores(in

int main(){
    int num[3];

    printf("Digite 3 valores");
    for (int i = 0; i < 3; i++) {
        scanf(" %d \n",num[i]);
    }

    ProcuraValores(num[1],num[2],num[3])
