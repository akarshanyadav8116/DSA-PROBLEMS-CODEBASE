#include<stdio.h>
int toh(int disk,int start,int finish,int temp){
	if(disk>0){
		toh(disk-1,start,temp,finish);
		printf("Move CD from %d to %d\n",start,finish);
		toh(disk-1,temp,finish,start);
	}
}
int main(){
	int n;
	printf("Enter the no. of CDs :");
	scanf("%d",&n);
	toh(n,1,3,2);
	return 0;
}
