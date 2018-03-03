#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TProduto {
	int codigo;
	char nome[30];
	char fabricante[30];
	float precoVarejo;
	int quantMinimaAtacado;
	float precoAtacado;
    int situacao;
} TProduto;
	
typedef struct TNoProduto {
	TProduto p;
	struct TNoProduto *Prox;
} TNoProduto;

// estrutura de controle da lista
typedef struct TListaProduto {
	TNoProduto *head;
	int tamanho;
} TListaProduto;

void Iniciar( TListaProduto *L ) {
    L->head = NULL;
    L->tamanho = 0;
}

void Inserir(  TListaProduto *L, TProduto p ) {
	
    // preencher essa função
	TNoProduto *ant, *atual;
	TNoProduto *no = malloc(sizeof(TNoProduto));
	no->p = p;
	
    // testando a lista vazia
	if ( no != NULL ) {

        if ( L->head == NULL) {
			L->head = no;
			no->Prox = NULL;
			L->tamanho++;
		} else {

			atual = L->head;
			
            // no será a nova cabeça
			if ( no->p.codigo < atual->p.codigo ) {
				L->head = no;
				no->Prox = atual;
				L->tamanho++;
			} else {
                
                // no não está no começo da lista
				while (( atual != NULL ) && ( no->p.codigo > atual->p.codigo ))	{
					ant = atual;
					atual = atual->Prox;
				}

				ant->Prox = no;
				no->Prox = atual;
				L->tamanho++;
			}
		}
    }
}


TNoProduto * Buscar( TListaProduto L, int codigo ) {

	// preencher essa função
    TNoProduto *auxiliar;
    auxiliar = L.head;
    while(auxiliar != NULL){
        if(auxiliar->p.codigo == codigo) {
            return auxiliar;
        } else {
            auxiliar = auxiliar->Prox;
        }
    }
}


int Remover ( TListaProduto * L, int codigo ) {
    TNoProduto *anterior, *atual ;
    atual = L->head;
    anterior = atual;
    while ( atual != NULL ) {
        if ( atual->p.codigo == codigo) {
            // encontrou o elemento a ser removido, reajustando ponteiros
            if ( atual == L->head ) {
                L->head = atual->Prox;
                free(atual);
                L->tamanho--;
            }
            else {
                // tratando os outros elementos da lista
                anterior->Prox = atual->Prox;
                free(atual);
                L->tamanho--;
            }
            return 0;
        } else {
            anterior = atual;
            atual = atual->Prox;
        }
    }
    return -1;
}

void Terminar (  TListaProduto *L ) {
    TNoProduto *no, *atual ;
    atual = L->head;
    while ( atual != NULL ) {
        no = atual->Prox;
        free(atual);
        atual = no;
        L->tamanho--;
    }
    L->head = NULL;
}

void Exibir ( TListaProduto L ) {
    TNoProduto *aux;
    aux = L.head;
    printf("*******Elementos na lista ***********\n");
    printf("Tamanho: %d\n", L.tamanho);
    printf("Head ->  ");
    while (aux != NULL && aux->p.situacao == 1) {	
		printf("%4d | %s \t| %s \t| R$ %7.2f | %03d | R$ %7.2f \n\t ", aux->p.codigo, aux->p.nome, aux->p.fabricante, aux->p.precoVarejo, aux->p.quantMinimaAtacado, aux->p.precoAtacado );
		aux = aux->Prox;		
	} 
	printf ( " NULL\n" );
	printf("********Fim da lista ***************\n");
}

int  Tamanho( TListaProduto L  ) {
	return L.tamanho;
}

void adicionar(char *nArquivo){
    FILE *file = fopen(nArquivo,"ab");
    char resp = 's';
    TProduto produto;
	if (file != NULL){
		while (resp == 's' || resp == 'S') {
            produto.situacao = 1;
			printf("Entre com o código do produto: ");
			scanf(" %d", &produto.codigo);
			printf("Entre com o nome do produto: ");
			scanf(" %[^\n]s", produto.nome);
			printf("Entre com o nome do fabricante do produto: ");
			scanf(" %[^\n]s", produto.fabricante);
			printf("Entre com o preço de varejo do produto: ");
			scanf(" %f", &produto.precoVarejo);
			printf("Entre com a quantidade mínima para cobrar preço de atacado: ");
			scanf(" %d", &produto.quantMinimaAtacado);
		    while ( produto.precoAtacado > produto.precoVarejo ){
				printf(" Preço de atacado deve ser menor ou igual ao de varejo\n");	
				printf("Entre com o preço de atacado do produto: ");
				scanf(" %f", &produto.precoAtacado);
            }
			fwrite(&produto, sizeof(TProduto), 1, file);
			fflush(file);
			printf("Deseja continuar ? [s/n]: ");
			scanf(" %c", &resp);
        }
		fclose(file);
}

int main() {
	int i = 1, ret, id, menu;
	char resp;
	TListaProduto l;
	TProduto p;
	TNoProduto *pNo, *pRet;
	FILE *f;
	char nomeArquivo[50];
	printf("Entre com o nome do arquivo: ");
	scanf(" %s", nomeArquivo);
	Iniciar(&l);
    f = fopen(nomeArquivo, "rb+");
    if (f == NULL){
        printf("Falha ao abrir Arquivo!\n");
    } else {
        printf("Arquivo Aberto com Sucesso!\n");
        do {
            fread(&p, sizeof(TProduto), 1, f);
            if (!feof(f))
                Inserir(&l, p);
        } while (!feof(f));
        Exibir(l);	
        fclose(f);
        printf("\n--==[ MENU ]==--\n\n");
        printf("[0] - Inserir Produto;\n");
        printf("[1] - Alterar Produto;\n");
        printf("[2] - Remover Produto;\n\n");
        printf("[3] - Fechar.\n");
        scanf("%d",&menu);
        while(menu < 0 || menu > 3){
            printf("Opção Inválida! Tente Novamente: ");
            scanf("%d",&menu);
        }
        switch (menu) {
            case 0:{
                adicionar(nomeArquivo);
                Terminar(&l);
                Iniciar(&l);
                f = fopen(nomeArquivo, "rb+");
                if (f != NULL){
                    printf("Arquivo Aberto com Sucesso!\n");
                    do {
                        fread(&p, sizeof(TProduto), 1, f);
                        if (!feof(f))
                            Inserir(&l, p);
                    } while (!feof(f));
                    Exibir(l);	
                    fclose(f);
                } else {
                    printf("Falha ao abrir Arquivo!\n");
                }
                break;
                   }
            case 1:
                printf("Entre com o código para Alterar o Produto:\n");
                
                break;
            case 2:{
                printf("Entre com o código para remover o produto:\n");
                scanf(" %d", &id);
                pRet = Buscar(l, id);
                if (pRet != NULL ){
                    printf("****** Produto encontrado *************\n\n");
                    printf(" \t%4d | %s \t| %s \t| R$ %7.2f | %03d | R$ %7.2f \n\n", pRet->p.codigo, pRet->p.nome, pRet->p.fabricante, pRet->p.precoVarejo, pRet->p.quantMinimaAtacado, pRet->p.precoAtacado);
                    printf("****** Removendo da lista *************\n\n");
                    Remover(&l, id);
                    Exibir(l);
                }
                break;
                   }
            case 3:
                
                break;
        }
            printf("Não encontrado \n");
        printf("Finalizando a lista\n");
        Terminar(&l);
        Exibir(l);
    }
}
}
