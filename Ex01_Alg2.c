/*
 * Ex01_Alg2.c
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
	float salario = 950.00, vendas,nSalario, p1 = 500.00, p2 = 700.00, p3 = 950.00, premio = 0.0;
	printf("Digite o Valos total de Vendas\n");
	scanf("%f", &vendas);
	if ((vendas > 100) && (vendas <= 500)){
		nSalario = salario + p1;
		premio = p1;
	} else if ((vendas > 500) && (vendas <= 750)){
		nSalario = salario + p2;
		premio = p2;
	} else if (vendas > 750){
		nSalario = salario + p3;
		premio = p3;
	} else {
		nSalario = salario;
	}
	printf("O salario %.2f + premiação de %.2f resultam: %.2f", salario, premio, nSalario);
	return 0;
}

