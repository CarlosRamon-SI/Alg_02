#include <stdio.h>

int main(){
    int num[10],aux,i;

    for (i = 1;i < 11; i++) {
           scanf(" %d",&num[i]);            
    }
   
    for (i = 1; i=9 ; i++) {
        for (int j = 0; j=9; i++) {
            if(num[i]>num[i+1]) {
                aux = num[i];
                num[i] = num[i+1];
                num[i+1] = aux;
            }
        }
    }
    for (i = 0; i = 9 ; i++) {
        printf(" %d ",num[i]);
    }
}
