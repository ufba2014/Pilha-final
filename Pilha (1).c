/*Estrutura de Dados - Pilha*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct no{//Struct em que se baseia a pilha.
	int cod;
	struct no *prox;
};
typedef struct no No;

int g_tam;

	void menu(No *Pilha);
	void inicia(No *Pilha);
	int teste_vazia(No *Pilha);
	void imprime(No *Pilha);
	void libera(No *Pilha);
	void inserir(No *Pilha);
	No *apagar(No *Pilha);


int main(){// Função principal

	int opcao;

	No *Pilha = (No *) malloc(sizeof(No));

	if(Pilha== NULL){
		printf("Sem memoria disponivel para alocar a pilha.\n");
		exit(1);
	}
	else{
		inicia(Pilha);
		menu(Pilha);
		free(Pilha);
		return 0;
	}
}

void inicia(No *Pilha)//Inicia a pilha
{
	Pilha->prox = NULL;
	g_tam=0;
}

void menu(No *Pilha){//Função que trem o menu do programa
clock_t inicio, fim;

	int op;
	No *aux= NULL;

	while(1){

		system("cls");
			printf("\t  ==== MENU ====\n\n");
			printf("\t1. Inserir novo elemento;\n");
			printf("\t2. Apagar um elemento;\n");
			printf("\t3. Exibir Pilha;\n");
			printf("\t4. Tamanho da Pilha;\n");
			printf("\t5. Zerar Pilha.\n");
			scanf("%d", &op);

			switch(op){
				case 1:
				    inicio=clock();
					inserir(Pilha);
					fim=clock();
                  printf("Tempo de execucao: %lf\n",((double)(fim - inicio)/CLOCKS_PER_SEC));
                  system("Pause");
                  break;



				case 2:
				    inicio=clock();
					aux= apagar(Pilha);
					if(aux != NULL)
					printf("Elemento retirado: %d\n\n", aux->cod);
					fim=clock();
                  printf("Tempo de execucao: %lf\n",((double)(fim - inicio)/CLOCKS_PER_SEC));
                  system("Pause");
                  break;




				case 3:
				    inicio=clock();
					imprime(Pilha);
					fim=clock();
                  printf("Tempo de execucao: %lf\n",((double)(fim - inicio)/CLOCKS_PER_SEC));
                  system("Pause");
                  break;




				case 4:
				    inicio=clock();
					printf("A pilha possui %d elementos. \n", g_tam);
					fim=clock();
                  printf("Tempo de execucao: %lf\n",((double)(fim - inicio)/CLOCKS_PER_SEC));
                  system("Pause");
                  break;



				case 5:
				    inicio=clock();
					libera(Pilha);
					inicia(Pilha);
					fim=clock();
                  printf("Tempo de execucao: %lf\n",((double)(fim - inicio)/CLOCKS_PER_SEC));
                  system("Pause");
                  break;



				default:
					printf("Comando invalido, por favor escolha uma opcao.\n\n");
			}
	}
}


int teste_vazia(No *Pilha){// Testa se a pilha está vazia. Se o primeiro elemento aponta para NULL quer dizer que a pilha não tem
						   //elementos
	if(Pilha->prox == NULL)
		return 1;
	else
		return 0;
}

void imprime(No *Pilha){// Função de impressão da pilha

	No *aux= Pilha->prox;

	if(teste_vazia(Pilha)){
		printf("A pilha esta vazia. \n");
	}
	else{
		printf("\nPilha:\n");

		while( aux != NULL){
			printf("   %d\n", aux->cod);
			aux = aux->prox;
		}
	}
}

void libera(No *Pilha){//Libera o espaço alocado da Pilha

	No *proxNo,*atual;

	if(!teste_vazia(Pilha)){//Ou seja, se a pilha não está vazia a função irá esvaziá-la

		atual = Pilha->prox;//O ponteiro atual recebe o primeiro elemento da pilha

		while(atual != NULL){
			proxNo = atual->prox;//Uma ligação para que não se perca quem é o primeiro nó

			free(atual);
			atual = proxNo;//atual recebe o proximo nó e o loço continua se repetindo até que a pilha seja apagada
		}
	}
}

void inserir(No *Pilha){//Iserção de nós na pilha

	No *novo=(No*) malloc(sizeof(No));
	No *aux= NULL;

	if(novo == NULL){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}
	else{
		printf("Novo elemento: "); scanf("%d", &novo->cod);

		novo->prox = NULL;

		if(teste_vazia(Pilha))
			Pilha->prox= novo;//Se a pilha estiver vazia novo será o primeiro nó da pilha
		else{

		   aux= Pilha->prox;

			while(aux->prox != NULL){
				aux = aux->prox;
			}

			aux->prox = novo;
		}

		g_tam++;
	}
}

No *apagar(No *Pilha){//Apaga um nó da pilha. O ultimo elemento inserido.

	No *ult=NULL, *pnult=NULL;

	if(Pilha->prox == NULL){
		printf("Pilha vazia\n\n");
		return NULL;
	}else{
		ult = Pilha->prox;
	    pnult = Pilha;

		while(ult->prox != NULL){
			pnult = ult;
			ult = ult->prox;
		}

		pnult->prox = NULL;
		g_tam--;
		return ult;
	}
}
