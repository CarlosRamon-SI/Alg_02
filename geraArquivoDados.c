#include <stdio.h>

typedef struct TProduto{
	int codigo;
	char nome[30];
	char fabricante[30];
	float precoVarejo;
	int quantMinimaAtacado;
	float precoAtacado;	
	}TProduto;

int main()
{
	FILE *f;
	TProduto p;
	char resp;
	char nomeArquivo[50];
	printf("Entre com o nome do arquivo: ");
	scanf(" %s", nomeArquivo);
	
	f = fopen(nomeArquivo, "wb");
	if ( f != NULL )
	{
		do
		{
			printf("Entre com o código do produto: ");
			scanf(" %d", &p.codigo);
			printf("Entre com o nome do produto: ");
			scanf(" %[^\n]s", p.nome);
			printf("Entre com o nome do fabricante do produto: ");
			scanf(" %[^\n]s", p.fabricante);
			printf("Entre com o preço de varejo do produto: ");
			scanf(" %f", &p.precoVarejo);
			printf("Entre com a quantidade mínima para cobrar preço de atacado: ");
			scanf(" %d", &p.quantMinimaAtacado);
			do {
				printf(" Preço de atacado deve ser menor ou igual ao de varejo\n");	
				printf("Entre com o preço de atacado do produto: ");
				scanf(" %f", &p.precoAtacado);
		    }
		    while ( p.precoAtacado > p.precoVarejo );
			// gravando informacao
			fwrite(&p, sizeof(TProduto), 1, f );
			fflush(f);
			printf("Deseja continuar (s/n) ?: ");
			scanf(" %c", &resp);			
		}
		while (resp == 's' || resp == 'S');
		fclose(f);
		printf("Dados gravados no arquivo\n");
		
		printf("Mostrando informações gravadas\n");
		f = fopen(nomeArquivo, "rb");
		do
		{
			fread(&p, sizeof(TProduto), 1, f );
			if ( !feof(f) )
			{
			printf("*****************************\n");
			printf("Cod: %d\n", p.codigo);
			printf("Nome: %s\n", p.nome);
			printf("Fabricante %s\n", p.fabricante);
			printf("Preço Varejo: R$ %.2f\n", p.precoVarejo );
			printf("Preco Atacado: R$ %.2f (minimo %d) \n", p.precoAtacado, p.quantMinimaAtacado);
			}
		}
		while (!feof(f) );
	}
	else
		printf("Não foi possível abrir o arquivo %s\n", nomeArquivo);
}
