#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void bubble_sort1(int *array,int n);
void bubble_sort2(int *array,int n);
int optcount1,optcount2;
int main(){
	system("clear");
	FILE *fp;
	clock_t time1,time2;
	double time_taken1,time_taken2;
	fp = fopen("analysis.csv","a+");
	int size_of_array;
	printf("Enter size of array:");
	scanf("%d",&size_of_array);
	int *array = (int *)malloc(size_of_array*sizeof(int));
	//worst case
	int t= size_of_array;
	for(int i=0;i<size_of_array;i++){
		array[i]=t--;
	}
	time1=clock();
	bubble_sort1(array,size_of_array);
	time1=clock()-time1;
	time_taken1 = ((double)time1)/CLOCKS_PER_SEC;
	// fprintf(fp,"%d,%lf\n",size_of_array,time_taken1);
	//best case
	for(int i=0;i<size_of_array;i++){
		array[i]=i;
	}
	time2=clock();
	bubble_sort2(array,size_of_array);
	time2=clock()-time2;
	time_taken2 = ((double)time2)/CLOCKS_PER_SEC;
	fprintf(fp,"%d,%lf,%lf,,,%d,%d,%d\n",size_of_array,time_taken1,time_taken2,size_of_array,optcount1,optcount2);
	fclose(fp);
	return 0;
}

void bubble_sort1(int *array,int n){
	int temp;
	for(int i=0;i<n;i++){
		optcount1++;
		for(int j=0;j<n-i-1;j++){
			optcount1++;
			if(array[j]>array[j+1]){
				optcount1++;
				temp = array[j+1];
				array[j+1]=array[j];
				array[j]=temp;
			}
		}
	}
}

void bubble_sort2(int *array,int n){
	int temp;
	for(int i=0;i<n;i++){
		optcount2++;
		for(int j=0;j<n-i-1;j++){
			optcount2++;
			if(array[j]>array[j+1]){
				optcount2++;
				temp = array[j+1];
				array[j+1]=array[j];
				array[j]=temp;
			}
		}
	}
}
