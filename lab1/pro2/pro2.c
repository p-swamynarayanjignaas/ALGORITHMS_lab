#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct GRAPH{
	struct GRAPH *link;
	char v1,v2;
}NODE;

void insert(NODE **function,char e1,char e2);
void display(NODE *function);
void adjacency(NODE *function,int vertices,int edges,char **vertices_list);

int main(){
	system("clear");
	int vertices,edges;
	char *vertices_list[10];
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
	display(function);
	adjacency(function,vertices,edges,vertices_list);
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

void adjacency(NODE *function,int vertices,int edges,char **vertices_list){
	char *vertices_list_buffer[10];
	for(int i=0;i<vertices;i++)
	vertices_list_buffer[i] = vertices_list[i];

	int flag1,flag2;
	int matrix[10][10];
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
	for(int i=0;i<vertices;i++){
		for(int j=0;j<vertices;j++){
			printf("%d\t",matrix[i][j]);
		}
		printf("\n");
	}
	for(int i=0;i<vertices;i++){
			char *b;
			b= vertices_list[i];
			printf("%s->",b);
		for(int j=0;j<vertices;j++){
			if(matrix[i][j]==1){
				char *a;
				a = vertices_list[j];
				printf("%s->",a);
			}
		}
			printf("\b\n");
	}
}

