#include <stdio.h>

int main(){
    int *p, *q, i, j;
    i = 5;
    j = 17;
    p = &i;
    q = p;
    printf("%p %d %d\n", p, *p, (*q)*3);
    q = &j;
    *p = *q;
    printf("%p %d %d\n", q, *p, (*q)*3);
}
