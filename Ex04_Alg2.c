#include <stdio.h>
#include <string.h>

typedef struct TCadastro {
	char nome[100];
	double altura;
	double peso;
	char cpf[14];
	char sexo[9];
} TCadastro ;

int main(int argc, char **argv) {
	
	int i = 0, m = 0;
	float imc;
	char pesquisa[14];
	TCadastro Aluno[5];
	m = 0;
	for ( i = 0 ; i < 1 ; i++ ) {
		printf("Digite seu Nome: ");
		scanf(" %[^\n]s", Aluno[i].nome);
				
		printf("Digite sua Altura: ");
		scanf(" %lf", &Aluno[i].altura);
				
		printf("Digite seu Peso: ");
		scanf(" %lf", &Aluno[i].peso);
				
		printf("Digite seu CPF: ");
		scanf(" %s", Aluno[i].cpf);
				
		printf("Digite seu Sexo: ");
		scanf(" %s", Aluno[i].sexo);
}
	printf("Qual aluno deseja calcular IMC? [PESQUISE PELO <CPF> ] : ");
	scanf(" %s", pesquisa);
	
	for ( i = 0 ; i < 1 ; i++ ) {
		printf(" %s \n", Aluno[i].nome);
		printf(" %.2lf \n", Aluno[i].altura);
		printf(" %.2lf \n", Aluno[i].peso);
		printf(" %s \n", Aluno[i].cpf);
		printf(" %s \n", Aluno[i].sexo);
		
	}
	for ( i = 0 ; i < 5 ; i++ ) {
		if ( Aluno[i].cpf == pesquisa ) {
			m = i;
		}
	}
	imc = Aluno[m].peso / ( Aluno[m].altura * Aluno[m].altura );
	
	printf("O IMC de %s é igual a %.2f.", Aluno[m].nome, imc);
}
