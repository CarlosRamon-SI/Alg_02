#include <stdio.h>
#include <stdlib.h>

int main(){
    float a, *p;
    printf("Digite um Valor Real: ");
    scanf("%f",&a);
    printf("adress a %p\n",&a);
    printf("a %f\n",a);
    printf("adress p %p\n",p);
    printf("p %f\n",*p);
    p = &a;
    printf("adress p %p\n",p);
    printf("p %f\n",*p);
}
