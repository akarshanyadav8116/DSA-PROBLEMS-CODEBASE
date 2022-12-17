#include<stdio.h>
#include<stdlib.h>
int* countsort(int a[],int k,int size){
	int i,*hash,*b,temp;
	hash=(int*)calloc(k,sizeof(int));
	for(i=0;i<size;i++){
		hash[a[i]]++;
	}
	for(i=1;i<k;i++){
		hash[i]+=hash[i-1];
	}
	b=(int*)calloc(size,sizeof(int));
	for(i=0;i<size;i++){
		b[--hash[a[i]]]=a[i];
	}
	return b;
}
int main(){
	int i,n,*arr,max=0;
	printf("Name : Akarshan Yadav\n");
	printf("Roll No. :2101640100022\n");
	printf("Section : CS II A\n");
	printf("Program : Count Sort Algorithm\n\n");
	printf("Enter the size of the array :");
	scanf("%d",&n);
	arr=(int*)calloc(n,sizeof(int));
	printf("Enter the elements of the array :");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
		if(max<arr[i]){
			max=arr[i];
		}
	}
	arr=countsort(arr,max+1,n);
	printf("\nThe sorted array is :\n");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	return 0;
}
