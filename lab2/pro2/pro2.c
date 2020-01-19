#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int gcd_middle_school(int m,int n);
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
		ans = gcd_middle_school(a,b);
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

int gcd_middle_school(int m,int n){
	if(m>n)
		gcd_middle_school(n,m);
		int factor = 2;
		int gcd = 1;
		int t = m;
		for(factor = 2;factor<=t;factor++){
			optcount++;
			while(m%factor==0 && n%factor == 0){
				optcount++;
				gcd = gcd * factor;
				m = m/factor;
				n= n/factor;
				if(m==0||n==0){
					optcount++;
					return gcd;
				}
			}
		}
	return gcd;
}