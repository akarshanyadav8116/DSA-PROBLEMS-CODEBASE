#include<stdio.h>
#include<stdlib.h>
void merge(int arr[],int l,int m,int r){
	int n1,n2,i,j,k;
	n1=m-l+1;
	n2=r-m;
	int L[n1],R[n2];
	for(i=0;i<n1;i++){
		L[i]=arr[l+i];
	}
	for(j=0;j<n2;j++){
		R[j]=arr[m+j+1];
	}
	i=0;
	j=0;
	k=l;
	while(i<n1&&j<n2){
		if(L[i]<=R[j]){
			arr[k]=L[i];
			k++;i++;
		}
		else{
			arr[k]=R[j];
			k++;j++;
		}
	}
	while(i<n1){
		arr[k]=L[i];
		k++;i++;
	}
	while(j<n2){
		arr[k]=R[j];
		k++;j++;
	}
}

void mergesort(int arr[],int l,int r){
	if(l<r){
		int m=l+(r-l)/2;
		mergesort(arr,l,m);
		mergesort(arr,m+1,r);
		merge(arr,l,m,r);
	}
}

int main(){
	int i,arr_size;
    printf("Enter the size of the array");
    scanf("%d",&arr_size);
    int arr[arr_size];
    printf("Enter the elements of the array\n");
    for(i=0;i<arr_size;i++){
    	scanf("%d",&arr[i]);
	}
    printf("Given array is \n");
    for(i=0;i<arr_size;i++){
		printf("%d ",arr[i]);
	}
    mergesort(arr,0,arr_size-1);
    printf("\nSorted array is \n");
    for(i=0;i<arr_size;i++){
		printf("%d ",arr[i]);
	}
    return 0;
}
