/*
 * Ex02_Alg2.c
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

int main(int argc, char **argv)
{
	float aluno[6], mediaTurma;
	int i, cont = 0;
	
	for (i = 1; i < 7;i++) {
		printf("Digite a nota do aluno %d:", i);
		scanf("%f", &aluno[i-1]);
		mediaTurma += aluno[i-1];
	}
	
	mediaTurma = mediaTurma / 6;
	
	for (i = 0; i < 6 ;i++) {
		if (aluno[i] > mediaTurma) {
			cont++;
		}
	}
	printf("A média da turma é: %.2f. E %d Alunos estão acima da média", mediaTurma,cont);
	return 0;
}

