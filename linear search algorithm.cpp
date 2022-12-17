#include<stdio.h>
#include<stdlib.h>
int lsearch(int a[],int key,int p,int r){
	int i;
	for(i=p;i<=r;i++){
		if(a[i]==key){
			return i;
		}
	}
	return -1;
}
int main(){
	int i,n,*arr,ele,pos;
	printf("Enter the size of the array :");
	scanf("%d",&n);
	arr=(int*)calloc(n,sizeof(int));
	printf("Enter the elements of the array :");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("Enter the element to search :");
	scanf("%d",&ele);
	pos=lsearch(arr,ele,0,n-1);
	if(pos==-1){
		printf("Element not found");
	}
	else{
		printf("The element is at position %d",pos+1);
	}
	return 0;
}
