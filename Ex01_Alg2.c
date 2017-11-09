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

