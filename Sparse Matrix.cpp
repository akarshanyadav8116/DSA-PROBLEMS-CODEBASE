#include<stdio.h>
#include<stdlib.h>
int** createsparse(int **a,int rows,int cols,int c){
	int **sparr,i,j,k=0;
	sparr=(int**)calloc(3,sizeof(int*));
	for(i=0;i<3;i++){
		sparr[i]=(int*)calloc(c,sizeof(int));
	}
	for(i=0;i<rows;i++){
		for(j=0;j<cols;j++){
			if(a[i][j]!=0){
				sparr[0][k]=i;
				sparr[1][k]=j;
				sparr[2][k]=a[i][j];
				k++;			
			}
		}
	}
	return sparr;
}
int main(){
	int i,j,**arr,r,c,nz=0,**sp;
	printf("Enter the number of rows :");
	scanf("%d",&r);
	printf("Enter the number of columns :");
	scanf("%d",&c);
	arr=(int**)calloc(r,sizeof(int*));
	for(i=0;i<c;i++){
		arr[i]=(int*)calloc(c,sizeof(int));
	}
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			scanf("%d",&arr[i][j]);
			if(arr[i][j]!=0){
				nz++;
			}
		}
	}
	if(nz>(r*c-nz)){
		printf("\nThe sparse matrix cannot be created");
	}
	else{
		sp=createsparse(arr,r,c,nz);
		for(i=0;i<nz;i++){
			printf("%d ",sp[0][i]);
		}
		printf("\n");
		for(i=0;i<nz;i++){
			printf("%d ",sp[1][i]);
		}
		printf("\n");
		for(i=0;i<nz;i++){
			printf("%d ",sp[2][i]);
		}
	}
	return 0;
}
