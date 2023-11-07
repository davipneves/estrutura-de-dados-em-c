
#include <stdio.h>
#include <stdlib.h>

typedef struct sNo {
    struct sNo* prox;
    char valor;
} No;

void inserir(No** lista, char n) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo != NULL) {
        novo->valor = n;
        novo->prox = *lista;
        *lista = novo;
    } else {
        printf("\nNao foi possivel alocar memoria");
    }
}

void removerInicio(No** lista){
	No* q;
	
	if(*lista!=NULL){
		q = *lista;
		*lista = q->prox;
		free(q);
		printf("O no foi removido com sucesso");
	}else{
		printf("A lista esta vazia");
	}
	
}

void remover(No** lista) {
    while (*lista != NULL) {
        No* temp = *lista;
        *lista = (*lista)->prox;
        free(temp);
    }
}

void printar(No* lista){
	int x = 1;
	while(lista != NULL){
		printf("O valor na posicao %d e %c", x, lista->valor);
		lista = lista->prox;
		x++;
	}
}

void mostrar(No* lista) {
    int x = 0;
    while (lista != NULL) {
        char info = lista->valor;
        if (info == 'a' || info == 'e' || info == 'i' || info == 'o' || info == 'u' ||
            info == 'A' || info == 'E' || info == 'I' || info == 'O' || info == 'U') {
            printf("O valor na posicao %d e a vogal '%c'\n", x, info);
        }
        lista = lista->prox;
        x++;
    }
}

int main() {
    No* lista = NULL;
    int esc;
    char valor;

    do {
        printf("\nMenu de Opcoes:\n");
        printf("1. Inserir elemento no inicio da lista\n");
        printf("2. Remover todos os elementos da lista\n");
        printf("3. Imprimir a posicao das vogais na lista\n");
        printf("4. Remover No no inicio\n");
        printf("5. Mostrar todos os elementos\n");
        printf("6. Sair\n");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &esc);

        switch (esc) {
            case 1:
                printf("Digite o elemento a ser inserido: ");
                scanf(" %c", &valor);
                inserir(&lista, valor);
                break;
            case 2:
                remover(&lista);
                printf("Todos os elementos foram removidos da lista.\n");
                break;
            case 3:
                if (lista == NULL) {
                    printf("\nA lista esta vazia.\n");
                } else {
                    mostrar(lista);
                }
                break;
            case 4:
            	removerInicio(&lista);
            	break;
            case 5:
            	printar(lista);
            	break;
            case 6:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opcao invalida. Escolha uma opcao valida.\n");
                break;
        }
    } while (esc != 6);

    return 0;
}

