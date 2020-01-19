#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int gcd_integer_checking(int m,int n);
int optcount;
int main(){
	system("clear");
	int ans,test_cases,a,b;
	FILE *fp;
	clock_t start,end,t;
	double time_diff;
	fp = fopen("analysis.csv","w+");
	printf("Enter number of test cases:");
	scanf("%d",&test_cases);
	for(int i=0;i<test_cases;i++){
		a = i+1;
		b = i+2;
		t = clock();
		ans = gcd_integer_checking(a,b);
		t = clock()-t;
		double time_taken;
		time_taken = ((double)t)/CLOCKS_PER_SEC;
		printf("GCD of (%d,%d) = %d\n",a,b,ans);
		printf("Time = %lf\n",time_taken);
		fprintf(fp,"%d,%lf,%d\n",a+b,time_taken,optcount);
		optcount = 0;	
	}

	fclose(fp);
	return 0;
}

 int gcd_integer_checking(int m,int n){
 	int small;
 	small = (m>n)?n:m;
 	for(int i=small;i>=1;i--){
 		optcount++;
 		if(m%i==0 && n%i==0){
 			optcount++;
 			return i;
 		}
 		else
 			continue;
 	}
 }