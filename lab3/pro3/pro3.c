#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
void partition(int *array,int n,int sum_of_set);
void bubble_sort(int *array,int n);
int disjoint_check(int *arr1,int *arr2,int n,int sum_of_set);

int optcount;
int main(){
	system("clear");
	FILE *fp;
	fp = fopen("analysis.csv","a+");
	clock_t time;
	double time_taken;
	int size_of_array;
	printf("Enter number of elements:");
	scanf("%d",&size_of_array);
	int sum_of_set=0;

	int *array = (int *)malloc(size_of_array*sizeof(int));
	printf("Enter elements of set:");
	for(int i=0;i<size_of_array;i++){
		scanf("%d",&array[i]);
	}
	for(int i=0;i<size_of_array;i++){
		sum_of_set+=array[i];
	}
	bubble_sort(array,size_of_array);
	time = clock();
	partition(array,size_of_array,sum_of_set);
	time = clock()-time;
	time_taken = ((double)time)/CLOCKS_PER_SEC;
	fprintf(fp,"%d,%lf\n",size_of_array,time_taken);
	fclose(fp);
	return 0;
}

void bubble_sort(int *array,int n){
	int temp;
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i-1;j++){
			if(array[j]>array[j+1]){
				temp = array[j+1];
				array[j+1]=array[j];
				array[j]=temp;
			}
		}
	}
}
void partition(int *array,int n,int sum_of_set){
	int **table;
	int index1,index2;
	int no_of_subsets = pow(2,n);
	int p=0,k=1;
	table = (int **)malloc(no_of_subsets*sizeof(int*));
	for(int i=0;i<no_of_subsets;i++){
		table[i] = (int *)malloc((n+1)*sizeof(int));
		for(int j=0;j<n;j++){
			if(i & (1<<j)){
				table[i][p] = array[j];
				p++;
			}
		}
		p=0;
	}
	// for(int i=0;i<no_of_subsets;i++){
	// 	printf("%d)",i+1);
	// 	for(int j=0;j<=n;j++){
	// 		printf("%d",table[i][j]);
	// 	}
	// 	printf("\n");
	// }
	int sum = 0;
	for(int i=0;i<no_of_subsets;i++){
		for(int j=0;j<n;j++){
			sum += table[i][j];
		}
		table[i][n] = sum;
		sum = 0;
	}
	// for(int i=0;i<no_of_subsets;i++){
	// 	printf("%d)sum = %d\n",(i+1),table[i][n]);
	// }
	int flag  = 0;
	for(int i=0;i<no_of_subsets;i++){
		for(int j=1;j<no_of_subsets;j++){
			if(table[i][n] == table[j][n]&&(disjoint_check(table[i],table[j],n,sum_of_set)==1&&(i!=j))){
				flag = 1;
				index1=i;
				index2=j;
				break;
			}
			else{
				flag = 0;

			}

		}
		if(flag == 1){
			break;	
		}
	}
	if(flag == 1){
		printf("Partitions possible\n");
			printf("Set1->");
		for(int i=0;i<n;i++){
			if(table[index1][i]!=0){
				printf("%d ",table[index1][i]);
			}
		}
			printf("\n");
			printf("Set2->");
		for(int i=0;i<n;i++){
			if(table[index2][i]!=0){
				printf("%d ",table[index2][i]);
			}
		}
			printf("\n");

	}
	if(flag == 0){
		printf("Partitions not possible!\n");
	}
}

int disjoint_check(int *arr1,int *arr2,int n,int sum_of_set){
	int sum1=0,sum2=0;
	for(int i=0;i<n;i++){
		sum1 += arr1[i];
		sum2 += arr2[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(arr1[i]==arr2[j]){
				if(arr1[i]==0 && arr2[j]==0)
				return 0;
			}
		}
	}
	// if(sum1+sum2==sum_of_set){
	// 	return 1;
	// }
	return 0;
}