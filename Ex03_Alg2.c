/*
 * Ex03_Alg2.c
 * 
 * Copyright 2017 Aluno <aluno@estacao>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


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

