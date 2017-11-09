#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int m[6][4], i, j, cont;
	
	// gerador de matrix
	for (i=0;i<6;i++) {
		for (j=0;j<4;j++) {
			m[i][j] = rand() % 100;
		}
	}
	
	// print da matriz
	for (i=0;i<6;i++) {
		for (j=0;j<4;j++) {
			printf("%d\t", m[i][j]);
		}
		printf("\n");
	}
	
	printf("\n \n \n");
	
	// troca de valores
	for (i=0;i<6;i++) {
		for (j=0;j<4;j++) {
			if ((m[i][j] > 30) && (m[i][j] < 39)){
				cont++;
				m[i][j] = -5;
			}
		}
	}
	
	// re print da matriz
	for (i=0;i<6;i++) {
		for (j=0;j<4;j++) {
			printf("%d\t", m[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}

