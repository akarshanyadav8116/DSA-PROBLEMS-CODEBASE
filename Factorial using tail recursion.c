#include<stdio.h>
int factorial(int n,int res){
	if(n==1){
		return res;
	}
	factorial(n-1,res*n);
}
int main(){
	int n;
	printf("Enter a number to calculate factorial");
	scanf("%d",&n);
	printf("The factorial of %d is %d ",n,factorial(n,1));
	return 0;
}
