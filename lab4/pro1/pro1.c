#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include<time.h>

int min[500], min_value = INT_MAX;

void printCombinations(int size, int arr[size][size], int buf[size], int buf_1[size], int ix){

	int i, j;
	
	if(ix == size){
		int sum = 0, flag = 1;
		
		for(i = 0; i < size; i++){
			sum += buf[i];
		}
		
		for(i = 0; i < size - 1; i++){
			for(j = i + 1; j < size; j++){
				if(buf_1[i] == buf_1[j]){
					flag = 0;
					break;
				}
			}
		}
		
		if(sum < min_value && flag){
			for(i = 0; i < size; i++){
				min[i] = buf[i];
			}
			min_value = sum;
		}
	}
	
	else{
		for(i = 0; i < size; i++){
			buf[ix] = arr[i][ix];
			buf_1[ix] = i;
			printCombinations(size, arr, buf, buf_1, ix + 1);
		}
	}
}

int main(){
	FILE *fp;
	fp = fopen("analysis.csv","a+");
	clock_t time;
	double time_taken;
	int i, j, size;
	
	printf("Enter number of employees:\n");
	scanf("%d", &size);
	
	int arr[size][size];
	
	// printf("Enter charge matrix:\n");
	int count = 1;
	for(i = 0; i < size; i++){
		for(j = 0; j < size; j++)
			// scanf("%d", &arr[i][j]);
			arr[i][j]=count++;
	}

	int buff[size];
	int buff_1[size];
	time = clock();
	printCombinations(size, arr, buff, buff_1, 0);
	time = clock()-time;
	time_taken = ((double)time)/CLOCKS_PER_SEC;
	// printf("The Minimum Cost Combination is : ");

	// for(j = 0; j < size; j++)
 //    	printf("%d ", min[j]);
	fprintf(fp,"%d,%lf,%d\n",size,time_taken,min_value);
	fclose(fp);
	printf("\nThe Minimum Cost is : %d\n", min_value);
	return 0;
}