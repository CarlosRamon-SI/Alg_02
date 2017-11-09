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

