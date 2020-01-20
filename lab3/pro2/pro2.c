#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int string_match(char str1[],char str[]);
int optcount;
int main(){
	system("clear");
	clock_t time;
	FILE *fp;
	fp = fopen("analysis.csv","a+");
	double time_taken;
	char str1[100],str2[100];
	printf("Enter string 1:");
	scanf("%[^\n]*c",str1);
	char ffff;
	scanf("%c",&ffff);
	printf("Enter string 2:");
	scanf("%[^\n]*c",str2);
	int m = strlen(str1);
	int n = strlen(str2);
	time = clock(); 
	int ans = string_match(str1,str2);
	time = clock()-time;
	time_taken = ((double)time)/CLOCKS_PER_SEC;
	fprintf(fp,"%d,%lf,%d,%d\n",m+n,time_taken,optcount,ans);
	printf("%d\n",ans);
	fclose(fp);
	return 0;
}

int string_match(char str1[],char str2[]){
	int flag;
	int m = strlen(str1);
	int n = strlen(str2);
	char *temp;
	if(m<n){
		temp = str1;
		str1=str2;
		str2=temp;
	}
	m = strlen(str1);
	n = strlen(str2);
	for(int i=0;i<=m-n;i++){
		optcount++;
		for(int j=i;j<i+n;j++){
			optcount++;
			 flag = 1;
			 if(str1[j]!=str2[j-i]){
			 	optcount++;
			 	flag = 0;
			 	break;
			 }
		}
		if(flag == 1){
			optcount++;
			break;
		}
	}
	if(flag == 1)return 1;
	else
	return 0;
}

