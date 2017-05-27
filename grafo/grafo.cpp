#include <stdio.h>
#include <stdlib.h>

struct node{
	
	int value;
	
	node *next = NULL;
};

int main(int argc, char const *argv[]){

	int i;
	
	int N;
	
	int qnt_nodes;
	
	int j;
	
	struct node *aux;
	
	int **matrix_adj;
	
	FILE *fp;

	printf("Enter number of vertices: ");

	scanf("%d", &qnt_nodes);

	printf("\n###################\n");
	
	printf("\n");

	struct node *graph = (node*) malloc(sizeof(struct node) * qnt_nodes);
	
	matrix_adj = (int**) malloc(sizeof(int**) * qnt_nodes);

	for (i = 0; i < qnt_nodes; i++) {

		matrix_adj[i] = (int*) malloc(sizeof(int*) * qnt_nodes);
	}

	fp = fopen("grafo.txt", "r");

	if(fp == NULL) exit(1);

	for(i = 0; i < qnt_nodes ; i++){

		for(j = 0 ; j < qnt_nodes ; j++){

			fscanf(fp, "%d", &matrix_adj[i][j]);
		}
	}

	for(i = 0; i < qnt_nodes ; i++){

		for(j = 0 ; j < qnt_nodes ; j++){

			printf("%d ", matrix_adj[i][j]);

		}

		printf("\n");
	}		

	printf("\n################### \n\n");

	 for (i = 0; i < qnt_nodes; i++) {
		
		aux = &graph[i];
		
		aux->value = i + 1;
				
		for (j = 0; j < qnt_nodes; j++) {
		
			if(matrix_adj[i][j] == 1){
						
				node *novo = (node*) malloc(sizeof(node*));

				novo->value = j + 1;
			 				
				novo->next = NULL;

				aux->next = novo;
				
				aux = novo;
			}

		}	
	}

	for (i = 0; i < qnt_nodes; i++){
		
		printf("%d", graph[i].value);

		aux = graph[i].next;

		while(aux != NULL){
			
			printf("->");

			printf("%d", aux->value);
			
			aux = aux->next;
		}

		printf("\n");

	}
	
	return 0;
}