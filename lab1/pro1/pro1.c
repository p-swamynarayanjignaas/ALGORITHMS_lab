#include<stdio.h>
#include<stdlib.h>

typedef struct BST{
	int key;
	struct BST *lchild;
	struct BST *rchild;
}NODE;

int search(NODE *root,int temp_key);
void insert(NODE **root,int temp_key);
void inorder(NODE *root);
void preorder(NODE *root);
void postorder(NODE *root);

int main(){
	system("clear");
	int option;
	int temp_key;
	NODE* tree;
	tree = NULL;
	printf("1.Search\n2.Inorder\n3.Preorder\n4.Postorder\n5.Exit\n");
	while(1<2){
		printf("Enter option:");
		scanf("%d",&option);
		switch(option){
			case 1:{
				printf("Enter key:");
				scanf("%d",&temp_key);
				int flag = search(tree,temp_key);
				if(flag == 1){
					printf("Key found\n");
				}
				if(flag ==0){
					printf("Key not found\n");
					insert(&tree,temp_key);
					printf("Key id inserted\n");
				}
			}break;
			case 2:{
				inorder(tree);
				printf("\n");
			}break;
			case 3:{
				preorder(tree);
				printf("\n");
			}break;
			case 4:{
				postorder(tree);
				printf("\n");
			}break;
			case 5:{
				exit(0);
			}break;
		}
	}
	return 0;
}

int search(NODE *root,int temp_key){
	if(root == NULL){
		return 0;
	}
	else if(root->key == temp_key){
		return 1;
	}
	else{
		if(temp_key > root->key){
			search(root->rchild,temp_key);
		}
		else if(temp_key < root->key){
			search(root->lchild,temp_key);
		}
	}
	
}

void insert(NODE **root,int temp_key){
	if(*root == NULL){
		*root = (NODE *)malloc(sizeof(NODE));
		(*root)->key =  temp_key;
		(*root)->lchild = NULL;
		(*root)->rchild = NULL;
	}
	if((*root)->key > temp_key){
		insert(&((*root)->rchild),temp_key);
	}
	if((*root)->key < temp_key){
		insert(&((*root)->lchild),temp_key);
	}	
}

void inorder(NODE *root){
	if(root!=NULL){
		inorder(root->lchild);
		printf("%d\t",root->key);
		inorder(root->rchild);
	}
}

void preorder(NODE *root){
	if(root!=NULL){
		printf("%d\t",root->key);
		preorder(root->lchild);
		preorder(root->rchild);
	}
}

void postorder(NODE *root){
	if(root!=NULL){
		postorder(root->lchild);
		postorder(root->rchild);
		printf("%d\t",root->key);
	}
}