#include <stdio.h>
#include <stdlib.h>

typedef struct sNo{
	char valor;
	struct sNo* prox;
	
}No;

void inserir_inicio(No **lista, int n){
	No *novo = ( struct sNo *) malloc(sizeof( struct sNo));
	if(novo!= NULL){
		novo->valor = n;
		novo->prox = *lista;
		*lista = novo;
	}else{
		printf("Nao foi possivel alocar memoria");
	}
	
}

int main(){
	No *lista = NULL;
	
	int esc= NULL;
	char valor;
	
	do{
		printf("Selecione uma das opcoes abaixo\n");
		printf("1. Inserir informacao no inicio\n0. sair do peograma\n");
		scanf("%d", &esc);
		
		switch (esc){
			case (1):
				printf("Digite o valor da informacao\n");
				scanf(" %c", &valor);
				inserir_inicio(&lista, valor);
				break;
			default:
				printf("O valor inserido nao e valido\n");
				break;	
		}
	}while(esc != 0);


	
	
	 
	return 0;
}
