#include<stdio.h>
#include<stdlib.h>
int bsearch(int a[],int p,int r,int key){
	int beg,mid,last;
	beg=0;
	last=r;
	while(beg<=last){
		mid=(beg+last)/2;
		if(a[mid]==key){
			return mid;
		}
		else if(key<a[mid]){
			last=mid-1;
		}
		else{
			beg=mid+1;
		}
	}
	return -1;
}
int main(){
	int i,n,*arr,pos,ele;
	printf("Enter the size of the array :");
	scanf("%d",&n);
	printf("Enter the elements of the array :");
	arr=(int*)calloc(n,sizeof(int));
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("Enter the element to search :");
	scanf("%d",&ele);
	pos=bsearch(arr,0,n-1,ele);
	if(pos==-1){
		printf("Element not found");
	}
	else{
		printf("The element is at position :%d",pos+1);
	}
	return 0;
}
