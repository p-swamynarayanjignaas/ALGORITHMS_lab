#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"stack.h"
typedef struct GRAPH{
	struct GRAPH *link;
	char v1,v2;
}NODE;

void insert(NODE **function,char e1,char e2);
void display(NODE *function);
int** adjacency_matrix(NODE *function);
void depth_first_search(int index);
char *vertices_list[10];
int vertices,edges;
int** adj_matrix;
int reach[10];

int main(){
	system("clear");
	char *edge;
	NODE *function;
	function = NULL;	
	printf("Enter number of vertices:");
	scanf("%d",&vertices);
	for(int i=0;i<vertices;i++){
		vertices_list[i]=malloc(1*sizeof(char));
		printf("Enter vertice %d:",i+1);
		scanf("%s",vertices_list[i]);
	}
	printf("Vertices:{");
	for(int i=0;i<vertices;i++){
		printf("%s,",vertices_list[i]);
	}
	printf("\b}\n");
	printf("Enter number of edges:");
	scanf("%d",&edges);
	for(int i=0;i<edges;i++){
		edge=malloc(1*sizeof(char));
		printf("Enter edge(v1v2):");
		scanf("%s",edge);
		char a1 = edge[0];
		char a2 = edge[1];
		insert(&function,a1,a2);
		free(edge);
	}
	int index;
	char vertex_dfs;
	char ffff;
	scanf("%c",&ffff);
	printf("Enter vertex for depth first search:");
	scanf("%c",&vertex_dfs);
		for(int i=0;i<vertices;i++){
		if(*vertices_list[i]==vertex_dfs){
			index = i;
			break;
		}
	}
	display(function);
	adj_matrix = adjacency_matrix(function);
	for(int i=0;i<vertices;i++){
		for(int j=0;j<vertices;j++){
			printf("%d\t",adj_matrix[i][j]);
		}
		printf("\n");
	}
	printf("Topologiacal order:\n");
	depth_first_search(index);
	printf("\n");
	return 0;
}

void insert(NODE **function,char e1,char e2){
	NODE *node,*temp;
	node = (NODE *)malloc(sizeof(NODE));
	node->v1 = e1;
	node->v2 = e2;
	node->link = NULL;
	if(*function == NULL){
		*function = node;
		(*function)->link = NULL;
		return;
	}
	temp = *function;
	while(temp->link!=NULL){
		temp = temp->link;
	}
	temp->link = node;
}

void display(NODE *function){
	printf("Edges:{");
	while(function->link!=NULL){
		printf("(%c,%c),",function->v1,function->v2);
		function = function->link;
	}
	printf("(%c,%c)}\n",function->v1,function->v2);
}

int** adjacency_matrix(NODE *function){
	int **matrix = (int **)malloc(vertices*sizeof(int *));
	for(int i=0;i<vertices;i++){
		matrix[i]= (int *)malloc(vertices*sizeof(int));
	}
	char *vertices_list_buffer[10];
	int flag1,flag2;
	for(int i=0;i<vertices;i++)
		vertices_list_buffer[i] = vertices_list[i];
	for(int i=0;i<vertices;i++){
		for(int j=0;j<vertices;j++){
			matrix[i][j]=0;
		}
	}
	while(function->link!=NULL){
		for(int i=0;i<vertices;i++){
			char b;
			char *a;
			a = vertices_list[i];
			b=a[0];
			if(	function->v1==b){
				flag1 = i;
			}
		}
		for(int j=0;j<vertices;j++){
			char b;
			char *a;
			a = vertices_list_buffer[j];
			b=a[0];
			if(	function->v2==b){
				flag2 = j;
			}
		}		
		matrix[flag1][flag2]=1;
		function = function->link;
	}
	for(int i=0;i<vertices;i++){
		char b;
		char *a;
		a = vertices_list[i];
		b=a[0];
		if(	function->v1==b){
			flag1 = i;
		}
	}
	for(int j=0;j<vertices;j++){
		char b;
		char *a;
		a = vertices_list_buffer[j];
		b=a[0];
		if(	function->v2==b){
			flag2 = j;
		}
	}	
	matrix[flag1][flag2]=1;
	
	return matrix;
}

void depth_first_search(int index){
	stack s;
	s.top = -1;
	int i;
	reach[index]=1;
	for(i=0;i<vertices;i++){
		if(adj_matrix[index][i] && !reach[i]){
			printf("Pushing %s\n",vertices_list[i]);
			push(&s,i);
			// printf("%s\n",vertices_list[i]);
    		  // printf("\n %d->%d",index,i);
			depth_first_search(i);
		}
		// else{
		// 	printf("\n%s",vertices_list[pop(&s)]);
		// }
	}
			printf("\n%s",vertices_list[pop(&s)]);
}