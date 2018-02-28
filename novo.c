#include <stdio.h>

int main(){
    FILE *f;
    float x;
    f = fopen("listaProdutos.dat","rb");
    if ( f != NULL) {
        while(fread(&x, sizeof(float),1,f) != 0){
            printf("\n%6.2f ",x);
        }
        fclose(f);
    }
}
