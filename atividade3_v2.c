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
    free(no);
}


TProduto * Buscar( TListaProduto L, int codigo ) {

	// preencher essa função
    TNoProduto *anterior, *atual;
    //TNoProduto *noh = malloc(sizeof(TNoProduto));


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
    printf("Head -> ");
    while (aux != NULL ) {	
		printf("%d | %s | %s | %.2f | %d | %.2f \n ", aux->p.codigo, aux->p.nome, aux->p.fabricante, aux->p.precoVarejo, aux->p.quantMinimaAtacado, aux->p.precoAtacado );
		aux = aux->Prox;		
	} 
	printf ( " NULL\n" );
	printf("********Fim da lista ***************\n");
}

int  Tamanho( TListaProduto L  ) {
	return L.tamanho;
}

int main(){
	int i = 1, ret, id;
	char resp;
	TListaProduto l;
	TProduto p, *pRet ;
	TNoProduto *pNo;
	FILE *f;
	char nomeArquivo[50];
	printf("Entre com o nome do arquivo: ");
	scanf(" %s", nomeArquivo);
	Iniciar(&l);
	f = fopen(nomeArquivo, "rb+");
	do {
		fread(&p, sizeof(TProduto), 1, f);
		if (!feof(f))
			Inserir(&l, p);
	} while (!feof(f));
	Exibir(l);	
	fclose(f);
	printf("Entre com um código para se buscar um produto:\n");
	scanf(" %d", &id );
	pRet = Buscar(l, id );
	if (pRet != NULL ){
		printf("****** Produto encontrado ************* \n\n");
		printf("%d | %s | %s | %.2f | %d | %.2f \n ", pRet->codigo, pRet->nome, pRet->fabricante, pRet->precoVarejo, pRet->quantMinimaAtacado, pRet->precoAtacado );
		printf("****** Removendo da lista ************* \n\n");
		Remover(&l, id );
		Exibir(l);
	} else
        printf("Não encontrado \n");
	printf("Finalizando a lista\n" );
	Terminar(&l);
	Exibir(l);	
}
