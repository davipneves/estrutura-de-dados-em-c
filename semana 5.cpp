#include <stdio.h>
#include <stdlib.h>

typedef struct sNo{
	struct sNo* dir;
	struct sNo* esq;
	char valor;
	
}No;

No* pesquisar(No* lista, int elem){
	No* aux;
	aux =lista;
	
	if(lista!=NULL){
		while(aux!=NULL){
			if(aux->valor == elem){
				return aux;
			}
			aux = aux->dir;
		}
	}
}

void inserirInicio(No** lista,char n){
	No* novo=(No*) malloc(sizeof(No*));
	if(novo!= NULL){	
	novo->esq = NULL;
	novo->valor = n;
	novo->dir = *lista;
	*lista=novo;
	printf("Valor inserido com sucesso\n");
	}else{
		printf("\nNao foi possivel alocar memoria\n");
	}
}

void removerInicio(No** lista){
	No* q;
	
	if(*lista!=NULL){
		q = *lista;
		*lista = q->dir;
		free(q);
		printf("O no foi removido com sucesso\n");
	}else{
		printf("A lista esta vazia\n");
	}
	
}

void remover(No** lista, int elem){
	No* q;
	if((q=pesquisar(*lista,elem))!= NULL){
		if(*lista==q){
			removerInicio(lista);
		}else{
			((q->esq)->dir = q->dir);
			if(q->dir != NULL){
				(q->dir)->esq = q->esq;
				free(q);
			}
			
		}
	}
}



void printar(No* lista){
	char info = lista->valor;
	while(lista!=NULL){
		printf("%c\n", lista->valor);
		lista = lista->dir;
	}
}

int main(){
	No* lista = NULL;
	int esc;
	char valor;
	char elemEspecif;
	do{
		printf("\nMenu de opcoes\n");
		printf("1. Inserir no inicio\n");
		printf("2. Exibir elementos da lista\n");
		printf("3. Remover elemento especififico\n");
		printf("4. Sair do programa\n");
		printf("Opcao: ");
		scanf(" %d",&esc);
		
		switch(esc){
			case 1:
				printf("Digite o valor a ser inserido: ");
				scanf(" %c", &valor);
				inserirInicio(&lista,valor);
				break;
			case 2:
				printar(lista);
				break;
			case 3:
				printf("Qual elemento deve ser removido?: ");
				scanf(" %c", &elemEspecif);
				remover(&lista, elemEspecif);
			deafult:
				printf("Insira o numero corresponde a uma das funcoes acima\n");
				break;
			}
	}while(esc != 4);
	
}
